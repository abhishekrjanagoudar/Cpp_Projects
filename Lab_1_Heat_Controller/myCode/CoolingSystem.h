/* CoolingSystem.h - short notes */

#ifndef COOLINGSYSTEM_H_
#define COOLINGSYSTEM_H_

#include "PowerManagement.h"

// CoolingSystem: controls cooler; holds pointer to PowerManagement
class CoolingSystem
{
public:
    // Cooler temperature (Celsius)
    float coolerValue;

    // Pointer to PowerManagement
    PowerManagement *powerManager;

    // Constructor: accept pointer to PowerManagement
    CoolingSystem(PowerManagement *powerManager);

    // Destructor
    ~CoolingSystem();

    // Set cooler temperature
    void setCoolerTemperature(int value);
};

#endif /* COOLINGSYSTEM_H_ */
