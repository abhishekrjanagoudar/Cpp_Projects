# 02 · Modulo-N Counter 🔢

A focused C++ exercise on designing a **configurable modulo counter** from scratch.

## Class Overview

| Class | Responsibility |
|---|---|
| `ModuloNDigit` | Single digit that wraps at modulus N |
| `ModuloNCounter` | Multi-digit counter built from an array of `ModuloNDigit` |

---

## 🧠 Important Concepts Used & Learnt

### 1. Dynamic Memory Allocation (`new` / `delete[]`)
The counter stores its digits on the heap using a raw pointer to a dynamic array:
```cpp
ModuloNDigit* counter; // pointer to heap-allocated array
// In constructor:
counter = new ModuloNDigit[noOfDigits];
// In destructor:
delete[] counter;
```
This is the classic manual memory management pattern — the foundation before learning smart pointers.

### 2. Copy Constructor (Deep Copy)
Because the class owns heap memory, the compiler-generated copy constructor would do a **shallow copy** (copy the pointer, not the data). A custom copy constructor is required:
```cpp
ModuloNCounter(const ModuloNCounter& other); // must deep-copy the array
```
This illustrates the **Rule of Three**: if you write a destructor, you must also write a copy constructor and copy assignment operator.

### 3. Destructor Responsibility
The destructor must explicitly `delete[]` the array to avoid memory leaks — one of the most fundamental concepts in C++ resource management.

### 4. Enums & State Representation
Simple `int` fields encode the counter's range and digit count — straightforward state modelling without overhead.

### 5. Carry Propagation Algorithm
`increment()` propagates a carry from the least-significant digit upward — an algorithmic pattern mirroring how binary/decimal addition works.

### 6. `const` Correctness
Accessor methods should be marked `const` to signal they do not modify object state — a discipline enforced throughout the course.

---

## Source
All source files are in [`myCode/`](./myCode/)

## Reference
See `Lab1.pdf` for the full assignment specification.
