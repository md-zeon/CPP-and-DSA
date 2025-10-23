# Day 6: Patterns - Practice Problems

## Problem 1: Square Pattern

**Difficulty:** Easy

### Description

Print a square pattern of stars.

### Input Format

- A single integer `n` (side length)

### Output Format

- Print n rows of n stars each

### Sample Input

```
4
```

### Sample Output

```
****
****
****
****
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 2: Rectangle Pattern

**Difficulty:** Easy

### Description

Print a rectangle pattern of stars.

### Input Format

- Two integers: `rows` and `cols`

### Output Format

- Print rows lines of cols stars each

### Sample Input

```
3 5
```

### Sample Output

```
*****
*****
*****
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 3: Right Triangle (Increasing)

**Difficulty:** Easy

### Description

Print a right triangle pattern with increasing stars.

### Input Format

- A single integer `n`

### Output Format

- Print n rows with 1 to n stars

### Sample Input

```
5
```

### Sample Output

```
*
**
***
****
*****
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 4: Right Triangle (Decreasing)

**Difficulty:** Easy

### Description

Print a right triangle pattern with decreasing stars.

### Input Format

- A single integer `n`

### Output Format

- Print n rows with n to 1 stars

### Sample Input

```
5
```

### Sample Output

```
*****
****
***
**
*
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 5: Number Triangle 1

**Difficulty:** Easy

### Description

Print a triangle pattern with numbers.

### Input Format

- A single integer `n`

### Output Format

- Print numbers in triangular pattern

### Sample Input

```
5
```

### Sample Output

```
1
12
123
1234
12345
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 6: Number Triangle 2

**Difficulty:** Easy

### Description

Print a triangle pattern with repeated numbers.

### Input Format

- A single integer `n`

### Output Format

- Print the row number repeatedly

### Sample Input

```
5
```

### Sample Output

```
1
22
333
4444
55555
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 7: Floyd's Triangle

**Difficulty:** Easy

### Description

Print Floyd's triangle pattern.

### Input Format

- A single integer `n` (number of rows)

### Output Format

- Print consecutive numbers in triangular pattern

### Sample Input

```
5
```

### Sample Output

```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 8: Inverted Number Triangle

**Difficulty:** Easy

### Description

Print an inverted triangle with numbers.

### Input Format

- A single integer `n`

### Output Format

- Print inverted triangular pattern

### Sample Input

```
5
```

### Sample Output

```
12345
1234
123
12
1
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 9: Binary Triangle

**Difficulty:** Easy

### Description

Print a triangle pattern with 0s and 1s.

### Input Format

- A single integer `n`

### Output Format

- Print binary pattern (sum of row and column indices)

### Sample Input

```
5
```

### Sample Output

```
1
01
010
1010
10101
```

### Logic

- Print 1 if (row + col) is even, else 0

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 10: Pyramid Pattern

**Difficulty:** Medium

### Description

Print a pyramid pattern of stars.

### Input Format

- A single integer `n`

### Output Format

- Print pyramid with n rows

### Sample Input

```
5
```

### Sample Output

```
    *
   ***
  *****
 *******
*********
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 11: Diamond Pattern

**Difficulty:** Medium

### Description

Print a diamond pattern of stars.

### Input Format

- A single integer `n`

### Output Format

- Print diamond with 2n-1 rows

### Sample Input

```
3
```

### Sample Output

```
  *
 ***
*****
 ***
  *
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 12: Hollow Square

**Difficulty:** Easy

### Description

Print a hollow square pattern.

### Input Format

- A single integer `n`

### Output Format

- Print hollow square of stars

### Sample Input

```
5
```

### Sample Output

```
*****
*   *
*   *
*   *
*****
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 13: Number Pyramid

**Difficulty:** Medium

### Description

Print a pyramid pattern with numbers.

### Input Format

- A single integer `n`

### Output Format

- Print pyramid with consecutive numbers

### Sample Input

```
4
```

### Sample Output

```
   1
  2 3
 4 5 6
7 8 9 10
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 14: Pascal's Triangle

**Difficulty:** Medium

### Description

Print Pascal's triangle up to n rows.

### Input Format

- A single integer `n`

### Output Format

- Print Pascal's triangle

### Sample Input

```
5
```

### Sample Output

```
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
```

### Logic

- Each number is sum of two numbers above it

### Constraints

- 1 ≤ n ≤ 20 (to avoid overflow)

---

## Problem 15: Zigzag Pattern

**Difficulty:** Medium

### Description

Print a zigzag or wave pattern.

### Input Format

- A single integer `n`

### Output Format

- Print zigzag pattern

### Sample Input

```
4
```

### Sample Output

```
1 2 3 4
8 7 6 5
9 10 11 12
16 15 14 13
```

### Constraints

- 1 ≤ n ≤ 100

---

## Additional Practice Problems

### Problem 16: Border Pattern

Print a pattern with stars on borders and empty inside.

### Problem 17: Checkerboard Pattern

Print a checkerboard pattern of two characters.

### Problem 18: Triangle with Spaces

Print a triangle with leading spaces.

### Problem 19: Number Diamond

Print a diamond pattern with numbers.

### Problem 20: Alphabet Triangle

Print a triangle pattern with alphabets.

### Problem 21: Spiral Pattern

Print numbers in spiral pattern.

### Problem 22: Heart Pattern

Print a heart shape with stars.

### Problem 23: Christmas Tree

Print a Christmas tree pattern.

### Problem 24: Sandglass Pattern

Print an hourglass or sandglass pattern.

### Problem 25: Cross Pattern

Print a cross or plus pattern.

## Pattern Categories

### 1. Basic Patterns

- Square, Rectangle
- Right triangles (increasing/decreasing)

### 2. Number Patterns

- Sequential numbers
- Row-wise repetition
- Floyd's triangle

### 3. Advanced Patterns

- Pyramids and diamonds
- Hollow patterns
- Pascal's triangle

### 4. Special Patterns

- Binary patterns
- Alphabet patterns
- Custom shapes

## Key Takeaways

### Loop Nesting

```cpp
// Pattern 1: Square
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        cout << "*";
    }
    cout << endl;
}

// Pattern 2: Triangle
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cout << "*";
    }
    cout << endl;
}

// Pattern 3: Pyramid
for(int i = 0; i < n; i++) {
    // Print spaces
    for(int j = 0; j < n-i-1; j++) {
        cout << " ";
    }
    // Print stars
    for(int j = 0; j < 2*i+1; j++) {
        cout << "*";
    }
    cout << endl;
}
```

### Common Patterns

1. **Square:** `n × n` stars
2. **Triangle:** `i` stars in row `i`
3. **Pyramid:** Spaces `(n-i-1)`, stars `(2*i+1)`
4. **Diamond:** Upper pyramid + lower pyramid

### Best Practices

- Use nested loops for 2D patterns
- Calculate spaces and stars mathematically
- Use functions for repeated patterns
- Consider pattern symmetry

### Common Mistakes

- **Off-by-one errors:** Loop bounds
- **Space calculation:** Incorrect space count
- **Pattern alignment:** Misaligned patterns
- **Variable scope:** Loop variable conflicts

### Optimization Tips

- Pre-calculate repeated values
- Use string concatenation for patterns
- Consider pattern symmetry for code reuse
- Use mathematical formulas for complex patterns
