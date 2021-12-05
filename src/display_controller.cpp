#include "display_controller.h"
#include <algorithm>
#include <iostream>

display_controller::display_controller(particle_controller *particle_ctrl)
{
    this->particle_ctrl = particle_ctrl;
}

int display_controller::init()
{
#ifdef SIM_DISP
    using namespace glm;
    // opengl init
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n"
                  << std::endl;
        return -1;
    }
#elif defined(TERM_SIM_DISP)
// do nothing?
#else
// todo - rgb display init
#endif

    return 0;
}

void display_controller::redraw()
{
    pixel_matrix *pixels = particle_ctrl->get_pixel_matrix();

#ifdef SIM_DISP
    // opengl simulator
    using namespace glm;
#elif defined(TERM_SIM_DISP)
    using std::cout;
    using std::endl;

    cout << "╔";

    for (int x = 0; x < DISP_COLS; x++)
    {
        cout << "═";
    }

    cout << "╗";

    cout << endl;

    // terminal simulator
    for (int y = 0; y < DISP_ROWS; y++)
    {
        cout << "║";
        for (int x = 0; x < DISP_COLS; x++)
        {
            uint8_t rgb = (*pixels)[x][y];
            if (rgb)
                cout << "█";
            else
                cout << " ";
        }

        cout << "║";

        cout << endl;
    }

    cout << "╚";

    for (int x = 0; x < DISP_COLS; x++)
    {
        cout << "═";
    }

    cout << "╝";
    cout << endl;

#else
    // rgb display
    // todo
#endif
}