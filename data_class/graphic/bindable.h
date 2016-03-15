#ifndef BINDABLE_H
#define BINDABLE_H

#include "shader.h"

class Bindable {
public:
    Bindable(std::string id): id_(id) {  }

    virtual void bind(Shader &shader) = 0;
    inline std::string getId() { return this->id_; }

protected:
   std::string id_;
};


#endif // BINDABLE_H
