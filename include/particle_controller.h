#ifndef PARTICLE_CONTROLLER
#define PARTICLE_CONTROLLER

#include <vector>
#include "particle.h"
#include "time_master.h"

class particle_controller
{
public:
    particle_controller(time_master *time_mstr);
    void init();
    void do_time_step(vector_2 accel);
    int get_particle_count();

private:
    // todo accelerometer_controller accel_ctrl;
    std::vector<particle> particles;
    time_master *time_mstr;
};

#endif /* PARTICLE_CONTROLLER */
