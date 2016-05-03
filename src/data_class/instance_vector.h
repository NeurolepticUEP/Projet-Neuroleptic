#ifndef INSTANCE_VECTOR_H
#define INSTANCE_VECTOR_H

#include <vector>

#include "graphic/drawable.h"
#include "instance.h"


/***************************************************************************************
 * Classe contenant l'ensemble des instance d'un même maillage                         *
 *------------------------------------------------------------------------------------*/
class Instance_Vector : protected QOpenGLFunctions_3_3_Core,  Drawable {
public:

    // Note : Pourquoi ne pas directement donnée les meshes ? Cela donnerai une meilleur vision du lien unissant les deux
    Instance_Vector(
            int nb_vertice                  //Nombre de vertices du mesh dont cette classe represente les instances
            )
        : nb_indices_(nb_vertice)
    {
        this->initializeOpenGLFunctions();
    }
    virtual ~Instance_Vector() {  }

    //Ajout d'une Instance a l'ensemble
    inline void addInstance(Instance* i) { this->vec_instance_.push_back(i); }

    //Dessin des elements contenu dans l'ensemble
    virtual void draw(Shader &shader) {
        std::vector<Instance*>::iterator it;

        for(it = this->vec_instance_.begin(); it != this->vec_instance_.end(); ++it) {
            shader.setUniformLocationM("matrix_model", (*it)->getOWMatrix());

            glDrawElements(GL_TRIANGLES, this->nb_indices_, GL_UNSIGNED_INT, 0);
        }
    }

private:
    std::vector<Instance*> vec_instance_;
    int nb_indices_;
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // INSTANCE_VECTOR_H
