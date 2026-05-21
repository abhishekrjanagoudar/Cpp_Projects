#include "Bank.h"
#include "Customer.h"

Customer* Bank::createCustomer()
{

    // Create customer
	auto customer = std::make_unique<Customer>(nextCustomerNumber);

    // Get customer ID
	std::string id = customer->getId();

    // Get raw pointer
	Customer *rawPtr = customer.get();

    // Move ownership into map
	customers.insert({id, std::move(customer)});

    // Increment ID counter
	nextCustomerNumber++;

    // Return observer pointer
	return rawPtr;
}

Customer* Bank::lookupCustomer(std::string id) const {

    // Find customer in map
	auto it = customers.find(id);

    // If found
	if (it != customers.end()){

        // Return raw pointer
		return it->second.get();
	}

    // Not found
	return nullptr;
}

std::vector<Customer*> Bank::allCustomers() const
{
    // Store all customer pointers
    std::vector<Customer*> result;

    // Loop through map
    for (const auto& pair : customers)
    {
        // Add raw pointer to vector
        result.push_back(pair.second.get());
    }

    // Return vector
    return result;
}
