# C++ Syntax Cheat Sheet 📚

## 1. Classes & Objects

```cpp
class MyClass {
private:
    int value;

public:
    MyClass();              // Constructor
    ~MyClass();             // Destructor
    void doSomething();
    int getValue() const;
};
```

**Access Modifiers:**
- `public` - anyone can use
- `private` - only this class
- `protected` - this class + subclasses

---

## 2. Constructors

```cpp
// Default constructor
MyClass() { value = 0; }

// Parameterized constructor
MyClass(int v) { value = v; }

// Initializer list (preferred)
MyClass(int v) : value(v) { }
```

---

## 3. Pointers

```cpp
int x = 42;
int* ptr = &x;          // & = address-of
cout << *ptr;           // * = dereference

MyClass* obj = new MyClass();
obj->getValue();        // -> for pointers
delete obj;             // Free memory
obj = nullptr;
```

---

## 4. Smart Pointers

```cpp
#include <memory>

std::unique_ptr<MyClass> p1(new MyClass());
// Automatic cleanup, cannot be copied

std::shared_ptr<MyClass> p2(new MyClass());
// Multiple owners allowed
```

---

## 5. Methods

**Header (.h):**
```cpp
class MyClass {
public:
    void myMethod();
    int getValue() const;
};
```

**Implementation (.cpp):**
```cpp
void MyClass::myMethod() {
    // code here
}

int MyClass::getValue() const {
    return value;
}
```

**const methods** = cannot modify members

---

## 6. Inheritance

```cpp
class Parent {
public:
    virtual void print() { }
};

class Child : public Parent {
public:
    void print() override { }
};
```

---

## 7. Vector

```cpp
#include <vector>

std::vector<int> v;
v.push_back(5);         // Add
v.pop_back();           // Remove last
cout << v[0];           // Access
v.size();               // Length
```

---

## 8. Map

```cpp
#include <map>

std::map<std::string, int> m;
m["key"] = 10;          // Insert/update
cout << m["key"];       // Lookup

for (auto& pair : m) {
    cout << pair.first << pair.second;
}
```

---

## 9. Set

```cpp
#include <set>

std::set<int> s;
s.insert(5);
s.erase(5);
cout << s.size();
```

---

## 10. Exceptions

```cpp
// Throw
if (x < 0) {
    throw std::invalid_argument("Bad value");
}

// Catch
try {
    doSomething();
}
catch (const std::invalid_argument& e) {
    cout << e.what();
}
```

---

## 11. Loops

```cpp
// For loop
for (int i = 0; i < 10; i++) { }

// Range-based loop
for (auto& item : container) { }

// While loop
while (condition) { }
```

---

## 12. Strings

```cpp
#include <string>

std::string s = "hello";
s.length();
s.substr(0, 2);
std::to_string(42);     // int to string
```

---

## 13. Output

```cpp
#include <iostream>
#include <iomanip>

cout << "text" << endl;
cout << std::fixed << std::setprecision(2) << 3.14;
cout << std::setw(10) << "padded";
```

---

## 14. Enum

```cpp
enum Color { RED, GREEN, BLUE };

Color c = RED;
switch (c) {
    case RED: cout << "Red"; break;
}
```

---

## 15. File I/O

```cpp
#include <fstream>

// Write
std::ofstream out("file.txt");
out << "Hello";
out.close();

// Read
std::ifstream in("file.txt");
std::string line;
while (std::getline(in, line)) { }
```

---

## Quick Syntax

| What | Syntax |
|-----|--------|
| Class | `class Name { };` |
| Object | `Name obj;` |
| Pointer | `Name* ptr = new Name();` |
| Delete | `delete ptr;` |
| Method | `void doIt() { }` |
| Const | `int get() const { }` |
| Vector | `std::vector<T> v;` |
| Map | `std::map<K, V> m;` |
| Throw | `throw std::exception();` |
| Try-Catch | `try { } catch { }` |
