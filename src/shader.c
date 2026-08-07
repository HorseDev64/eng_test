#include "graphics.h"
#define DIR_IMPLEMENT
#include <shader.h>

void sh_check_shader_compilation(unsigned int shader, char *name)
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
void sh_check_program_linking4(unsigned int program)
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



void sh_init_shader_program(GLenum shader_type, 
                         unsigned int *program, cb_shader *shade,
                         const char *shader_src_dir)
{
    char tmp_dir[dir_get_size(shader_src_dir)];
    dir_get_file(tmp_dir, sizeof(tmp_dir), shader_src_dir);

    char tmp_src[fsize(shader_src_dir) + 1];
    get_file_content(shader_src_dir, sizeof(tmp_src), tmp_src);
    const char *src = tmp_src;

    shade->id = glCreateShader(shader_type);
    glShaderSource(shade->id, 1, &src, NULL);
    glCompileShader(shade->id);
    sh_check_shader_compilation(shade->id, "default");

    if(*program)
    {
        glAttachShader(*program, shade->id);
        return;
    }
    *program = glCreateProgram();
    glAttachShader(*program, shade->id);

    shade->program = *program;
}

void sh_attach_shader(unsigned int *program, cb_shader *shader)
{

    glAttachShader(*program, shader->id);
}
void sh_delete_shader_id(cb_shader *shade) { glDeleteShader(shade->id); }

void sh_link_shader_program(unsigned int program)
{
    glLinkProgram(program);
    sh_check_program_linking4(program);
}

