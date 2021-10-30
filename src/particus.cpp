#include <iostream>
#include <time.h>
#include "program_controller.h"

int main()
{
	srand(time(NULL));
	program_controller prog_ctl;

	prog_ctl.init();
	prog_ctl.run();
}
