# 07 · Sensor Network 🌡️

A C++ exam question bank (2023 Summer Semester) implementing a network of sensors with pluggable adjuster strategies and custom exception handling.

## Class Overview

| Class | Responsibility |
|---|---|
| `Sensor` | Stores readings; applies an `Adjuster` to normalise values |
| `SensorNetwork` | Container of named sensors; enforces unique names |
| `Adjuster` | Abstract strategy base for value adjustment |
| `NullAdjuster` | Identity adjuster — passes values through unchanged |
| `LinearAdjuster` | Applies `y = a·x + b` linear transformation |
| `TableBasedAdjuster` | Piecewise-linear lookup table adjuster |
| `TestSensor` | Sensor subclass that injects fixed test readings |
| `DuplicateSensorName` | Exception thrown when a duplicate name is added |

---

## 🧠 Important Concepts Used & Learnt

### 1. Strategy Pattern
The adjuster algorithm is **injected at runtime** as a `shared_ptr<Adjuster>`. Swapping the adjuster changes the sensor's behaviour without modifying `Sensor` itself:
```cpp
protected:
    std::shared_ptr<Adjuster> adjuster; // holds any Adjuster subclass
```
This is the **Strategy design pattern** — a key OOP pattern for open/closed design.

### 2. `std::shared_ptr<T>` (Shared Ownership)
Multiple sensors could theoretically share the same adjuster instance. `shared_ptr` manages the lifetime automatically via reference counting:
```cpp
Sensor(const std::string& name,
       std::shared_ptr<Adjuster> adjuster = NullAdjuster::sharedInstance);
```

### 3. Singleton-like Shared Instance
`NullAdjuster::sharedInstance` is a static `shared_ptr` — a single shared object used as a default, avoiding repeated allocation for the most common case.

### 4. Pure Virtual `rawReading()` — Template Method Pattern
`Sensor::reading()` calls `rawReading()` (which subclasses implement) and then applies the adjuster. This is the **Template Method pattern**: the base class defines the algorithm skeleton, subclasses fill in one step:
```cpp
virtual float rawReading() const = 0; // subclass provides raw data
virtual float reading() const;        // base class applies adjustment
```

### 5. Custom Exception Class (`DuplicateSensorName`)
A domain-specific exception inherits from `std::exception` (or similar), carrying extra information about which name conflicted:
```cpp
class DuplicateSensorName : public std::exception { ... };
```
This teaches designing meaningful exception hierarchies instead of throwing generic `std::runtime_error`.

### 6. `std::map<std::string, ...>` for Named Lookup
`SensorNetwork` stores sensors keyed by name for O(log n) lookup and enforces uniqueness:
```cpp
// sensors stored in a map: name → sensor pointer
```

### 7. Default Parameter with Smart Pointer
The `Sensor` constructor uses a `shared_ptr` as a **default argument**, making the adjuster optional without overloading:
```cpp
Sensor(const std::string& name,
       std::shared_ptr<Adjuster> adjuster = NullAdjuster::sharedInstance);
```

### 8. Piecewise-Linear Interpolation (`TableBasedAdjuster`)
`TableBasedAdjuster` holds a lookup table and interpolates between points — a numerical algorithm implemented in pure C++.

---

## Marks Breakdown (Exam Total: 84)
| Class | `.cpp` | Tests | Total |
|---|---|---|---|
| DuplicateSensorName | 2 | 0 | 2 |
| LinearAdjuster | 4 | 0 | 4 |
| Sensor | 4 | 12 | 16 |
| SensorNetwork | 11 | 16 | 27 |
| TableBasedAdjuster | 18 | 0 | 18 |
| TestSensor | 5 | 0 | 5 |
| Adjusters (combined) | 0 | 12 | 12 |

## Source
All source files are in [`myCode/`](./myCode/)  
Unit tests: [`myCode/tests.cpp`](./myCode/tests.cpp)

## Reference
See `2023SoSe-APT-1.pdf` for the full exam specification.
