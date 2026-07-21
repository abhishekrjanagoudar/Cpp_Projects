# 08 · Shopping Engine 🛒

A C++ exam question bank (2023 Winter Semester) modelling a shop database with discount rules, shopping lists, and price evaluation logic.

## Class Overview

| Class | Responsibility |
|---|---|
| `Shop` | Catalogue of products with associated discounts |
| `ShopDb` | Registry of multiple shops; lookup by name |
| `ShoppingList` | A customer's list of items to purchase |
| `Product` | Named product with a base unit price |
| `Item` | Line item: product + quantity in a shopping list |
| `Discount` | Abstract base for discount strategies |
| `NoDiscount` | Null discount — full price always |
| `FixedDiscount` | Subtracts a flat amount from the total |
| `QuantityDiscount` | Applies a percentage above a quantity threshold |

---

## 🧠 Important Concepts Used & Learnt

### 1. Strategy Pattern (Discount Algorithms)
`Discount` is a pure abstract class with a single method. Any concrete discount is a **swappable strategy**:
```cpp
class Discount {
public:
    virtual float discountFor(float quantity) const = 0;
    virtual ~Discount();
};
```
`Shop` stores a `Discount*` per product — swap the pointer, swap the pricing rule.

### 2. Null Object Pattern (`NoDiscount`)
Instead of checking for `nullptr` before applying a discount, a `NoDiscount` object always returns `0.0` — eliminating null checks throughout the codebase. This is the **Null Object pattern**.

### 3. Policy/Business Rule Modelling
`QuantityDiscount` encodes a threshold + percentage in a single object:
```cpp
// discount = percentage only when quantity >= threshold
float discountFor(float quantity) const override;
```
This pattern separates business rules from their consumers, making rules independently changeable and testable.

### 4. Pure Virtual Destructor Pattern
`Discount::~Discount()` is `virtual` (though not pure) — critical in any polymorphic hierarchy to ensure derived destructors are called through a base pointer:
```cpp
virtual ~Discount(); // must be virtual for correct destruction via Discount*
```

### 5. Association vs. Ownership
`Shop` holds references/pointers to `Product` and `Discount` objects — it **associates** with them without owning them. `ShoppingList` **owns** its `Item` objects. Understanding this distinction drives memory management decisions.

### 6. Database-Style Lookup (`ShopDb`)
`ShopDb` acts as a repository of shops keyed by name — the **Repository pattern**. Lookup by string key uses `std::map` for efficient retrieval.

### 7. Aggregation via `std::vector`
`ShoppingList` accumulates `Item` objects in a `std::vector`, then can compute total price by iterating and summing discounted line totals.

### 8. Separation of Pricing Logic
Price calculation happens in `Item` (unit price × quantity × (1 - discount)) rather than in `ShoppingList` or `Shop` — each class computes only what it owns.

---

## Marks Breakdown (Exam Total: 81)
| Class | `.cpp` | Tests | Total |
|---|---|---|---|
| Product | 2 | 0 | 2 |
| QuantityDiscount | 6 | 8 | 14 |
| Shop | 22 | 5 | 27 |
| ShopDb | 9 | 7 | 16 |
| ShoppingList | 4 | 12 | 16 |
| FixedDiscount | 0 | 6 | 6 |

## Source
All source files are in [`myCode/`](./myCode/)  
Unit tests: [`myCode/tests.cpp`](./myCode/tests.cpp)

## Reference
See `2023WiSe-APT.pdf` for the full exam specification.
