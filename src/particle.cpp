#include <iostream>
#include "particle.h"

particle::particle(double x, double y, uint64_t millis) : exact_pos(x, y), velocity(0, 0)
{
    last_update_millis = millis;
}

void particle::update_position(double x, double y)
{
    exact_pos.set_x(x);
    exact_pos.set_y(y);
}

void particle::update_velocity(vector_2 accel, uint64_t millis)
{
    std::cout << "DEBUG " << millis - last_update_millis << ": previous vel: ";
    velocity.print_coords();
    vector_2 delta_v = accel * ((millis - last_update_millis) / 1000.0);

    std::cout << " / delta_v: ";
    delta_v.print_coords();
    std::cout << " / new: ";
    // implement kinematic equation
    velocity = velocity + delta_v;
    velocity.print_coords();
    std::cout << std::endl;

    last_update_millis = millis;
}
