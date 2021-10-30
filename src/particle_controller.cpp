#include "particle_controller.h"

void particle_controller::init()
{
    // generate 50-100 particles
    int num_particles = rand() % 50 + 50;

    for (int i = 0; i < num_particles; i++)
    {
        // random x and y position within bounds
        int rand_x = rand() % 64;
        int rand_y = rand() % 32;
        particles.push_back(particle(rand_x, rand_y));
    }
}

void particle_controller::do_time_step()
{
    // todo
}

int particle_controller::get_particle_count()
{
    return particles.size();
}
