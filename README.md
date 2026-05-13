# Advanced Programming Techniques - Practice Repository 📘✨

<p align="center">
	<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=22&pause=1000&color=1F6FEB&center=true&vCenter=true&width=900&lines=Practice+Advanced+Programming+Techniques+in+C%2B%2B;Solve+Past+Exam+Question+Banks+Step+by+Step;Learn+with+Tests%2C+OOP+Design%2C+and+Real+Exam+Patterns" alt="Animated intro banner" />
</p>

<p align="center">
	<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ badge" />
	<img src="https://img.shields.io/badge/Purpose-Exam%20Practice-2EA043?style=for-the-badge" alt="Purpose badge" />
	<img src="https://img.shields.io/badge/Status-Work%20In%20Progress-F39C12?style=for-the-badge" alt="Status badge" />
</p>

This repository contains previous-year exam practice sets for the course
Advanced Programming Techniques.

Each exam folder includes:
- an incomplete C++ codebase,
- a test file describing required behavior,
- starter main files,
- and (in some sets) generated documentation/output folders.

The goal is to practice reading specs from tests, completing class designs,
and implementing object-oriented logic under exam-style constraints.

## Repository Overview 🗂️

| Folder | Theme | What you practice |
|---|---|---|
| Exam-2022WiSe_Bank | Banking domain model | OOP basics, associations, account/customer handling, exceptions, JSON output |
| Exam-2023SoSe_SensorAdjustor | Sensor calibration network | Inheritance/polymorphism, adjuster strategies, validation with custom exceptions |
| Exam-2023WiSe_ShoppingList | Shopping and discounts | Data modeling, discount rules, database-like lookup, evaluation logic |
| Exam-2024SoSe_Notebook | Notes/topics hierarchy | Composite-style structures, CSV serialization, tree-like ownership |
| Exam-2024WiSe_Resistor | Electrical resistor networks | Recursive/composite calculations, tolerances, file read/write parsing |

## Recommended Study Order (Easiest -> Hardest) 🎯

The order below is based on current incompleteness and conceptual complexity
in the existing starter code.

| Rank | Question Bank | Why this order |
|---|---|---|
| 1 | Exam-2022WiSe_Bank | Smaller scope, direct class interactions, beginner-friendly domain |
| 2 | Exam-2023SoSe_SensorAdjustor | Clear strategy pattern usage and focused validation tasks |
| 3 | Exam-2023WiSe_ShoppingList | More classes and richer discount/business-rule combinations |
| 4 | Exam-2024WiSe_Resistor | Composite network math plus persistence/parsing tasks |
| 5 | Exam-2024SoSe_Notebook | Highest TODO density and deeper hierarchy + CSV reconstruction |

## Quick Start Workflow 🚀

1. Pick the next question bank from the ordered list above.
2. Read `myCode/tests.cpp` first to understand expected behavior.
3. Inspect related headers before implementation.
4. Implement incrementally and run tests after each logical unit.
5. Keep notes of recurring patterns (exceptions, ownership, serialization).

## Practice Tracker ✅

Use this checklist to track progress.

### Exam-2022WiSe_Bank 🏦
- [ ] Understand class relationships (Bank, Customer, Account types)
- [ ] Complete missing test-driven behaviors
- [ ] Validate exception and JSON-related outputs

### Exam-2023SoSe_SensorAdjustor 🌡️
- [ ] Implement/verify adjuster behavior (null, linear, table-based)
- [ ] Validate sensor reading adjustments
- [ ] Test duplicate sensor handling in network

### Exam-2023WiSe_ShoppingList 🛒
- [ ] Complete item/list/shop/shop-db operations
- [ ] Verify fixed/linear/quantity discount logic
- [ ] Complete purchase evaluation scenarios

### Exam-2024WiSe_Resistor ⚡
- [ ] Verify resistor nominal/min/max computations
- [ ] Complete serial/parallel network calculations
- [ ] Complete network read/write verification

### Exam-2024SoSe_Notebook 📓
- [ ] Complete note/topic/notebook base behavior
- [ ] Verify parent-child item handling
- [ ] Complete CSV save/load round-trip tests

## Notes 🧠

- This repository is intended for exam practice, not production software.
- Prefer solving from tests first (red -> green -> refactor style).
- Keep solutions simple and readable before optimizing.
