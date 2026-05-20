// Address implementation.
#include "Address.h"
#include <iostream>
using namespace std;

const std::string& Address::getCityName() const
{
	return cityName;
}

unsigned short Address::getPostalCode() const
{
	return postalCode;
}

const std::string& Address::getStreet() const
{
	return street;
}

Address::Address(std::string street, unsigned short postalCode,
		std::string cityName, std::string additionalDetails)
{
	this->street = street;
	this->postalCode = postalCode;
	this->cityName = cityName;
	this->additionalDetails = additionalDetails;
}

Address::~Address()
{

}

const std::string& Address::getAdditionDetails() const
{
	return additionalDetails;
}

void Address::write(ostringstream &os) const
{
	os << street << ';' << postalCode << ';' << cityName << ';'
			<< additionalDetails;
}
