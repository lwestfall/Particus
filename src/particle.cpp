#include <iostream>
#include "particle.h"

particle::particle(double x, double y) : exact_pos(x, y), velocity(0, 0)
{
}

void particle::update_position(double x, double y)
{
    exact_pos.set_x(x);
    exact_pos.set_y(y);
}

void particle::update_velocity(vector_2 delta_v)
{
    velocity = velocity + delta_v;
}
