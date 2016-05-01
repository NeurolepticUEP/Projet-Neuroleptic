#include "scenegraph.h"

#include <iostream>

#include "graphic/mesh.h"
#include "instance_vector.h"

#include "../data_maker.h"
#include "../objloading.h"

SceneGraph::SceneGraph() {
    this->mesh_graph_ = new MeshGraph();

    this->loadCubeData();
}

SceneGraph::~SceneGraph() {
    delete this->mesh_graph_;
}

void SceneGraph::draw(Shader &shader) {
    this->mesh_graph_->draw(shader);
}

bool SceneGraph::addInstance(Instance *i, std::string mesh_id) {
    Instance_Vector *i_vec;

    i_vec = this->mesh_graph_->findById(mesh_id);
    if(i_vec == nullptr) {
        std::cout << "Mesh: " << mesh_id << " not found" << std::endl;
        return false;
    }

    i_vec->addInstance(i);
    return true;
}

void SceneGraph::loadFile(std::string file) {
    Mesh *mesh = loadObjFile(file.c_str());

    (*this->mesh_graph_)[mesh] = new Instance_Vector(mesh->getNbIndices());
}

void SceneGraph::loadCubeData() {
    Mesh *mesh = Data_Maker::createCubeMesh();

    (*this->mesh_graph_)[mesh] = new Instance_Vector(36);
}
