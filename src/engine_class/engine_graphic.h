#ifndef ENGINE_GRAPHIC_H
#define ENGINE_GRAPHIC_H

#include <string>

#include "engine_abstract.h"


#include "rendernnode.h"

/***************************************************************************************
 * Classe definnissant les fonctionnalité du moteur de rendu                           *
 *------------------------------------------------------------------------------------*/
class Engine_Graphic : protected QOpenGLFunctions_3_3_Core, public Engine_Abstract {
public:
    Engine_Graphic(World *world);
    ~Engine_Graphic();

    //Initialise les differents elements du moteur
    //Doit etre utilisé apres l'initialisation d'openGl pour que le moteur fonctionne
    virtual void initialize();

    //Affiche les donnée affichable dans le world (Aucune modification des donnée)
    virtual void update(World_Data* data);

    //Change la taille du rendu pour celui de la fenetre
    void resize();

private:
    RenderNode *render_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // ENGINE_GRAPHIC_H
