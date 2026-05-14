#include "Controller.h"

Controller::Controller()
{
    // Start from a neutral state.
    this->currentTemp = 0;
    this->tempSetByUser = 0;
}

Controller::~Controller()
{
    // No heap memory is owned here.
}

void Controller::setTempSetByUser(int value)
{
    // Simple setter: update the stored target value.
    this->tempSetByUser = value;
}
