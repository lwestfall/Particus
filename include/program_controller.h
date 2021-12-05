#ifndef PROGRAM_CONTROLLER
#define PROGRAM_CONTROLLER

#include "accelerometer_controller.h"
#include "button_controller.h"
#include "display_controller.h"
#include "particle_controller.h"
#include "time_master.h"

class program_controller
{
public:
	program_controller();
	void init();
	void run();

private:
	accelerometer_controller accel_ctrl;
	button_controller btn_ctrl;
	display_controller display_ctrl;
	particle_controller particle_ctrl;
	time_master time_mstr;
};

#endif /* PROGRAM_CONTROLLER */
