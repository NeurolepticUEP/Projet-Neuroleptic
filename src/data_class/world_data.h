#ifndef WORLD_DATA_H
#define WORLD_DATA_H

#include <string>

#include "graphic/camera.h"
#include "scenegraph.h"
#include "instance.h"


/***************************************************************************************
 * Classe representant l'ensemble des donnée necessaire au bon fonctionnement du projet*
 *------------------------------------------------------------------------------------*/
class World_Data {
public:
    World_Data(
            Camera *camera,             //Camera representant le point de vue de la scene
            SceneGraph *scene           //Scene devant etre affichée
            )
        : camera_(camera), scene_(scene)
    {

    }

    ~World_Data() {
        delete this->camera_;
        delete this->scene_;
    }

    //Accesseur
    inline Camera* getCamera() { return this->camera_; }
    inline SceneGraph* getScene() { return this->scene_; }

    //Fonction permettant de lier une instance a une des partie du corps definie par FAAST
    inline void addBodyPart(Instance* i, int slot) { this->body_part_[slot] = i; }

    //Fonction permettant de recuperer l'instance liée a la partie du corps definie par FAAST
    inline Instance* getBodyPart(int slot) { return this->body_part_[slot]; }

private:
    Camera *camera_;
    SceneGraph *scene_;

    Instance* body_part_[24];
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // WORLD_DATA_H
