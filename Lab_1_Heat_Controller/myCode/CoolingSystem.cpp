/* CoolingSystem.cpp - implementation (short notes) */

#include "CoolingSystem.h"

// Constructor: store pointer and init cooler value
CoolingSystem::CoolingSystem(PowerManagement *powerManager)
{
    this->powerManager = powerManager;
    this->coolerValue = 0;
}

// Destructor
CoolingSystem::~CoolingSystem()
{
}

// Set cooler temperature
void CoolingSystem::setCoolerTemperature(int value)
{
    coolerValue = value;
}
