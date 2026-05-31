#pragma once

#include <vector>
#include <memory>

#include "Vehicle.h"

using namespace std;

/*
========================================================
CLASS: Garage
========================================================
Purpose:
Stores multiple vehicles.
*/

class Garage {

private:

    // Shared ownership of vehicles
    vector<shared_ptr<Vehicle>> vehicles;

public:

    // Add vehicle into garage
    void addVehicle(shared_ptr<Vehicle> vehicle);

    // Show all vehicles
    void showAllVehicles();
};
