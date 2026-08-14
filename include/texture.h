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
    unsigned int id;
    GLenum type;
    GLenum format;
}cb_texture;


void cb_genTexture(cb_texture* texture, GLenum type, GLint layer, GLenum format, const char* image);
void cb_defaultconfigureTexture2D(cb_texture *texture, int config_option);

void cb_configureTexture(cb_texture *texture, GLenum target, GLenum name,
                         GLint param, bool genMipmap);

void cb_textureImage(cb_texture* texture, const char* image);

