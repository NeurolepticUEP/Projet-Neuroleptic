#ifndef INSTANCE_VECTOR_H
#define INSTANCE_VECTOR_H

#include <vector>

#include "graphic/drawable.h"
#include "instance.h"

class Instance_Vector : protected QOpenGLFunctions_3_3_Core,  Drawable {
public:
    Instance_Vector(int nb_vertice): nb_vertices_(nb_vertice) {
        this->initializeOpenGLFunctions();
    }
    virtual ~Instance_Vector() {  }

    inline void addInstance(Instance* i) { this->vec_instance_.push_back(i); }

    virtual void draw(Shader &shader) {
        std::vector<Instance*>::iterator it;

        for(it = this->vec_instance_.begin(); it != this->vec_instance_.end(); ++it) {
            shader.setUniformLocationM("matrix_model", (*it)->getOWMatrix());

            glDrawArrays(GL_TRIANGLES, 0, nb_vertices_);
            glBindVertexArray(0);
        }
    }

private:
    std::vector<Instance*> vec_instance_;
    int nb_vertices_;

};

#endif // INSTANCE_VECTOR_H
