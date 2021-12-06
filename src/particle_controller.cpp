#include "particle_controller.h"
#include <cmath>

particle_controller::particle_controller(time_master *time_mstr)
{
    this->time_mstr = time_mstr;
}

void particle_controller::init()
{
    // generate 50-100 particles
    int num_particles = rand() % 50 + 50;
    // int num_particles = 1;

    for (int i = 0; i < num_particles; i++)
    {
        add_random_particle();
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

    // this controls the proportion of velocity lost due to drag
    // 0 means no drag, 1 means very sticky drag (cancels all velocity)
    double drag_coefficient = 0.1;

    for (auto &particle : particles)
    {
        vector_2 init_vel = particle.get_velocity();
        vector_2 new_vel = particle.add_velocity(delta_v + delta_v * -drag_coefficient);

        // another kinematic equation to calculate new position
        vector_2 delta_xy = ((init_vel + new_vel) / 2) * now_millis / 1000.0;
        particle.add_position(delta_xy);
    }
}

void particle_controller::add_random_particle()
{
    // random x and y position within bounds and random velocity
    int rand_x = rand() % DISP_COLS;
    int rand_y = rand() % DISP_ROWS;
    double rand_vx = (((double)rand() / (RAND_MAX)) - ((double)rand() / (RAND_MAX))) * 0.1;
    double rand_vy = (((double)rand() / (RAND_MAX)) - ((double)rand() / (RAND_MAX))) * 0.1;
    particles.push_back(particle(rand_x, rand_y, rand_vx, rand_vy));
}
void particle_controller::remove_particle()
{
    if (particles.size() > 0)
        particles.pop_front();
}

int particle_controller::get_particle_count()
{
    return particles.size();
}

pixel_matrix *particle_controller::get_pixel_matrix()
{
    std::fill(&pixels[0][0], &pixels[0][0] + DISP_COLS * DISP_ROWS, 0);

    // todo move collision detection to position update
    particle *particle_map[DISP_COLS][DISP_ROWS] = {nullptr};

    for (auto &particle : particles)
    {
        // this dampens the bounce velocity, 0 is no bounce, 1 is perfectly elastic bounce
        double bounciness = 0.8;

        if (particle.get_position().get_x() < 0 && particle.get_velocity().get_x() < 0)
        {
            // left border collision
            particle.set_velocity(vector_2(particle.get_velocity().get_x() * -bounciness, particle.get_velocity().get_y()));
            particle.set_position(vector_2(0, particle.get_position().get_y()));
        }

        if (particle.get_position().get_x() > DISP_COLS - 1 && particle.get_velocity().get_x() > 0)
        {
            // right border collision
            particle.set_velocity(vector_2(particle.get_velocity().get_x() * -bounciness, particle.get_velocity().get_y()));
            particle.set_position(vector_2(DISP_COLS - 1, particle.get_position().get_y()));
        }

        if (particle.get_position().get_y() < 0 && particle.get_velocity().get_y() < 0)
        {
            // top border collision
            particle.set_velocity(vector_2(particle.get_velocity().get_x(), particle.get_velocity().get_y() * -bounciness));
            particle.set_position(vector_2(particle.get_position().get_x(), 0));
        }

        if (particle.get_position().get_y() > DISP_ROWS - 1 && particle.get_velocity().get_y() > 0)
        {
            // bottom border collision
            particle.set_velocity(vector_2(particle.get_velocity().get_x(), particle.get_velocity().get_y() * -bounciness));
            particle.set_position(vector_2(particle.get_position().get_x(), DISP_ROWS - 1));
        }

        vector_2 pos = particle.get_position();
        vector_2 vel = particle.get_velocity();
        uint8_t x = pos.get_x();
        uint8_t y = pos.get_y();

        // sanity check
        if (x >= 0 && x < DISP_COLS && y >= 0 && y < DISP_ROWS)
        {
            // todo - incorporate rgb
            if (particle_map[x][y] == nullptr)
            {
                particle_map[x][y] = &particle;
                pixels[x][y] = 1;
            }
            else
            {
                // particles collide
                handle_collision(&particle, particle_map[x][y]);
                pixels[x][y] = 2;
            }
        }
    }

    return &pixels;
}

void particle_controller::reset_step_time()
{
    last_step_millis = time_mstr->millis_since_start();
}

void particle_controller::handle_collision(particle *p1, particle *p2)
{
    // same mass objects exchange velocities on elastic collision
    // inject randomness to simulate inelasticity and minor mass differences
    // todo - detect if one particle is against border and treat as border collision
    double inelastic_coeff = ((double)rand() / (RAND_MAX)) * 0.2 + 0.85;
    double mass_ratio = ((double)rand() / (RAND_MAX)) * 0.2 + 0.9;
    vector_2 temp = p1->get_velocity() * inelastic_coeff * mass_ratio;
    p1->set_velocity(p2->get_velocity() * inelastic_coeff * (1 / mass_ratio));
    p2->set_velocity(temp);
}
