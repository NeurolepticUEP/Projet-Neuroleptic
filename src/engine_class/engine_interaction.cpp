#include "engine_interaction.h"

#include <iostream>


#include "vrpn_Text.h"
#include "vrpn_Connection.h"

#include "world.h"



Engine_Interaction::~Engine_Interaction() {
    delete this->vrpnTracker;
}

void VRPN_CALLBACK trackerEventHandler_Left(void* userData, const vrpn_TRACKERCB t) {
    Engine_Interaction *i = (Engine_Interaction*)userData;

    Instance *in = i->getWorld()->getData()->getBodyPart(8);
    glm::mat4 mat = glm::translate(in->getOWMatrix(), glm::vec3(t.pos[0]*0.001, t.pos[1], t.pos[2]));

    in->setOWMatrix(mat);
}

void VRPN_CALLBACK trackerEventHandler_Right(void* userData, const vrpn_TRACKERCB t) {
    Engine_Interaction *i = (Engine_Interaction*)userData;

    Instance *in = i->getWorld()->getData()->getBodyPart(14);
    glm::mat4 mat = glm::translate(in->getOWMatrix(), glm::vec3(t.pos[0]*0.001, t.pos[1], t.pos[2]));

    in->setOWMatrix(mat);
}

Engine_Interaction::Engine_Interaction(World *world): Engine_Abstract(world) {
    this->vrpnTracker= new vrpn_Tracker_Remote("Tracker0@localhost");

    vrpnTracker->register_change_handler( this, trackerEventHandler_Right, 14);
    vrpnTracker->register_change_handler( this, trackerEventHandler_Left, 8);
}


void Engine_Interaction::keyboardEventHandler(QKeyEvent *e) {
    switch(e->key()) {
        case Qt::Key_Right:
            this->world_->getData()->getCamera()->translateLocal(glm::vec3(1.0, 0.0, 0.0));
            break;
        case Qt::Key_Left:
            this->world_->getData()->getCamera()->translateLocal(glm::vec3(-1.0, 0.0, 0.0));
            break;
        case Qt::Key_Escape:
            this->world_->getWindow()->close();
            break;
    }
}

void Engine_Interaction::initialize() {

}

void Engine_Interaction::update(World_Data *data) {

    QCursor e = this->world_->getWindow()->cursor();
    int width = this->world_->getWindow()->width();
    int height = this->world_->getWindow()->height();
    int x = this->world_->getWindow()->x();
    int y = this->world_->getWindow()->y();

    float diffX = (e.pos().rx() - width/2 - x) * 0.001;
    float diffY = (e.pos().ry() - height/2 - y) * 0.001;

    //data->getCamera()->rotateAroundUp(diffX);
    //data->getCamera()->rotateAroundRight(diffY);

    this->vrpnTracker->mainloop();
}
