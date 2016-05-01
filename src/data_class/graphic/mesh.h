#ifndef MESH
#define MESH

#include <string>

#include "../../gl_include.h"
#include "bindable.h"

class Mesh : protected QOpenGLFunctions_3_3_Core, public Bindable {
public:
    Mesh(std::string &id, GLuint vao, GLuint vbo);
    Mesh(std::string &id, GLfloat *vertices, GLuint *indices, int vert_length, int ind_length);
    virtual ~Mesh();

    GLuint getVAO();
    GLuint getVBO();
    GLuint getEBO();

    int getNbIndices() { return this->nb_indices_; }

    virtual void bind(Shader&);

private:
    GLuint vao_;
    GLuint vbo_;
    GLuint ebo_;

    int nb_indices_;
};

#endif // MESH

