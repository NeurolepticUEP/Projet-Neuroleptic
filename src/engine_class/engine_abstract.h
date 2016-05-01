#ifndef ENGINE_ABSTRACT_H
#define ENGINE_ABSTRACT_H

#include "../data_class/world_data.h"

class World;

class Engine_Abstract {
public:
    Engine_Abstract(World* world) : world_(world) {  }
    virtual ~Engine_Abstract() {  }

    virtual void initialize() = 0;
    virtual void update(World_Data *data) = 0;

    inline World* getWorld() { return this->world_; }

protected:
    World *world_;
};

#endif // ENGINE_ABSTRACT_H
