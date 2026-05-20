/* HeatingSystem.h - short notes */

#ifndef HEATINGSYSTEM_H_
#define HEATINGSYSTEM_H_

#include "PowerManagement.h"

// HeatingSystem: controls heater; uses PowerManagement pointer.
class HeatingSystem
{
public:
    // Heater temperature (Celsius)
    float heaterTemperature;

    // Constructor: accept pointer to PowerManagement
    HeatingSystem(PowerManagement *powerManager);

    // Pointer to PowerManagement (shows pointer usage)
    PowerManagement *powerManager;

    // Destructor
    ~HeatingSystem();

    // Set heater temperature (simple setter)
    void setHeaterTemperature(int value);
};

#endif /* HEATINGSYSTEM_H_ */
