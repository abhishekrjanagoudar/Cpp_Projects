#ifndef CONTROLLER_H_
#define CONTROLLER_H_

// Controller stores the current temperature and the user's target value.
class Controller
{
public:
    // Constructor initializes the state to known values.
    Controller();

    // Destructor is virtual in case the class is extended later.
    virtual ~Controller();

    // Public data keeps the example straightforward for learning.
    float currentTemp;

    float tempSetByUser;

    // Stores the new target temperature.
    void setTempSetByUser(int value);
};

#endif /* CONTROLLER_H_ */
