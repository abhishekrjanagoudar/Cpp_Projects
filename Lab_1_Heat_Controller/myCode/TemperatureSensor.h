/* TemperatureSensor.h - short notes (no STL used) */

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

#include "PowerManagement.h"

// TemperatureSensor: reads current temperature; shows pointer use
class TemperatureSensor
{
public:
    // Current temperature
    float currentTemperature;

    // Pointer to PowerManagement
    PowerManagement *powerManager;

    // Constructor: set pointer and init temperature
    TemperatureSensor(PowerManagement *powerManager);

    // Destructor
    ~TemperatureSensor();

    // Return current temperature (simple accessor)
    float getCurrentTemperature();
};

#endif /* TEMPERATURESENSOR_H_ */
