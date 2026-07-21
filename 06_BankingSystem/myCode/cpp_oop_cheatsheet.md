# C++ OOP Cheat Sheet — Exam Prep

---

## 1. Classes & Objects

```cpp
// Declaration (.h)
class Account {
public:
    Account(int id, double balance);   // constructor
    ~Account();                         // destructor
    double getBalance() const;          // const = doesn't modify object
    static int count;                   // shared across all instances
    virtual void print() const;         // overridable
    virtual double fee() const = 0;     // pure virtual → makes class abstract

private:
    int id_;
    double balance_;
};

// Definition (.cpp)
Account::Account(int id, double balance)
    : id_(id), balance_(balance) {}     // ← initializer list (preferred)

Account::~Account() {}                  // destructor

double Account::getBalance() const { return balance_; }

int Account::count = 0;                 // static member init outside class
```

**Key Rules:**
- `const` after `()` → method won't change member variables
- Pure virtual `= 0` → **must** be overridden in derived class
- Abstract class → cannot be instantiated directly
- Always add **virtual destructor** in base class

---

## 2. Inheritance & Polymorphism

```cpp
class SavingsAccount : public Account {     // public inheritance
public:
    SavingsAccount(int id, double bal, double rate)
        : Account(id, bal), rate_(rate) {}  // call base constructor

    double fee() const override {
        return getBalance() * rate_;  // use getter! balance_ is private in base
    }
    // override = compiler verifies you're actually overriding a virtual

private:
    double rate_;
};

// Polymorphism: base pointer → calls derived method
Account* acc = new SavingsAccount(1, 500.0, 0.02);
acc->fee();   // calls SavingsAccount::fee() ← dynamic dispatch

// dynamic_cast: safely downcast
SavingsAccount* sa = dynamic_cast<SavingsAccount*>(acc);
if (sa) { /* cast succeeded */ }
```

---

## 3. Memory Management

```cpp
// Raw pointer (manual, error-prone)
Account* a = new SavingsAccount(1, 100);
delete a;   // YOU must free it

// unique_ptr — single owner, auto-deleted
auto acc = std::make_unique<SavingsAccount>(1, 100.0, 0.02);
acc->getBalance();          // use like a pointer

// Get raw (observer) pointer — no ownership transfer
Account* raw = acc.get();   // acc still owns it

// Transfer ownership (acc becomes null after this)
accounts[id] = std::move(acc);

// shared_ptr — multiple owners, ref-counted
auto shared = std::make_shared<SavingsAccount>(2, 200.0, 0.01);

// nullptr — modern C++ null (NOT NULL)
Account* acc = nullptr;   // preferred over NULL or 0
```

**Smart Pointer Ownership Table:**

| Pointer | Ownership | Can Copy? |
|---|---|---|
| `raw pointer` | none (observer) | yes |
| `unique_ptr` | single owner | NO — must `std::move()` |
| `shared_ptr` | shared (ref-counted) | yes |

**Deleted Copy (critical with unique_ptr):**
```cpp
class Bank {
public:
    Bank(const Bank&) = delete;             // no copy constructor
    Bank& operator=(const Bank&) = delete;  // no copy assignment
    // Why: Bank contains unique_ptr members — copying is impossible
};
```

**Ownership Pattern (Bank Project):**
```cpp
// Manager owns via unique_ptr in map
std::map<std::string, std::unique_ptr<Account>> accounts_;

// Lookup returns raw observer pointer
Account* find(const std::string& id) {
    auto it = accounts_.find(id);
    if (it == accounts_.end()) return nullptr;  // not found
    return it->second.get();                    // raw ptr, no ownership
}
```

---

## 4. STL Containers

```cpp
// vector
std::vector<int> v;
v.push_back(42);              // copy into vector
v.emplace_back(42);           // construct in-place (faster, modern)
v.erase(v.begin() + 1);       // erase by index

// map (sorted key-value)
std::map<std::string, int> m;
m["key"] = 10;                 // insert/update (CREATES if missing!)
m.insert({"key", 10});         // insert only if key not present
m.emplace("key", 10);          // construct in-place, only if not present
auto it = m.find("key");
if (it != m.end()) {
    it->first;   // key
    it->second;  // value
}

// Range-based loop
for (const auto& [key, val] : m) { /* ... */ }
for (const auto& elem : v)       { /* ... */ }

// set (unique sorted elements)
std::set<int> s;
s.insert(5);
s.count(5);   // 1 if exists, 0 if not
```

**⚠️ [] vs find() — Classic Exam Trap:**
```cpp
m["x"];        // DANGER: creates entry with default value if "x" missing!
m.find("x");   // safe: only searches, never inserts

// Rule: always use find() when you only want to check existence
```

---

## 5. Exception Handling

```cpp
#include <stdexcept>

void deposit(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Amount must be positive");
    if (amount > limit_)
        throw std::logic_error("Exceeds limit");
    balance_ += amount;
}

// Caller:
try {
    acc->deposit(-50);
} catch (const std::invalid_argument& e) {
    std::cerr << e.what();
} catch (const std::exception& e) {   // catch-all base
    std::cerr << e.what();
}
```

---

## 6. File Structure

```
Account.h    <- declarations only
Account.cpp  <- definitions (includes Account.h)
main.cpp     <- includes Account.h
```

```cpp
// Account.h
#ifndef ACCOUNT_H      // include guard
#define ACCOUNT_H

class Customer;        // forward declaration (avoids circular include)

class Account {
    Customer* owner_;  // pointer/ref -> forward decl is enough
};

#endif
```

**Rule:** Only `#include` in `.h` what you **use in declarations**. Everything else goes in `.cpp`.

---

## 7. Bank Project Patterns

```cpp
// ID generation with zero-padding
std::string generateId(int num) {
    std::string s = std::to_string(num);          // "3"
    return std::string(4 - s.size(), '0') + s;    // "0003"
}

// Storing polymorphic object in map
accounts_[id] = std::make_unique<SavingsAccount>(id, 0.0, 0.02);

// Creating and linking Customer -> Account
auto cust = std::make_unique<Customer>(custId, name);
Customer* custPtr = cust.get();           // observer ptr
customers_[custId] = std::move(cust);    // map owns it
custPtr->addAccount(acc.get());           // link raw ptr

// Enum for account type
enum class AccountType { Savings, Checking, Loan };
// enum class = scoped enum: names don't leak into surrounding scope
// AccountType::Savings  ← must qualify with type name (safer!)
// OLD enum: Savings alone works → name collision risk

AccountType type = AccountType::Savings;
if (type == AccountType::Savings) { /* ... */ }
```

---

## 8. Operator Overloading & friend

```cpp
class Money {
    double amount_;
public:
    Money operator+(const Money& other) const {
        return Money(amount_ + other.amount_);
    }
    // friend: allows external function access to private members
    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        return os << m.amount_;
    }
};
```

---

## 9. Reference vs Pointer

```cpp
int x = 5;

int* p = &x;    // pointer: can be null, can be reassigned, needs *p to access
int& r = x;     // reference: alias for x, cannot be null, cannot be reseated

*p = 10;        // dereference to write
r  = 10;        // works directly like x

// const reference parameter — avoids copying (very common pattern)
void print(const std::string& name);   // read-only, no copy made
void bad(std::string name);            // copies the whole string!
```

**Rule:** Use `const T&` for large objects you don't need to modify. Use `T*` when null is a valid state.

---

## 10. Access Specifiers

| Keyword | Accessible from |
|---|---|
| `private` | inside the class only |
| `protected` | class + derived classes |
| `public` | everywhere |

```cpp
class Base {
private:   int a_;   // only Base can use
protected: int b_;   // Base + Derived can use
public:    int c_;   // anyone can use
};
```

---

## 11. vtable & Linker Note

```cpp
// virtual functions create a hidden vtable per class
// vtable maps function calls to the correct derived implementation at runtime

// COMMON LINKER ERROR:
// "undefined reference to vtable for Account"
// CAUSE: declared a virtual function but forgot to DEFINE it (even the destructor)

// Fix: always define every declared virtual function, even if empty:
virtual ~Account() {}   // not just declared — defined!
```

---

## 12. Lambda (Modern C++)

```cpp
// Lambda syntax: [capture](params) { body }
auto add = [](int a, int b) { return a + b; };
add(3, 4);  // → 7

// Sort with custom comparator
std::sort(v.begin(), v.end(),
    [](int a, int b) {
        return a < b;   // ascending
    });

// Capture local variable by reference
int limit = 100;
auto overLimit = [&limit](int val) { return val > limit; };
```

---

## 13. Quick Reference: this pointer

```cpp
class Foo {
    int val_;
public:
    void set(int val_) {
        this->val_ = val_;  // disambiguates member vs param with same name
    }
    Foo& doSomething() {
        /* ... */
        return *this;       // enables method chaining: foo.a().b().c()
    }
};
```

---

## 14. Common Exam Pitfalls

| Mistake | Fix |
|---|---|
| Forgot `virtual` destructor in base | Always add `virtual ~Base() {}` |
| Slicing: `Base b = derived` | Use `Base*` or `Base&` instead |
| Copying `unique_ptr` | Use `std::move()` to transfer |
| `find()` not checked | Always compare to `.end()` |
| Missing `override` keyword | Add `override` — catches typos |
| Not initializing static member | Define outside class: `int Cls::x = 0;` |
| Circular `#include` | Use forward declaration in `.h` |
| Accessing private base member directly | Use the getter (`getBalance()`) |
| `m["x"]` to check existence | Use `m.find("x") != m.end()` |
| `NULL` instead of `nullptr` | Use `nullptr` in modern C++ |
| Class with `unique_ptr` copied | Delete copy constructor and `operator=` |
| Virtual function declared, not defined | Linker error: "undefined reference to vtable" |
