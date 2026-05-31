#pragma once

#include "Vehicle.h"

/*
========================================================
CLASS: Bike
========================================================
Purpose:
Derived class representing bike.
*/

class Bike : public Vehicle {

private:

    // Sports bike status
    bool isSportsBike;

public:

    // Constructor
    Bike(string name,
         string regNo,
         bool sports);

    // Overridden method
    void displayType() override;
};

inline Bike::Bike(string name, string regNo, bool sports)
{
	this->vehicleName = name;
	this->registrationNumber = regNo;
	this->isSportsBike = sports;
}

inline void Bike::displayType()
{
}
