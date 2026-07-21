/* TemperatureSensor.cpp - implementation (short notes) */

#include "TemperatureSensor.h"
#include "PowerManagement.h"

// Constructor: store pointer and init temperature
TemperatureSensor::TemperatureSensor(PowerManagement *powerManager)
{
    this->powerManager = powerManager;
    this->currentTemperature = 0;
}

// Destructor
TemperatureSensor::~TemperatureSensor()
{
}

// Return current temperature
float TemperatureSensor::getCurrentTemperature()
{
    return currentTemperature;
}
