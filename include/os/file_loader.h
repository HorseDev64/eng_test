#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
* returns the size of a file without
                        * the null terminator '\0'
                        */
static inline int fsize(const char *filename) {
  struct stat st;

  if (stat(filename, &st) == 0)
    return (int)st.st_size;

  return -1;
}
void *get_file_content(const char *filename, int size, char* buffer);
static inline void omla() { printf("omla\n"); }

#ifdef FILE_LOADER_DEF

void *get_file_content(const char *filename, int size, char* buffer) {

  FILE *fd = fopen(filename, "r");
  fseek(fd, 0, SEEK_END);
  fseek(fd, 0, SEEK_SET);

  fread(buffer, 1, size, fd);

  fclose(fd);
  buffer[size - 1] = '\0';

}

#endif
