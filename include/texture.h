#pragma once
#include <stdio.h>
#include "graphics.h"
#include <stb_image.h>
#include <stdbool.h>
#define CB_TEXTURE_CONFIG_BASIC0 1
#define CB_TEXTURE_CONFIG_BASIC1 2
#define CB_TEXTURE_CONFIG_BASIC2 3
#define CB_TEXTURE_CONFIG_BASIC3 4
#define CB_TEXTURE_CONFIG_BASIC4 5
#define CB_TEXTURE_CONFIG_BASIC5 6

typedef struct
{
    GLint layer;
    GLint id;
    GLenum type;
}cb_texture;


void cb_genTexture(cb_texture* texture, GLenum type, GLint layer, GLenum format, const char* image);


