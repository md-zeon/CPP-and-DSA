# Day 03: Operators in C++

## Topics Covered

- **Arithmetic Operators**: `+`, `-`, `*`, `/`, `%`
- **Operator Precedence**: Order of operations in expressions
- **Parentheses**: Changing precedence with parentheses
- **Expression Evaluation**: How complex expressions are calculated

## Key Concepts

1. **Operator Precedence**: Determines the order in which operations are performed
2. **Parentheses Override**: Parentheses can change the natural precedence
3. **Integer Division**: Division of integers truncates decimal part
4. **Expression Building**: Combining multiple operators in single expressions

## Code Examples

```cpp
int x = 10, y = 5;

// Different expressions showing operator precedence
int exp1 = (x * y / x);        // (10 * 5 / 10) = 5
int exp2 = (x * (y / x));      // (10 * (5 / 10)) = 0
int exp3 = (y * (x / y + x / y)); // (5 * (10 / 5 + 10 / 5)) = 20
int exp4 = (y * x / y + y * x / y); // (5 * 10 / 5 + 5 * 10 / 5) = 20

cout << exp1 << ", " << exp2 << ", " << exp3 << ", " << exp4 << endl;
// Output: 5, 0, 20, 20
```

## Key Takeaways

- **Precedence Order**: Multiplication and division have higher precedence than addition and subtraction
- **Left to Right**: Operators with same precedence are evaluated left to right
- **Parentheses First**: Expressions in parentheses are evaluated before others
- **Integer Math**: Be careful with division - integers truncate decimals

## Common Mistakes to Avoid

- Forgetting operator precedence in complex expressions
- Not using parentheses when needed for clarity
- Assuming floating-point division when using integers
