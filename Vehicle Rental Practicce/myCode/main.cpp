/*
 * main.cpp
 *
 *  Created on: 20 May 2026
 *      Author: abhir
 */

#include "RentalSystem.h"
#include "Vehicle.h"
#include "Customer.h"

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	/*
	 * =========================
	 * CREATE RENTAL SYSTEM
	 * =========================
	 */

	RentalSystem rs;

	/*
	 * =========================
	 * CREATE VEHICLES
	 * =========================
	 */

	Vehicle v1(101, "Toyota");
	Vehicle v2(102, "BMW");
	Vehicle v3(103, "Tesla");

	/*
	 * =========================
	 * ADD VEHICLES
	 * =========================
	 */

	rs.addVehicle(v1);
	rs.addVehicle(v2);
	rs.addVehicle(v3);

	/*
	 * =========================
	 * CREATE CUSTOMERS
	 * =========================
	 */

	Customer c1(1, "Abhi");
	Customer c2(2, "Rahul");

	/*
	 * =========================
	 * ADD CUSTOMERS
	 * =========================
	 */

	rs.addCustomer(c1);
	rs.addCustomer(c2);

	/*
	 * =========================
	 * DISPLAY DATA
	 * =========================
	 */

	rs.displayVehicles();

	rs.displayCustomers();

	/*
	 * =========================
	 * RENT VEHICLES
	 * =========================
	 */

	rs.rentVehicle(1, 101);

	rs.rentVehicle(2, 102);

	/*
	 * =========================
	 * RETURN VEHICLE
	 * =========================
	 */

	rs.returnVehicle(1, 101);

	/*
	 * =========================
	 * DISPLAY HISTORY
	 * =========================
	 */

	rs.displayRentalHistory();

	/*
	 * =========================
	 * DISPLAY VIP CUSTOMER
	 * =========================
	 */

	rs.displayVIP();

	return 0;
}
