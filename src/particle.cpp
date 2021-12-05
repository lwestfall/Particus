#include <cmath>
#include <iostream>
#include "configuration.h"
#include "particle.h"

particle::particle(double x, double y, double vx, double vy) : exact_pos(x, y), velocity(vx, vy)
{
}

vector_2 particle::get_velocity()
{
    return velocity;
}

void particle::set_velocity(vector_2 velocity)
{
    this->velocity = velocity;
}

vector_2 particle::get_position()
{
    return this->exact_pos;
}

void particle::set_position(vector_2 position)
{
    this->exact_pos = position;
}

vector_2 particle::add_velocity(vector_2 delta_v)
{
    velocity = velocity + delta_v;
    return velocity;
}

vector_2 particle::add_position(vector_2 delta_xy)
{
    exact_pos = exact_pos + delta_xy;
    return exact_pos;
}
