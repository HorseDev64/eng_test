#pragma once
#include "graphics.h"
#include "os/directory.h"
#include "os/files.h"
#include <linux/limits.h>
#include <math/vector.h>
#include <string.h>

#define cbSetUniform(Program, Uniform, X) _Generic((X), \
    int: cbUniform1i, \
    float: cbUniform1f, \
    vec2: cbUniformVec2, \
    vec3: cbUniformVec3 \
    )(Program, Uniform, X)

typedef struct
{
    unsigned int id;
} g_program;


typedef struct
{
    unsigned int id;
    char* src_path;
} cb_shader;


typedef struct
{
    char* name;
    GLint location;
} g_uniform;

// TODO: maybe we ~could~ MUST make some
// uniform struct that records its address so we dont have to
// search for it every time, reducing overhead
//

void sh_check_shader_compilation(unsigned int shader, char *name);
void sh_check_program_linking(unsigned int program);
void genShader(cb_shader* sh, GLenum type, const char* relative_path);
void genProgram(g_program* program, int size, cb_shader* shaders);
void cbGetUniformLocation(g_program* program, g_uniform *uniform);
void cbUniform1f(g_program* program, g_uniform uniform, float newValue);
void cbUniformVec2(g_program* program, g_uniform uniform, cb_vec2 newValue);
void cbUniformVec3(g_program* program, g_uniform uniform, cb_vec3 newValue);
void cbUniform1i(g_program* program, g_uniform uniform, int newValue);


