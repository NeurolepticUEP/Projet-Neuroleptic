#ifndef RENDERGRAPH_H
#define RENDERGRAPH_H

#include <string>

#include "gl_include.h"

#include "../data_class/state.h"
#include "../data_class/scenegraph.h"
#include "../data_class/graphic/shader.h"
#include "../data_class/graphic/camera.h"


class RenderNode {
public:
    RenderNode();
    ~RenderNode();

    void draw(Camera *camera, SceneGraph *scene);

private:
    Shader *shader_;
};

#endif // RENDERGRAPH_H
