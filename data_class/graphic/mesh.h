#ifndef MESH
#define MESH

#include <string>

#include "gl_include.h"
#include "bindable.h"

class Mesh : protected QOpenGLFunctions_3_3_Core, public Bindable {
public:
    Mesh(std::string &id, GLuint vao, GLuint vbo);
    Mesh(std::string &id, GLfloat *vertices, int length);
    virtual ~Mesh();

    GLuint getVAO();
    GLuint getVBO();
    GLuint getEBO();

    virtual void bind(Shader&);

private:
    GLuint vao_;
    GLuint vbo_;
};

#endif // MESH

