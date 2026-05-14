// Student implementation.

#include "Student.h"
#include <iostream>
using namespace std;

unsigned int Student::nextMatrikelNumber = 100000;

Student::~Student()
{

}

Student::Student(std::string firstName, std::string lastName,
		Poco::Data::Date dateOfBirth, std::string street,
		unsigned short postalCode, std::string cityName,
		std::string additionalDetails) :
		address(Address(street, postalCode, cityName, additionalDetails)), firstName(
				firstName), lastName(lastName), dateOfBirth(dateOfBirth)
{
	this->matrikelNumber = nextMatrikelNumber;
}

const Address& Student::getAddress() const
{
	return address;
}

const Poco::Data::Date& Student::getDateOfBirth() const
{
	return dateOfBirth;
}

const vector<Enrollment>& Student::getEnrollments() const
{
	return enrollments;
}

const std::string& Student::getFirstName() const
{
	return firstName;
}

const std::string& Student::getLastName() const
{
	return lastName;
}

unsigned int Student::getMatrikelNumber() const
{
	return matrikelNumber;
}

void Student::refreshNextMatrikelNumber()
{
	nextMatrikelNumber++;
}

void Student::resetNextMatrikelNumber()
{
	nextMatrikelNumber = 100000;
}

Student::Student() :
		address(Address("", 0, "", "")), firstName(""), lastName(""), dateOfBirth(
				Poco::Data::Date(2000, 1, 1)), matrikelNumber(0)
{
}

void Student::setAddress(const Address &address)
{
	this->address = address;
}

void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

void Student::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

void Student::addEnrollment(Enrollment &enrollment)
{
	enrollments.push_back(enrollment);
}

void Student::write(ostringstream &os) const
{
	os << matrikelNumber << ';' << firstName << ';' << lastName << ';'
			<< dateOfBirth.day() << '.' << dateOfBirth.month() << '.'
			<< dateOfBirth.year() << ';';
	address.write(os);
}

void Student::read(istringstream &is)
{
	string matrikelNumber, firstName, lastName, dobDD, dobMM, dobYY, street,
			postalCode, city, additionalDetails;

	getline(is, matrikelNumber, ';');
	getline(is, firstName, ';');
	getline(is, lastName, ';');
	getline(is, dobDD, '.');
	getline(is, dobMM, '.');
	getline(is, dobYY, ';');
	getline(is, street, ';');
	getline(is, postalCode, ';');
	getline(is, city, ';');
	getline(is, additionalDetails, '\n');

	this->matrikelNumber = stoi(matrikelNumber);
	if (this->matrikelNumber >= this->nextMatrikelNumber)
	{
		this->nextMatrikelNumber = this->matrikelNumber + 1;
	}

	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = Poco::Data::Date(stoi(dobYY), stoi(dobMM), stoi(dobDD));
	unsigned short postal = (unsigned short) stoi(postalCode);

	Address address(street, postal, city, additionalDetails);
	this->address = address;

}
