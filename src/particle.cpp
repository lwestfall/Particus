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

void particle::set_position(double x, double y)
{
    exact_pos.set_x(x);
    exact_pos.set_y(y);
}

vector_2 particle::add_velocity(vector_2 delta_v)
{
    velocity = velocity + delta_v;
    return velocity;
}

vector_2 particle::add_position(vector_2 delta_xy)
{
    exact_pos = exact_pos + delta_xy;

    // clamp out of bounds
    if (exact_pos.get_x() < 0)
    {
        exact_pos.set_x(0);
        velocity.set_x(0);
    }
    else if (exact_pos.get_x() > DISP_COLS - 1)
    {
        exact_pos.set_x(DISP_COLS - 1);
        velocity.set_x(0);
    }

    if (exact_pos.get_y() < 0)
    {
        exact_pos.set_y(0);
        velocity.set_y(0);
    }
    else if (exact_pos.get_y() > DISP_ROWS - 1)
    {
        exact_pos.set_y(DISP_ROWS - 1);
        velocity.set_y(0);
    }

    return exact_pos;
}

uint8_t particle::get_x_coord()
{
    return std::round(exact_pos.get_x());
}

uint8_t particle::get_y_coord()
{
    return std::round(exact_pos.get_y());
}