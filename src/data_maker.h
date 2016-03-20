#ifndef DATA_MAKER_H
#define DATA_MAKER_H

#include <string>
#include <iostream>

#include "gl_include.h"
#include "data_class/graphic/mesh.h"

class Data_Maker {
public:
    static Mesh* createCubeMesh();
};

#endif // DATA_MAKER_H
