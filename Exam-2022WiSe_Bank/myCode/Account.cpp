#include "Account.h"
#include "Customer.h"

Account::Account(Customer* customer, Bank::AccountType type)
{
    // Get full customer ID
    std::string customerId = customer->getId();

    // Take last 8 digits
    std::string customerSuffix = customerId.substr(3, 7);

    // Store account type digit
    std::string typeDigit;

    // Determine type digit
    if (type == Bank::Current)
    {
        typeDigit = "1";
    }
    else if (type == Bank::Savings)
    {
        typeDigit = "2";
    }
    else
    {
        typeDigit = "3";
    }

    // Temporary fixed sequence number
    std::string sequence = "01";

    // Final account ID
    id = typeDigit + sequence + customerSuffix;
}

Bank::AccountType Account::accountType(std::string accountId) {
	char typeDigit = accountId[0];

	if (typeDigit == '1'){
		return Bank::Current;
	}

	else if (typeDigit == '2'){
		return Bank::Savings;
	}

	else if (typeDigit == '3'){
		return Bank::CD;
	}

	// Invalid account type
    throw std::invalid_argument("Invalid account ID");

}

Account::~Account() {
}

std::string Account::getId() const {
	return id;
}

float Account::getBalance() const {
	return balance;
}

void Account::transact(float amount) {
	balance = balance + amount;
}

Poco::JSON::Object::Ptr Account::toJson() const {
	// Create JSON object
	Poco::JSON::Object::Ptr obj = new Poco::JSON::Object;

	// Set account type using polymorphism
	setAccountType(*obj);

	// Add balance field
	obj->set("balance", balance);

	// Return JSON object
	return obj;
}
