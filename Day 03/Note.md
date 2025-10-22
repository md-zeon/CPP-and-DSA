# Day 03: Operators Notes

This file contains additional notes, tips, and best practices for operators in C++.

## Key Notes

### 1. Arithmetic Operators
- **Multiplication (*)**: Associative and commutative.
- **Division (/)**: For integers, truncates towards zero. Use `float` or `double` for decimal results.
- **Addition (+)** and **Subtraction (-)**: Basic operations.

### 2. Operator Precedence
- Precedence determines evaluation order without parentheses.
- Mnemonic: "Please Excuse My Dear Aunt Sally" (Parentheses, Exponents, Multiplication/Division, Addition/Subtraction).
- In C++, multiplication and division have the same precedence and are left-associative.

### 3. Parentheses
- Always use parentheses for clarity, even if not required.
- They override precedence and make code readable.

### 4. Integer Division
- `5 / 10 = 0` (not 0.5).
- To get decimal, use `5.0 / 10` or cast: `(float)5 / 10`.

### 5. Expressions
- Evaluate step by step, following precedence.
- Use variables for clarity: `int product = x * y;`.

## Best Practices
- Use parentheses in complex expressions to avoid confusion.
- Prefer descriptive variable names.
- Test expressions with different values.
- Use floating-point types for division if decimals are needed.

## Common Pitfalls
- Assuming division gives decimals (use float).
- Misunderstanding precedence, e.g., `2 + 3 * 4 = 14`, not 20.
- Forgetting that modulo `%` only works with integers.

## Tips for Learning
- Practice by rewriting expressions with parentheses.
- Use online precedence calculators.
- Experiment in code to see results.

## Resources
- C++ Operator Precedence: cppreference.com
- Tutorials: GeeksforGeeks on operators.
