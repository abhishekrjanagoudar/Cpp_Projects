# 10 · Circuit Analyzer ⚡

A C++ exam question bank (2024 Winter Semester) implementing a recursive resistor network calculator with file-based parsing and tolerance-aware resistance values.

## Class Overview

| Class | Responsibility |
|---|---|
| `Resistance` | Abstract base — name, nominal/min/max values, CSV write |
| `Resistor` | Leaf component: single physical resistor |
| `ResistorConnection` | Abstract composite — owns a list of child `Resistance` nodes |
| `SerialResistorConnection` | Sums resistances of children in series |
| `ParallelResistorConnection` | Computes parallel equivalent resistance of children |
| `ResistanceReader` | Parses a text file into a `ResistorConnection` tree |

---

## 🧠 Important Concepts Used & Learnt

### 1. Composite Pattern (Recursive Structure)
`ResistorConnection` is both a `Resistance` (it has a value) **and** a container of `Resistance` children. This recursive structure allows arbitrarily deep nesting:
```cpp
class ResistorConnection : public Resistance {
protected:
    std::list<ResistancePtr> resistors; // children — each may itself be a connection
};
```
Calling `nominalValue()` on a connection automatically recurses into its children.

### 2. `std::unique_ptr<T>` via `typedef` Alias
`ResistancePtr` is a `typedef` for `std::unique_ptr<Resistance>` — a clean alias that makes container declarations readable:
```cpp
typedef std::unique_ptr<Resistance> ResistancePtr;
std::list<ResistancePtr> resistors;
```
Unique ownership ensures children are destroyed when the connection is destroyed.

### 3. `operator+=` for Building the Tree
The composite tree is built incrementally using the compound assignment operator:
```cpp
ResistorConnection& operator+=(ResistancePtr resistor);
```
This enables a fluent, natural API for assembling a circuit from components.

### 4. `operator<<` (Stream Insertion Overload)
`Resistance` defines a free `operator<<` so that any resistor or connection can be printed directly to any `std::ostream`:
```cpp
std::ostream& operator<<(std::ostream& out, Resistance& resistor);
```

### 5. Pure Virtual Value Methods
`nominalValue()`, `minimalValue()`, and `maximumValue()` are all pure virtual in `Resistance` — forcing both `Resistor` and `ResistorConnection` subclasses to implement them with their own formulas:
- **Series**: `nominalValue = Σ child.nominalValue()`
- **Parallel**: `nominalValue = 1 / Σ(1 / child.nominalValue())`

### 6. Tolerance Propagation
Min/max values encode the tolerance band. Serial and parallel connections must correctly propagate tolerances through their formulas — a real numerical challenge.

### 7. `virtual` Method Overriding Across Levels
`ResistorConnection::write()` overrides `Resistance::write()` to recursively write all children before writing itself — demonstrating multi-level virtual dispatch.

### 8. CSV File Parsing (`ResistanceReader`)
The reader parses a CSV file line by line, reconstructing the `Resistance` tree from flat text. This involves:
- String tokenisation (`std::istringstream`, `getline` with delimiter)
- Distinguishing leaf nodes (resistors) from composite nodes (connections) by bracket syntax in the name field

### 9. `std::list<T>` for Ordered Insertion
Children are stored in `std::list<ResistancePtr>` — an ordered sequence that supports efficient front/back insertion without invalidating iterators.

### 10. `virtual char separator()` — Behaviour Variation
`SerialResistorConnection` and `ParallelResistorConnection` override `separator()` to return different delimiter characters (`-` vs `|`), affecting how the connection is serialised to CSV and displayed.

---

## Marks Breakdown (Exam Total: 104)
| Class | `.cpp` | Tests | Total |
|---|---|---|---|
| ParallelResistorConnection | 10 | 10 | 20 |
| Resistance | 11 | 0 | 11 |
| ResistanceReader | 17 | 8 | 25 |
| Resistor | 9 | 5 | 14 |
| ResistorConnection | 17 | 0 | 17 |
| SerialResistorConnection | 9 | 8 | 17 |

## Source
All source files are in [`myCode/`](./myCode/)  
Unit tests: [`myCode/tests.cpp`](./myCode/tests.cpp)  
Sample data: [`data.txt`](./data.txt)

## Reference
See `2024WiSe-APT.pdf` for the full exam specification.
