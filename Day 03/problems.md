# Day 3: Operators - Practice Problems

## Problem 1: Arithmetic Operators

**Difficulty:** Easy

### Description

Write a program to demonstrate the use of arithmetic operators with two numbers.

### Input Format

- Two integers: `x` and `y`

### Output Format

- Print results of: `x + y`, `x - y`, `x * y`, `x / y`, `x % y`

### Sample Input

```
10 3
```

### Sample Output

```
Addition: 13
Subtraction: 7
Multiplication: 30
Division: 3
Modulus: 1
```

### Constraints

- -1000 ≤ x, y ≤ 1000
- y ≠ 0

---

## Problem 2: Operator Precedence

**Difficulty:** Easy

### Description

Evaluate expressions considering operator precedence and associativity.

### Input Format

- Values for variables: `x = 10`, `y = 5`

### Output Format

- Evaluate and print: `(x * y / x)`, `(x * (y / x))`, `(y * (x / y + x / y))`, `(y * x / y + y * x / y)`

### Sample Input

```
x = 10, y = 5
```

### Sample Output

```
Expression 1 (x * y / x): 5
Expression 2 (x * (y / x)): 5
Expression 3 (y * (x / y + x / y)): 10
Expression 4 (y * x / y + y * x / y): 10
```

### Note

- `/` operator performs integer division
- Study precedence: `*`, `/`, `%` have higher precedence than `+`, `-`

---

## Problem 3: Compound Assignment Operators

**Difficulty:** Easy

### Description

Demonstrate the use of compound assignment operators.

### Input Format

- Initial value: `num = 10`

### Output Format

- Show step-by-step modification using `+=`, `-=`, `*=`, `/=`, `%=`

### Sample Input

```
Initial: 10
```

### Sample Output

```
Initial: 10
After += 5: 15
After -= 3: 12
After *= 2: 24
After /= 4: 6
After %= 4: 2
```

---

## Problem 4: Relational Operators

**Difficulty:** Easy

### Description

Compare two numbers using relational operators.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print results of: `a == b`, `a != b`, `a > b`, `a < b`, `a >= b`, `a <= b`

### Sample Input

```
10 5
```

### Sample Output

```
a == b: false (0)
a != b: true (1)
a > b: true (1)
a < b: false (0)
a >= b: true (1)
a <= b: false (0)
```

### Constraints

- -1000 ≤ a, b ≤ 1000

---

## Problem 5: Logical Operators

**Difficulty:** Easy

### Description

Demonstrate logical operators with boolean values.

### Input Format

- Two boolean values: `p` and `q`

### Output Format

- Print results of: `p && q`, `p || q`, `!p`, `!q`

### Sample Input

```
p = true (1), q = false (0)
```

### Sample Output

```
p && q: false (0)
p || q: true (1)
!p: false (0)
!q: true (1)
```

---

## Problem 6: Bitwise Operators

**Difficulty:** Medium

### Description

Perform bitwise operations on two numbers.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print results of: `a & b`, `a | b`, `a ^ b`, `~a`, `a << 1`, `a >> 1`

### Sample Input

```
5 3
```

### Sample Output

```
Bitwise AND (a & b): 1
Bitwise OR (a | b): 7
Bitwise XOR (a ^ b): 6
Bitwise NOT (~a): -6
Left Shift (a << 1): 10
Right Shift (a >> 1): 2
```

### Binary Representation

- 5 in binary: 101
- 3 in binary: 011

### Constraints

- 0 ≤ a, b ≤ 1000

---

## Problem 7: Ternary Operator

**Difficulty:** Easy

### Description

Find the maximum of two numbers using the ternary operator.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print the maximum value using ternary operator

### Sample Input

```
10 15
```

### Sample Output

```
Maximum: 15
```

### Code Example

```cpp
int max = (a > b) ? a : b;
```

---

## Problem 8: Operator Precedence Challenge

**Difficulty:** Medium

### Description

Evaluate a complex expression considering operator precedence.

### Input Format

- Values: `a = 2`, `b = 3`, `c = 4`, `d = 5`

### Output Format

- Evaluate: `a + b * c / d - a % b`

### Sample Input

```
a = 2, b = 3, c = 4, d = 5
```

### Sample Output

```
Result: 4
```

### Step-by-Step Evaluation

1. `b * c` = 3 \* 4 = 12
2. `12 / d` = 12 / 5 = 2 (integer division)
3. `a % b` = 2 % 3 = 2
4. `a + 2` = 2 + 2 = 4
5. `4 - 2` = 2

### Note

- `*` and `/` have higher precedence than `+` and `-`
- `%` has same precedence as `*` and `/`
- Left to right associativity for same precedence

---

## Additional Practice Problems

### Problem 9: Swap Two Numbers

Swap two numbers using arithmetic operators (without third variable).

**Hint:** Use `a = a + b`, `b = a - b`, `a = a - b`

### Problem 10: Check Even/Odd

Check if a number is even or odd using bitwise AND operator.

**Hint:** `if (n & 1 == 0)` then even, else odd

### Problem 11: Check Power of 2

Check if a number is a power of 2 using bitwise operators.

**Hint:** `if (n > 0 && (n & (n - 1)) == 0)`

### Problem 12: Count Set Bits

Count the number of 1's in binary representation of a number.

### Problem 13: Temperature Conversion

Convert temperature from Celsius to Fahrenheit and vice versa.

**Formula:** F = (C × 9/5) + 32, C = (F - 32) × 5/9

### Problem 14: Simple Calculator

Create a simple calculator that performs basic arithmetic operations based on user choice.

### Problem 15: Bitwise Calculator

Create a calculator for bitwise operations (AND, OR, XOR, NOT, Shift).

## Key Takeaways

### Operator Precedence (Highest to Lowest)

1. `()` (Parentheses)
2. `++`, `--` (Unary increment/decrement)
3. `*`, `/`, `%` (Multiplicative)
4. `+`, `-` (Additive)
5. `<<`, `>>` (Shift)
6. `<`, `<=`, `>`, `>=` (Relational)
7. `==`, `!=` (Equality)
8. `&` (Bitwise AND)
9. `^` (Bitwise XOR)
10. `|` (Bitwise OR)
11. `&&` (Logical AND)
12. `||` (Logical OR)
13. `?:` (Ternary)
14. `=`, `+=`, `-=`, `*=` (Assignment)

### Common Mistakes to Avoid

- **Integer Division:** `5 / 2 = 2` (not 2.5)
- **Modulus with Negative:** `(-5) % 3` may vary by compiler
- **Operator Associativity:** `a - b - c` is `(a - b) - c`
- **Bitwise vs Logical:** `&` vs `&&`, `|` vs `||`

### Best Practices

- Use parentheses for clarity in complex expressions
- Be careful with integer division
- Understand short-circuit evaluation for logical operators
- Use compound assignment operators for conciseness
