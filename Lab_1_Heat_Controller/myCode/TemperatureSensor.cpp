#include "TemperatureSensor.h"
#include "PowerManagement.h"

TemperatureSensor::TemperatureSensor(PowerManagement *powerManager)
{
    // Store the shared dependency through a pointer.
    this->powerManager = powerManager;
    this->currentTemperature = 0;
}

TemperatureSensor::~TemperatureSensor()
{
    // No manual cleanup is necessary.
}

float TemperatureSensor::getCurrentTemperature()
{
    // Return the cached reading.
    return currentTemperature;
}
