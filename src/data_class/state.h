#ifndef STATE_H
#define STATE_H

#include <map>
#include <string>

#include "graphic/drawable.h"
#include "graphic/mesh.h"
#include "instance_vector.h"


/***************************************************************************************
 * Classe representant une interaction basique dans le graphe de scene                 *
 * Ainsi, ce dernier regroupe un ensemble d'objet devant etre lié a un ensemble d'objet*
 * a affiché                                                                           *
 *------------------------------------------------------------------------------------*/
template<typename Key = Bindable*, typename Element = Drawable*>
class Abstract_State : public std::map<Key, Element>, Drawable {
public:
    virtual ~Abstract_State() {
        for(typename Abstract_State::iterator it = this->begin(); it != this->end(); ++it) {
            delete it->first;
            delete it->second;
        }
    }

    //Fonction permettant de retrouver un des fils a partir de son identifiant
    virtual Element findById(std::string id) {
        typename Abstract_State::iterator it = this->begin();

        while(it != this->end() &&  it->first->getId() != id) {
            it++;
        }

        return (it != this->end())? it->second : nullptr;
    }

    //Fonction dessinant le micro-grpahe
    virtual void draw(Shader &shader) {
        for(typename Abstract_State::iterator it = this->begin(); it != this->end(); ++it) {
            it->first->bind(shader);
            it->second->draw(shader);
        }
    }
};
/**************************************************************************************
* Auteur: ROVES Matthias                                                              *
***************************************************************************************/

typedef Abstract_State<Mesh*, Instance_Vector*> MeshGraph;

#endif // STATE_H

