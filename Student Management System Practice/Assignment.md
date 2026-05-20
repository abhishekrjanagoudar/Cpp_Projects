# C++ Practice Assignment
**Topic:** STL + Smart Pointers + .h/.cpp Separation

Build a simple:

📚 **Student Management System**

### You will practice:
- classes
- .h/.cpp
- vector
- map
- set
- list
- shared_ptr
- unique_ptr
- loops
- STL operations
- object handling

### 📁 File Structure
- `Student.h`
- `Student.cpp`
- `Course.h`
- `Course.cpp`
- `University.h`
- `University.cpp`
- `main.cpp`

---

## 🔹 TASK 1 — Student Class
**File:** `Student.h`

Create class:
```cpp
class Student
```

**Private Variables**
```cpp
int id;
string name;
```

**Public Functions**
```cpp
Student(int id, string name);
void display();
int getId();
string getName();
```

## 🔹 TASK 2 — Student.cpp

Implement:
- constructor
- `display()`
- getters

Use:
```cpp
Student::functionName()
```

## 🔹 TASK 3 — Course Class
**File:** `Course.h`

Use STL containers.

### A) Vector
Store students:
```cpp
vector<Student> students;
```
Practice:
- `push_back`
- iteration
- `erase`

### B) Set
Store unique course codes:
```cpp
set<string> courseCodes;
```
Practice:
- `insert`
- duplicate prevention
- iteration

### C) List
Store attendance order:
```cpp
list<int> attendanceQueue;
```
Practice:
- `push_front`
- `push_back`
- `insert`
- `erase`

### D) Map
Store marks:
```cpp
map<int, int> studentMarks;
```
Meaning: `studentId → marks`

Practice:
- `insert`
- `update`
- `find`
- `erase`

## 🔹 TASK 4 — Smart Pointers

### A) unique_ptr Practice
Inside `University.h`:
```cpp
unique_ptr<Course> course;
```
Tasks:
- create using `make_unique`
- access using `->`

### B) shared_ptr Practice
Create shared student object:
```cpp
shared_ptr<Student> topper;
```
Tasks:
- create using `make_shared`
- copy to another `shared_ptr`
- print `use_count()`

## 🔹 TASK 5 — University Class
**File:** `University.h`

Create:
```cpp
class University
```

**Private Variables**
```cpp
unique_ptr<Course> course;
shared_ptr<Student> topper;
```

**Public Functions**
```cpp
University();
void setup();
void display();
```

## 🔹 TASK 6 — University.cpp
Inside constructor:
```cpp
course = make_unique<Course>();
```

Inside `setup()`:
- add students
- add marks
- add course codes
- insert attendance

## 🔹 TASK 7 — main.cpp
Create:
```cpp
University u;
```
Call:
```cpp
u.setup();
u.display();
```

---

## 🔥 REQUIRED STL OPERATIONS
You MUST use all below.

### VECTOR
- `push_back()`
- `size()`
- `erase()`
- loop

### MAP
- `insert()`
- `find()`
- `erase()`
- update using `[]`

### SET
- `insert()`
- duplicate test
- `find()`
- `erase()`

### LIST
- `push_front()`
- `push_back()`
- `insert()`
- `remove()`

### SMART POINTERS
- `make_unique()`
- `make_shared()`
- `move()`
- `use_count()`
- `->`

---

## 🔥 BONUS TASKS (VERY GOOD PRACTICE)

### BONUS 1
Create:
```cpp
vector<shared_ptr<Student>>
```
Store shared student objects.

### BONUS 2
Create:
```cpp
map<int, unique_ptr<Student>>
```
Meaning: `studentId → unique student object`

### BONUS 3
Use iterator loops for:
- `vector`
- `map`
- `set`
- `list`

---

## 🔥 IMPORTANT RULES
**In .h ONLY:**
- class declarations
- function prototypes
- member variables

**In .cpp ONLY:**
- function definitions
- logic
- STL operations

---

## 🔥 What You Will Learn
After completing:
- STL basics
- memory management
- object flow
- pointers
- smart pointers
- OOP structure
- .h/.cpp separation
- exam-level concepts

## 🔥 Final Goal
Your project should:
- compile correctly
- print student data
- show STL usage
- show smart pointer ownership
- demonstrate all CRUD operations

## 🔥 Exam Tip
This assignment covers:
- OOP
- STL
- dynamic memory
- smart pointers
- containers
- iterators
- file separation

This is enough for strong C++ OOP revision practice.
