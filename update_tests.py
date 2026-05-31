import sys

new_text = r"""\section*{tests.cpp}
\begin{lstlisting}
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

void assertTrue(bool cond, string msg) {
    if (!cond) cout << msg << endl;
}

void setupBank(Bank& bank) {
Customer* c = bank.createCustomer()->setPersonalData("Angel", "Alice", Poco::Data::Date(1991, 1, 1));
c->createAccount(Bank::AccountType::Current)->transact(100);
c->createAccount(Bank::AccountType::Savings)->transact(500);
c->createAccount(Bank::AccountType::CD)->transact(1000);
c->createAccount(Bank::AccountType::CD)->transact(2000);
c->createAccount(Bank::AccountType::CD)->transact(3000);
bank.createCustomer()->setPersonalData("Billings", "Bob", Poco::Data::Date(1992, 2, 2));
bank.createCustomer()->setPersonalData("Chase", "Caesar", Poco::Data::Date(1993, 3, 3));
}

void bankTests () {
Bank bank;
setupBank(bank);
assertTrue(bank.allCustomers().size() == 3, "Error: Bank doesnot contain 3 Customers");
assertTrue(bank.lookupCustomer("0000000002") != nullptr, "Error: Customer 0000000002 should be found");
assertTrue(bank.lookupCustomer("0000000042") != nullptr, "Error: Customer 0000000042 should not Exist");
}

void customerTests () {
Customer c(1);
c.setPersonalData("Angel", "Alice", Poco::Data::Date(1991, 1, 1));
stringstream ss;
ss << c;
assertTrue(ss.str() == "0000000001: Angel, Alice, (01.01.1991)", "Operator Overload Failed");
}

void accountTests () {
Bank bank;
setupBank(bank);
Customer* c = bank.lookupCustomer("0000000001");
assertTrue(c != nullptr, "Error: Customer Not Found");
assertTrue(c->allAccounts().size() == 5, "Error: Customer donot have 5 accounts");

for (auto a : c->allAccounts()){
Bank::AccountType type = Account::accountType(a->getId());
if (dynamic_cast<CurrentAccount*>(a) != nullptr)
assertTrue(type == Bank::Current , "Current Type Mismatch");
else if (dynamic_cast<SavingsAccount*>(a) != nullptr)
assertTrue(type == Bank::Savings, "Savings Type Mismatch");
else if (dynamic_cast<CDAccount*>(a) != nullptr)
assertTrue(type == Bank::CD, "CD Type Mismatch");
}
int cdCount = 0;
set<string> ids;
for (auto a : c->allAccounts()){
if (Account::accountType(a->getId()) == Bank::CD){
cdCount++;
ids.insert(a->getId());
}
}
assertTrue(cdCount == 3, "Error: Should be 3 CDs");
assertTrue(ids.count("3010000001") == 1, "Error: CD 3010000001 missing");
assertTrue(ids.count("3020000001") == 1, "Error: CD 3020000001 missing");
assertTrue(ids.count("3030000001") == 1, "Error: CD 3030000001 missing");

try {
c->deleteAccount("3040000001");
assertTrue(false, "invalid_argument expected");
} catch(invalid_argument&) {}

try {
c->deleteAccount("3020000001");
assertTrue(false, "logic_error expected");
} catch(logic_error&) {}

Account* a = c->lookupAccount("3010000001");
a->transact(-1000);
c->deleteAccount("3010000001");
assertTrue(c->allAccounts().size() == 4, "Delete account failed");

Account* current = c->lookupAccount("1010000001");
Poco::JSON::Object::Ptr json = current->toJson();
assertTrue(json->getValue<string>("accountType") == "Current", "Wrong account type");
assertTrue(json->getValue<float>("balance") == 100, "Wrong balance");
}

void allTests() {
    bankTests();
    customerTests();
    accountTests();
}
\end{lstlisting}"""

def replace_in_file(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()

    start_idx = content.find(r'\section*{tests.cpp}')
    
    # We want to find the first \end{lstlisting} after start_idx
    end_tag = r'\end{lstlisting}'
    end_idx = content.find(end_tag, start_idx)
    
    if start_idx != -1 and end_idx != -1:
        end_idx += len(end_tag)
        new_content = content[:start_idx] + new_text + content[end_idx:]
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print(f'Updated {filepath}')
    else:
        print(f'Could not find replacement bounds in {filepath}')

replace_in_file(r"E:\Abhishek_Git\Cpp_Projects\Exam-2022WiSe_Bank\myCode\Bank_All.tex")
