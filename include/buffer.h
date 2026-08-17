#pragma once 
#include "graphics.h"

typedef struct
{
    unsigned int id;

} cb_graphic_array_object;

typedef struct
{
    GLenum type;
    unsigned int attached_vao;
    unsigned int id;

}cb_graphic_buffer;


void cbGenVertexArrays(size_t n, cb_graphic_array_object* vaos);

void cbGenGraphicBuffer(cb_graphic_buffer* buffer, GLenum type, unsigned int vao);
void cbGraphicBufferData(cb_graphic_buffer* buffer, size_t data_size, void* data, GLenum usage);
void cbGraphicBufferSubData(cb_graphic_buffer* buffer, size_t data_size, long offset,void* data);
void cbSetAttribute(cb_graphic_buffer* buffer, int size, int index, GLenum type, GLboolean normalized, long stride, void* begin_offset);



