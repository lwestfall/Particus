#include "display_controller.h"
#include <iostream>

int init() {
    #ifdef SIM_DISP
    using namespace glm;
    // opengl init
    if(!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n" << std::endl;
        return -1;
    }
    #else
    // todo - rgb display init
    #endif

    return 0;
}

lit_pixel display_controller::add_pixel(uint8_t x, uint8_t y, uint8_t rgb) {
    lit_pixel pixel = lit_pixel(x, y, rgb);
    pixels.push_back(pixel);
    return pixel;
}

