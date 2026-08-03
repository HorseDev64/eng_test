in the next config:


    unsigned int VBO[2], VBO2, EBO, VAO[2];
    glGenVertexArrays(2, VAO);
    glBindVertexArray(VAO[0]);
    glGenBuffers(2, VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 3,
                 (vertex *)two_triangles + 3, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                          (void *)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    //second triangle

    glBindVertexArray(VAO[1]);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 3, two_triangles,
                 GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                          (void *)0);
    glEnableVertexAttribArray(0);


    int acolor = glGetUniformLocation(program, "aColor");
    glUseProgram(program);
    glUniform4f(acolor, 0.7f, 0.2f, 0.2f, 1.0f);
    //========================================

    // move_triangle_position(triangle, (vec3){0.2f, -0.5f, 0.0f});

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        float time = glfwGetTime();
        float green = sin(time) ;
        glUniform4f(acolor, 0.0f, green, 0.0f, 1.0f);
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(sec_program);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

vertex_shader:
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 vertColor;

out vec3 newColor;

void main(){
 
    gl_Position = vec4(aPos, 1.0);
    newColor = vertColor;
    
}

fragment_shader:

#version 330 core

out vec4 FragColor;

uniform vec4 aColor;
void main(){
    FragColor = aColor;
} 

yellow_shader:

#version 330 core

out vec4 Frag_color;

void main(){

    Frag_color = vec4(1.0f, 1.0f, 0.1f, 0.0f);

    
}
 
theres an undefined behaviour where both triangle now use the same uniform aColor for their color, i dont know why, maybe is because i havent configure the 
vertColor variable in the second vao?

solution: no, it was not the problem, just not configuring the vao is a black color, the problem was that i didnt imported the variable newColor from the
vertex shader into the yellow_shader, most likely opengl tried to the find the variable in the program but since the compiler (by some reason) didnt launch
an error then it just got that undefined behaviour, maybe opengl trying to find desperately a valid memory address to fill up the unlinked newColor
```
hader vertex_shader = {0}, fragment_shader = {0}, yellow_shader = {0};
    init_shader_program(GL_VERTEX_SHADER, &vertex_shader.program, &vertex_shader, VERTEX_SHADER_DIR);
    init_shader_program(GL_FRAGMENT_SHADER, &vertex_shader.program, &fragment_shader, FRAGMENT_SHADER_DIR);
    link_shader_program(vertex_shader.program);

    
    init_shader_program(GL_VERTEX_SHADER, &yellow_shader.program, &vertex_shader, VERTEX_SHADER_DIR);
    init_shader_program(GL_FRAGMENT_SHADER, &yellow_shader.program, &yellow_shader, SHADERS_DIR"yellow_shader.glsl");
    link_shader_program(yellow_shader.program);

    delete_shader_id(&vertex_shader);
    delete_shader_id(&fragment_shader);
    delete_shader_id(&yellow_shader);

OUTPUT: the second triange has color and it actually outputs
the color of the vertex buffer object, but it not responds to the glUniform4f
call


////////////////////////////////
///////////DIFFERENT////////////

    shader vertex_shader = {0}, fragment_shader = {0}, yellow_shader = {0};
    init_shader_program(GL_VERTEX_SHADER, &vertex_shader.program, &vertex_shader, VERTEX_SHADER_DIR);
    init_shader_program(GL_FRAGMENT_SHADER, &vertex_shader.program, &fragment_shader, FRAGMENT_SHADER_DIR);
    link_shader_program(vertex_shader.program);

    init_shader_program(GL_FRAGMENT_SHADER, &yellow_shader.program, &yellow_shader, SHADERS_DIR"yellow_shader.glsl");
    attach_shader(&yellow_shader.program, &vertex_shader);
    link_shader_program(yellow_shader.program);

    delete_shader_id(&vertex_shader);
    delete_shader_id(&fragment_shader);
    delete_shader_id(&yellow_shader);

OUTPUT: the second triangle does not get color (fill-black) but it does 
respond to the glUniform4f call and changes its color correspondly

```

solution: the problem was that i linked the vertex_shader program into the yellow_shader program, so now when glUseProgram is called the 
vertex_shader program id is the one from the yellow_shader
