#ifndef MESH
#define MESH

#include <string>

#include "gl_include.h"
#include "bindable.h"

class Mesh : public Bindable {
public:
    Mesh(std::string &id, GLuint vao, GLuint vbo, GLuint ebo);
    virtual ~Mesh();

    GLuint getVAO();
    GLuint getVBO();
    GLuint getEBO();

    virtual void bind(Shader&);

private:
    GLuint vao_;
    GLuint vbo_;
    GLuint ebo_;
};

#endif // MESH

