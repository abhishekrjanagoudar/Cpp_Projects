/* HeatingSystem.cpp - implementation (short notes) */

#include "HeatingSystem.h"
#include "PowerManagement.h"

// Constructor: store pointer and init temperature
HeatingSystem::HeatingSystem(PowerManagement *powerManager)
{
    this->powerManager = powerManager; // pointer assignment
    this->heaterTemperature = 0; // init
}

// Destructor
HeatingSystem::~HeatingSystem()
{
}

// Set heater temperature (assignment)
void HeatingSystem::setHeaterTemperature(int value)
{
    this->heaterTemperature = value;
}
