#include <iostream>
#include "program_controller.h"

int main() {
    std::cout << "Hello, world!" << std::endl;

	program_controller prog_ctl;

	prog_ctl.init();
	prog_ctl.run();
}
