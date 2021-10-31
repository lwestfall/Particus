#include "accelerometer_controller.h"

void accelerometer_controller::init()
{
    // todo - init imu
}

vector_2 accelerometer_controller::get_accel()
{
    // todo - read actual accel from imu

    // delete me - for now just straight down at regular gravity
    return vector_2(0, -9.81) * scale_factor;
}