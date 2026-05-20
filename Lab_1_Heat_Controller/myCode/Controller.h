/* Controller.h - simple notes */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

// Controller: basic temperature controller (holds current and desired temp)
class Controller
{
public:
    // Constructor: initialize temperatures
    Controller();

    // Virtual destructor: safe for inheritance
    virtual ~Controller();

    // Current temperature (Celsius)
    float currentTemp;

    // Desired temperature set by user (Celsius)
    float tempSetByUser;

    // Set the desired temperature (example of a simple setter function)
    void setTempSetByUser(int value);
};

#endif /* CONTROLLER_H_ */
