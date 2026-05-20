/*
 * Customer.cpp
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#include "Customer.h"

#include <iostream>

Customer::Customer() {}

Customer::~Customer() {}

Customer::Customer(int id, const std::string &name) : customerId(id) , customerName(name) {}

void Customer::display() const
{
	std::cout << "ID: " << customerId << '\n' << "Name: " << customerName << '\n';
}

void Customer::addRental(int vehicleId)
{
	rentedVehicles.push_back(10);
	rentedVehicles.push_back(20);
	rentedVehicles.push_back(30);
	rentedVehicles.push_back(40);
	rentedVehicles.push_back(50);
}

void Customer::removeRental(int vehicleId)
{
	rentedVehicles.pop_back();
	rentedVehicles.pop_back();
	rentedVehicles.pop_back();
	rentedVehicles.pop_back();
	rentedVehicles.pop_back();
}

int Customer::getId() const
{
	return customerId;
}
