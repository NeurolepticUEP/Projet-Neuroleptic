#ifndef INSTANCE_H
#define INSTANCE_H

#include <string>

#include "../gl_include.h"

/***************************************************************************************
 * Classe definissant les instances des differents objets                              *
 *------------------------------------------------------------------------------------*/
class Instance {
public:
    Instance(
            std::string &id,            //Nom de l'instance (necessaire pour la structure contenant les donnée)
            glm::mat4 &OW_Matrix        //Matrice definissant l'instance
            )
        : id_(id), OW_matrix_(OW_Matrix)
    {

    }
    virtual ~Instance() {  }

    //Accesseur
    void setOWMatrix(glm::mat4& OW_matrix) { this->OW_matrix_ = OW_matrix; }
    glm::mat4& getOWMatrix() { return this->OW_matrix_; }

    std::string& getId() { return this->id_; }

private:
    std::string id_;
    glm::mat4 OW_matrix_;

};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

#endif // INSTANCE_H

