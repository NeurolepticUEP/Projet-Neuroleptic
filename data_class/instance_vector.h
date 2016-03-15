#ifndef INSTANCE_VECTOR_H
#define INSTANCE_VECTOR_H

#include <vector>

#include "graphic/drawable.h"
#include "instance.h"

class Instance_Vector : public std::vector<Instance*>, Drawable {
public:
    virtual ~Instance_Vector() {  }

    virtual void draw(Shader &shader) {
        Instance_Vector::iterator it;

        for(it = this->begin(); it != this->end(); ++it) {
            shader.setUniformLocationM("matrix_model", (*it)->getOWMatrix());

            //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            glDrawArrays(GL_TRIANGLES, 0, 36);
            glBindVertexArray(0);
        }
    }

};

#endif // INSTANCE_VECTOR_H
