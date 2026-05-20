/*
 * Vehicle.cpp
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() {}

Vehicle::~Vehicle() {}

Vehicle::Vehicle(int id, const std::string &name) : vehicleId(id) , vehicleName(name) {}

void Vehicle::display() const
{
	std::cout << "ID: " << vehicleId << '\n' << "Name: " << vehicleName << '\n' << "Rent Status: " << isRented << '\n';
}

void Vehicle::rentvehicle()
{
	if (isRented == true)
	{
		std::cout << "Vehicle is already rented" << std::endl;
	}
	else
	{
		isRented = true;

		std::cout << "Vehicle rented successfully" << std::endl;
	}
}

void Vehicle::returnVehicle()
{
	if (isRented == false)
	{
		std::cout << "Vehicle is already available" << std::endl;
	}
	else
	{
		isRented = false;

		std::cout << "Vehicle returned successfully" << std::endl;
	}
}

int Vehicle::getId() const
{
	return vehicleId;
}

std::string Vehicle::getName() const
{
	return vehicleName;
}

bool Vehicle::getRentalStatus() const
{
	return isRented;
}
