#include <iostream>
#include <cstdlib>
#include "HeatController.h"

using namespace std;

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);

    // Create the controller and set one sample temperature.
    HeatController heatController;
    heatController.setRoomTemp(24);

    return 0;
}
