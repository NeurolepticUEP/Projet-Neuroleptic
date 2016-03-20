#ifndef INSTANCE_H
#define INSTANCE_H

#include <string>

#include "../gl_include.h"

class Instance {
public:
    Instance(std::string &id, glm::mat4 &OW_Matrix) : id_(id), OW_matrix_(OW_Matrix) {  }
    virtual ~Instance() {  }

    void setOWMatrix(glm::mat4& OW_matrix) { this->OW_matrix_ = OW_matrix; }
    glm::mat4& getOWMatrix() { return this->OW_matrix_; }

    std::string& getId() { return this->id_; }

private:
    std::string id_;
    glm::mat4 OW_matrix_;

};

#endif // INSTANCE_H

