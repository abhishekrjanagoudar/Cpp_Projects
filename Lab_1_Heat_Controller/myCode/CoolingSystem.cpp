#include "CoolingSystem.h"

CoolingSystem::CoolingSystem(PowerManagement *powerManager)
{
    // Store the shared dependency and start from zero.
    this->powerManager = powerManager;
    this->coolerValue = 0;
}

CoolingSystem::~CoolingSystem()
{
    // Nothing to clean up.
}

// Simple setter that stores the new cooler temperature.
void CoolingSystem::setCoolerTemperature(int value)
{
    coolerValue = value;
}
