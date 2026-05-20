/* HeatController.h - simple notes */

#ifndef HEATCONTROLLER_H_
#define HEATCONTROLLER_H_

#include "UserInterface.h"
#include "HeatingSystem.h"
#include "CoolingSystem.h"
#include "PowerManagement.h"
#include "TemperatureSensor.h"
#include "Controller.h"
#include "Thermostat.h"

// HeatController: aggregates subsystems (composition). OOP: shows member objects.
class HeatController
{
public:
    // Constructor: initialize subsystems
    HeatController();

    // Destructor
    ~HeatController();

    // Power management object (example of direct member initialization)
    PowerManagement powerManagement = PowerManagement(240, 10);

    // UI uses pointer to powerManagement (shows passing address)
    UserInterface userInterface = UserInterface(&powerManagement);

    // Thermostat: constructed with pointer to power manager
    Thermostat thermostatController = Thermostat(&powerManagement);

    // Heating system (composition)
    HeatingSystem heatingSystem = HeatingSystem(&powerManagement);

    // Cooling system
    CoolingSystem coolingSystem = CoolingSystem(&powerManagement);

    // Temperature sensor (note: variable name `tempratureSensor` as in code)
    TemperatureSensor tempratureSensor = TemperatureSensor(&powerManagement);

    // Controller object
    Controller controller = Controller();

    // Set desired room temperature
    void setRoomTemp(int temp);
};

#endif /* HEATCONTROLLER_H_ */
