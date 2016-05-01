#ifndef INSTANCE_VECTOR_H
#define INSTANCE_VECTOR_H

#include <vector>
#include <iostream>

#include "graphic/drawable.h"
#include "instance.h"

class Instance_Vector : protected QOpenGLFunctions_3_3_Core,  Drawable {
public:
    Instance_Vector(int nb_vertice): nb_indices_(nb_vertice) {
        this->initializeOpenGLFunctions();
    }
    virtual ~Instance_Vector() {  }

    inline void addInstance(Instance* i) { this->vec_instance_.push_back(i); }

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

#endif // INSTANCE_VECTOR_H
