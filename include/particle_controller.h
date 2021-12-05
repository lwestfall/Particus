#ifndef PARTICLE_CONTROLLER
#define PARTICLE_CONTROLLER

#include "configuration.h"
#include "particle.h"
#include "time_master.h"
#include <deque>

class particle_controller
{
public:
    particle_controller(time_master *time_mstr);
    void init();
    void do_time_step(vector_2 accel);
    void add_random_particle();
    void remove_particle();
    int get_particle_count();
    pixel_matrix *get_pixel_matrix();
    void reset_step_time();

private:
    pixel_matrix pixels = {0};
    std::deque<particle> particles;
    uint64_t last_step_millis;
    time_master *time_mstr;
    void handle_collision(particle *p1, particle *p2);
};

#endif /* PARTICLE_CONTROLLER */
