#ifndef DISPLAY_CONTROLLER
#define DISPLAY_CONTROLLER

#include "lit_pixel.h"
#include <vector>

// comment the following line out to disable the simulator and enable the rgb display
#define SIM_DISP

#ifdef SIM_DISP
// includes for opengl display simulator
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#endif

class display_controller
{
public:
    int init();
    lit_pixel add_pixel(uint8_t x, uint8_t y, uint8_t rgb);
    void redraw();
private:
    std::vector<lit_pixel> pixels;
#ifdef SIM_DISP
    GLFWwindow* display;
#else
// unknown_type display;
#endif
};

#endif /* DISPLAY_CONTROLLER */
