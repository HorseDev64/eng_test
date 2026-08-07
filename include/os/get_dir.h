#pragma once
// give thanks to chatgpt
#include <stdlib.h>
#include <string.h>

extern int path_count;
extern char *build_root;
extern char *_root;
int get_executable_dir(char *out, size_t size);
int initRoot();
void gcnt();

int dir_get_size(const char* file_dir);
void dir_get_file(char* destination, int length, const char *file_dir);


#ifdef DIR_IMPLEMENT

/* */

int path_count = 0;
char* build_root = 0;
char* _root = 0;

int dir_get_size(const char *file_dir)
{
    return strlen(file_dir) + strlen(_root) + 2;
}
void dir_get_file(char *destination, int length, const char *file_dir)
{

    int last = 0;
    for(int i = 0; i < length; i++)
    {
        if(!last && _root[i] == '\0')
        {
            destination[i] = '/';
            last = i + 1;
            continue;
        }
        if(!last)
        {
            destination[i] = _root[i];
        }
        else
        {
            destination[i] = file_dir[i - last];
        }
    }

    destination[length - 1] = '\0';
}

int initRoot()
{
    gcnt();
    build_root = malloc(path_count);
    get_executable_dir(build_root, path_count);
    for(char *p = build_root; *p != '\0'; p++)
    {
        if(*p == '\\')
        {
            *p = '/';
        }
    }
    _root = malloc(path_count);
    strncpy(_root, build_root, path_count);
    for(int i = path_count; i >= 0; i--)
    {
        if(_root[i] == '/')
        {
            _root[i] = '\0';
            break;
        }
    }
    return 1;
}

#if defined(_WIN32)
#include <windows.h>
void gcnt() { path_count = MAX_PATH; }
int get_executable_dir(char *out, size_t size)
{
    char path[MAX_PATH];
    DWORD len = GetModuleFileNameA(NULL, path, MAX_PATH);
    if(len == 0 || len == MAX_PATH)
        return 0;

    for(int i = len - 1; i >= 0; --i)
    {
        if(path[i] == '\\')
        {
            path[i] = '\0';
            break;
        }
    }

    strncpy(out, path, size);
    out[size - 1] = '\0';
    return 1;
}

#elif defined(__APPLE__)
#include <limits.h>
#include <mach-o/dyld.h>
void gcnt() { path_count = PATH_MAX; }
int get_executable_dir(char *out, size_t size)
{
    char path[PATH_MAX];
    uint32_t len = sizeof(path);

    if(_NSGetExecutablePath(path, &len) != 0)
        return 0;

    for(int i = strlen(path) - 1; i >= 0; --i)
    {
        if(path[i] == '/')
        {
            path[i] = '\0';
            break;
        }
    }

    strncpy(out, path, size);
    out[size - 1] = '\0';

    return 1;
}

#elif defined(__linux__)
#include <libgen.h>
#include <limits.h>
#include <unistd.h>
void gcnt() { path_count = PATH_MAX; }
int get_executable_dir(char *out, size_t size)
{
    char path[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if(len == -1)
        return 0;

    path[len] = '\0';
    char *dir = dirname(path);

    strncpy(out, dir, size);
    out[size - 1] = '\0';

    return 1;
}

#else
#error "Platform not supported"
#endif
#endif
