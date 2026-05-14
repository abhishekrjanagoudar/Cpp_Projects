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

**Constructor:** A special member function that is automatically called when an object is created. Used to initialize objects.

**Syntax**
```cpp
class ClassName {
public:
    ClassName() {
        // initialization
    }
};
```

### Types of Constructors

**1. Default Constructor**
No parameters.

**Syntax**
```cpp
ClassName() {}
```

**Example**
```cpp
class Car {
public:
    Car() {
        cout << "Car created";
    }
};
```

**2. Parameterized Constructor**
Takes parameters.

**Syntax**
```cpp
ClassName(dataType value) {}
```

**Example**
```cpp
class Car {
public:
    int speed;

    Car(int s) {
        speed = s;
    }
};
```

**3. Copy Constructor**
Creates object by copying another object.

**Syntax**
```cpp
ClassName(const ClassName &obj) {}
```

**Example**
```cpp
class Car {
public:
    int speed;

    Car(int s) {
        speed = s;
    }

    Car(const Car &c) {
        speed = c.speed;
    }
};
```

---

## 3. Pointers

**Pointer:** A pointer stores the memory address of another variable.

**Syntax**
```cpp
dataType *pointerName;
```

**Example**
```cpp
int x = 10;
int *ptr = &x;

cout << x;      // 10
cout << &x;     // address of x
cout << ptr;    // address of x
cout << *ptr;   // value at address = 10
```

**Important Symbols**

| Symbol | Meaning |
|--------|---------|
| `&`    | Address of variable |
| `*`    | Value at address (dereference) |

**Pointer with Arrays**
```cpp
int arr[3] = {1,2,3};

int *ptr = arr;

cout << *ptr;      // 1
cout << *(ptr+1);  // 2
```

**Object Pointers (Dynamic Memory)**
```cpp
MyClass* obj = new MyClass();
obj->getValue();        // -> for pointers
delete obj;             // Free memory
obj = nullptr;
```

**The `this` Pointer**
`this` is a special pointer that stores the address of the current object. Used inside class member functions.

**Syntax**
```cpp
this->variableName
```

**Example**
```cpp
class Student {
public:
    int age;

    Student(int age) {
        this->age = age;  // Left age - Class Age , Right age - Parameterized
    }

    void display() {
        cout << this->age;
    }
};
```

**Key Points**
- Pointer stores address
- `*ptr` &rarr; value
- `&x` &rarr; address
- Used in dynamic memory, arrays, functions, OOPs

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

---

## 16. Lab 1 Syntax Additions

### Virtual and Override
```cpp
class Base {
public:
    virtual void print() = 0;
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void print() override;
};
```

### Rule of Three / Five
```cpp
class Example {
public:
    Example();
    Example(const Example& other);
    Example(Example&& other);
    Example& operator=(const Example& other);
    Example& operator=(Example&& other);
    ~Example();
};
```

### Arrays and Loops
```cpp
for (int row = 0; row < 8; ++row) {
    for (int col = 0; col < 8; ++col) {
    }
}

for (int index = size - 1; index >= 0; --index) {
}
```

### References and `this`
```cpp
void setValue(const std::string& value) {
    this->value = value;
}
```

---

## 17. Lab 2 Syntax Additions

### Value Types
```cpp
class GridPosition {
public:
    GridPosition(char row, int column);
    char getRow() const;
    int getColumn() const;
    bool operator==(const GridPosition& other) const;
};
```

### Enum and Switch
```cpp
enum Impact { NONE, HIT, SUNKEN };

switch (impact) {
case NONE:
    break;
case HIT:
    break;
case SUNKEN:
    break;
}
```

### Set and Map Usage
```cpp
std::set<GridPosition> positions;
std::map<GridPosition, Shot> shots;

positions.insert(GridPosition('A', 1));
shots[GridPosition('A', 1)] = Shot(GridPosition('A', 1), HIT);
```

### STL Algorithms
```cpp
std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
std::includes(container.begin(), container.end(), subset.begin(), subset.end());
```

### Range-Based Loop
```cpp
for (const auto& ship : ships) {
}
```

---

## 18. Lab 3 Syntax Additions

### Abstract Base Class
```cpp
class Course {
public:
    virtual ~Course() = 0;
    virtual void write(std::ostringstream& os) const = 0;
    virtual void read(std::istringstream& is) = 0;
    virtual std::string getCourseDetail() const = 0;
};
```

### Inheritance with Constructors
```cpp
class WeeklyCourse : public Course {
public:
    WeeklyCourse(unsigned int courseKey, std::string title, std::string major,
                 float creditPoints, Poco::DateTime::DaysOfWeek dayOfWeek,
                 Poco::Data::Time startTime, Poco::Data::Time endTime);
};
```

### Smart Pointers and Factory Style Creation
```cpp
std::unique_ptr<Course> course = std::make_unique<WeeklyCourse>(101, "Title", "Major", 3.0,
                                                                Poco::DateTime::DaysOfWeek::MONDAY,
                                                                Poco::Data::Time(9, 0, 0),
                                                                Poco::Data::Time(11, 0, 0));
```

### Serialization With Streams
```cpp
std::ostringstream os;
std::istringstream is(text);

os << value << ';' << otherValue;
getline(is, token, ';');
```

### Move Syntax
```cpp
Course other(std::move(course));
```

### Static Cast and Enum Conversion
```cpp
Poco::DateTime::DaysOfWeek day = static_cast<Poco::DateTime::DaysOfWeek>(dayNo);
```

### Map and Unique Pointer Access
```cpp
auto& courseMap = database.getCourses();
auto& studentMap = database.getStudents();

courseMap[101] = std::make_unique<BlockCourse>(101, "Title", "Major", 4.0,
                                               Poco::Data::Date(2025, 1, 1),
                                               Poco::Data::Date(2025, 2, 1),
                                               Poco::Data::Time(8, 0, 0),
                                               Poco::Data::Time(10, 0, 0));
```

---
