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
    glm::vec3 lightPosition = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 lightColor = glm::vec3(1.0, 1.0, 1.0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    glDisable(GL_BLEND);

    this->shader_->bind();

    this->shader_->setUniformLocation("camera_position", camera->getPosition());
    this->shader_->setUniformLocationM("matrix_projection", camera->getProjectionMatrix());
    this->shader_->setUniformLocationM("matrix_view", camera->getViewMatrix());

    this->shader_->setUniformLocation("light_position", lightPosition);
    this->shader_->setUniformLocation("light_color", lightColor);

    scene->draw(*(this->shader_));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

