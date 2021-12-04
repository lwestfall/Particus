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

	// todo - change this to return a status code for exit
	time_mstr.print_time();
	std::cout << "program controller started" << std::endl;

	particle_ctrl.init();
	time_mstr.print_time();
	std::cout << "particle controller initialized w/ "
			  << particle_ctrl.get_particle_count()
			  << " random particles." << std::endl;

	accel_ctrl.init();
	time_mstr.print_time();
	std::cout << "accelerometer controller initialized" << std::endl;

	if (btn_ctrl.init() != 0)
	{
		time_mstr.print_time();
		std::cerr << "button controller failed to initialize!" << std::endl;
		return;
	}
	time_mstr.print_time();
	std::cout << "button controller initialized" << std::endl;

	std::cout << "program ready, press any key to begin main loop";
	std::getchar();
	std::cout << std::endl;
}

void program_controller::run()
{
	const unsigned int FRAME_MAX_TIME_MILLIS = 1000 / 30;
	particle_ctrl.reset_step_time();

	for (;;)
	{
		// loop until exit
		uint64_t now_millis = time_mstr.millis_since_start();
		vector_2 now_accel = accel_ctrl.get_accel();
		particle_ctrl.do_time_step(now_accel);

		// handle button presses
		uint8_t btns = btn_ctrl.get_button_states();
		if (btns & 1)
		{
			// button 1 is pressed
			std::cout << "▼";
			particle_ctrl.add_random_particle();
		}
		else
		{
			std::cout << "▲";
		}

		if (btns & 2)
		{
			// button 2 is pressed
			std::cout << " ▼";
			particle_ctrl.remove_particle();
		}
		else
		{
			std::cout << " ▲";
		}

		// sleep until next frame for 30fps
		uint64_t time_taken = time_mstr.millis_since_start() - now_millis;

		// log current state
		time_mstr.print_time();
		std::cout << "(" << particle_ctrl.get_particle_count() << ") Frame took " << time_taken << " ms." << std::endl;

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
