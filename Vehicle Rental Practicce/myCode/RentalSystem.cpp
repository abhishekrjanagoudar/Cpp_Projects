/*
 * RentalSystem.cpp
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#include "RentalSystem.h"
#include <iostream>

RentalSystem::RentalSystem()
{
	// shared_ptr initialization
	vipCustomer = std::make_shared<Customer>(999, "VIP Customer");

	// unique_ptr initialization
	featuredVehicle = std::make_unique<Vehicle>(5000, "Tesla");
}

RentalSystem::~RentalSystem()
{
}

void RentalSystem::addVehicle(const Vehicle &v)
{
	vehicles.push_back(v);
}

void RentalSystem::addCustomer(const Customer &c)
{
	customers.insert({c.getId(), c});
}

void RentalSystem::rentVehicle(int customerId, int vehicleId)
{
	/*
	 * =========================
	 * FIND CUSTOMER IN MAP
	 * =========================
	 */

	auto customerIt = customers.find(customerId);

	if (customerIt == customers.end())
	{
		std::cout << "Customer not found\n";
		return;
	}

	/*
	 * =========================
	 * FIND VEHICLE IN VECTOR
	 * =========================
	 */

	for (Vehicle &v : vehicles)
	{
		if (v.getId() == vehicleId)
		{
			// Rent vehicle
			v.rentVehicle();

			// Add rental to customer
			customerIt->second.addRental(vehicleId);

			// Add to active rentals set
			activeRentals.insert(vehicleId);

			// Add rental history
			rentalHistory.push_back(
				"Customer rented vehicle ID: " +
				std::to_string(vehicleId));

			std::cout << "Vehicle rented successfully\n";

			return;
		}
	}

	std::cout << "Vehicle not found\n";
}

void RentalSystem::returnVehicle(int customerId, int vehicleId)
{
	/*
	 * =========================
	 * FIND CUSTOMER
	 * =========================
	 */

	auto customerIt = customers.find(customerId);

	if (customerIt == customers.end())
	{
		std::cout << "Customer not found\n";
		return;
	}

	/*
	 * =========================
	 * FIND VEHICLE
	 * =========================
	 */

	for (Vehicle &v : vehicles)
	{
		if (v.getId() == vehicleId)
		{
			// Return vehicle
			v.returnVehicle();

			// Remove rental from customer
			customerIt->second.removeRental(vehicleId);

			// Remove from active rentals
			activeRentals.erase(vehicleId);

			// Add history
			rentalHistory.push_back(
				"Customer returned vehicle ID: " +
				std::to_string(vehicleId));

			std::cout << "Vehicle returned successfully\n";

			return;
		}
	}

	std::cout << "Vehicle not found\n";
}

void RentalSystem::displayVehicles() const
{
	std::cout << "\n===== VEHICLES =====\n";

	for (const Vehicle &v : vehicles)
	{
		v.display();
		std::cout << '\n';
	}
}

void RentalSystem::displayCustomers() const
{
	std::cout << "\n===== CUSTOMERS =====\n";

	for (const auto &pair : customers)
	{
		pair.second.display();
		std::cout << '\n';
	}
}

void RentalSystem::displayRentalHistory() const
{
	std::cout << "\n===== RENTAL HISTORY =====\n";

	for (const std::string &history : rentalHistory)
	{
		std::cout << history << '\n';
	}
}

void RentalSystem::displayVIP() const
{
	std::cout << "\n===== VIP CUSTOMER =====\n";

	vipCustomer->display();

	std::shared_ptr<Customer> anotherVIP = vipCustomer;

	std::cout << "\nShared Pointer Count: "
			  << vipCustomer.use_count()
			  << '\n';

	std::cout << "\n===== FEATURED VEHICLE =====\n";

	featuredVehicle->display();
}
