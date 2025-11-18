

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "pch.hpp"
#include "Texture.hpp"

Texture::Texture(const char* imagePath) {
    // Load texture from imagePath
    glGenTextures(1, &this->ID);
    glBindTexture(GL_TEXTURE_2D, this->ID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load image, create texture and generate mipmaps
    int width, height, nrChannels;
    unsigned char *data = stbi_load(imagePath, &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format;
        if (nrChannels == 3) {
            format = GL_RGB;
        }
        else {
            format = GL_RGBA;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "ERROR::TEXTURE::FAILED_TO_LOAD::" << imagePath << std::endl;
    }
    stbi_image_free(data);  
}

Texture::~Texture(void) {

}