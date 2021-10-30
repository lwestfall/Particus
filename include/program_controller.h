#ifndef PROGRAM_CONTROLLER_H
#define PROGRAM_CONTROLLER_H

#include "particle_controller.h"
#include "time_master.h"

class program_controller
{
public:
	void init();
	void run();

private:
	particle_controller particle_ctrl;
	time_master time_mstr;
};

#endif /* PROGRAM_CONTROLLER_H */
