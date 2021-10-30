#ifndef PARTICLE_CONTROLLER
#define PARTICLE_CONTROLLER

#include <vector>
#include "particle.h"

class particle_controller
{
public:
    void init();
    void do_time_step();
    int get_particle_count();

private:
    // todo accelerometer_controller accel_ctrl;
    std::vector<particle> particles;
};

#endif /* PARTICLE_CONTROLLER */
