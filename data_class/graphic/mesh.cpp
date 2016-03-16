#include "mesh.h"

Mesh::Mesh(std::string &id, GLuint vao, GLuint vbo, GLuint ebo):
    Bindable(id), vao_(vao), vbo_(vbo), ebo_(ebo) {
}

Mesh::~Mesh() {

}

GLuint Mesh::getVAO() {
    return this->vao_;
}

GLuint Mesh::getVBO() {
    return this->vbo_;
}

GLuint Mesh::getEBO() {
    return this->ebo_;
}

void Mesh::bind(Shader&) {
    glBindVertexArray(this->vao_);
}
