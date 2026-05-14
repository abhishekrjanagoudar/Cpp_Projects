#include "UserInterface.h"

UserInterface::UserInterface(PowerManagement *powerManager)
{
    // Store the shared dependency and reset the values.
    this->powerManager = powerManager;
    this->currentTemperature = 0;
    this->temperatureSetByUser = 0;
}

UserInterface::~UserInterface()
{
    // No cleanup needed.
}

// Simple setter for the measured temperature.
void UserInterface::setCurrentTemperature(float currentTemperature)
{
    this->currentTemperature = currentTemperature;
}

// Simple setter for the target temperature.
void UserInterface::setTemperatureSetByUser(float temperatureSetByUser)
{
    this->temperatureSetByUser = temperatureSetByUser;
}
