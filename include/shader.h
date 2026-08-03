#pragma once
#include "graphics.h"
#include <stdbool.h>
#include "math/vector.h"
#include "os/file_loader.h"
#include "stdio.h"
#include "os/get_dir.h"
typedef struct
{
    unsigned int id;
    unsigned int program;
    GLenum shader_type;
}shader;

void sh_check_shader_compilation(unsigned int shader, char *name);
void sh_check_program_linking(unsigned int program);
int sh_get_dir_size(const char* file_dir);
void sh_get_file_dir(char* destination, int length, const char *file_dir);
void sh_init_shader_program(GLenum shader_type, unsigned int *program, shader* shade, const char* shader_src_dir);
void sh_attach_shader(unsigned int* program, shader* shader);
void sh_link_shader_program(unsigned int program);
void sh_delete_shader_id(shader* shade);

