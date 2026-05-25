#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "CDAccount.h"

#include <stdexcept>

Customer::Customer(unsigned int number) : number(number) {}

Customer::~Customer() {}

unsigned int Customer::getNumber() const
{
	// Return customer number
	return number;
}

std::string Customer::getId() const
{
	// Convert number to string
	std::string id = std::to_string(number);

	// Calculate required zeros
	int needed_zeros = 10 - id.length();

	// Create final padded ID
	std::string customerId = std::string(needed_zeros, '0') + id;

	// Return customer ID
	return customerId;
}

Customer* Customer::setPersonalData(std::string lastName,
		std::string firstName,
		Poco::Data::Date dateOfBirth)
{
	// Store last name
	this->lastName = lastName;

	// Store first name
	this->firstName = firstName;

	// Store DOB
	this->dateOfBirth = dateOfBirth;

	// Return current object pointer
	return this;
}

const Poco::Data::Date& Customer::getDateOfBirth() const
{
	// Return DOB
	return dateOfBirth;
}

const std::string& Customer::getFirstName() const
{
	// Return first name
	return firstName;
}

const std::string& Customer::getLastName() const
{
	// Return last name
	return lastName;
}

Account* Customer::createAccount(Bank::AccountType type)
{
	// Smart pointer for polymorphic object
	std::unique_ptr<Account> account;

	// Create Current account
	if (type == Bank::Current)
	{
		account = std::make_unique<CurrentAccount>(this);
	}

	// Create Savings account
	else if (type == Bank::Savings)
	{
		account = std::make_unique<SavingsAccount>(this);
	}

	// Create CD account
	else
	{
		account = std::make_unique<CDAccount>(this);
	}

	// Get raw observer pointer
	Account* rawPtr = account.get();

	// Get generated account ID
	std::string id = account->getId();

	// Move ownership into map
	accounts.insert({id, std::move(account)});

	// Return observer pointer
	return rawPtr;
}

std::vector<Account*> Customer::allAccounts() const
{
	// Vector for raw pointers
	std::vector<Account*> result;

	// Loop through accounts map
	for (const auto& pair : accounts)
	{
		// Add raw pointer into vector
		result.push_back(pair.second.get());
	}

	// Return vector
	return result;
}

Account* Customer::lookupAccount(std::string id) const
{
	// Search account in map
	auto it = accounts.find(id); //this means account id

	// If account found
	if (it != accounts.end())
	{
		// Return raw pointer
		return it->second.get();
	}

	// Account not found
	throw std::invalid_argument("Account does not exist");
}


void Customer::deleteAccount(std::string id)
{
	// Search account
	auto it = accounts.find(id);

	// Account not found
	if (it == accounts.end())
	{
		throw std::invalid_argument("Account does not exist");
	}

	// Balance must be zero
	if (it->second->getBalance() != 0)
	{
		throw std::logic_error("Account balance is not zero");
	}

	// Delete account using iterator
	accounts.erase(it);
}

std::ostream& operator<<(std::ostream& out,
		const Customer& customer)
{
	// Write customer data
	out << customer.getId()
		<< ": "
		<< customer.getLastName()
		<< ", "
		<< customer.getFirstName()
		<< " ("
		<< customer.getDateOfBirth().day()
		<< "."
		<< customer.getDateOfBirth().month()
		<< "."
		<< customer.getDateOfBirth().year()
		<< ")";

	// Return stream
	return out;
}
