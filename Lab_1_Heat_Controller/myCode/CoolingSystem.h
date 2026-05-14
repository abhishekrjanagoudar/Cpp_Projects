#ifndef COOLINGSYSTEM_H_
#define COOLINGSYSTEM_H_

#include "PowerManagement.h"

// CoolingSystem stores the cooler state for the example.
class CoolingSystem
{
public:
    // Public data keeps the class easy to inspect in diagrams.
    float coolerValue;

    // Pointer to the shared power-management object.
    PowerManagement *powerManager;

    // Constructor links the cooler to the shared power manager.
    CoolingSystem(PowerManagement *powerManager);

    // No cleanup needed.
    ~CoolingSystem();

    // Setter stores the requested cooler temperature.
    void setCoolerTemperature(int value);
};

#endif /* COOLINGSYSTEM_H_ */
