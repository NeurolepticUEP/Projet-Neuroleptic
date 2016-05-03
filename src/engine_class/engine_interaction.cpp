#include "engine_interaction.h"

#include <iostream>

#include "vrpn_Text.h"
#include "vrpn_Connection.h"

#include "world.h"

typedef struct data_s {
    Engine_Interaction *engine_i;
    int member;
} Data;

Engine_Interaction::~Engine_Interaction() {
    delete this->vrpnTracker;
}

void VRPN_CALLBACK trackerEventHandler(void* userData, const vrpn_TRACKERCB t) {
    Data *d = (Data*)userData;
    Engine_Interaction *engine_i = d->engine_i;
    int member = d->member;
    Instance *in = d->engine_i->getWorld()->getData()->getBodyPart(member);

    if(in != nullptr) {
        engine_i->setHistPos(member, 0, engine_i->getHistPos(member, 1));
        engine_i->setHistPos(member, 1, engine_i->getHistPos(member, 2));
        engine_i->setHistPos(member, 2, glm::vec3(t.pos[0]* -3.0f, t.pos[1] * 2.5f, t.pos[2] * -1.0f + 1.0f));

        engine_i->setHistQuad(member, 0, engine_i->getHistQuad(member, 1));
        engine_i->setHistQuad(member, 1, engine_i->getHistQuad(member, 2));
        engine_i->setHistQuad(member, 2, glm::vec4(t.quat[0], t.quat[1], t.quat[2], t.quat[3]));

        glm::vec3 pos_modif = engine_i->getHistPos(member, 0) * 0.33f + engine_i->getHistPos(member, 1) * 0.33f + engine_i->getHistPos(member, 2) * 0.33f;
        glm::vec4 quad_modif = engine_i->getHistQuad(member, 0) * 0.33f + engine_i->getHistQuad(member, 1) * 0.33f + engine_i->getHistQuad(member, 2) * 0.33f;

        glm::mat4 mat = glm::translate(glm::mat4(1.0f), pos_modif);
        mat = glm::rotate(mat, (float)quad_modif[3] * -1.0f, glm::vec3(quad_modif[0], quad_modif[1], quad_modif[2]));
        mat = glm::scale(mat, glm::vec3(0.5, 0.5, 0.5));
        in->setOWMatrix(mat);
    }
}

Engine_Interaction::Engine_Interaction(World *world):
    Engine_Abstract(world) {

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
    Data *d_droite = new Data(), *d_gauche = new Data();

    d_droite->engine_i = d_gauche->engine_i = this;
    d_droite->member = 14;
    d_gauche->member = 8;

    this->vrpnTracker= new vrpn_Tracker_Remote("Tracker0@localhost");

    vrpnTracker->register_change_handler( d_droite, trackerEventHandler, 14);
    vrpnTracker->register_change_handler( d_gauche, trackerEventHandler, 8);
}

void Engine_Interaction::update(World_Data *) {

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
