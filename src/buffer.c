#include <buffer.h>

void cbGenVertexArrays(size_t n, cb_graphic_array_object *vaos)
{
    glGenVertexArrays(n, (unsigned int *)(&vaos->id));
}

void cbGenGraphicBuffer(cb_graphic_buffer *buffer, GLenum type,
                        unsigned int vao)
{

    buffer->type = type;

    if(!vao)
        goto gen;

    buffer->attached_vao = vao;
    glBindVertexArray(vao);

gen:
    glGenBuffers(1, &buffer->id);
    glBindBuffer(type, buffer->id);
}

void cbGraphicBufferData(cb_graphic_buffer *buffer, size_t data_size,
                         void *data, GLenum usage)
{
    glBindBuffer(buffer->type, buffer->id);
    glBufferData(buffer->type, data_size, data, usage);
}

void cbGraphicBufferSubData(cb_graphic_buffer *buffer, size_t data_size,
                            long offset, void *data)
{
    glBindBuffer(buffer->type, buffer->id);
    glBufferSubData(buffer->type, offset, data_size, data);
}

void cbSetAttribute(cb_graphic_buffer *buffer, int size, int index, GLenum type,
                    GLboolean normalized, long stride, void *begin_offset)
{
    glVertexAttribPointer(index, size, type, normalized, stride, begin_offset);
    glEnableVertexAttribArray(index);
}
