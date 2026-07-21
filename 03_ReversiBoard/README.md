# 03 · Reversi Board ♟️

A C++ implementation of the classic **Reversi (Othello)** board game logic.

## Class Overview

| Class | Responsibility |
|---|---|
| `ReversiBoard` | Holds the 8×8 board state; enforces move legality and flips pieces |
| `ReversiConsoleView` | Renders the board to the terminal |

---

## 🧠 Important Concepts Used & Learnt

### 1. Enumerations (`enum`)
Cell state is represented with a named enum instead of raw magic integers:
```cpp
enum FieldState { BLACK, WHITE, BLANK };
```
This improves readability and prevents invalid values — a fundamental practice for representing fixed sets of states.

### 2. 2D Arrays (Stack-Allocated)
The board is a fixed-size two-dimensional array stored directly in the object:
```cpp
FieldState board[8][8]; // 8 rows × 8 columns, zero heap allocation
```
Teaches index arithmetic, row-major layout, and bounds awareness.

### 3. Nested Loop Logic & Direction Iteration
`setFieldState()` must scan in **all 8 directions** (horizontal, vertical, diagonal) to find and flip opponent pieces. This uses nested loops with direction offsets `(dr, dc)`:
```cpp
int directions[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
```
A key algorithmic pattern for any grid-based problem.

### 4. Bounds Checking
Every cell access must verify `column` and `row` are within `[0, 7]` before dereferencing `board[row][column]` — critical for preventing undefined behaviour.

### 5. Return Value as Status (`bool`)
`setFieldState()` returns `true` if the move was legal (and applied), `false` otherwise — a clean boolean status pattern without exceptions.

### 6. Class Grouping of Data + Behaviour
`ReversiBoard` is a textbook example of encapsulation: the `board` array is the data, and all operations on it (`getFieldState`, `setFieldState`) live in the same class.

### 7. Separation of Logic and View
`ReversiConsoleView` handles all output — `ReversiBoard` never touches `std::cout`. This MVC-like separation makes the logic independently testable.

---

## Source
All source files are in [`myCode/`](./myCode/)

## Reference
See `Lab1.pdf` for the full assignment specification.
