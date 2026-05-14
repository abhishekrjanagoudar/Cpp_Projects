#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "PowerManagement.h"

// Sensor component reads the environment temperature.
class TemperatureSensor
{
public:
    // Public state keeps the class easy to inspect in diagrams.
    float currentTemperature;

    // Pointer lets the sensor share the same power-management object.
    PowerManagement *powerManager;

    // Constructor links the sensor to shared power management.
    TemperatureSensor(PowerManagement *powerManager);

    // Destructor is empty because nothing is dynamically allocated.
    ~TemperatureSensor();

    // Getter returns the stored reading.
    float getCurrentTemperature();
};

#endif /* TEMPERATURESENSOR_H_ */
