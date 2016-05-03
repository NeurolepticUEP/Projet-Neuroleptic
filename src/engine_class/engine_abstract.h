#ifndef ENGINE_ABSTRACT_H
#define ENGINE_ABSTRACT_H

#include "../data_class/world_data.h"

class World;

/***************************************************************************************
 * Classe abstraite d'un moteur                                                        *
 *------------------------------------------------------------------------------------*/
class Engine_Abstract {
public:
    Engine_Abstract(World* world) : world_(world) {  }
    virtual ~Engine_Abstract() {  }

    //Fonction permettant d'initialiser le moteur une fois que tout est mis en place (openGL..)
    virtual void initialize() = 0;

    //Travail sur les donnée passée en parametre
    virtual void update(World_Data *data) = 0;

    //Accesseur
    inline World* getWorld() { return this->world_; }

protected:
    World *world_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // ENGINE_ABSTRACT_H
