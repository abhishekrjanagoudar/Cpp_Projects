# C++ Past Exam Cheat Sheet: STL, Pointers, and Streams 🚀🎓

This cheat sheet documents the **Standard Template Library (STL) containers & functions**, **pointers (smart & raw)**, **stream operations (ostream, stringstream, CSV I/O)**, and **exceptions** used across the past APT exams. 

---

## 🗂️ 1. STL Containers & Operations

### 🔹 `std::map<Key, Value>`
A sorted associative container containing unique key-value pairs.

| Operation | Syntax | Description | Exam Usage & Methods |
| :--- | :--- | :--- | :--- |
| **Lookup** | `auto it = map.find(key);` | Finds an element. Returns iterator to key, or `map.end()` if not found. | 🔍 [Bank.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Bank.cpp#L26-L40): `Bank::lookupCustomer` (find customer by ID).<br>🔍 [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L121-L135): `Customer::lookupAccount` / `deleteAccount` (find account by ID).<br>🔍 [Shop.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/Shop.cpp#L30-L47): `Shop::setBasePrice` / `setDiscount` (find product by name). |
| **Insertion** | `map.insert({key, value});` | Inserts element if key does not exist. | 📥 [Bank.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Bank.cpp#L17): `Bank::createCustomer`.<br>📥 [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L99): `Customer::createAccount`. |
| **Add / Edit** | `map[key] = value;` | Inserts or overwrites key-value pair. | 📥 [TableBasedAdjuster.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/TableBasedAdjuster.cpp#L4-L8): `TableBasedAdjuster::addBreakpoint` (stores breakpoints).<br>📥 [QuantityDiscount.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/QuantityDiscount.cpp#L10-L13): `QuantityDiscount::addLimit` (stores quantity limit discounts). |
| **Erasure (Iter)** | `map.erase(iterator);` | Removes element at iterator position. Avoids double search. | 🗑️ [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L156): `Customer::deleteAccount`. |
| **Bounds** | `map.begin()`, `map.end()` | Iterators pointing to start and end bounds. | 🔄 [TableBasedAdjuster.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/TableBasedAdjuster.cpp#L12-L39): `TableBasedAdjuster::adjust` (accesses `begin()` and `--end()` to find interpolation bounds). |

---

### 🔹 `std::vector<Type>`
A dynamic contiguous array that grows automatically.

| Operation | Syntax | Description | Exam Usage & Methods |
| :--- | :--- | :--- | :--- |
| **Add Element** | `vec.push_back(value);` | Appends element to the end. | 📥 [Bank.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Bank.cpp#L51): `Bank::allCustomers`.<br>📥 [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L113): `Customer::allAccounts`. <br>📥 [ShopDb.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/ShopDb.cpp#L20): `ShopDb::shops` (building raw pointer lookup results). |
| **Move Add** | `vec.push_back(std::move(ptr));` | Transfers unique pointer ownership into the vector. | 📥 [Topic.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024SoSe_Notebook/myCode/Topic.cpp#L15-L21): `Topic::add` (inserts child items into vector of unique_ptr). |
| **Iteration** | `for (auto item : vec)` | Range-based iteration. | 🔄 Used widely across exams to traverse observer pointers. |

---

### 🔹 `std::list<Type>`
A doubly-linked list optimized for rapid insertions/deletions anywhere.

| Operation | Syntax | Description | Exam Usage & Methods |
| :--- | :--- | :--- | :--- |
| **Add Element** | `lst.push_back(value);` | Appends element to list. | 📥 [ShoppingList.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/ShoppingList.cpp#L13-L16): `ShoppingList::addItem`. |
| **Move Add** | `lst.push_back(std::move(ptr));` | Transfers ownership of unique pointers. | 📥 [SensorNetwork.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/SensorNetwork.cpp#L11): `SensorNetwork::add`.<br>📥 [ResistorConnection.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024WiSe_Resistor/myCode/ResistorConnection.cpp#L18): `ResistorConnection::operator+=`. |
| **Iteration** | `for (auto it = lst.begin(); ...)` | Uses list iterators. List does **not** support random access indexes (`lst[i]`). | 🔄 [ShoppingList.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/ShoppingList.cpp#L18-L22): `ShoppingList::items` (retrieves iterator boundary variables `begin` and `end`).<br>🔄 [Shop.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/Shop.cpp#L54-L67): `Shop::calculatePurchase`. |

---

### 🔹 `std::set<Type>`
An associative container storing unique elements in sorted order.

| Operation | Syntax | Description | Exam Usage & Methods |
| :--- | :--- | :--- | :--- |
| **Clear** | `set.clear();` | Empties the set contents. | 🧹 [Shop.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/Shop.cpp#L51): `Shop::calculatePurchase` (resets the `notAvailable` items container). |
| **Insert** | `set.insert(value);` | Inserts element if not present. | 📥 [Shop.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/Shop.cpp#L65): `Shop::calculatePurchase` (tracks missing item pointer: `notAvailable.insert(&(*it))`). |
| **Find/Erase** | `set.find()`, `set.erase()` | Searching and deleting. | 🔍 [tests.cpp (ShoppingList)](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/tests.cpp#L103-L114): `shopDbTests` (verifies matching shop names). |
| **Count** | `set.count(value);` | Returns `1` if element is found, `0` otherwise. | 🔢 [tests.cpp (Bank)](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/tests.cpp#L194-L205): `accountTests` (checks set contains specific generated CD accounts). |

---

## ⚡ 2. Memory & Pointer Structures

Memory management in exams relies on separating **ownership** (managed by smart pointers) from **observation** (managed by raw pointers).

### 🟢 `std::unique_ptr<T>`
Exclusive ownership. The resource is freed automatically when the pointer goes out of scope. Cannot be copied, only moved.

* **Usage in Exams**:
  * Storing polymorphically owned children inside class member directories.
    * [Bank.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Bank.h#L28): `std::map<std::string, std::unique_ptr<Customer>> customers;`
    * [Customer.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.h#L29): `std::map<std::string, std::unique_ptr<Account>> accounts;`
    * [SensorNetwork.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/SensorNetwork.h#L13): `std::list<std::unique_ptr<Sensor>> sensors;`
    * [Topic.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024SoSe_Notebook/myCode/Topic.h#L10): `std::vector<std::unique_ptr<Item>> items;`
    * [Resistance.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024WiSe_Resistor/myCode/Resistance.h#L111): `typedef std::unique_ptr<Resistance> ResistancePtr;`
* **Common Code Snippet Patterns**:
  * **Creation**: `auto account = std::make_unique<CurrentAccount>(this);`
  * **Ownership Transfer**: `customers.insert({id, std::move(customer)});` or `items.push_back(std::move(item));`
  * **Observer Extraction**: `.get()` fetches the raw pointer without transferring ownership.
    * [Bank.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Bank.cpp#L14): `Customer *rawPtr = customer.get();` (returns raw observer pointer to user).

### 🔵 `std::shared_ptr<T>`
Shared ownership. Reference-counted pointer. Cleans up memory when the last owner is destroyed.

* **Usage in Exams**:
  * Shared strategies or lookup instances across multiple entities.
    * [Sensor.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/Sensor.h#L33): `std::shared_ptr<Adjuster> adjuster;` (allows multiple sensors to point to the same calibration logic instance).
    * [NullAdjuster.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/NullAdjuster.h#L15): `static std::shared_ptr<Adjuster> sharedInstance;` (Singleton adjuster).
    * [Product.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/Product.h#L28): `std::shared_ptr<Discount> discount;` (shared discount rules).

### 🔴 Raw Pointers (`T*`)
Observer pointers. They do **not** own the memory. Used to query, link, or invoke functions on objects owned elsewhere.

* **Usage in Exams**:
  * Database query lookups and vector results:
    * `Customer* Bank::lookupCustomer(std::string id) const` returns `it->second.get();`
    * `std::vector<Customer*> Bank::allCustomers() const` returns raw pointers collected from a map of unique pointers.
  * Parent pointers:
    * `virtual void writeCsv(std::ostream& out, const Item* parent)` in `Notebook` exam.

---

## 🖨️ 3. Stream & I/O Operations

### 🔹 Overloading the Stream Insertion Operator (`<<`)
Must be a global function. Allows passing objects directly to printing streams (like `std::cout` or file writing).

* **Syntax**:
  ```cpp
  std::ostream& operator<<(std::ostream& out, const ClassName& obj);
  ```
* **Exam Implementations**:
  * 🏦 **Bank**: Prints formatted customer information.
    * [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L159-L178):
      ```cpp
      std::ostream& operator<<(std::ostream& out, const Customer& customer) {
          out << customer.getId() << ": " << customer.getLastName() << ", " 
              << customer.getFirstName() << " (" << customer.getDateOfBirth().day() << "." ... << ")";
          return out;
      }
      ```
  * ⚡ **Resistor**: Prints general circuit info.
    * [Resistance.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024WiSe_Resistor/myCode/Resistance.cpp#L25-L28):
      ```cpp
      std::ostream& operator<<(std::ostream& out, Resistance& resistor) {
          out << resistor.toString();
          return out;
      }
      ```

### 🔹 Testing with `std::stringstream`
Acts as a stream in memory. Used in tests to verify custom string formatting operations without printing to console.

* **Exam Usage**:
  * [tests.cpp (Bank)](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/tests.cpp#L97-L103):
    ```cpp
    stringstream ss;
    ss << c;
    assertTrue(ss.str() == "0000000001: Angel, Alice, (01.01.1991)", "Operator Overload Failed");
    ```

### 🔹 CSV Deserialization (`std::getline`)
Used to parse values separated by delimiters (like `;` or `,`).

* **General CSV Formatting Pattern**:
  ```cpp
  std::getline(stream, stringVariable, ';'); // reads until delimiter ';'
  std::getline(stream, stringVariable, '\n'); // reads until end of line
  ```
* **Exam Usage**:
  * [ResistanceReader.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024WiSe_Resistor/myCode/ResistanceReader.cpp#L11): `getline(in, line);` reads lines from file one-by-one.
  * [WeeklyCourse.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Lab_3_StudentDb/myCode/WeeklyCourse.cpp#L70-L74): Delimited parsing of course metadata.

---

## ⚠️ 4. Error Handling & Exceptions

Throw exceptions for illegal operations (like bad lookup keys or invalid parameters) using standard header `<stdexcept>`.

| Exception Type | Syntax | Scenario | Exam Usage & Methods |
| :--- | :--- | :--- | :--- |
| **`std::invalid_argument`** | `throw std::invalid_argument("msg");` | Invalid parameters or failed directory searches. | 🚫 [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L134): `Customer::lookupAccount` / `deleteAccount` (account not found).<br>🚫 [Account.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Account.cpp#L52): `Account::accountType` (invalid first digit).<br>🚫 [Shop.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023WiSe_ShoppingList/myCode/Shop.cpp#L33): `Shop::setBasePrice` (product not sold at this shop). |
| **`std::logic_error`** | `throw std::logic_error("msg");` | Valid parameters, but violates logical rules in current state. | 🚫 [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L152): `Customer::deleteAccount` (throwing error if balance is not 0). |
| **Custom Exception** | `class DerivedEx : public std::invalid_argument` | Inheriting standard exceptions to pass contextual arguments. | 🚫 [DuplicateSensorName.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/DuplicateSensorName.cpp#L3): Inherits `std::invalid_argument` and is thrown in `SensorNetwork::add`. |

---

## 🎛️ 5. Key Helper & Mathematical Functions

* **`std::to_string(num)`**: Converts an integer/float value into a `std::string`.
  * Used in [Customer.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2022WiSe_Bank/myCode/Customer.cpp#L22) to convert customer number for padding logic.
* **`std::stol(str)`**: Converts a string containing digits into a `long` value.
  * Hinted in [Note.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024SoSe_Notebook/myCode/Note.h#L71) and [Topic.h](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2024SoSe_Notebook/myCode/Topic.h#L71) to parse IDs during CSV load processes.
* **`std::next(it)`**: Returns the iterator advanced by 1 step.
  * Used in [TableBasedAdjuster.cpp](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/TableBasedAdjuster.cpp#L29) to set up two adjacent iterators for linear interpolation: `auto k_n1 = std::next(k_n);`.
* **`fabs(val)`**: Returns the absolute value of floating point calculations.
  * Used in [tests.cpp (SensorAdjustor)](file:///e:/Abhishek_Git/Cpp_Projects/Exam-2023SoSe_SensorAdjustor/myCode/tests.cpp#L84) to compare float totals safely under precision tolerances: `fabs(adjusted - expected) < 0.0001`.
