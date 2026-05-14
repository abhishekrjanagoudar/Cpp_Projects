#ifndef THERMOSTAT_H_
#define THERMOSTAT_H_

#include "PowerManagement.h"

// Thermostat stores the temperature requested by the user.
class Thermostat
{
public:
    // Public state keeps the example easy to read.
    float temperatureSetByUser;

    // Pointer to the shared power-management object.
    PowerManagement *powerManager;

    // Constructor links the thermostat to the power manager.
    Thermostat(PowerManagement *powerManager);

    // No cleanup needed.
    ~Thermostat();

    // Getter returns the stored value.
    float getTempratureSetByUser();
};

#endif /* THERMOSTAT_H_ */
