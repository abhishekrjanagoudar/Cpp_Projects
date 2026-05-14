#ifndef HEATCONTROLLER_H_
#define HEATCONTROLLER_H_

#include "UserInterface.h"
#include "HeatingSystem.h"
#include "CoolingSystem.h"
#include "PowerManagement.h"
#include "TemperatureSensor.h"
#include "Controller.h"
#include "Thermostat.h"

// HeatController is the top-level object that wires all sub-components.
class HeatController
{
public:
    // Constructor creates the full component tree.
    HeatController();

    // Destructor is empty because the members clean themselves up.
    ~HeatController();

    // PowerManagement is the shared dependency used by the components.
    PowerManagement powerManagement = PowerManagement(240, 10);

    // Member objects use pointers to the shared power-management object.
    UserInterface userInterface = UserInterface(&powerManagement);

    // The thermostat stores the temperature requested by the user.
    Thermostat thermostatController = Thermostat(&powerManagement);

    // Heating and cooling are separate functional components.
    HeatingSystem heatingSystem = HeatingSystem(&powerManagement);

    CoolingSystem coolingSystem = CoolingSystem(&powerManagement);

    // Sensor reads the current temperature from the environment.
    TemperatureSensor tempratureSensor = TemperatureSensor(&powerManagement);

    // Controller keeps the current value and the user-set target.
    Controller controller = Controller();

    // Updates the target temperature in the collaborating components.
    void setRoomTemp(int temp);
};

#endif /* HEATCONTROLLER_H_ */
