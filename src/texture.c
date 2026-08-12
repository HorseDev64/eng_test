#include "graphics.h"
#define STB_IMAGE_IMPLEMENTATION
#include <texture.h>

void cb_genTexture(cb_texture *texture, GLenum type, GLint layer, GLenum format,
                   const char *image)
{

    glActiveTexture(layer);
    glGenTextures(1, &texture->id);
    glBindTexture(type, texture->id);

    int width, height, nrChannels;
    unsigned char *file = stbi_load(image, &width, &height, &nrChannels, 0);

    if(type == GL_TEXTURE_2D)
    {

        glTexImage2D(type, 0, format, width, height, 0, format,
                     GL_UNSIGNED_BYTE, file);
    }
    else if(type == GL_TEXTURE_3D)
    {
        printf("i havent done anything here lol\n");
    }

    printf("%i\n", &texture);

    stbi_image_free(file);
}

void cb_defaultconfigureTexture2D(cb_texture *texture, int config_option)
{
    glActiveTexture(texture->layer);
    glBindTexture(texture->type, texture->id);
    switch(config_option)
    {

    case CB_TEXTURE_CONFIG_BASIC0:
        goto conf0;

        break;
    case CB_TEXTURE_CONFIG_BASIC1:
        goto conf1;

        break;
    }

conf0:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    goto def_conf;

conf1:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                    GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    goto def_conf;

def_conf:
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void cb_configureTexture(cb_texture *texture, GLenum target, GLenum name,
                         GLint param, bool genMipmap)
{
    glActiveTexture(texture->layer);
    glBindTexture(texture->type, texture->id);
    glTexParameteri(target, name, param);
}
