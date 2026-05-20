/*
 * RentalSystem.h
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#ifndef RENTALSYSTEM_H_
#define RENTALSYSTEM_H_
#include <map>
#include <vector>
#include <set>
#include <list>
#include <memory>
#include <string>
#include "Customer.h"
#include "Vehicle.h"

class RentalSystem
{

private:
	std::vector<Vehicle> vehicles;
	std::map<int, Customer> customers;
	std::set<int> activeRentals;
	std::list<std::string> rentalHistory;
	std::unique_ptr<Vehicle> featuredVehicle;
	std::shared_ptr<Customer> vipCustomer;

public:
	RentalSystem();
	virtual ~RentalSystem();

	void addVehicle(const Vehicle& v);
	void addCustomer(const Customer& c);
	void rentVehicle(int customerId, int vehicleId);
	void returnVehicle(int customerId, int vehicleId);
	void displayVehicles() const;
	void displayCustomers() const;
	void displayRentalHistory() const;
	void displayVIP() const;

};

#endif /* RENTALSYSTEM_H_ */
