#ifndef PROGRAM_CONTROLLER_H
#define PROGRAM_CONTROLLER_H

#include "particle_controller.h"

class program_controller
{
public:
	void init();
	void run();

private:
	particle_controller particle_ctrl;
};

#endif /* PROGRAM_CONTROLLER_H */
