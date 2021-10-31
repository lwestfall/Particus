#ifndef PARTICLE
#define PARTICLE

#include <cstdint>
#include "vector_2.h"

class particle
{
public:
    particle(double x, double y);
    void update_position(double x, double y);
    void update_velocity(vector_2 delta_v);

private:
    vector_2 exact_pos;
    vector_2 velocity;
};

#endif /* PARTICLE */
