#include "graphics.h"

void omla()
{
    unsigned int face;
    glGenTextures(1, &face);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, face);

}
/*#pragma once
#include "graphics.h"
#include <stdio.h>

void check_shader_compilation(unsigned int shader, char *name)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERROR: compiling %s shader: \n %s\n", name, infoLog);
    }
}
void check_program_linking(unsigned int program)
{
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("ERROR: linking %s  \n ", infoLog);
    }
}



static inline void main_implementation()
{
    char vert_dir[get_dir_size(VERTEX_SHADER_DIR)];
    get_file_dir(vert_dir,sizeof(vert_dir), VERTEX_SHADER_DIR);
    char frag_dir[get_dir_size(FRAGMENT_SHADER_DIR)];
    get_file_dir(frag_dir, sizeof(frag_dir), FRAGMENT_SHADER_DIR);
   
    char yellow_dir[get_dir_size(SHADERS_DIR"yellow_shader.glsl")];
    get_file_dir(yellow_dir, sizeof(yellow_dir), "src/shaders/yellow_shader.glsl");
 
    int y_src_size = fsize(yellow_dir);

    char y_src[y_src_size + 1];  
    get_file_content(yellow_dir, sizeof(y_src), y_src);
    y_src[y_src_size - 1] = '\0';
    const char* yellow_src = y_src;


    unsigned int vertex_shader, fragment_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vert_source, NULL);
    glCompileShader(vertex_shader);
    check_shader_compilation(vertex_shader, "vertex");

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &frag_source, NULL);
    glCompileShader(fragment_shader);
    check_shader_compilation(fragment_shader, "fragment");

    //glShaderSource() ;

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    check_program_linking(program);

    unsigned int yellow_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(yellow_shader, 1 ,&yellow_src, NULL);
    glCompileShader(yellow_shader);
    check_shader_compilation(yellow_shader, "yellow");

    unsigned int sec_program = glCreateProgram();
    glAttachShader(sec_program, vertex_shader);
    glAttachShader(sec_program, yellow_shader);
    glLinkProgram(sec_program);
    check_program_linking(sec_program);
    glDeleteShader(yellow_shader);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);


    
    int v_src_size = fsize(vert_dir);
    int f_src_size = fsize(frag_dir);

    char f_src[f_src_size + 1];
    char v_src[v_src_size + 1];

    for(char *car = v_src; *car != '\0'; car += 1)
    {

        *car = 0;
    }
    for(char *car = f_src; *car != '\0'; car += 1)
    {

        *car = 0;
    }

    get_file_content(vert_dir, v_src_size, v_src);
    get_file_content(frag_dir, f_src_size, f_src);
    v_src[v_src_size - 1] = '\0';
    f_src[f_src_size - 1] = '\0';
    const char *vert_source = v_src;
    const char *frag_source = f_src;




unsigned int vert_shader, frag_shader;
    vert_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert_shader, 1, &vert_source, NULL);
    glCompileShader(vert_shader);
    check_shader_compilation(vert_shader, "vertex");

    frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &frag_source, NULL);
    glCompileShader(frag_shader);
    check_shader_compilation(frag_shader, "fragment");

    unsigned int program;
    program = glCreateProgram();
    glAttachShader(program, vert_shader);
    glAttachShader(program, frag_shader);
    glLinkProgram(program);
    check_program_linking(program);

    unsigned int VBO, EBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square_vertices), square_vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_i), triangle_i, GL_STATIC_DRAW);

}*/

    
