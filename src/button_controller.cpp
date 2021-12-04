#include "button_controller.h"
#include <pigpio.h>

int button_controller::init()
{
    // initialize the gpio and set pin modes if successful
    if (gpioInitialise() >= 0)
    {
        gpioSetMode(btn1_gpio, PI_INPUT);
        gpioSetMode(btn2_gpio, PI_INPUT);
        return 0;
    }

    // return error code if failed to init
    return -1;
}

uint8_t button_controller::get_button_states()
{
    // read pins 0-31 as bitmap
    uint32_t gpio_bank = gpioRead_Bits_0_31();

    // get btn bit values by shifting right and masking
    uint8_t btn1_bit = (uint8_t)(gpio_bank >> btn1_gpio) & 1;
    uint8_t btn2_bit = (uint8_t)(gpio_bank >> btn2_gpio - 1) & 2;

    // recombine into a single bitmap and return
    return btn1_bit | btn2_bit;
}