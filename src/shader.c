
#include "graphics.h"
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
void sh_check_program_linking(unsigned int program)
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

void genShader(cb_shader* sh, GLenum type, const char* relative_path)
{
    cb_path path;
    path_to_exec(&path);
    step_back_path(&path, 2);
    append_two_paths(&path, relative_path);

    int size = strlen(path.path);
    sh->src_path = malloc(size + 1);
    for (int i = 0; i < size + 1; i++) {
    
        sh->src_path[i] = path.path[i];
    }
    sh->src_path[size] = '\0';

    char sh_src[get_file_size(sh->src_path)];
    get_file_contents(sh_src, sizeof(sh_src), sh->src_path);
    const char* shsrc = sh_src;
    sh->id = glCreateShader(type);
    glShaderSource(sh->id, 1, &shsrc, NULL);
    glCompileShader(sh->id);
    sh_check_shader_compilation(sh->id, "a shader bro");

}

void genProgram(g_program* program, int size, cb_shader* shaders)
{
    if(glIsProgram(program->id))
    {
        goto attach;
    }
    program->id = glCreateProgram();

attach:
    for (int i = 0; i < size; i++) {
        glAttachShader(program->id, shaders[i].id);
    }
    glLinkProgram(program->id);
    sh_check_program_linking(program->id);
}

void cbGetUniformLocation(g_program* program, g_uniform *uniform)
{
    uniform->location = glGetUniformLocation(program->id, uniform->name);
}
void cbUniform1f(g_program* program, g_uniform uniform, float newValue)
{
    glUseProgram(program->id);
    glUniform1f(uniform.location, newValue);
}
void cbUniformVec2(g_program* program, g_uniform uniform, cb_vec2 newValue){
    glUseProgram(program->id);
    glUniform2f(uniform.location, newValue.x, newValue.y);
}

void cbUniformVec3(g_program* program, g_uniform uniform, cb_vec3 newValue){
    glUseProgram(program->id);
    glUniform3f(uniform.location, newValue.x, newValue.y, newValue.z);

}

void cbUniform1i(g_program* program, g_uniform uniform, int newValue){
    glUseProgram(program->id);
    glUniform1i(uniform.location, newValue);

}



