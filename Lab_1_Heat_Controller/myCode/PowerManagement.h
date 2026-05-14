#ifndef POWERMANAGEMENT_H_
#define POWERMANAGEMENT_H_

// Shared power component used by all other subsystems.
class PowerManagement
{
public:
    // Public state keeps the learning example direct and easy to inspect.
    int voltage;

    int current;

    bool isPowerSystemOn;

    // Constructor sets the operating values.
    PowerManagement(int vol, int cur);

    // Destructor is empty because no resources are owned.
    ~PowerManagement();
};

#endif /* POWERMANAGEMENT_H_ */
