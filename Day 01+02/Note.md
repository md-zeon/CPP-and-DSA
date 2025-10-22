# Day 01+02: C++ Basics Notes

This file contains additional notes, tips, best practices, and reminders related to the topics in `cppBasics.cpp`.

## Key Notes

### 1. Preprocessor Directives

- `#include <iostream>` is essential for input/output operations.
- `#define` is used for constants, but prefer `const` variables in modern C++ for type safety.
- Example: Instead of `#define PI 3.14;`, use `const float PI = 3.14;`.

### 2. Namespace

- `using namespace std;` brings all standard library names into scope, but it can lead to name conflicts.
- Best practice: Use `std::cout` instead to avoid pollution.

### 3. Main Function

- Always end `main()` with `return 0;` to indicate successful execution.
- In some environments, omitting it is allowed, but it's good practice to include it.

### 4. Comments

- Use comments to explain complex logic, not obvious code.
- Multi-line comments: `/* comment */`.

### 5. Input/Output

- `cin` requires the user to press Enter after input.
- For multiple inputs: `cin >> a >> b;` works sequentially.
- Use `std::fixed` and `std::setprecision` for formatted floating-point output if needed.

### 6. Data Types

- Choose data types based on range and precision.
- `int` is typically 32-bit, but use `long long` for larger numbers.
- `float` vs `double`: `double` has higher precision.

### 7. Variables

- Initialize variables to avoid garbage values: `int a = 0;`.
- Use meaningful names: `sideLength` instead of `n`.

### 8. Arithmetic Operations

- Division: `int / int` gives int (truncates), use `float` for decimal results.
- Modulo `%` only for integers.

## Practice Task Notes

### Area of a Square

- Simple multiplication: Ensure input is positive.

### Total Bill with GST

- The code subtracts GST, but typically GST is added to the bill.
- Correct formula: `total = bill + gst;`.
- Use `const float GST_RATE = 0.18;` for maintainability.

### Simple Interest

- Ensure inputs are positive.
- Formula: SI = (P _ R _ T) / 100.
- Use `double` for more precision if needed.

### Area of a Circle

- Use `M_PI` from `<cmath>` for better PI value, or define a constant.
- Formula: area = π \* r².

## Best Practices

- Write clean, readable code.
- Use consistent indentation (e.g., 4 spaces).
- Test with various inputs, including edge cases (e.g., zero, negative).
- Compile and run code frequently to catch errors early.

## Common Pitfalls

- Forgetting semicolons `;` at the end of statements.
- Mixing data types in operations (e.g., int + float).
- Not handling invalid inputs (e.g., non-numeric for cin).
- Overusing global variables (prefer local).

## Tips for Learning

- Practice by modifying the code and seeing the effects.
- Use online compilers like Replit or Code::Blocks for quick testing.
- Read the code aloud to understand flow.
- Refer to C++ documentation for more details.

## Resources

- C++ Reference: cppreference.com
- Books: "C++ Primer" by Lippman.
- Tutorials: freeCodeCamp C++ course.
