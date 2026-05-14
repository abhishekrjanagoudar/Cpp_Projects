#include "HeatingSystem.h"
#include "PowerManagement.h"

HeatingSystem::HeatingSystem(PowerManagement *powerManager)
{
    // Store the shared dependency and start from zero.
    this->powerManager = powerManager;
    this->heaterTemperature = 0;
}

HeatingSystem::~HeatingSystem()
{
    // Nothing to clean up.
}

// Simple setter that stores the new heater temperature.
void HeatingSystem::setHeaterTemperature(int value)
{
    this->heaterTemperature = value;
}
