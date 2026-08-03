#pragma once
#include "graphics.h"
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void glfw_hints();
void loadGLAD()
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {

        printf("mala notinia mi gente\n");
    }
}
GLFWwindow *genWindow(int width, int height, char *title);

#ifdef WINDOW_IMPLEMENTATION

inline void glfw_hints()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *genWindow(int width, int height, char *title)
{
    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if(window == NULL)
    {
        printf("window cannot open \n");
        glfwTerminate();
        return NULL;
    }

    return window;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

#endif
