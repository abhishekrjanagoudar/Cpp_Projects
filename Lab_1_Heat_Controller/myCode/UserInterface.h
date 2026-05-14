#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include "PowerManagement.h"

// UserInterface stores the values entered by the user.
class UserInterface
{
public:
    // Current measured temperature.
    float currentTemperature;

    // Target temperature entered by the user.
    float temperatureSetByUser;

    // Pointer to the shared power-management object.
    PowerManagement *powerManager;

    // Constructor sets the initial state.
    UserInterface(PowerManagement *powerManager);

    // No cleanup needed.
    ~UserInterface();

    // Setter stores the current temperature.
    void setCurrentTemperature(float currentTemperature);

    // Setter stores the requested target temperature.
    void setTemperatureSetByUser(float temperatureSetByUser);
};

#endif /* USERINTERFACE_H_ */
