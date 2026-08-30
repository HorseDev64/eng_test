#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void get_file_contents(char* dest, size_t size, const char* dir);
long get_file_size(const char* dir);


#ifdef FILES_IMPLEMENTATION

long get_file_size(const char* dir)
{
    struct stat st;
    stat(dir, &st);
    return (long)st.st_size + 1;

}


void get_file_contents(char* dest, size_t size, const char* dir){

    FILE* file = fopen(dir, "r");

    int ch, i = 0;
    while((ch = fgetc(file)) != EOF && i < size - 1)
    {

        dest[i] = ch;

        i++;
    }

    dest[i] = '\0';
    fclose(file);
    
}
#endif
