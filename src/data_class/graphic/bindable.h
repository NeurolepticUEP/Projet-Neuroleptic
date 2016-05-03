#ifndef BINDABLE_H
#define BINDABLE_H

#include "shader.h"

/***************************************************************************************
 * Classe virtuelle pur servant a interfacer les objet pouvant etre lier a la carte    *
 * graphique.                                                                          *
 * L'identifiant a pour but de faciliter le travail de tri entre les differents        *
 * elements                                                                            *
 *------------------------------------------------------------------------------------*/
class Bindable {
public:
    Bindable(std::string id): id_(id) {  }

    virtual void bind(Shader &shader) = 0;

    //Accesseur pour l'identifiant
    inline std::string getId() { return this->id_; }
protected:
   std::string id_;
};
 /**************************************************************************************
 * Auteur: ROVES Matthias                                                              *
 ***************************************************************************************/


#endif // BINDABLE_H
