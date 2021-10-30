#include "particle.h"

particle::particle(double x, double y) : exact_pos(x, y), velocity(x, y)
{
}

void particle::update_position(double x, double y)
{
    exact_pos.set_x(x);
    exact_pos.set_y(y);
}

void particle::update_velocity(vector_2 accel, uint64_t millis)
{
    // implement kinematic equation
    velocity = velocity + (accel * millis);

    last_update_millis = millis;
}
