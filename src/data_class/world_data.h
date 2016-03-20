#ifndef WORLD_DATA_H
#define WORLD_DATA_H

#include <string>

#include "graphic/camera.h"
#include "scenegraph.h"
#include "instance.h"


class World_Data {
public:
    World_Data(Camera *camera, SceneGraph *scene): camera_(camera), scene_(scene) {  }
    ~World_Data() {
        delete this->camera_;
        delete this->scene_;
    }

    inline Camera* getCamera() { return this->camera_; }
    inline SceneGraph* getScene() { return this->scene_; }

    inline void addBodyPart(Instance* i, int slot) { this->body_part_[slot] = i; }
    inline Instance* getBodyPart(int slot) { return this->body_part_[slot]; }

private:
    Camera *camera_;
    SceneGraph *scene_;

    Instance* body_part_[24];
};

#endif // WORLD_DATA_H
