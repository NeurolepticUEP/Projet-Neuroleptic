#include "texture.h"

#include "SOIL.h"

GLuint Texture::createFromFile(char* file) {
    GLuint texture;
    int width, height;
    unsigned char* data;

    glGenTextures(1, &texture);
    data = SOIL_load_image(file, &width, &height, 0, SOIL_LOAD_RGB);

    glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    SOIL_free_image_data(data);

    return texture;
}
