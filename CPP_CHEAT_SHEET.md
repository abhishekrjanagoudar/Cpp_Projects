# C++ Cheat Sheet for Exams

## 1. .h vs .cpp

// Short Definition
.h file = declarations and class interface. .cpp file = function implementations and program logic.

// Syntax
```cpp
// Student.h
class Student {
private:
    int age;

public:
    Student(int age);
    int getAge() const;
};

// Student.cpp
#include "Student.h"

Student::Student(int age) {
    this->age = age;
}

int Student::getAge() const {
    return age;
}
```

// Example
Use .h to show what the class can do. Use .cpp to write how it works.

// Important Notes
- .h keeps declarations, .cpp keeps implementation.
- Put includes in .cpp when possible to keep headers small.
- Use "#include \"Student.h\"" inside the .cpp file.
- Most Important Exam Note: declaration first, definition later.

## 2. Class Structure

// Short Definition
A class groups data and functions together.

// Syntax
```cpp
class Car {
private:
    int speed;   // hidden data

public:
    Car(int s);
    void setSpeed(int s);
    int getSpeed() const;
};
```

// Example
```cpp
class Car {
private:
    int speed;

public:
    Car(int s);
    void setSpeed(int s);
    int getSpeed() const;
};

Car::Car(int s) : speed(s) {}

void Car::setSpeed(int s) {
    speed = s;
}

int Car::getSpeed() const {
    return speed;
}
```

// Important Notes
- private = internal data.
- public = functions other code can call.
- Use getters/setters when data must stay controlled.
- Common mistake: writing function bodies inside the header when the task asks for .cpp separation.

## 3. Constructors

// Short Definition
A constructor runs automatically when an object is created.

// Syntax
```cpp
class Student {
private:
    int age;

public:
    Student(int age);   // parameterized constructor
};
```

// Example
```cpp
Student::Student(int age) {
    this->age = age;    // this-> means current object
}
```

// Important Notes
- Constructor name must be the same as the class name.
- No return type, not even void.
- Use this-> when parameter name is same as member name.
- Common mistake: forgetting to initialize members.

## 4. Methods

// Short Definition
Methods are functions inside a class.

// Syntax
```cpp
class Student {
public:
    int getAge() const;
};

int Student::getAge() const {
    return age;
}
```

// Example
```cpp
class Box {
private:
    int value;

public:
    void setValue(int v);
    int getValue() const;
};

void Box::setValue(int v) {
    value = v;
}

int Box::getValue() const {
    return value;
}
```

// Important Notes
- Use ClassName::functionName in .cpp.
- const after the function means the method does not modify the object.
- Common mistake: missing ClassName:: in implementation.

## 5. const

// Short Definition
const means the value should not change.

// Syntax
```cpp
const int x = 5;
int getAge() const;
void printName(const std::string& name);
```

// Example
```cpp
int Student::getAge() const {
    return age;
}

void printName(const std::string& name) {
    std::cout << name << '\n';
}
```

// Important Notes
- const variable = cannot change after assignment.
- const method = does not modify object data.
- const reference avoids copying.
- Common mistake: forgetting const in getter functions.

## 6. References

// Short Definition
A reference is another name for an existing variable.

// Syntax
```cpp
int x = 10;
int& ref = x;
```

// Example
```cpp
void setAge(int& age) {
    age = 20;   // changes original variable
}
```

// Important Notes
- Use & in function parameters to avoid copying.
- References must be initialized.
- Common mistake: confusing reference & with address-of operator.

## 7. Pointers

// Short Definition
A pointer stores the address of a variable.

// Syntax
```cpp
int x = 10;
int* ptr = &x;
```

// Example
```cpp
int x = 10;
int* ptr = &x;

std::cout << x << '\n';     // value
std::cout << &x << '\n';    // address of x
std::cout << ptr << '\n';   // address stored in ptr
std::cout << *ptr << '\n';  // value at address
```

// Important Notes
- &x gives the address of x.
- *ptr gives the value at the stored address.
- Use -> for object access through a pointer.
- Common mistake: using *ptr when ptr is not valid.

## 8. this and this->

// Short Definition
this is a pointer to the current object.

// Syntax
```cpp
this->member = value;
```

// Example
```cpp
class Student {
private:
    int age;

public:
    Student(int age) {
        this->age = age;   // member = parameter
    }
};
```

// Important Notes
- Use this-> when parameter names hide member names.
- Helps make code clear in constructors and setters.
- Common mistake: writing age = age; without this->.

## 9. Inheritance

// Short Definition
Inheritance lets one class use features of another class.

// Syntax
```cpp
class Parent {
public:
    void show();
};

class Child : public Parent {
public:
    void childOnly();
};
```

// Example
```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Bark\n";
    }
};
```

// Important Notes
- public inheritance means "is-a" relationship.
- Child class gets parent functions.
- Common mistake: forgetting public after the colon.

## 10. virtual and override

// Short Definition
virtual allows runtime polymorphism. override checks that a child function really replaces a parent function.

// Syntax
```cpp
class Base {
public:
    virtual void print() const;
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void print() const override;
};
```

// Example
```cpp
class Shape {
public:
    virtual void draw() const {
        std::cout << "Shape\n";
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Circle\n";
    }
};
```

// Important Notes
- virtual on base class enables dynamic dispatch.
- override catches spelling/signature mistakes.
- Use virtual destructor in base classes.
- Most Important Exam Note: always use override in derived classes when possible.

## 11. Smart Pointers

// Short Definition
Smart pointers manage memory automatically.

// Syntax
```cpp
#include <memory>

std::unique_ptr<Student> p1 = std::make_unique<Student>(10);
std::shared_ptr<Student> p2 = std::make_shared<Student>(10);
```

// Example
```cpp
std::unique_ptr<Student> p1 = std::make_unique<Student>(10);
// only one owner, auto delete

std::shared_ptr<Student> p2 = std::make_shared<Student>(10);
// shared ownership
```

// Important Notes
- unique_ptr = one owner.
- shared_ptr = many owners.
- Prefer smart pointers over raw new/delete.
- Common mistake: copying a unique_ptr.

## 12. vectors, maps, sets

// Short Definition
STL containers store and organize data.

// Syntax
```cpp
#include <vector>
#include <map>
#include <set>

std::vector<int> nums;
std::map<std::string, int> ages;
std::set<int> values;
```

// Example
```cpp
std::vector<int> nums = {1, 2, 3};
nums.push_back(4);          // add element

std::map<std::string, int> ages;
ages["Ali"] = 20;           // insert or update

std::set<int> values;
values.insert(5);            // unique values only
```

// Important Notes
- vector = ordered list.
- map = key-value pairs.
- set = unique sorted values.
- Common mistake: using [] on map for lookup when key may not exist.

## 13. Exceptions

// Short Definition
Exceptions handle errors safely.

// Syntax
```cpp
try {
    // code
}
catch (const std::exception& e) {
    // error handling
}
```

// Example
```cpp
if (age < 0) {
    throw std::invalid_argument("Age must be positive");
}

try {
    setAge(-1);
}
catch (const std::invalid_argument& e) {
    std::cout << e.what();
}
```

// Important Notes
- throw creates the error.
- catch handles the error.
- Use const std::exception& for general error handling.
- Common mistake: throwing errors but never catching them.

## 14. File Handling

// Short Definition
File handling reads from and writes to files.

// Syntax
```cpp
#include <fstream>

std::ofstream out("file.txt");
std::ifstream in("file.txt");
```

// Example
```cpp
// write
std::ofstream out("data.txt");
out << "Hello\n";

// read
std::ifstream in("data.txt");
std::string line;
while (std::getline(in, line)) {
    std::cout << line << '\n';
}
```

// Important Notes
- ofstream = write file.
- ifstream = read file.
- Check if the file opened before using it.
- Common mistake: forgetting to close or check the file stream.

## 15. Quick Syntax Table

| Topic | Syntax |
|---|---|
| Class | `class Name { ... };` |
| Object | `Name obj;` |
| Pointer | `Type* ptr = &value;` |
| Reference | `Type& ref = value;` |
| Const method | `int get() const;` |
| Override | `void f() override;` |
| Vector | `std::vector<int> v;` |
| Map | `std::map<K, V> m;` |
| Set | `std::set<T> s;` |
| Throw | `throw std::runtime_error("msg");` |

## 16. Most Important Exam Notes

- .h = declaration, .cpp = implementation.
- Use const for read-only functions and variables.
- Use & for passing large objects without copying.
- Use * for pointers and -> for pointer member access.
- Use this-> when member names and parameter names are the same.
- Use virtual in base classes and override in child classes.
- Prefer smart pointers instead of raw new/delete.
- Use vector for ordered data, map for key-value data, set for unique values.
- Always check file open status when reading/writing files.
- Common mistakes: missing ClassName::, forgetting const, forgetting public inheritance, and using raw pointers without deleting them.

---
