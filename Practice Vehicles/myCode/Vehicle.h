#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Engine.h"
#include "Wheel.h"

using namespace std;

/*
========================================================
CLASS: Vehicle
========================================================
Purpose:
Base class for all vehicles.
*/

class Vehicle {

protected:

    // Vehicle name
    string vehicleName;

    // Registration number
    string registrationNumber;

    // Smart pointer to Engine
    unique_ptr<Engine> engine;

    // Dynamic list of wheels
    vector<Wheel> wheels;

    // Service history map
    map<int, string> serviceHistory;

public:

    // Constructor
    Vehicle(string name,
            string regNo);

    // Virtual method
    virtual void displayType();

    // Add wheel into vector
    void addWheel(const Wheel& wheel);

    // Add service record into map
    void addServiceRecord(
        int year,
        const string& description
    );

    // Display service history
    void showServiceHistory();

    // Transfer engine ownership
    void setEngine(unique_ptr<Engine> eng);

    // Virtual destructor
    virtual ~Vehicle();
};

inline Vehicle::Vehicle(string name, string regNo)
{
	this->vehicleName = name;
	this->registrationNumber = regNo;
}

inline void Vehicle::displayType()
{
}

inline void Vehicle::addWheel(const Wheel &wheel)
{
}

inline void Vehicle::addServiceRecord(int year, const string &description)
{
}

inline void Vehicle::showServiceHistory()
{
	return serviceHistory;
}

inline void Vehicle::setEngine(unique_ptr<Engine> eng)
{
}

inline Vehicle::~Vehicle()
{
}
