#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
#include <ostream>
#include <sstream>

using std::ostream;
using std::ostringstream;

// Stores basic address details.
class Address
{
private:
	std::string street; 			 // Street name.
	unsigned short postalCode; 		// Postal code.
	std::string cityName; 		   // City name.
	std::string additionalDetails;  // Additional address details.

public:
	Address(std::string street, unsigned short postalCode, std::string cityName,
			std::string additionalDetails);

	virtual ~Address();

	const std::string& getCityName() const;

	unsigned short getPostalCode() const;

	const std::string& getStreet() const;

	const std::string& getAdditionDetails() const;

	void write(ostringstream &os) const;
};

#endif // ADDRESS_H
