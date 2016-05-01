#include "rendernnode.h"

#include <iostream>
#include <string>

RenderNode::RenderNode() {
    this->shader_ = new Shader("./shader/display.vert", "./shader/display.frag");

    this->initializeOpenGLFunctions();
}

RenderNode::~RenderNode() {
    delete this->shader_;
}

void RenderNode::draw(Camera *camera, SceneGraph *scene) {
    glm::vec3 lightPosition = glm::vec3(0.0f, 0.0f, 5.0f);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    this->shader_->bind();

    this->shader_->setUniformLocation("light_position", lightPosition);
    this->shader_->setUniformLocation("camera_position", camera->getPosition());

    this->shader_->setUniformLocationM("matrix_projection", camera->getProjectionMatrix());
    this->shader_->setUniformLocationM("matrix_view", camera->getViewMatrix());

    this->shader_->setUniformLocationT("texture_diffuse", 0);
    this->shader_->setUniformLocationT("texture_roughtness", 1);
    this->shader_->setUniformLocationT("texture_metalpart", 2);
    this->shader_->setUniformLocationT("texture_normal", 3);

    scene->draw(*(this->shader_));
}

