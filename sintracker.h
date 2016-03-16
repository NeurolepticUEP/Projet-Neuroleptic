#ifndef SINTRACKER_H
#define SINTRACKER_H

#include "vrpn_Tracker.h"
#include "vrpn_Connection.h"

class SinTracker : public vrpn_Tracker {
public:
    SinTracker(vrpn_Connection *c = 0);
    ~SinTracker();

    virtual void mainloop();

private:
    struct timeval timestamp_;
};

#endif // SINTRACKER_H
