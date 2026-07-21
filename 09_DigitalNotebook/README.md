# 09 · Digital Notebook 📓

A C++ exam question bank (2024 Summer Semester) implementing a hierarchical notebook structure with CSV serialisation and tree-like ownership.

## Class Overview

| Class | Responsibility |
|---|---|
| `Notebook` | Top-level container of topics; CSV read/write entry point |
| `Topic` | Groups related notes under a named heading |
| `Note` | A named note belonging to a topic; owns items |
| `Item` | Leaf node — a single text entry inside a note |

---

## 🧠 Important Concepts Used & Learnt

### 1. Composite Pattern
The hierarchy `Notebook → Topic → Note → Item` is a textbook **Composite pattern**: both containers (`Topic`) and leaves (`Note`, `Item`) implement the same `Item` interface, enabling uniform recursive traversal:
```cpp
class Topic : public Item {
    std::vector<std::unique_ptr<Item>> items; // holds any Item subclass
};
```

### 2. `std::unique_ptr<T>` (Exclusive Ownership)
Each parent **owns** its children exclusively via `unique_ptr` — when a `Topic` is destroyed, all its children are automatically destroyed too. No manual `delete`:
```cpp
std::vector<std::unique_ptr<Item>> items;
void add(std::unique_ptr<Item>& item);
void add(std::unique_ptr<Item>&& item); // rvalue overload for move
```

### 3. Move Semantics with `unique_ptr`
Since `unique_ptr` cannot be copied, items are transferred into the container via **move**:
```cpp
void add(std::unique_ptr<Item>&& item); // rvalue ref: takes ownership
```
This is a practical encounter with C++11 move semantics in a real data structure.

### 4. Polymorphism Through Base Pointer
`Topic::getItems()` returns `std::vector<const Item*>` — callers get pointers to the base class and call virtual methods without knowing the concrete type:
```cpp
virtual std::vector<const Item*> getItems() const;
```

### 5. Recursive Tree Traversal
`printItem()` and `writeCsv()` both recurse through the tree. Each node prints itself then calls the same method on its children — a foundational recursive algorithm:
```cpp
void printItem(std::ostream& out, int indent) const; // indent grows with depth
```

### 6. CSV Serialisation with `std::map` for Reconstruction
`fromCsv()` uses a `std::map<long, Topic*>` to rebuild the parent-child relationships while reading line by line — each line carries its own ID and parent ID:
```cpp
static bool fromCsv(std::map<long, Topic*>& topics, std::string line);
```
This is a non-trivial **ID-based tree reconstruction** from flat CSV data.

### 7. Static Factory Method
`Notebook::loadFromCsv(std::istream& in)` is a **static factory** — it reads from a stream and constructs a fully populated `Notebook`:
```cpp
static Notebook* loadFromCsv(std::istream& in);
```

### 8. Slicing Problem Awareness
The implementation notes warn that CSV loading creates `Topic` objects when the first line should be a `Notebook`. Fixing this requires accessing the pointer in the ID map and replacing it — a deep lesson in object slicing and dynamic type identity.

### 9. Indentation in Recursive Output
The `indent` parameter grows by a fixed amount at each recursion level, producing visually nested output — a simple but illustrative example of passing state through recursion.

---

## Marks Breakdown (Exam Total: 97)
| Class | `.cpp` | Tests | Total |
|---|---|---|---|
| Item | 6 | 0 | 6 |
| Note | 17 | 6 | 23 |
| Notebook | 18 | 10 | 28 |
| Topic | 25 | 15 | 40 |

## Source
All source files are in [`myCode/`](./myCode/)  
Unit tests: [`myCode/tests.cpp`](./myCode/tests.cpp)

## Reference
See `2024SoSe-APT.pdf` for the full exam specification.
