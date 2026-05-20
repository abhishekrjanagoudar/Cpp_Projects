/* UserInterface.h - short notes */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include "PowerManagement.h"

// UserInterface: handles user input/output; stores temps
class UserInterface
{
public:
    // Current temperature
    float currentTemperature;

    // Desired temperature set by user
    float temperatureSetByUser;

    // Pointer to PowerManagement
    PowerManagement *powerManager;

    // Constructor: init values and store power manager pointer
    UserInterface(PowerManagement *powerManager);

    // Destructor
    ~UserInterface();

    // Set current temperature
    void setCurrentTemperature(float currentTemperature);

    // Set desired temperature (from UI)
    void setTemperatureSetByUser(float temperatureSetByUser);
};

#endif /* USERINTERFACE_H_ */
