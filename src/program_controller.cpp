#include <iostream>
#include "program_controller.h"
#include "vector_2.h"

void program_controller::init()
{
	std::cout << "program controller initialized" << std::endl;
}

void program_controller::run()
{
	// todo - change this to return a status code for exit
	time_mstr.print_time();
	std::cout << "program controller started" << std::endl;

	particle_ctrl.init();
	time_mstr.print_time();
	std::cout << "particle controller initialized w/ "
			  << particle_ctrl.get_particle_count()
			  << " random particles." << std::endl;

	for (;;)
	{
		// loop until exit
	}
}
