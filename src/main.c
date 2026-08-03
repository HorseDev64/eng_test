#include "graphics.h"
#include "math/vector.h"
#include <X11/Xlib.h>
#include <math.h>
#define VERTEX_SHADER_DIR "src/shaders/vertex_shader.glsl"
#define FRAGMENT_SHADER_DIR "src/shaders/fragment_shader.glsl"
#define SHADERS_DIR "src/shaders/"
#define WINDOW_IMPLEMENTATION
#define FILE_LOADER_DEF
#define PRIMITIVES_IMPLEMENTATION
#include <primitives.h>
#include <shader.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <window.h>

void process_input(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main()
{

    //=============INIT CONFIG================
    //=================================

    initRoot();
    glfw_hints();
    GLFWwindow *window = genWindow(800, 800, "ventanita uwu");
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    loadGLAD();
    glViewport(0, 0, 800, 800);

    // REJECT MALLOC

    shader vertex_shader = {0}, fragment_shader = {0}, yellow_shader = {0};
    sh_init_shader_program(GL_VERTEX_SHADER, &vertex_shader.program,
                           &vertex_shader, VERTEX_SHADER_DIR);
    sh_init_shader_program(GL_FRAGMENT_SHADER, &vertex_shader.program,
                           &fragment_shader, FRAGMENT_SHADER_DIR);
    sh_link_shader_program(vertex_shader.program);

    sh_delete_shader_id(&vertex_shader);
    sh_init_shader_program(GL_FRAGMENT_SHADER, &yellow_shader.program,
                           &yellow_shader, SHADERS_DIR "yellow_shader.glsl");
    sh_init_shader_program(GL_VERTEX_SHADER, &yellow_shader.program,
                           &vertex_shader, VERTEX_SHADER_DIR);

    sh_link_shader_program(yellow_shader.program);

    sh_delete_shader_id(&fragment_shader);
    sh_delete_shader_id(&yellow_shader);

    //    add_triangle_attribute(second_triangle, (vec3){-0.5f, 0.0f, 0.0f},
    //    CB_POSITION);

    // add_triangle_attribute((vertex *)two_triangles + 3,
    //                        (vec3){-0.5f, 0.0f, 0.0f}, CB_POSITION);

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

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                          (void *)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    // second triangle

    glBindVertexArray(VAO[1]);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * 3, two_triangles,
                 GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                          (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                          (void *)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    //========================================

    // move_triangle_position(triangle, (vec3){0.2f, -0.5f, 0.0f});
    int acolor = glGetUniformLocation(vertex_shader.program, "aColor");
    glUniform4f(acolor, 1.0f, 0.3f, 0.4f, 1.0f);
    int offsetx = glGetUniformLocation(vertex_shader.program, "offsetx");
float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
};
    //in case of using the GL_CLAMP_TO_BORDER option, remember to set the filler color 
    //with glTexParameterfv
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

    //when a textures is downscaled, or upscaled we decide which type of texel interpolation
    //we want
    //also this works for configuring mipmaps
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    //if we want to configure the texel drawing of the mipmaps
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    //yeah mipmaps are used when downscaling, so why would you configure it when its upscaled?
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        process_input(window);
        glBindVertexArray(VAO[0]);
        glUseProgram(vertex_shader.program);
        glUniform4f(acolor, 1.0f, 0.3f, 0.4f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(VAO[1]);
        glUseProgram(yellow_shader.program);
        glUniform1f(offsetx, 0.5f);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
