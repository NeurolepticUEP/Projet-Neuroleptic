#include "engine_graphic.h"

#include <iostream>

#include "../gl_include.h"
#include "world.h"

Engine_Graphic::Engine_Graphic(World *world)
    : Engine_Abstract(world) {
}

Engine_Graphic::~Engine_Graphic() {

}

void Engine_Graphic::initialize() {
    this->initializeOpenGLFunctions();

    int width = this->world_->getWindow()->width();
    int height = this->world_->getWindow()->height();

    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    this->render_ = new RenderNode();
}

void  Engine_Graphic::resize() {
    glViewport(0, 0, this->world_->getWindow()->width(), this->world_->getWindow()->height());
}

void Engine_Graphic::update(World_Data *data) {
    this->render_->draw(data->getCamera(), data->getScene());
}
