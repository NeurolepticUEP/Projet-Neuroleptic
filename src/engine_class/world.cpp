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

World::~World() {
    for(unsigned int i = 0; i < this->engines_.size(); ++i) {
        delete this->engines_[i];
    }
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
    glm::mat4 mat(0.5f);
    std::string name_pok1("mesh_POK1"), name_pok2("mesh_POK2"), mesh_pok("POK");

    mat = glm::translate(mat, glm::vec3(1.0, 0.0, 0.0));
    Instance *inst_pok1 = new Instance(name_pok1, mat);

    mat = glm::translate(mat, glm::vec3(-2.0, 0.0, 0.0));
    Instance *inst_pok2 = new Instance(name_pok2, mat);

    scene->loadFile("POK.obj");
    scene->addInstance(inst_pok1, mesh_pok);
    scene->addInstance(inst_pok2, mesh_pok);

    this->data_ = new World_Data(camera, scene);

    this->data_->addBodyPart(inst_pok1, 8);
    this->data_->addBodyPart(inst_pok2, 14);
}

void World::update() {
    for(unsigned int i = 0; i < this->engines_.size(); ++i) {
        this->engines_[i]->update(this->data_);
    }
}
