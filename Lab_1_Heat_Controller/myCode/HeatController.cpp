/* HeatController.cpp - implementation (short notes) */

#include "HeatController.h"

// Constructor
HeatController::HeatController()
{
}

// Destructor
HeatController::~HeatController()
{
}

// Update UI and controller with desired temperature
void HeatController::setRoomTemp(int temp)
{
    userInterface.setTemperatureSetByUser(temp); // calls UI method
    controller.setTempSetByUser(temp); // updates controller state
}
