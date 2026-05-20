// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "University.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);

	University u;
	u.setup();
	u.display();



	return 0;
}
