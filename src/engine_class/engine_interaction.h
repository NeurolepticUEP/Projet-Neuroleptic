#ifndef ENGINE_INTERACTION_H
#define ENGINE_INTERACTION_H

#include <QKeyEvent>
#include <QCursor>
#include <vector>

#include "engine_abstract.h"

#include "vrpn_Tracker.h"

#include "../sintracker.h"

class Window;

class Engine_Interaction : public Engine_Abstract {
public:
    Engine_Interaction(World* world);
    ~Engine_Interaction();

    void keyboardEventHandler(QKeyEvent *e);

    virtual void initialize();
    virtual void update(World_Data* data);

private:
    SinTracker *sintracker_;
    vrpn_Tracker_Remote* vrpnTracker;
};

#endif // ENGINE_INTERACTION_H
