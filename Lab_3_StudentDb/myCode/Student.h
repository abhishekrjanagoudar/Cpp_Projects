#ifndef STUDENT_H
#define STUDENT_H

#include <Poco/Data/Date.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Address.h"
#include "Enrollment.h"

// Stores one student record.
class Student
{
private:
	Address address;              // Student's address.
	std::string firstName;        // Student's first name.
	std::string lastName;         // Student's last name.
	Poco::Data::Date dateOfBirth; // Student's date of birth.
	static unsigned int nextMatrikelNumber;
	unsigned int matrikelNumber;  // Student's matrikel number.
	std::vector<Enrollment> enrollments;

public:
	Student();

	Student(std::string firstName, std::string lastName,
			Poco::Data::Date dateOfBirth, std::string street,
			unsigned short postalCode, std::string cityName,
			std::string additionalDetails);

	virtual ~Student();

	void addEnrollment(Enrollment &enrollment);
	static void refreshNextMatrikelNumber();
	static void resetNextMatrikelNumber();

	const Address& getAddress() const;
	const Poco::Data::Date& getDateOfBirth() const;
	const std::vector<Enrollment>& getEnrollments() const;
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	unsigned int getMatrikelNumber() const;

	void setAddress(const Address &address);
	void setDateOfBirth(const Poco::Data::Date &dateOfBirth);
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);

	void write(std::ostringstream &os) const;
	void read(std::istringstream &is);
};

#endif // STUDENT_H
