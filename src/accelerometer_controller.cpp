#include "accelerometer_controller.h"
#include <linux/i2c-dev.h>

accelerometer_controller::accelerometer_controller() : imu(ASCALE, GSCALE, MSCALE, MMODE, SAMPLE_RATE_DIVISOR)
{
}

int accelerometer_controller::init()
{
    switch (imu.begin(0))
    {
    case MPUIMU::ERROR_IMU_ID:
        // Bad IMU device ID
        return 1;
    case MPUIMU::ERROR_MAG_ID:
        // Bad magnetometer device ID
        return 2;
    case MPUIMU::ERROR_SELFTEST:
        // Failed self-test
        return 3;
    default:
        // MPU9250 online!
        // try getting valid acceleration and set biases
        vector_2 accel = get_accel();

        if (valid_flag)
        {
            bias_x = accel.get_x();
            bias_y = accel.get_y();
            return 0;
        }
        return 4;
    }
}

vector_2 accelerometer_controller::get_accel()
{
    // refresh imu
    if (imu.checkNewData())
    {
        // get values, az is unused but needed for third parameter
        float ax, ay, az;
        imu.readAccelerometer(ax, ay, az);

        // imu reports in milli-g, so divide by 1000 for g and multiply by 9.81 m/s
        ax *= scale_factor;
        ay *= scale_factor;

        valid_flag = true;
        return vector_2(ax - bias_x, ay - bias_y);
    }

    valid_flag = false;

    // this represents an error in case the imu data check returns false
    return vector_2(-9999, -9999);
}

bool accelerometer_controller::get_valid_flag()
{
    return valid_flag;
}