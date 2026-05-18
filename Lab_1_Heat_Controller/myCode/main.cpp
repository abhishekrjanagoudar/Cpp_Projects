/* main.cpp - simple runner */

// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include "HeatController.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Main program: construct HeatController and set room temp
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

    // Create controller (calls constructors for member subsystems)
    HeatController heatController = HeatController();
    heatController.setRoomTemp(24); // example call to set temperature
    return 0;
}
