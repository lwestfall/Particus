#ifndef PROGRAM_CONTROLLER
#define PROGRAM_CONTROLLER

#include "accelerometer_controller.h"
#include "button_controller.h"
#include "particle_controller.h"
#include "time_master.h"

class program_controller
{
public:
	program_controller();
	void init();
	void run();

private:
	particle_controller particle_ctrl;
	time_master time_mstr;
	accelerometer_controller accel_ctrl;
	button_controller btn_ctrl;
};

#endif /* PROGRAM_CONTROLLER */
