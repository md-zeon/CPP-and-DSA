# Day 03: Operators DRY Run

This file provides step-by-step dry runs of the expressions in `operators.cpp`.

## Code Snippet
```cpp
int x = 10, y = 5;

int exp1 = (x * y / x);
int exp2 = (x * (y / x));
int exp3 = (y * (x / y + x / y));
int exp4 = (y * x / y + y * x / y);

cout << exp1 << ", " << exp2 << ", " << exp3 << ", " << exp4 << endl;
```

## Dry Run

### Initialization
- x = 10
- y = 5

### Expression 1: exp1 = (x * y / x)
- Step 1: x * y = 10 * 5 = 50
- Step 2: 50 / x = 50 / 10 = 5
- Result: exp1 = 5

### Expression 2: exp2 = (x * (y / x))
- Step 1: y / x = 5 / 10 = 0 (integer division)
- Step 2: x * 0 = 10 * 0 = 0
- Result: exp2 = 0

### Expression 3: exp3 = (y * (x / y + x / y))
- Step 1: x / y = 10 / 5 = 2
- Step 2: x / y = 10 / 5 = 2 (again)
- Step 3: 2 + 2 = 4
- Step 4: y * 4 = 5 * 4 = 20
- Result: exp3 = 20

### Expression 4: exp4 = (y * x / y + y * x / y)
- Step 1: y * x = 5 * 10 = 50
- Step 2: 50 / y = 50 / 5 = 10
- Step 3: y * x = 5 * 10 = 50 (again)
- Step 4: 50 / y = 50 / 5 = 10
- Step 5: 10 + 10 = 20
- Result: exp4 = 20

### Output
- cout << 5 << ", " << 0 << ", " << 20 << ", " << 20 << endl;
- Printed: 5, 0, 20, 20

## Another Example with Different Values
Assume x=8, y=4

- exp1 = (8*4/8) = (32/8) = 4
- exp2 = (8*(4/8)) = (8*0) = 0
- exp3 = (4*(8/4 + 8/4)) = (4*(2+2)) = (4*4) = 16
- exp4 = (4*8/4 + 4*8/4) = (32/4 + 32/4) = (8+8) = 16

Output: 4, 0, 16, 16

## Tips
- Pay attention to integer division.
- Parentheses change the order.
- Test with different values to see patterns.
