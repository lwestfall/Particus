#ifndef ACCELEROMETER_CONTROLLER
#define ACCELEROMETER_CONTROLLER

#include "vector_2.h"
#include "MPU9250_Master_I2C.h"
#include <wiringPi.h>

class accelerometer_controller
{
public:
    accelerometer_controller();
    int init();
    vector_2 get_accel();
    bool get_valid_flag();

private:
    // stores whether the last accel vector returned by get_accel was a valid one
    bool valid_flag;
    float bias_x = 0;
    float bias_y = 0;
    const MPUIMU::Gscale_t GSCALE = MPUIMU::GFS_250DPS;
    const MPUIMU::Ascale_t ASCALE = MPUIMU::AFS_2G;
    const MPU9250::Mscale_t MSCALE = MPU9250::MFS_16BITS;
    const MPU9250::Mmode_t MMODE = MPU9250::M_100Hz;
    const uint8_t SAMPLE_RATE_DIVISOR = 0x04;
    MPU9250_Master_I2C imu;
    double scale_factor = 0.15; // this scales the acceleration so it can be tuned for the display
};

#endif /* ACCELEROMETER_CONTROLLER */
