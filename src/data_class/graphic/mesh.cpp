#include "mesh.h"

Mesh::Mesh(std::string &id, GLuint vao, GLuint vbo):
    Bindable(id), vao_(vao), vbo_(vbo) {

    this->initializeOpenGLFunctions();
}

Mesh::Mesh(std::string &id, GLfloat *vertices, int length): Bindable(id) {
    GLuint vao, vbo;

    this->initializeOpenGLFunctions();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, length * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11*sizeof(GLfloat), (GLvoid*) 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11*sizeof(GLfloat), (GLvoid*) (3*sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11*sizeof(GLfloat), (GLvoid*) (6*sizeof(GLfloat)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 11*sizeof(GLfloat), (GLvoid*) (9*sizeof(GLfloat)));
        glEnableVertexAttribArray(3);

    glBindVertexArray(0);

    this->vao_ = vao;
    this->vbo_ = vbo;
}

Mesh::~Mesh() {

}

GLuint Mesh::getVAO() {
    return this->vao_;
}

GLuint Mesh::getVBO() {
    return this->vbo_;
}

void Mesh::bind(Shader&) {
    glBindVertexArray(this->vao_);
}
