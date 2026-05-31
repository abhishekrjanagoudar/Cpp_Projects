#pragma once

#include "Vehicle.h"

/*
========================================================
CLASS: Mechanic
========================================================
Purpose:
Demonstrates raw pointer usage.
*/

class Mechanic {

private:

    // Raw pointer to vehicle
    Vehicle* currentVehicle;

public:

    // Constructor
    Mechanic();

    // Inspect vehicle using raw pointer
    void inspectVehicle(Vehicle* vehiclePtr);
};
