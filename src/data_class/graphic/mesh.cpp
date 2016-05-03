#include "mesh.h"

Mesh::Mesh(std::string &id, GLuint vao, GLuint vbo, GLuint ebo):
    Bindable(id), vao_(vao), vbo_(vbo), ebo_(ebo) {

    this->initializeOpenGLFunctions();
}

Mesh::Mesh(std::string &id, GLfloat *vertices, GLuint *indices, int vert_length, int ind_length): Bindable(id) {
    GLuint vao, vbo, ebo;

    this->initializeOpenGLFunctions();

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vert_length * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, ind_length * sizeof(GLuint), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9*sizeof(GLfloat), (GLvoid*) 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9*sizeof(GLfloat), (GLvoid*) (3*sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9*sizeof(GLfloat), (GLvoid*) (6*sizeof(GLfloat)));
        glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    this->vao_ = vao;
    this->vbo_ = vbo;
    this->ebo_ = ebo;
    this->nb_indices_ = ind_length;
}

Mesh::~Mesh() {

}

GLuint Mesh::getVAO() {
    return this->vao_;
}

GLuint Mesh::getVBO() {
    return this->vbo_;
}

GLuint Mesh::getEBO(){
    return this->ebo_;
}

void Mesh::bind(Shader&) {
    glBindVertexArray(this->vao_);
}
