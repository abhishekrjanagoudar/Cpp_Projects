#pragma once

#include <iostream>
#include <string>

#include "FuelType.h"

using namespace std;

/*
========================================================
CLASS: Engine
========================================================
Purpose:
Represents engine information of vehicle.
*/

class Engine {

private:

    // Stores engine horsepower
    int horsePower;

    // Stores fuel type
    FuelType fuelType;

public:

    // Default constructor
    Engine();

    // Parameterized constructor
    Engine(int hp, FuelType fuel);

    // Starts engine
    void startEngine();

    // Returns horsepower
    int getHorsePower();
};

inline Engine::Engine()
{

}

inline Engine::Engine(int hp, FuelType fuel)
{
	this->horsePower = hp;
	this->fuelType = fuel;
}

inline void Engine::startEngine()
{
}

inline int Engine::getHorsePower()
{
	return horsePower;
}
