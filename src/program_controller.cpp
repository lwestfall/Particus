#include <iostream>
#include <chrono>
#include <thread>
#include "program_controller.h"
#include "vector_2.h"

program_controller::program_controller() : particle_ctrl(&time_mstr)
{
}

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

	accel_ctrl.init();
	std::cout << "accelerometer controller initialized" << std::endl;

	const unsigned int FRAME_MAX_TIME_MILLIS = 1000 / 30;

	for (;;)
	{
		// loop until exit
		uint64_t now_millis = time_mstr.millis_since_start();
		vector_2 now_accel = accel_ctrl.get_accel();
		particle_ctrl.do_time_step(now_accel);

		// sleep until next frame for 30fps
		uint64_t time_taken = time_mstr.millis_since_start() - now_millis;
		time_mstr.print_time();
		std::cout << "Frame took " << time_taken << " ms." << std::endl;
		if (time_taken < FRAME_MAX_TIME_MILLIS)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_MAX_TIME_MILLIS - time_taken));
		}
		else
		{
			std::cout << "Frame took too long!" << std::endl;
		}
	}
}
