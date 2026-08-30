#include "graphics.h"
#include "math/vector.h"
#define VERTEX_SHADER_DIR "/src/shaders/vertex_shader.glsl"
#define FRAGMENT_SHADER_DIR "/src/shaders/fragment_shader.glsl"
#define SHADERS_DIR "src/shaders/"

#define DIRECTORY_IMPLEMENTATION
#define FILES_IMPLEMENTATION
#define WINDOW_IMPLEMENTATION
#define PRIMITIVES_IMPLEMENTATION
#include <os/directory.h>
#include <buffer.h>
#include <primitives.h>
#include <shader.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <texture.h>
#include <window.h>
// #include <texture.h>

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

    glfw_hints();
    GLFWwindow *window = genWindow(800, 800, "ventanita uwu");
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    loadGLAD();
    glViewport(0, 0, 800, 800);

    // REJECT MALLOC

    cb_shader vertex_shader = {0}, fragment_shader = {0};
    g_program program;
   
    //    add_triangle_attribute(second_triangle, (vec3){-0.5f, 0.0f, 0.0f},
    //    CB_POSITION);

    genShader(&vertex_shader, GL_VERTEX_SHADER, VERTEX_SHADER_DIR);
    genShader(&fragment_shader, GL_FRAGMENT_SHADER, FRAGMENT_SHADER_DIR);
    genProgram(&program, 1 , &vertex_shader);
    genProgram(&program, 1 , &fragment_shader);


    // add_triangle_attribute((vertex *)two_triangles + 3,
    //                        (vec3){-0.5f, 0.0f, 0.0f}, CB_POSITION);
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    cb_graphic_buffer vbo, ebo;
    cb_graphic_array_object vao;
    cbGenVertexArrays(1, &vao);
    cbGenGraphicBuffer(&vbo, GL_ARRAY_BUFFER, vao.id);
    cbGraphicBufferData(&vbo, sizeof(square_vertices) + sizeof(tex_indices),
                        NULL, GL_STATIC_DRAW);
    cbGraphicBufferSubData(&vbo, sizeof(square_vertices), 0, square_vertices);
    cbGraphicBufferSubData(&vbo, sizeof(tex_indices), sizeof(square_vertices),
                           tex_indices);
    cbSetAttribute(&vbo, 3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                   (void *)0);
    cbSetAttribute(&vbo, 3, 1, GL_FLOAT, GL_FALSE, sizeof(float) * 6,
                   (void *)(sizeof(float) * 3));
    cbSetAttribute(&vbo, 2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,
                   (void *)(sizeof(square_vertices)));

    cbGenGraphicBuffer(&ebo, GL_ELEMENT_ARRAY_BUFFER, vao.id);
    cbGraphicBufferData(&ebo, sizeof(indices), indices, GL_STATIC_DRAW);

    //========================================

    // move_triangle_position(triangle, (vec3){0.2f, -0.5f, 0.0f});
    int acolor = glGetUniformLocation(program.id, "aColor");
    glUniform4f(acolor, 1.0f, 0.3f, 0.4f, 1.0f);
    int offsetx = glGetUniformLocation(program.id, "offsetx");

    // in case of using the GL_CLAMP_TO_BORDER option, remember to set the
    // filler color
    //=================================
    //==========TEXTURE SETTS=============

    cb_path wood_dir, face_dir;
    path_to_exec(&wood_dir);
    path_to_exec(&face_dir);
    step_back_path(&wood_dir, 2);
    step_back_path(&face_dir, 2);
    append_two_paths(&wood_dir, "/assets/textures/wooden_container.jpg");
    append_two_paths(&face_dir, "/assets/textures/awesomeface.png");

    // cb_texture wood, face;
    cb_texture wood, face;
    // stbi_set_flip_vertically_on_load(true);
    cb_genTexture(&wood, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, wood_dir.path);
    cb_defaultconfigureTexture2D(&wood, CB_TEXTURE_CONFIG_BASIC0);
    cb_genTexture(&face, GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, face_dir.path);
    cb_defaultconfigureTexture2D(&face, CB_TEXTURE_CONFIG_BASIC1);
    glUseProgram(program.id);
    glUniform1i(glGetUniformLocation(program.id, "ourTex"), 0);
    glUniform1i(glGetUniformLocation(program.id, "tex2"), 1);
    glUniform1f(glGetUniformLocation(program.id, "alpha2"), 0.2f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    float v = 0;
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        process_input(window);

        if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        {
            v += 0.02f;
        }
        if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        {
            v -= 0.02f;
        }
        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, wood);
        // glActiveTexture(GL_TEXTURE1);
        // glBindTexture(GL_TEXTURE_2D, face);

        glUseProgram(program.id);
        glBindVertexArray(vao.id);
        glUniform1f(glGetUniformLocation(program.id, "alpha2"), v);

        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
