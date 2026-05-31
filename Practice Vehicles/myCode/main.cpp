#include <memory>

#include "Car.h"
#include "Bike.h"
#include "Garage.h"
#include "Mechanic.h"

using namespace std;

int main() {

    // Create shared_ptr car
    auto car1 = make_shared<Car>(
        "BMW",
        "KA01AB1234",
        4
    );

    // Create unique_ptr engine
    auto engine1 = make_unique<Engine>(
        300,
        FuelType::Petrol
    );

    // Transfer ownership
    car1->setEngine(move(engine1));

    // Add wheels
    car1->addWheel(Wheel(18));
    car1->addWheel(Wheel(18));

    // Add service records
    car1->addServiceRecord(
        2024,
        "Oil Change"
    );

    car1->addServiceRecord(
        2025,
        "Brake Service"
    );

    // Create garage
    Garage garage;

    garage.addVehicle(car1);

    // Polymorphism
    garage.showAllVehicles();

    // Raw pointer demo
    Mechanic mechanic;

    mechanic.inspectVehicle(car1.get());

    // Map iteration
    car1->showServiceHistory();

    return 0;
}
