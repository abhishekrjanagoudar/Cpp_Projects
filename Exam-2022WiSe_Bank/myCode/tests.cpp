
#include <iostream>
#include <sstream>
#include <set>
#include <Poco/JSON/Stringifier.h>

using namespace std;

#include "Bank.h"
#include "Customer.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "CDAccount.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Initializes a bank with customers with different account
 * types. Can be used as data for various tests.
 */
void setupBank(Bank& bank) {
    // The following code has been commented out to keep
    // the start project buildable. Remove the comments
    // when you have implemented the required methods.


    Customer* c = bank.createCustomer()->setPersonalData
            ("Angel", "Alice", Poco::Data::Date(1991, 1, 1));
    c->createAccount(Bank::AccountType::Current)->transact(100);
    c->createAccount(Bank::AccountType::Savings)->transact(500);
    c->createAccount(Bank::AccountType::CD)->transact(1000);
    c->createAccount(Bank::AccountType::CD)->transact(2000);
    c->createAccount(Bank::AccountType::CD)->transact(3000);
    bank.createCustomer()->setPersonalData
            ("Billings", "Bob", Poco::Data::Date(1992, 2, 2));
    bank.createCustomer()->setPersonalData
            ("Chase", "Caesar", Poco::Data::Date(1993, 3, 3));

}

void bankTests () {
    /**
     * Create a bank and initialize it with setupBank.
     */
	Bank bank;
	setupBank(bank);

    /*
     * (1) Assert that the bank has three customers.
     */
	assertTrue(
			bank.allCustomers().size() == 3,
			"Error: Bank doesnot contain 3 Customers"
			);


   /*
    * (2) Assert that the customer with id 0000000002 can be looked up.
    */
	assertTrue(
			bank.lookupCustomer("0000000002") != nullptr,
			"Error: Customer 0000000002 should be found"
			);

   /*
    * (3) Assert that there is no customer with id 0000000042.
    */
	assertTrue(
			bank.lookupCustomer("0000000042") != nullptr,
			"Error: Customer 0000000042 should not Exist"
			);

}

void customerTests () {
    /*
     * (1) Create a Customer with sample data. Assert that
     * invoking the overloaded left shift operator produces the
     * expected result. (Hint: use a stringstream.)
     */
    // Add your code here:
	Customer c(1);

	c.setPersonalData("Angel", "Alice", Poco::Data::Date(1991, 1, 1));

	stringstream ss;
	ss << c;

	assertTrue(
			ss.str() == "0000000001: Angel, Alice, (01.01.1991)",
			"Operator Overload Failed"
			);

}

void accountTests () {
    /**
     * Create a bank and initialize it with setupBank.
     */
    // Add your code here:
	Bank bank;

	setupBank(bank);

	Customer* c = bank.lookupCustomer("0000000001");

    /*
     * (1) Lookup Customer 0000000001 (Alice), assert that she is found.
     */
    // Add your code here:
	assertTrue(
			c != nullptr,
			"Error: Customer Not Found"
			);

    /*
     * (2) Assert that Alice has 5 accounts.
     */
    // Add your code here:
	assertTrue(
			c->allAccounts().size() ==5 ,
			"Error: Customer donot have 5 accounts"
			);
    /**
     * (3) Assert that the C++-types of Alice's accounts and the
     * types derived from the account id (see Account::accountType)
     * match.
     */
    // Add your code here:
	for (auto a : c->allAccounts()){
		Bank::AccountType type = Account::accountType(a->getId());

		if (dynamic_cast<CurrentAccount*>(a) != nullptr){
			assertTrue(
					type == Bank::Current ,
					"Current Type Mismatch"
					);
		}
		else if (dynamic_cast<SavingsAccount*>(a) != nullptr){
			assertTrue(
					type == Bank::Savings,
					"Savings Type Mismatch"
					);
		}

		else if (dynamic_cast<CDAccount*>(a) != nullptr){
			assertTrue(
					type == Bank::CD,
					"CD Type Mismatch"
					);
		}

	}



    /**
     * (4) Assert that Alice has 3 accounts of type CD
     * and that these accounts have the ids "3010000001",
     * "3020000001" and "3030000001". The check must not
     * rely on accounts being returned in a specific sequence.
     *
     * In order to check this, proceed as follows:
     *  * Obtain the ids
     *  * Filter out the CD accounts and count them
     *  * Out the ids in a set and assert that the set contains
     *    the expected ids.
     */
    // Add your code here:
	int cdCount = 0;
	set <string> ids;
	for (auto a : c->allAccounts()){
		if (Account::accountType(a->getId()) == Bank::CD){
			cdCount++;
			ids.insert(a->getId());
		}
	}

	assertTrue(
			cdCount == 3,
			"Error: Should be 3 CDs"
			);
	assertTrue(
			ids.count("3010000001") == 1,
			"Error: CD 3010000001 missing"
			);
	assertTrue(
			ids.count("3020000001") == 1,
			"Error: CD 3020000001 missing"
			);
	assertTrue(
			ids.count("3030000001") == 1,
			"Error: CD 3030000001 missing"
			);

    /**
     * (5) Assert that an attempt to delete account 3040000001
     * throws an invalid_argument exception.
     */
    // Add your code here:
	try{
		c->deleteAccount("3040000001");
		assertTrue(
				false, "invalid_argument expected");
	}
	catch(invalid_argument&){

	}

     /**
      * (6) Assert that an attempt to delete account 3020000001
      * throws a logic_error exception.
      */
    // Add your code here:
	try{
		c->deleteAccount("3020000001");
		assertTrue(
				false, "logic_error expected");
		}
		catch(logic_error&){

		}

      /**
       * (7) Withdraw the deposit from account 3010000001,
       * delete the account and assert that Alice has only
       * 4 accounts left
       */
    // Add your code here:
		Account* a =
				c->lookupAccount(
						"3010000001"
						);
		a->transact(-1000);
		c->deleteAccount(
				"3010000001"
				);
		assertTrue(
				c->allAccounts().size()==4,
		        "Delete account failed"
				);

      /**
       * (8) Lookup Alice's account 1010000001, create
       * the JSON object representing its data and assert
       * that the account type is "Current" and the balance
       * is 100.
       */
    // Add your code here:
		Account* current =
				c->lookupAccount(
						"1010000001"
						);

		Poco::JSON::Object::Ptr json =
		        current->toJson();

		assertTrue(
		        json->getValue<string>("accountType")
		                == "Current",
		        "Wrong account type"
		);

		assertTrue(
		        json->getValue<float>("balance")
		                == 100,
		        "Wrong balance"
		);

}

void allTests() {
    bankTests();
    customerTests();
    accountTests();
}
