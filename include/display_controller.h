#ifndef DISPLAY_CONTROLLER
#define DISPLAY_CONTROLLER

#include "configuration.h"
#include "particle_controller.h"
#include <stdint.h>

// opengl simulator mode
// #define OGL_SIM_DISP

// terminal simulator mode
#define TERM_SIM_DISP

#ifdef OGL_SIM_DISP
// includes for opengl display simulator
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#endif

class display_controller
{
public:
    display_controller(particle_controller *particle_ctrl);
    int init();
    void redraw();

private:
    particle_controller *particle_ctrl;
#ifdef OGL_SIM_DISP
    GLFWwindow *display;
#else
// unknown_type display;
#endif
};

#endif /* DISPLAY_CONTROLLER */
