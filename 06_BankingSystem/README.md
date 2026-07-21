# 06 · Banking System 🏦

A C++ exam question bank (2022 Winter Semester) modelling a bank with multiple account types, customers, and JSON-style output.

## Class Overview

| Class | Responsibility |
|---|---|
| `Bank` | Holds customers and their accounts; top-level entity |
| `Account` | Abstract base — balance, IBAN, transaction history |
| `SavingsAccount` | Interest-bearing savings account |
| `CurrentAccount` | Overdraft-enabled current/checking account |
| `CDAccount` | Fixed-term certificate-of-deposit account |
| `Customer` | Personal data + list of owned accounts |

---

## 🧠 Important Concepts Used & Learnt

### 1. Abstract Base Class with Protected Constructor
`Account` cannot be instantiated directly — only subclasses can call its constructor via `protected`:
```cpp
protected:
    Account(Customer* customer, Bank::AccountType type);
public:
    virtual ~Account();
```
This forces the correct subclass to be created for each account type.

### 2. Pure Virtual Functions for Subclass Specialisation
Each concrete account type must implement `setAccountType()` to inject the correct type string into JSON:
```cpp
virtual Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj) const = 0;
```
This is **polymorphism in practice**: the base class drives the JSON output flow, while subclasses fill in the type-specific field.

### 3. Nested Enum (Scoped Inside Class)
`Bank::AccountType` is an enum scoped inside `Bank` — avoiding global namespace pollution:
```cpp
class Bank {
public:
    enum AccountType { Current, Savings, CD };
};
```

### 4. Forward Declaration
`Account.h` forward-declares `Customer` to break a circular `#include` dependency:
```cpp
class Customer;  // forward declaration — no #include "Customer.h" needed here
```
A critical technique for managing inter-class dependencies in multi-file projects.

### 5. Static Method for ID Parsing
`Account::accountType(std::string accountId)` is a `static` utility that decodes the account type from an ID string — no instance needed:
```cpp
static Bank::AccountType accountType(std::string accountId);
```

### 6. Exception Handling (`std::invalid_argument`)
`accountType()` throws `std::invalid_argument` if the ID is malformed — teaching exception-as-error-signal for invalid inputs:
```cpp
// @throws invalid_argument if the type cannot be derived from the id.
```

### 7. JSON Output via Poco Library
`Account::toJson()` builds a `Poco::JSON::Object` and returns a smart-pointer (`Ptr`) to it:
```cpp
Poco::JSON::Object::Ptr toJson() const;
```
This exposes the pattern of using third-party serialisation libraries and returning managed objects.

### 8. Sequence Number Generation (Non-trivial ID Logic)
Account IDs encode type + sequence number + customer ID. Finding the next free sequence number requires scanning existing accounts — a real algorithmic challenge, not just a setter.

---

## Marks Breakdown (Exam)
See `tests.cpp` for expected behaviour.

## Source
All source files are in [`myCode/`](./myCode/)  
Unit tests: [`myCode/tests.cpp`](./myCode/tests.cpp)

## Reference
See `2022WiSe-APT-1.pdf` for the full exam specification.
