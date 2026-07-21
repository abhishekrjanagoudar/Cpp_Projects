# 04 · Naval Battle (Battleship) 🚢

A C++ implementation of the classic **Battleship** game with separate grids for the player and opponent.

## Class Overview

| Class | Responsibility |
|---|---|
| `Board` | Abstract base for any grid |
| `OwnGrid` | Tracks player's ships and incoming shots |
| `OpponentGrid` | Tracks shots fired at the opponent, infers hits/misses |
| `Ship` | Represents a ship placement with hit tracking |
| `Shot` | Encapsulates a single shot (position + result) |
| `GridPosition` | Value type for (row, col) grid coordinates |
| `ConsoleView` | Renders both grids to the terminal |

---

## 🧠 Important Concepts Used & Learnt

### 1. `std::set<T>` for Unique Position Tracking
Both `OwnGrid` and `Ship` use `std::set<GridPosition>` to store positions that have been shot at or occupied. `std::set` guarantees uniqueness and O(log n) lookup:
```cpp
std::set<GridPosition> shotAt;       // positions already hit
std::set<GridPosition> occupiedArea() const; // ship's cells
std::set<GridPosition> blockedArea() const;  // ship + surrounding buffer zone
```

### 2. `std::vector<T>` for Ordered Collections
Ships placed on the grid are stored in a `std::vector<Ship>`, allowing iteration and dynamic growth:
```cpp
std::vector<Ship> ships;
```

### 3. `std::map<K,V>` for Frequency/Quota Tracking
`OwnGrid` uses a map to track how many ships of each length are still allowed to be placed:
```cpp
std::map<int,int> totalShip = {{5,1},{4,2},{3,3},{2,4}};
```
This is a clean pattern for enforcing game rules without hard-coded conditionals.

### 4. Operator Overloading (`operator==`, `operator<`)
`GridPosition` and `Ship` implement `operator==` so they can be compared and stored in `std::set` (which requires `operator<`):
```cpp
bool operator==(const Ship& other) const;
```

### 5. `const` Member Functions
Query methods like `getBow()`, `getStern()`, `length()`, `occupiedArea()` are all `const` — they promise not to modify the object, enabling use in const contexts.

### 6. Value Types vs. Reference Types
`GridPosition` is a **value type** (small, copyable, stored by value). `Ship` is passed by `const&` to avoid copying. This distinction is fundamental to efficient C++ design.

### 7. Abstract Base Class
`Board` is an abstract base class providing a common interface. Both `OwnGrid` and `OpponentGrid` specialise it — classic polymorphism enabling the `ConsoleView` to work with either grid type.

### 8. Scoped Enum / Impact Type
Shot results (MISS, HIT, DESTROYED) are represented with an enum `Impact`, demonstrating typed return values from game logic methods.

---

## Source
All source files are in [`myCode/`](./myCode/)

## Reference
See `Lab2.pdf` for the full assignment specification.
