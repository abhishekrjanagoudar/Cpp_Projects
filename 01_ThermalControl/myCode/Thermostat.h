/* Thermostat.h - short notes */

#ifndef THERMOSTAT_H_
#define THERMOSTAT_H_

#include "PowerManagement.h"

// Thermostat: stores user-set temperature; provides accessor
class Thermostat
{
public:
    // User-set temperature
    float temperatureSetByUser;

    // Pointer to PowerManagement
    PowerManagement *powerManager;

    // Constructor: init and store power manager pointer
    Thermostat(PowerManagement *powerManager);

    // Destructor
    ~Thermostat();

    // Return user-set temperature (note: spelling kept as in code)
    float getTempratureSetByUser();
};

#endif /* THERMOSTAT_H_ */
