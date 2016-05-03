#include "engine_interaction.h"

#include <iostream>

#include "vrpn_Text.h"
#include "vrpn_Connection.h"

#include "world.h"



Engine_Interaction::~Engine_Interaction() {
    delete this->vrpnTracker;
}

void VRPN_CALLBACK trackerEventHandler_Right(void* userData, const vrpn_TRACKERCB t) {
    Engine_Interaction *i = (Engine_Interaction*)userData;

    Instance *in = i->getWorld()->getData()->getBodyPart(14);

    if(in != nullptr) {
        i->setHistPos(14, 0, i->getHistPos(14, 1));
        i->setHistPos(14, 1, i->getHistPos(14, 2));
        i->setHistPos(14, 2, glm::vec3(t.pos[0]* -3.0f, t.pos[1] * 2.5f, t.pos[2] * -1.0f + 1.0f));

        i->setHistQuad(14, 0, i->getHistQuad(14, 1));
        i->setHistQuad(14, 1, i->getHistQuad(14, 2));
        i->setHistQuad(14, 2, glm::vec4(t.quat[0], t.quat[1], t.quat[2], t.quat[3]));

        glm::vec3 pos_modif = i->getHistPos(14, 0) * 0.33f + i->getHistPos(14, 1) * 0.33f + i->getHistPos(14, 2) * 0.33f;
        glm::vec4 quad_modif = i->getHistQuad(14, 0) * 0.33f + i->getHistQuad(14, 1) * 0.33f + i->getHistQuad(14, 2) * 0.33f;

        glm::mat4 mat = glm::translate(glm::mat4(1.0f), pos_modif);
        mat = glm::rotate(mat, (float)quad_modif[3] * -1.0f, glm::vec3(quad_modif[0], quad_modif[1], quad_modif[2]));
        mat = glm::scale(mat, glm::vec3(0.5, 0.5, 0.5));
        in->setOWMatrix(mat);
    }

}

void VRPN_CALLBACK trackerEventHandler_Left(void* userData, const vrpn_TRACKERCB t) {
    Engine_Interaction *i = (Engine_Interaction*)userData;

    Instance *in = i->getWorld()->getData()->getBodyPart(8);

    if(in != nullptr) {
        i->setHistPos(8, 0, i->getHistPos(8, 1));
        i->setHistPos(8, 1, i->getHistPos(8, 2));
        i->setHistPos(8, 2, glm::vec3(t.pos[0]* -3.0f, t.pos[1] * 2.5f, t.pos[2] * -1.0f + 1.0f));

        i->setHistQuad(8, 0, i->getHistQuad(8, 1));
        i->setHistQuad(8, 1, i->getHistQuad(8, 2));
        i->setHistQuad(8, 2, glm::vec4(t.quat[0], t.quat[1], t.quat[2], t.quat[3]));

        glm::vec3 pos_modif = i->getHistPos(8, 0) * 0.33f + i->getHistPos(8, 1) * 0.33f + i->getHistPos(8, 2) * 0.33f;
        glm::vec4 quad_modif = i->getHistQuad(8, 0) * 0.33f + i->getHistQuad(8, 1) * 0.33f + i->getHistQuad(8, 2) * 0.33f;

        glm::mat4 mat = glm::translate(glm::mat4(1.0f), pos_modif);
        mat = glm::rotate(mat, (float)quad_modif[3] * -1.0f, glm::vec3(quad_modif[0], quad_modif[1], quad_modif[2]));
        mat = glm::scale(mat, glm::vec3(0.5, 0.5, 0.5));
        in->setOWMatrix(mat);
    }
}

Engine_Interaction::Engine_Interaction(World *world):
    Engine_Abstract(world) {
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


//    QCursor e = this->world_->getWindow()->cursor();
//    int width = this->world_->getWindow()->width();
//    int height = this->world_->getWindow()->height();
//    int x = this->world_->getWindow()->x();
//    int y = this->world_->getWindow()->y();

//    float diffX = (e.pos().rx() - width/2 - x) * 0.001;
//    float diffY = (e.pos().ry() - height/2 - y) * 0.001;

//    data->getCamera()->rotateAroundUp(diffX);
//    data->getCamera()->rotateAroundRight(diffY);

//    this->vrpnTracker->mainloop();
}
