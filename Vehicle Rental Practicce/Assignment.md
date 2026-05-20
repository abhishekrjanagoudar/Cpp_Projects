# C++ OOP + STL + Smart Pointer Practice Assignment
## 🚗 Vehicle Rental Management System

You will build a small OOP project using:
- classes
- STL containers
- smart pointers
- .h/.cpp
- constructors
- maps/vectors/sets/lists
- object interaction

## 📁 File Structure
- `Vehicle.h`
- `Vehicle.cpp`
- `Customer.h`
- `Customer.cpp`
- `RentalSystem.h`
- `RentalSystem.cpp`
- `main.cpp`

## 🎯 Main Goal

System should:
- store vehicles
- store customers
- track rentals
- manage unique IDs
- use STL containers
- use smart pointers

---

## 🔥 CLASS 1 — Vehicle
**Purpose:** Represents one vehicle in rental system.

**Example:**
- Car
- Bike
- Truck

**File:** `Vehicle.h`

### Attributes (Private)
1. **Vehicle ID**
   ```cpp
   int vehicleId;
   ```
   Unique ID for vehicle.

2. **Vehicle Name**
   ```cpp
   std::string vehicleName;
   ```
   Example: BMW, Tesla, Honda

3. **Rental Status**
   ```cpp
   bool isRented;
   ```
   Tracks whether vehicle is rented.

### Methods (Public)
- **Constructor**
  ```cpp
  Vehicle(int id, const std::string& name);
  ```
  Purpose: initialize vehicle object

- **display()**
  ```cpp
  void display() const;
  ```
  Purpose: print vehicle details

- **rentVehicle()**
  ```cpp
  void rentVehicle();
  ```
  Purpose: mark vehicle as rented

- **returnVehicle()**
  ```cpp
  void returnVehicle();
  ```
  Purpose: mark vehicle as available

- **getId()**
  ```cpp
  int getId() const;
  ```
  Purpose: return vehicle ID

- **getName()**
  ```cpp
  std::string getName() const;
  ```
  Purpose: return vehicle name

- **getRentalStatus()**
  ```cpp
  bool getRentalStatus() const;
  ```
  Purpose: return rental status

---

## 🔥 CLASS 2 — Customer
**Purpose:** Represents customer renting vehicles.

**File:** `Customer.h`

### Attributes (Private)
1. **Customer ID**
   ```cpp
   int customerId;
   ```

2. **Customer Name**
   ```cpp
   std::string customerName;
   ```

3. **Rented Vehicle IDs**
   ```cpp
   std::vector<int> rentedVehicles;
   ```
   Purpose: store rented vehicle IDs

   Practice:
   - vector insertion
   - iteration
   - erase

### Methods (Public)
- **Constructor**
  ```cpp
  Customer(int id, const std::string& name);
  ```

- **display()**
  ```cpp
  void display() const;
  ```
  Print customer details.

- **addRental()**
  ```cpp
  void addRental(int vehicleId);
  ```
  Add rented vehicle ID into vector.

- **removeRental()**
  ```cpp
  void removeRental(int vehicleId);
  ```
  Remove vehicle from vector.

- **getId()**
  ```cpp
  int getId() const;
  ```

---

## 🔥 CLASS 3 — RentalSystem
**Purpose:** Main system manager.

Controls:
- vehicles
- customers
- rentals

**File:** `RentalSystem.h`

### Attributes (Private)
1. **Vehicles Container**
   ```cpp
   std::vector<Vehicle> vehicles;
   ```
   Purpose: store all vehicles
   
   Practice:
   - push_back
   - erase
   - loops

2. **Customers Container**
   ```cpp
   std::map<int, Customer> customers;
   ```
   Meaning: `customerId` → `Customer` object
   
   Practice:
   - insert
   - find
   - erase
   - update

3. **Active Rental IDs**
   ```cpp
   std::set<int> activeRentals;
   ```
   Purpose: store currently rented vehicle IDs, prevent duplicates
   
   Practice:
   - insert
   - erase
   - find

4. **Rental History**
   ```cpp
   std::list<std::string> rentalHistory;
   ```
   Purpose: store rental log history
   Example: `"Customer 1 rented BMW"`
   
   Practice:
   - push_back
   - push_front
   - iteration

5. **Smart Pointer Practice**
   - **unique_ptr**
     ```cpp
     std::unique_ptr<Vehicle> featuredVehicle;
     ```
     Purpose: one exclusive featured vehicle
     
     Practice:
     - make_unique
     - ->
     - ownership
     
   - **shared_ptr**
     ```cpp
     std::shared_ptr<Customer> vipCustomer;
     ```
     Purpose: shared VIP customer access
     
     Practice:
     - make_shared
     - use_count
     - copying shared ownership

### Methods (Public)
- **Constructor**
  ```cpp
  RentalSystem();
  ```
  Initialize smart pointers.

- **addVehicle()**
  ```cpp
  void addVehicle(const Vehicle& v);
  ```
  Purpose: add vehicle into vector

- **addCustomer()**
  ```cpp
  void addCustomer(const Customer& c);
  ```
  Purpose: insert customer into map

- **rentVehicle()**
  ```cpp
  void rentVehicle(int customerId, int vehicleId);
  ```
  Purpose: assign vehicle to customer, update all containers
  
  Practice:
  - map find
  - set insert
  - vector update
  - list push_back

- **returnVehicle()**
  ```cpp
  void returnVehicle(int customerId, int vehicleId);
  ```
  Purpose: return rented vehicle
  
  Practice:
  - erase operations

- **displayVehicles()**
  ```cpp
  void displayVehicles() const;
  ```
  Display all vehicles.

- **displayCustomers()**
  ```cpp
  void displayCustomers() const;
  ```
  Display all customers.

- **displayRentalHistory()**
  ```cpp
  void displayRentalHistory() const;
  ```
  Display list contents.

- **displayVIP()**
  ```cpp
  void displayVIP() const;
  ```
  Display shared_ptr customer details.

---

## 🔥 REQUIRED STL PRACTICE
- **VECTOR**: Use `push_back`, `erase`, `size`, `loops`
- **MAP**: Use `insert`, `find`, `erase`, `[]`
- **SET**: Use `insert`, `find`, `erase`, `duplicate prevention`
- **LIST**: Use `push_back`, `push_front`, `insert`, `remove`

## 🔥 REQUIRED SMART POINTER PRACTICE
- **unique_ptr**: Practice `make_unique`, `->`, `ownership`
- **shared_ptr**: Practice `make_shared`, `copy ownership`, `use_count`

## 🔥 REQUIRED CONCEPTS
You MUST practice:
- Constructor ✅
- Destructor ✅
- Getter functions ✅
- const methods ✅
- initializer list ✅
- STL iteration ✅
- smart pointers ✅
- .h/.cpp separation ✅
- access specifiers ✅

---

## 🔥 BONUS TASKS
- **BONUS 1**: Create `vector<shared_ptr<Customer>>`
- **BONUS 2**: Use iterator loops everywhere.
- **BONUS 3**: Create search functions (search vehicle, search customer)

## 🔥 FINAL OUTPUT SHOULD SHOW
- Vehicle added
- Customer added
- Vehicle rented
- Vehicle returned
- Rental history
- VIP customer
- Smart pointer count

## 🔥 What This Assignment Teaches
After completing:
- real OOP flow
- STL usage
- container interaction
- smart pointers
- ownership concepts
- object communication
- exam preparation
- project structure
