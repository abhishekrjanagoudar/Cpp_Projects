# 01 · Thermal Control System 🌡️

A C++ implementation of a heat control system built around **composition and delegation** patterns.

## Class Overview

| Class | Responsibility |
|---|---|
| `HeatController` | Central coordinator — delegates to all subsystems |
| `Controller` | Abstract base for control logic |
| `CoolingSystem` | Manages the cooling actuator |
| `HeatingSystem` | Manages the heating actuator |
| `Thermostat` | Reads and applies temperature setpoints |
| `TemperatureSensor` | Provides raw temperature readings |
| `PowerManagement` | Handles power state transitions |
| `UserInterface` | Exposes settings/status to the user |

---

## 🧠 Important Concepts Used & Learnt

### 1. Composition (Has-A Relationship)
`HeatController` owns all subsystem objects **as direct members** (not pointers), so their lifetimes are tied to the controller. This is **composition** — the strongest form of aggregation.
```cpp
// All subsystems are value members — created and destroyed with HeatController
PowerManagement powerManagement = PowerManagement(240, 10);
HeatingSystem   heatingSystem   = HeatingSystem(&powerManagement);
CoolingSystem   coolingSystem   = CoolingSystem(&powerManagement);
```

### 2. In-Class Member Initialisation
C++11 allows members to be initialised directly at the point of declaration, making constructors cleaner:
```cpp
PowerManagement powerManagement = PowerManagement(240, 10); // in-class init
```

### 3. Passing `this`-Object's Members by Address
Subsystems that need to share `PowerManagement` state receive a raw pointer to the already-constructed member:
```cpp
UserInterface userInterface = UserInterface(&powerManagement);
```
This demonstrates **pointer-as-dependency-injection** without dynamic allocation.

### 4. Single Responsibility Principle (SRP)
Each class handles exactly one domain concern (heating, cooling, sensing, UI). `HeatController` only **orchestrates** — it never contains heating/cooling logic itself.

### 5. Constructor Chaining & Initialisation Order
Member objects are constructed in **declaration order**, which is why `PowerManagement` must be declared before the objects that depend on it.

### 6. Destructor Basics
Because members are value types, the compiler-generated destructor chain is sufficient — no manual `delete` needed.

---

## Source
All source files are in [`myCode/`](./myCode/)

## Reference
See `Lab1.pdf` for the full assignment specification.
