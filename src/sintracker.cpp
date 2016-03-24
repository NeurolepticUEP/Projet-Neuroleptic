#include "sintracker.h"

#include <iostream>
#include <math.h>

SinTracker::SinTracker(vrpn_Connection *c):
    vrpn_Tracker("sinTracker0", c){

}

SinTracker::~SinTracker() {

}

void SinTracker::mainloop() {
    vrpn_gettimeofday(&this->timestamp_, nullptr);

    vrpn_Tracker::timestamp = this->timestamp_;

    // We will just put a fake data in the position of our tracker
    static float angle = 0; angle += 0.01f;

    // the pos array contains the position value of the tracker
    // XXX Set your values here
    pos[0] = sinf( angle );
    pos[1] = 0.0f;
    pos[2] = 0.0f;

    // the d_quat array contains the orientation value of the tracker, stored as a quaternion
    // XXX Set your values here
    d_quat[0] = 0.0f;
    d_quat[1] = 0.0f;
    d_quat[2] = 0.0f;
    d_quat[3] = 1.0f;

    char msgbuf[1000];

    d_sensor = 0;

    int  len = vrpn_Tracker::encode_to(msgbuf);

    if (d_connection->pack_message(len, this->timestamp_, position_m_id,
                                   d_sender_id, msgbuf, vrpn_CONNECTION_LOW_LATENCY)
        ) {
        std::cout << "can't write message: tossing" << std::endl;
    }

    server_mainloop();
}
