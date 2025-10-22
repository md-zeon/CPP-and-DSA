# Day 03: Operators Recap

## Topics Covered

### 1. Arithmetic Operators

- **Multiplication (\*)**: Used for multiplication, e.g., `x * y`.
- **Division (/)**: Used for division, e.g., `x / y`. Note: Integer division truncates the result.
- **Addition (+)**: Used for addition.
- **Subtraction (-)**: Used for subtraction.

### 2. Operator Precedence

- Operators have precedence levels that determine the order of evaluation.
- **Multiplication and Division** have higher precedence than **Addition and Subtraction**.
- Parentheses `()` can override precedence.

### 3. Expressions

- The code evaluates four expressions to demonstrate precedence:
  - `exp1 = (x * y / x)`: Multiplies x and y, then divides by x.
  - `exp2 = (x * (y / x))`: Divides y by x first (due to parentheses), then multiplies by x.
  - `exp3 = (y * (x / y + x / y))`: Divides x by y twice, adds them, then multiplies by y.
  - `exp4 = (y * x / y + y * x / y)`: Follows precedence: multiplications and divisions first, then addition.

### 4. Variables

- `int x = 10, y = 5;`: Declaring and initializing multiple variables.

### 5. Output

- Using `cout` to print multiple values separated by commas.

## Key Learnings

- Understanding how operators are evaluated in expressions.
- Importance of parentheses to control order of operations.
- Integer division behavior (truncation).

## Common Mistakes

- Assuming division always gives decimal results (use float for that).
- Ignoring operator precedence, leading to unexpected results.
- Forgetting parentheses in complex expressions.
