/* PowerManagement.h - short notes */

#ifndef POWERMANAGEMENT_H_
#define POWERMANAGEMENT_H_

// PowerManagement: holds voltage/current and power state
class PowerManagement
{
public:
    // System voltage (V)
    int voltage;

    // System current (A)
    int current;

    // Power system on/off flag
    bool isPowerSystemOn;

    // Constructor: set voltage and current
    PowerManagement(int vol, int cur);

    // Destructor
    ~PowerManagement();
};

#endif /* POWERMANAGEMENT_H_ */
