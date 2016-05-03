#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include <vector>
#include <string>

#include "instance.h"
#include "graphic/shader.h"
#include "state.h"

/***************************************************************************************
 * Graph representant l'ensemble de la scene                                           *
 *------------------------------------------------------------------------------------*/
class SceneGraph {
public:
    SceneGraph();
    ~SceneGraph();

    //Fonction ajoutant une instance i au mesh identifié par mesh_id
    bool addInstance(Instance *i, std::string mesh_id);

    //Fonction permettant de charger en memoire
    void loadFile(std::string file);

    //Fonction dessinant l'ensemble du graphe de la scene
    void draw(Shader &shader);

private:
    void loadCubeData();

    MeshGraph *mesh_graph_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // SCENEGRAPH_H
