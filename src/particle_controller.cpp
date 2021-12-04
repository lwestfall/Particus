#include "particle_controller.h"

particle_controller::particle_controller(time_master *time_mstr)
{
    this->time_mstr = time_mstr;
}

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

void particle_controller::do_time_step(vector_2 accel)
{
    uint64_t now_millis = time_mstr->millis_since_start();
    const double delta_t_seconds = (now_millis - last_step_millis) / 1000.0;
    last_step_millis = now_millis;

    // implement kinematic equation to find change in velocity
    // to be added to all particle
    vector_2 delta_v = accel * delta_t_seconds;

    for (auto &particle : particles)
    {
        particle.update_velocity(delta_v);
    }
}

void particle_controller::add_random_particle()
{
    particle new_particle = particle(64 / 2, 32 / 2);
    particles.push_back(new_particle);
}
void particle_controller::remove_particle()
{
    particles.pop_front();
}

int particle_controller::get_particle_count()
{
    return particles.size();
}

void particle_controller::reset_step_time()
{
    last_step_millis = time_mstr->millis_since_start();
}