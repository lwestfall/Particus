#ifndef PARTICLE_CONTROLLER
#define PARTICLE_CONTROLLER

#include <deque>
#include "particle.h"
#include "time_master.h"

class particle_controller
{
public:
    particle_controller(time_master *time_mstr);
    void init();
    void do_time_step(vector_2 accel);
    void add_random_particle();
    void remove_particle();
    int get_particle_count();
    void reset_step_time();

private:
    // todo accelerometer_controller accel_ctrl;
    std::deque<particle> particles;
    uint64_t last_step_millis;
    time_master *time_mstr;
};

#endif /* PARTICLE_CONTROLLER */
