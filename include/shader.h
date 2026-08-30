#pragma once
#include "graphics.h"
#include "os/directory.h"
#include "os/files.h"
#include <linux/limits.h>
#include <string.h>


typedef struct
{
    unsigned int id;
} g_program;


typedef struct
{
    unsigned int id;
    char* src_path;
} cb_shader;

void sh_check_shader_compilation(unsigned int shader, char *name);
void sh_check_program_linking(unsigned int program);
void genShader(cb_shader* sh, GLenum type, const char* relative_path);
void genProgram(g_program* program, int size, cb_shader* shaders);

