#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <vector>
#include <string>

#include "instance.h"
#include "graphic/shader.h"
#include "state.h"

class SceneGraph {
public:
    SceneGraph();
    ~SceneGraph();

    bool addInstance(Instance *i, std::string mesh_id);
    void draw(Shader &shader);

private:
    void loadCubeData();

    MeshGraph *mesh_graph_;
};

#endif // SCENEGRAPH_H
