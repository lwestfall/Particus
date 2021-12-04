#ifndef BUTTON_CONTROLLER
#define BUTTON_CONTROLLER

#include <stdint.h>

class button_controller
{
public:
    // initialize the GPIOs for the buttons
    int init();

    // get the states of the buttons, bit 0 (LSB) is button 1, bit 1 is button 2
    // 1 is button pressed, 0 is not pressed
    uint8_t get_button_states();

private:
    // gpio pin numbers
    // these must be in the range 0-31
    int btn1_gpio = 16;
    int btn2_gpio = 20;
};

#endif /* BUTTON_CONTROLLER */