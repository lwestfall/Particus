#include <iostream>
#include <time.h>
#include "program_controller.h"

int main()
{
	srand(time(NULL));
	program_controller prog_ctl;

	int exit_status = prog_ctl.init();

	if (exit_status != 0 && exit_status != SIGINT)
	{
		std::cerr << "Program controller returned error status during init! Code: " << exit_status << std::endl;
		return exit_status;
	}
	else if (exit_status == SIGINT)
	{
		std::cout << "\nGoodbye!" << std::endl;
		return 0;
	}

	exit_status = prog_ctl.run();

	if (exit_status != 0 && exit_status != SIGINT)
	{
		std::cerr << "Program controller returned error status during run loop! Code: " << exit_status << std::endl;
		return exit_status;
	}

	std::cout << "\nGoodbye!" << std::endl;
}
