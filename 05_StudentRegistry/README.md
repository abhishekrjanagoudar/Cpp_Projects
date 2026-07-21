# 05 · Student Registry 🎓

A C++ student database system with a text-based UI, modelling courses, enrollments, and student records.

## Class Overview

| Class | Responsibility |
|---|---|
| `StudentDb` | Central store: holds all students and courses |
| `Student` | Holds personal info and list of enrollments |
| `Address` | Value type for a student's postal address |
| `Enrollment` | Links a student to a course with a grade |
| `Course` | Abstract base — common course attributes |
| `WeeklyCourse` | Recurring weekly schedule variant |
| `BlockCourse` | Compact block-week schedule variant |
| `SimpleUI` | Menu-driven console interface |

---

## 🧠 Important Concepts Used & Learnt

### 1. Abstract Base Class with Pure Virtual Functions
`Course` declares pure virtual methods forcing every concrete subclass to implement them:
```cpp
virtual void write(std::ostringstream& os) const = 0;
virtual void read(std::istringstream& is)        = 0;
virtual std::string getCourseDetail() const      = 0;
virtual ~Course() = 0; // pure virtual destructor
```
A pure virtual destructor is needed when the base class must be abstract but defines no other pure virtuals.

### 2. Static Members & Auto-incrementing IDs
`Student` uses a `static` member to generate unique matriculation numbers:
```cpp
static unsigned int nextMatrikelNumber; // shared across all Student instances
static void refreshNextMatrikelNumber();
static void resetNextMatrikelNumber();
```
Static members live at class scope, not per-object — perfect for counters and shared state.

### 3. Move Constructor
`Course` declares both a copy and a **move constructor**:
```cpp
Course(Course&& oldCourse);  // move — transfers ownership efficiently
Course(Course& oldCourse);   // copy — duplicates the data
```
Move semantics (C++11) avoid unnecessary copies when inserting into containers.

### 4. `std::map<K, V>` as a Database
`Course` uses a static `std::map<unsigned char, std::string>` to map major IDs to major names — a lightweight lookup table inside the class itself.

### 5. Stream-Based Serialisation (`ostringstream` / `istringstream`)
`Student::write()` and `Student::read()` use string streams to serialise/deserialise student data to/from text format — foundational for persistence without a database library.

### 6. Third-Party Library: Poco
The project uses **Poco C++ Libraries**:
- `Poco::Data::Date` for the date-of-birth field
- `Poco::JSON::Object` in the banking system for JSON output
This teaches integrating external libraries into an Eclipse CDT project.

### 7. Separation of UI from Data (`SimpleUI`)
`SimpleUI` owns all `std::cin`/`std::cout` interaction. Domain classes (`StudentDb`, `Student`) are never aware of the console — they expose only data methods.

### 8. `const` Reference Returns
Accessors return `const&` to avoid copying large objects while preventing external modification:
```cpp
const std::vector<Enrollment>& getEnrollments() const;
const std::string& getFirstName() const;
```

---

## Source
All source files are in [`myCode/`](./myCode/)

## Reference
See `Lab3.pdf` for the full assignment specification.
