#ifndef ENGINE_GRAPHIC_H
#define ENGINE_GRAPHIC_H

#include <string>

#include "engine_abstract.h"


#include "rendernnode.h"

class Window;

class Engine_Graphic : protected QOpenGLFunctions_3_3_Core, public Engine_Abstract {
public:
    Engine_Graphic(World *world);
    virtual ~Engine_Graphic();

    virtual void initialize();
    virtual void update(World_Data* data);

    void resize(int w, int h);

private:
    RenderNode *render_;
};

#endif // ENGINE_GRAPHIC_H
