#include "PowerManagement.h"

PowerManagement::PowerManagement(int vol, int cur)
{
    // Constructor stores the power settings and turns the system on.
    this->voltage = vol;
    this->current = cur;
    this->isPowerSystemOn = true;
}

PowerManagement::~PowerManagement()
{
    // Nothing to release.
}
