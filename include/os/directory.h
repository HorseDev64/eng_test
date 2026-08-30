
#pragma once
#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>


typedef struct
{
    char path[PATH_MAX];
    ssize_t effective_size;

}cb_path;



void path_to_exec(cb_path* path);
void step_back_path(cb_path* path, int steps);
void append_two_paths(cb_path* path, const char* new);






#ifdef DIRECTORY_IMPLEMENTATION
void path_to_exec(cb_path* path)
{
    path->effective_size = readlink("/proc/self/exe", path->path, PATH_MAX);
    if(path->effective_size == -1)
    {
        perror("ERROR: NO POSSIBLE TO GET EXECUTABLE PATH");
    }
    path->path[path->effective_size] = '\0';

}
void append_two_paths(cb_path* path, const char* new)
{

    int size = path->effective_size + strlen(new);
    for(int i = path->effective_size; i < size; i++)
    {
        path->path[i] = new[i - path->effective_size];

    }
    path->effective_size += strlen(new);

    path->path[size] = '\0';
}
void step_back_path(cb_path* path, int steps)
{
    int i = 0;
    for (char* ch = path->path + path->effective_size - 1; i < steps ; ch--) {
        if(*ch == '/')
        {
            i++;
            
        }
        path->effective_size--;
        *ch = 'a';

    }

    path->path[path->effective_size] = '\0';

}
#endif
