#ifndef STATE_H
#define STATE_H

#include <map>
#include <string>

#include "graphic/drawable.h"
#include "graphic/mesh.h"
#include "instance_vector.h"


template<typename Key = Bindable*, typename Element = Drawable*>
class Abstract_State : public std::map<Key, Element>, Drawable {
public:
    virtual ~Abstract_State() {
        for(typename Abstract_State::iterator it = this->begin(); it != this->end(); ++it) {
            delete it->first;
            delete it->second;
        }
    }

    virtual Element findById(std::string id) {
        typename Abstract_State::iterator it = this->begin();

        while(it != this->end() &&  it->first->getId() != id) {
            it++;
        }

        return (it != this->end())? it->second : nullptr;
    }

    virtual void draw(Shader &shader) {
        for(typename Abstract_State::iterator it = this->begin(); it != this->end(); ++it) {
            it->first->bind(shader);
            it->second->draw(shader);
        }
    }
};

class MeshGraph : public Abstract_State<Mesh*, Instance_Vector*> {  };


#endif // STATE_H

