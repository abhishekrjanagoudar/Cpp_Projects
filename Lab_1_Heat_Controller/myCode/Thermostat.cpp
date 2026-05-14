#include "Thermostat.h"

#include "PowerManagement.h"

Thermostat::Thermostat(PowerManagement *powerManager)
{
    // Store the shared dependency and initialize the target value.
    this->powerManager = powerManager;
    this->temperatureSetByUser = 0;
}

Thermostat::~Thermostat()
{
    // No cleanup needed.
}

// Return the stored target temperature.
float Thermostat::getTempratureSetByUser()
{
    return temperatureSetByUser;
}
