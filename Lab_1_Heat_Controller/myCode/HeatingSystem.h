#ifndef HEATINGSYSTEM_H_
#define HEATINGSYSTEM_H_

#include "PowerManagement.h"

// HeatingSystem stores the heater state for the example.
class HeatingSystem
{
public:
    // Public data keeps the class easy to inspect in diagrams.
    float heaterTemperature;

    // Constructor links the heater to the shared power manager.
    HeatingSystem(PowerManagement *powerManager);

    // Pointer to the shared power-management object.
    PowerManagement *powerManager;

    // No cleanup needed.
    ~HeatingSystem();

    // Setter stores the requested heater temperature.
    void setHeaterTemperature(int value);
};

#endif /* HEATINGSYSTEM_H_ */
