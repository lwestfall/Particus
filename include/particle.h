#ifndef PARTICLE
#define PARTICLE

#include <cstdint>
#include "vector_2.h"

class particle
{
public:
    particle(double x, double y, uint64_t millis);
    void update_position(double x, double y);
    void update_velocity(vector_2 accel, uint64_t millis);

private:
    vector_2 exact_pos;
    vector_2 velocity;
    uint64_t last_update_millis;
};

#endif /* PARTICLE */
