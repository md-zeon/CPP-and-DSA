# Day 4: Conditional Statements - Practice Problems

## Problem 1: Positive, Negative, or Zero

**Difficulty:** Easy

### Description

Write a program to check whether a given number is positive, negative, or zero.

### Input Format

- A single integer `n`

### Output Format

- Print "Positive", "Negative", or "Zero"

### Sample Input 1

```
5
```

### Sample Output 1

```
Positive
```

### Sample Input 2

```
-3
```

### Sample Output 2

```
Negative
```

### Sample Input 3

```
0
```

### Sample Output 3

```
Zero
```

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 2: Leap Year Check

**Difficulty:** Easy

### Description

Write a program to check if a given year is a leap year.

### Input Format

- A single integer `year`

### Output Format

- Print "Leap year" or "Not a leap year"

### Sample Input 1

```
2024
```

### Sample Output 1

```
Leap year
```

### Sample Input 2

```
2023
```

### Sample Output 2

```
Not a leap year
```

### Leap Year Rules

- Divisible by 4 AND (not divisible by 100 OR divisible by 400)

### Constraints

- 1 ≤ year ≤ 10^9

---

## Problem 3: Armstrong Number (3-Digit)

**Difficulty:** Medium

### Description

Check if a 3-digit number is an Armstrong number.
An Armstrong number is one where the sum of cubes of its digits equals the number itself.

### Input Format

- A single 3-digit integer `n`

### Output Format

- Print "[n] is an Armstrong number" or "[n] is not an Armstrong number"

### Sample Input 1

```
371
```

### Sample Output 1

```
371 is an Armstrong number
```

### Sample Input 2

```
123
```

### Sample Output 2

```
123 is not an Armstrong number
```

### Explanation for 371

- 3³ + 7³ + 1³ = 27 + 343 + 1 = 371 ✓

### Constraints

- 100 ≤ n ≤ 999

---

## Problem 4: Largest of Three Numbers

**Difficulty:** Easy

### Description

Find the largest among three given numbers.

### Input Format

- Three integers: `a`, `b`, `c`

### Output Format

- Print the largest number

### Sample Input

```
10 25 15
```

### Sample Output

```
25
```

### Constraints

- -10^9 ≤ a, b, c ≤ 10^9

---

## Problem 5: Grade Calculator

**Difficulty:** Easy

### Description

Calculate grade based on marks obtained.

### Input Format

- Single integer `marks` (0-100)

### Output Format

- Print the grade: A, B, C, D, or F

### Grade Criteria

- A: 90-100
- B: 80-89
- C: 70-79
- D: 60-69
- F: 0-59

### Sample Input 1

```
85
```

### Sample Output 1

```
B
```

### Sample Input 2

```
92
```

### Sample Output 2

```
A
```

### Constraints

- 0 ≤ marks ≤ 100

---

## Problem 6: Triangle Type

**Difficulty:** Easy

### Description

Determine the type of triangle based on side lengths.

### Input Format

- Three integers: `a`, `b`, `c` (side lengths)

### Output Format

- Print "Equilateral", "Isosceles", "Scalene", or "Not a triangle"

### Sample Input 1

```
5 5 5
```

### Sample Output 1

```
Equilateral
```

### Sample Input 2

```
3 4 5
```

### Sample Output 2

```
Scalene
```

### Sample Input 3

```
2 3 5
```

### Sample Output 3

```
Not a triangle
```

### Triangle Inequality

- a + b > c
- a + c > b
- b + c > a

### Constraints

- 1 ≤ a, b, c ≤ 1000

---

## Problem 7: Vowel or Consonant

**Difficulty:** Easy

### Description

Check if a given character is a vowel or consonant.

### Input Format

- A single character `ch` (lowercase or uppercase)

### Output Format

- Print "Vowel" or "Consonant"

### Sample Input 1

```
a
```

### Sample Output 1

```
Vowel
```

### Sample Input 2

```
b
```

### Sample Output 2

```
Consonant
```

### Vowels

- a, e, i, o, u (both lowercase and uppercase)

### Constraints

- Character is an alphabet letter

---

## Problem 8: Absolute Value

**Difficulty:** Easy

### Description

Calculate the absolute value of a number using conditional statements.

### Input Format

- A single integer `n`

### Output Format

- Print the absolute value of `n`

### Sample Input 1

```
-5
```

### Sample Output 1

```
5
```

### Sample Input 2

```
10
```

### Sample Output 2

```
10
```

### Implementation

```cpp
int abs = (n < 0) ? -n : n;
```

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 9: Number of Days in Month

**Difficulty:** Medium

### Description

Find the number of days in a given month and year.

### Input Format

- Two integers: `month` (1-12), `year`

### Output Format

- Print the number of days in that month

### Sample Input 1

```
2 2024
```

### Sample Output 1

```
29
```

### Sample Input 2

```
2 2023
```

### Sample Output 2

```
28
```

### Sample Input 3

```
4 2023
```

### Sample Output 3

```
30
```

### Logic

- February: 28 or 29 days (leap year check)
- April, June, September, November: 30 days
- Rest: 31 days

### Constraints

- 1 ≤ month ≤ 12
- 1 ≤ year ≤ 10^9

---

## Problem 10: Calculator with Menu

**Difficulty:** Medium

### Description

Create a simple calculator with menu-driven interface.

### Input Format

- Choice of operation (1-5)
- Two numbers for operation

### Output Format

- Result of the selected operation

### Menu Options

1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Modulus

### Sample Input

```
1
10 5
```

### Sample Output

```
Result: 15
```

### Note

- Handle division by zero
- Handle invalid menu choices

---

## Additional Practice Problems

### Problem 11: Even or Odd

Check if a number is even or odd.

### Problem 12: Century Year

Check if a year is a century year (divisible by 100).

### Problem 13: Profit or Loss

Calculate profit/loss percentage based on cost and selling price.

### Problem 14: Electricity Bill

Calculate electricity bill based on units consumed.

**Slabs:**

- 0-100 units: ₹3/unit
- 101-200 units: ₹5/unit
- 201+ units: ₹8/unit

### Problem 15: Triangle Validity

Check if three angles form a valid triangle (sum = 180°).

### Problem 16: Youngest Among Three

Find the youngest person among three given ages.

### Problem 17: Divisibility Check

Check if a number is divisible by both 3 and 5.

### Problem 18: Character Case

Check if a character is uppercase, lowercase, or digit.

### Problem 19: Roots of Quadratic Equation

Find the nature of roots of quadratic equation ax² + bx + c = 0.

### Problem 20: Income Tax Calculator

Calculate income tax based on slabs.

## Key Takeaways

### Conditional Statement Types

1. **if statement:** Single condition check
2. **if-else statement:** Two-way decision
3. **if-else if-else:** Multiple conditions
4. **nested if:** Conditions within conditions
5. **switch statement:** Multiple choices (for discrete values)
6. **ternary operator:** Compact if-else

### Common Patterns

```cpp
// Pattern 1: Simple if-else
if (condition) {
    // true case
} else {
    // false case
}

// Pattern 2: Multiple conditions
if (condition1) {
    // case 1
} else if (condition2) {
    // case 2
} else {
    // default case
}

// Pattern 3: Ternary operator
result = (condition) ? value_if_true : value_if_false;
```

### Best Practices

- Use curly braces even for single statements
- Avoid deep nesting (consider early returns)
- Use meaningful variable names in conditions
- Handle edge cases (zero, negative, boundary values)
- Use appropriate data types for comparisons

### Common Mistakes

- **Missing break in switch:** Causes fall-through
- **Dangling else:** Ambiguous association with if
- **Integer division in conditions:** `5/2 == 2` not `2.5`
- **Floating point comparison:** Use epsilon for float comparison
- **Assignment vs equality:** `=` vs `==`
