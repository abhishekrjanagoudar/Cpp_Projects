/* Thermostat.cpp - implementation (short notes) */

#include "Thermostat.h"

#include "PowerManagement.h"

// Constructor: store pointer and init value
Thermostat::Thermostat(PowerManagement *powerManager)
{
    this->powerManager = powerManager;
    this->temperatureSetByUser = 0;
}

// Destructor
Thermostat::~Thermostat()
{
}

// Return user-set temperature
float Thermostat::getTempratureSetByUser()
{
    return temperatureSetByUser;
}
