/* Controller.cpp - implementation (short notes) */

#include "Controller.h"

// Constructor: initialize member variables
Controller::Controller()
{
    this->currentTemp = 0; // default current temperature
    this->tempSetByUser = 0; // default desired temperature
}

// Destructor: no dynamic resources to free
Controller::~Controller()
{
}

// Setter: update the desired temperature (simple function, shows `this->`)
void Controller::setTempSetByUser(int value)
{
    this->tempSetByUser = value; // assignment to member variable
}
