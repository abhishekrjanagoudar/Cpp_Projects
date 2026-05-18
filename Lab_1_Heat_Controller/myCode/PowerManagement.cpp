/* PowerManagement.cpp - implementation (short notes) */

#include "PowerManagement.h"

// Constructor: set voltage/current and enable power
PowerManagement::PowerManagement(int vol, int cur)
{
    this->voltage = vol;
    this->current = cur;
    this->isPowerSystemOn = true;
}

// Destructor
PowerManagement::~PowerManagement()
{
}
