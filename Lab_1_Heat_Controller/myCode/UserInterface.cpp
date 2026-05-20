/* UserInterface.cpp - implementation (short notes) */

#include "UserInterface.h"

// Constructor: store pointer and init temps
UserInterface::UserInterface(PowerManagement *powerManager)
{
    this->powerManager = powerManager;
    this->currentTemperature = 0;
    this->temperatureSetByUser = 0;
}

// Destructor
UserInterface::~UserInterface()
{
}

// Set current temperature (assignment)
void UserInterface::setCurrentTemperature(float currentTemperature)
{
    this->currentTemperature = currentTemperature;
}

// Set desired temperature from UI
void UserInterface::setTemperatureSetByUser(float temperatureSetByUser)
{
    this->temperatureSetByUser = temperatureSetByUser;
}
