# C++ OOP + STL + Smart Pointer Practice Assignment
## 🏦 Bank Account Management System

You will build a comprehensive OOP project using:
- classes and inheritance (polymorphism)
- STL containers (`std::map`, `std::vector`)
- smart pointers (`std::unique_ptr`)
- .h/.cpp separation
- exception handling
- string manipulation and formatting
- integration with external libraries (POCO C++ for JSON and Date)

## 📁 File Structure
- `Account.h` / `Account.cpp` (Base Class)
- `CurrentAccount.h` / `CurrentAccount.cpp` (Derived)
- `SavingsAccount.h` / `SavingsAccount.cpp` (Derived)
- `CDAccount.h` / `CDAccount.cpp` (Derived)
- `Customer.h` / `Customer.cpp`
- `Bank.h` / `Bank.cpp`
- `main.cpp`
- `tests.cpp`

## 🎯 Main Goal

System should:
- manage a bank that stores customers
- allow customers to hold multiple types of accounts (Current, Savings, CD)
- track balances and perform transactions
- generate complex unique account IDs automatically based on specific sequence logic
- correctly manage memory using `std::unique_ptr`
- serialize account data to JSON format using Poco

---

## 🔥 CLASS 1 — Bank
**Purpose:** Represents the Bank. In the scope of this exercise, the properties of the bank are reduced to "a bank has customers".

**File:** `Bank.h`

### Attributes (Private)
1. **Next Customer Number**
   ```cpp
   unsigned int nextCustomerNumber = 1;
   ```
   The number of the next customer that is created by an invocation of `createCustomer()`.

2. **Customers Container**
   ```cpp
   std::map<std::string, std::unique_ptr<Customer>> customers;
   ```
   The customer directory. Customers are stored by their id.

### Methods (Public)
- **Account Type Enum**
  ```cpp
  enum AccountType { CD, Current, Savings };
  ```
  The account types offered by the bank (in alphabetical order).

- **createCustomer()**
  ```cpp
  Customer* createCustomer();
  ```
  Creates a new customer, assigning it the next available id. The customer is added to the customer directory. Returns a raw pointer for observation.

- **lookupCustomer()**
  ```cpp
  Customer* lookupCustomer(std::string id) const;
  ```
  Looks up a customer in the customer directory by its id. Returns a pointer to the customer or `nullptr` if no customer with this id exists.

- **allCustomers()**
  ```cpp
  std::vector<Customer*> allCustomers() const;
  ```
  Returns pointers to all customers of the bank.

---

## 🔥 CLASS 2 — Customer
**Purpose:** Represents a customer of the bank holding multiple accounts.

**File:** `Customer.h`

### Attributes (Private)
1. **Customer Number & Details**
   ```cpp
   const unsigned int number;
   std::string lastName;
   std::string firstName;
   Poco::Data::Date dateOfBirth;
   ```

2. **Accounts Container**
   ```cpp
   std::map<std::string, std::unique_ptr<Account>> accounts;
   ```

### Methods (Public)
- **Constructor**
  ```cpp
  Customer(unsigned int number);
  ```
  Creates a new customer record with the given number.

- **setPersonalData()**
  ```cpp
  Customer* setPersonalData(std::string lastName, std::string firstName, Poco::Data::Date dateOfBirth);
  ```
  Sets the personal data. Returns the customer for method chaining.

- **ID Generation**
  ```cpp
  std::string getId() const;
  ```
  **Task Details:** Returns the customer id. The id is the customer number left padded with zeros until the length is 10. Example: if the customer number is `1234`, the id is `"0000001234"`.

- **Account Management**
  ```cpp
  Account* createAccount(Bank::AccountType type);
  Account* lookupAccount(std::string id) const;
  void deleteAccount(std::string id);
  ```
  **Task Details for `deleteAccount`:** 
  - Delete the account with the given id if its balance is 0.
  - **Implementation hint:** in order to avoid searching through the accounts twice, the implementation must use an iterator for searching and erasing the account.
  - Throws `invalid_argument` if an account with the given id does not exist.
  - Throws `logic_error` if the balance of the account is not 0.

- **allAccounts()**
  ```cpp
  std::vector<Account*> allAccounts() const;
  ```
  Returns a list of all accounts of the user as a vector of pointers.

### Operator Overload
- **operator<<**
  ```cpp
  std::ostream& operator<< (std::ostream& out, const Customer& customer);
  ```
  **Task Details:** Writes a customer's personal data to the stream as:
  `<id>: <lastName>, <firstName> (<dateOfBirth>)`
  `<dateOfBirth>` may have English or German format, no zero-padding required.
  Example: `0000000001: Angel, Alice (1.1.1991)`

---

## 🔥 CLASS 3 — Account (Abstract Base Class)
**Purpose:** Base class for all Accounts.

**File:** `Account.h`

### Attributes (Private & Protected)
1. **Account Details**
   ```cpp
   std::string id;
   float balance = 0;
   ```

### Methods (Protected & Public)
- **Constructor (Protected)**
  ```cpp
  Account(Customer* customer, Bank::AccountType type);
  ```
  **Crucial Logic for ID Generation:**
  Accounts have an id which is assigned upon creation as follows:
  - The first digit indicates the account type (1: Current, 2: Savings, 3: Certificate of deposit)
  - The second and third digit represent a counter (sequence number) for the number of accounts of a given type. Counting starts with 1.
  - The remaining 8 digits are the same as the 8 rightmost digits of the customer id.
  
  **Implementation Details:**
  To evaluate the account id, the method uses the type passed as argument. In addition, it searches through the existing accounts of the customer in order to find the next free sequence number for creating an account of the desired type.
  *Note that finding the next free sequence number isn't trivial.* Imagine that you have created accounts with ids `3010000001`, `3020000001`, `3030000001`. Then the second account is deleted, leaving accounts `3010000001`, `3030000001`. If you create a new account of type "3", you'll have to detect that sequence number "02" is not used and create `3020000001` as new id.

- **setAccountType() (Pure Virtual)**
  ```cpp
  virtual Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj) const = 0;
  ```
  Sets the field "accountType" of the JSON object. Returns the object for method invocation chaining.

- **accountType() (Static)**
  ```cpp
  static Bank::AccountType accountType(std::string accountId);
  ```
  Given an account id, extract and return the account type. Throws `invalid_argument` exception if the type cannot be derived from the id.

- **transact()**
  ```cpp
  void transact(float amount);
  ```
  Combined method for deposit (positive amount) and withdraw (negative amount).

- **toJson()**
  ```cpp
  Poco::JSON::Object::Ptr toJson() const;
  ```
  Creates a JSON Object that represents the account data. Fields are "accountType" and "balance", e.g.: `{"accountType":"Current","balance":100}`.

---

## 🔥 CLASSES 4, 5, 6 — Derived Accounts
**Purpose:** Specific implementations of the `Account` base class.

**Files:** `CurrentAccount.h`, `SavingsAccount.h`, `CDAccount.h`

### Methods (Public)
- **Constructors**
  ```cpp
  CurrentAccount(Customer* customer);
  SavingsAccount(Customer* customer);
  CDAccount(Customer* customer);
  ```
  Initializes a new account for the customer.

- **setAccountType() Overrides**
  ```cpp
  Poco::JSON::Object& setAccountType(Poco::JSON::Object& obj) const override;
  ```
  Sets the field "accountType" of the object to "Current", "Savings", or "CD" respectively. Returns the object for method invocation chaining.

---

## 🔥 REQUIRED STL & C++ PRACTICE
- **MAP (`std::map`)**: 
  - Storing `<std::string, std::unique_ptr<T>>`
  - **Explicit Task**: Using iterators explicitly to find and safely `erase` elements (required in `Customer::deleteAccount` to avoid double searching).
- **VECTOR (`std::vector`)**:
  - Returning lists of observer raw pointers from collections of unique pointers.
- **STRING MANIPULATION (`std::string`, `std::to_string`)**:
  - Zero-padding numbers for IDs.
  - Substring extraction and parsing for complex ID generation logic.
- **EXCEPTIONS**:
  - Throwing `std::invalid_argument` for bad lookups or invalid ID structures.
  - Throwing `std::logic_error` if the balance of the account is not 0 upon deletion.

## 🔥 REQUIRED SMART POINTER PRACTICE
- **`std::unique_ptr`**: 
  - Strict ownership representation (Bank owns Customers, Customer owns Accounts).
  - Safe memory cleanup upon erasure.

## 🔥 REQUIRED CONCEPTS
You MUST practice:
- Abstract Classes & Pure Virtual Functions (`= 0`) ✅
- Inheritance & Polymorphism ✅
- Virtual Destructors (`virtual ~Account()`) ✅
- `static` methods ✅
- Overloading `operator<<` as a global function ✅
- Using third-party libraries (POCO JSON & Date) ✅

## 🔥 What This Assignment Teaches
After completing:
- Complex string manipulation and logic puzzles (finding available sequence gaps for ID generation).
- Deep understanding of memory ownership (`unique_ptr` vs raw pointer observation).
- Using Abstract Base classes with Template Method pattern (`toJson` calling `setAccountType`).
- Integration of object-oriented design with functional JSON serialization.
- Practical optimization (avoiding double search with iterators).