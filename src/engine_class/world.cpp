#include "world.h"

#include <iostream>
#include <string>

#include "../window.h"
#include "../data_class/graphic/camera.h"
#include "../data_class/instance.h"
#include "../data_class/scenegraph.h"

#include "engine_graphic.h"
#include "engine_interaction.h"

World::World(QWidget *window): window_(window) {
    this->engines_.push_back(new Engine_Interaction(this));
    this->engines_.push_back(new Engine_Graphic(this));
}

void World::initialize() {
    for(unsigned int i = 0; i < this->engines_.size(); ++i) {
        this->engines_[i]->initialize();
    }

    Camera *camera = new Camera(
                               MODE_TRACKBALL_H,
                               glm::vec3(0.0, 0.0, -3.0f), glm::vec3(0.0, 0.0, 1.0),
                               45.0f, this->window_->width(), this->window_->height()
                              );


    SceneGraph *scene = new SceneGraph();
    glm::mat4 mat(1.0f);
    std::string name("test"), mesh("cube_mesh");

    Instance *inst = new Instance(name, mat);
    scene->addInstance(inst, mesh);
    this->data_ = new World_Data(camera, scene);
    this->data_->addBodyPart(inst, 8);

    inst = new Instance(name, mat);
    scene->addInstance(inst, mesh);
    this->data_ = new World_Data(camera, scene);
    this->data_->addBodyPart(inst, 8);
}

void World::update() {
    for(unsigned int i = 0; i < this->engines_.size(); ++i) {
        this->engines_[i]->update(this->data_);
    }
}
