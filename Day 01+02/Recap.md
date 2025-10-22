# Day 01+02: C++ Basics Recap

## Topics Covered

### 1. Preprocessor Directives

- `#include <iostream>`: Includes the input-output stream library for using `cin` and `cout`.
- `#define PI 3.14;`: Defines a macro for PI (note: semicolon is unnecessary in macro definitions).

### 2. Namespace

- `using namespace std;`: Allows use of standard library elements without prefixing with `std::`.

### 3. Main Function

- Entry point of the program: `int main()`.
- Returns 0 on successful execution.

### 4. Comments

- Single-line comments using `//`.
- Used to explain code and disable lines for testing.

### 5. Output and Input

- `cout`: Used for output, e.g., `cout << "Hello";`.
- `endl`: Inserts a newline and flushes the buffer.
- `cin`: Used for input, e.g., `cin >> variable;`.

### 6. Data Types

- **Primitive**: int (4 bytes), char (1 byte), bool (1 byte), float (4 bytes), double (8 bytes).
- **Non-Primitive**: Strings, arrays, etc.

### 7. Variables and Operations

- Declaring variables: `int a = 10;`.
- Arithmetic operations: addition, subtraction, multiplication, division.
- Garbage values in uninitialized variables.

### 8. Practice Tasks

- **Area of a Square**: Takes side length `n` and computes `n * n`.
- **Total Bill with GST**: Calculates bill from prices of pencil, pen, eraser, applies 18% GST, and subtracts it (note: code seems to subtract GST, but typically GST is added).
- **Simple Interest**: Formula: `(p * r * t) / 100` (inputs: principal, rate, time).
- **Area of a Circle**: Formula: `3.14 * radius * radius`.

## Key Learnings

- Basic syntax and structure of C++ programs.
- Handling user input and output.
- Performing simple calculations.
- Importance of data types and variable initialization.

## Common Mistakes

- Forgetting to initialize variables (leads to garbage values).
- Incorrect use of macros (e.g., semicolon in #define).
- Misunderstanding GST calculation (code subtracts instead of adding).
