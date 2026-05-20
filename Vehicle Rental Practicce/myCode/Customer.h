/*
 * Customer.h
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
#include <vector>
#include "Vehicle.h"

class Customer
{

private:
	int customerId;
	std::string customerName;
	std::vector<int> rentedVehicles;

public:
	Customer();
	virtual ~Customer();

	Customer(int id, const std::string& name);
	void display() const;
	void addRental(int vehicleId);
	void removeRental(int vehicleId);
	int getId() const;
};

#endif /* CUSTOMER_H_ */
