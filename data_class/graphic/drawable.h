#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "shader.h"

class Drawable {
public:
    virtual void draw(Shader &shader) = 0;
};

#endif // DRAWABLE_H

