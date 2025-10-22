# Day 04: Conditional Statements Recap

## Topics Covered

### 1. If-Else Statements

- **if**: Executes block if condition is true.
- **else if**: Checks additional conditions if previous are false.
- **else**: Executes if no conditions are true.

### 2. Logical Operators

- **&& (AND)**: True if both conditions are true.
- **|| (OR)**: True if at least one condition is true.
- **! (NOT)**: Inverts the condition.

### 3. Comparison Operators

- **>**: Greater than.
- **<**: Less than.
- **==**: Equal to.
- **!=**: Not equal to.
- **>=**: Greater than or equal to.
- **<=**: Less than or equal to.

### 4. Modulo Operator (%)

- Used to get remainder, e.g., `year % 4 == 0`.

### 5. Loops (While)

- **while**: Repeats as long as condition is true.
- Used here to extract digits.

### 6. Macros

- **#define CUBE(x) (x _ x _ x)**: Defines a macro for cubing a number.

### 7. Typedef

- **typedef const int ci;**: Creates an alias for a type.

## Practice Tasks

### 1. Positive, Negative, or Zero

- Input: integer n
- Output: "Positive", "Negative", or "Zero" based on value.

### 2. Leap Year Check

- Input: year
- Condition: Leap if divisible by 4, or by 100 and 400.
- Output: "Leap year" or "Not a leap year".

### 3. Armstrong Number

- For 3-digit number, check if sum of cubes of digits equals the number.
- Example: 371 (3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371)

## Key Learnings

- Control flow with conditionals.
- Combining conditions with logical operators.
- Using loops for digit manipulation.
- Macro usage for reusable code.

## Common Mistakes

- Incorrect leap year logic (should be divisible by 4, but not by 100 unless by 400).
- Forgetting to update loop variable in while.
- Misusing == vs = in conditions.
