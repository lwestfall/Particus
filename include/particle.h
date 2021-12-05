#ifndef PARTICLE
#define PARTICLE

#include <cstdint>
#include "vector_2.h"

class particle
{
public:
    particle(double x, double y, double vx, double vy);
    vector_2 get_velocity();
    void set_velocity(vector_2 velocity);
    void set_position(double x, double y);
    vector_2 add_velocity(vector_2 delta_v);
    vector_2 add_position(vector_2 delta_xy);
    uint8_t get_x_coord();
    uint8_t get_y_coord();

private:
    vector_2 exact_pos;
    vector_2 velocity;
};

#endif /* PARTICLE */
