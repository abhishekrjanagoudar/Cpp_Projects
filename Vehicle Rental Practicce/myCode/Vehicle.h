/*
 * Vehicle.h
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <string>

class Vehicle
{

private:
	int vehicleId;
	std::string vehicleName;
	bool isRented;

public:
	//Default Contructor and Desctuctors
	Vehicle();
	virtual ~Vehicle();

	//Required Methods
	Vehicle(int id, const std::string& name);
	void display() const;
	void rentVehicle();
	void returnVehicle();
	int getId() const;
	std::string getName() const;
	bool getRentalStatus() const;


};

#endif /* VEHICLE_H_ */
