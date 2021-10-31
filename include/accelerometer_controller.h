#ifndef ACCELEROMETER_CONTROLLER
#define ACCELEROMETER_CONTROLLER

#include "vector_2.h"

class accelerometer_controller
{
public:
    void init();
    vector_2 get_accel();

private:
    // todo ICM_20948_I2C imu;
    double scale_factor = 1; // this scales the acceleration so it can be tuned for the display
};

#endif /* ACCELEROMETER_CONTROLLER */
