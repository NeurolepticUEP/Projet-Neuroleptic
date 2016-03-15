#ifndef TEXTURE_H
#define TEXTURE_H

#include "gl_include.h"
#include "shader.h"

class Texture {
public:
    static GLuint createFromFile(char* file);

    Texture(GLuint tex = 0): texid_(tex) {  }
    ~Texture() {  }

    GLint texid_;
};

#endif // TEXTURE_H

