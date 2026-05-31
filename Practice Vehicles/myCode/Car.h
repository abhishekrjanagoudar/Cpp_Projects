#pragma once
#include "Vehicle.h"

/*
========================================================
CLASS: Car
========================================================
Purpose:
Derived class representing car.
*/

class Car : public Vehicle {

private:

    // Number of doors
    int numberOfDoors;

public:

    // Constructor
    Car(string name,
        string regNo,
        int doors);

    // Overridden method
    void displayType() override;
};

inline Car::Car(string name, string regNo, int doors)
{
	this->vehicleName = name;
	this->registrationNumber = regNo;
	this->numberOfDoors = doors;
}

inline void Car::displayType()
{
}
