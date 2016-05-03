#ifndef RENDERGRAPH_H
#define RENDERGRAPH_H

#include <string>

#include "../gl_include.h"

#include "../data_class/state.h"
#include "../data_class/scenegraph.h"
#include "../data_class/graphic/shader.h"
#include "../data_class/graphic/camera.h"


/***************************************************************************************
 * Classe definnissant le noeud de rendu affichant la scene                            *
 *------------------------------------------------------------------------------------*/
class RenderNode : protected QOpenGLFunctions_3_3_Core {
public:
    RenderNode();
    ~RenderNode();

    //Affiche la scene selon le point de vue de la camera
    void draw(Camera *camera, SceneGraph *scene);

private:
    Shader *shader_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // RENDERGRAPH_H
