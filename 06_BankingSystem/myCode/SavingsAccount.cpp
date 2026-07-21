#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(Customer *customer) : Account(customer , Bank::Savings) {}

Poco::JSON::Object& SavingsAccount::setAccountType(
		Poco::JSON::Object &obj) const {
	obj.set("accountType" , "Savings Account");
	return obj;
}
