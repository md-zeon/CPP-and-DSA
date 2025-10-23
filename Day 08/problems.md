# Day 8: Binary Number System - Practice Problems

## Problem 1: Decimal to Binary Conversion

**Difficulty:** Easy

### Description

Convert a decimal number to its binary representation.

### Input Format

- A single integer `n`

### Output Format

- Print the binary representation

### Sample Input

```
10
```

### Sample Output

```
1010
```

### Explanation

10 in binary is 1010

### Constraints

- 0 ≤ n ≤ 10^9

---

## Problem 2: Binary to Decimal Conversion

**Difficulty:** Easy

### Description

Convert a binary number to its decimal equivalent.

### Input Format

- A single integer `binary` (containing only 0s and 1s)

### Output Format

- Print the decimal equivalent

### Sample Input

```
1010
```

### Sample Output

```
10
```

### Explanation

1×2³ + 0×2² + 1×2¹ + 0×2⁰ = 8 + 0 + 2 + 0 = 10

### Constraints

- Binary number contains only 0s and 1s

---

## Problem 3: Check Even or Odd using Bitwise

**Difficulty:** Easy

### Description

Check if a number is even or odd using bitwise operators.

### Input Format

- A single integer `n`

### Output Format

- Print "Even" or "Odd"

### Sample Input

```
5
```

### Sample Output

```
Odd
```

### Logic

- If last bit is 0, even; if 1, odd
- Use `n & 1 == 0` for even check

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 4: Check Power of 2

**Difficulty:** Easy

### Description

Check if a number is a power of 2 using bitwise operators.

### Input Format

- A single integer `n`

### Output Format

- Print "Power of 2" or "Not a Power of 2"

### Sample Input 1

```
8
```

### Sample Output 1

```
Power of 2
```

### Sample Input 2

```
10
```

### Sample Output 2

```
Not a Power of 2
```

### Logic

- Powers of 2 have exactly one set bit
- Use `n > 0 && (n & (n - 1)) == 0`

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 5: Count Set Bits

**Difficulty:** Easy

### Description

Count the number of 1's in the binary representation of a number.

### Input Format

- A single integer `n`

### Output Format

- Print the count of set bits

### Sample Input

```
7
```

### Sample Output

```
3
```

### Explanation

7 in binary is 111, which has 3 set bits

### Algorithm

1. Initialize count = 0
2. While n != 0:
   - count += n & 1
   - n >>= 1
3. Return count

### Constraints

- 0 ≤ n ≤ 10^9

---

## Problem 6: Bitwise AND Operation

**Difficulty:** Easy

### Description

Perform bitwise AND operation on two numbers.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print the result of a & b

### Sample Input

```
5 3
```

### Sample Output

```
1
```

### Binary Explanation

- 5: 101
- 3: 011
- AND: 001 = 1

### Constraints

- 0 ≤ a, b ≤ 10^9

---

## Problem 7: Bitwise OR Operation

**Difficulty:** Easy

### Description

Perform bitwise OR operation on two numbers.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print the result of a | b

### Sample Input

```
5 3
```

### Sample Output

```
7
```

### Binary Explanation

- 5: 101
- 3: 011
- OR: 111 = 7

### Constraints

- 0 ≤ a, b ≤ 10^9

---

## Problem 8: Bitwise XOR Operation

**Difficulty:** Easy

### Description

Perform bitwise XOR operation on two numbers.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print the result of a ^ b

### Sample Input

```
5 3
```

### Sample Output

```
6
```

### Binary Explanation

- 5: 101
- 3: 011
- XOR: 110 = 6

### Constraints

- 0 ≤ a, b ≤ 10^9

---

## Problem 9: Left Shift Operation

**Difficulty:** Easy

### Description

Perform left shift operation on a number.

### Input Format

- Two integers: `n` and `positions`

### Output Format

- Print n << positions

### Sample Input

```
5 2
```

### Sample Output

```
20
```

### Explanation

5 in binary: 101
Left shift by 2: 10100 = 20

### Constraints

- 0 ≤ n ≤ 10^9
- 0 ≤ positions ≤ 31

---

## Problem 10: Right Shift Operation

**Difficulty:** Easy

### Description

Perform right shift operation on a number.

### Input Format

- Two integers: `n` and `positions`

### Output Format

- Print n >> positions

### Sample Input

```
20 2
```

### Sample Output

```
5
```

### Explanation

20 in binary: 10100
Right shift by 2: 101 = 5

### Constraints

- 0 ≤ n ≤ 10^9
- 0 ≤ positions ≤ 31

---

## Problem 11: Bitwise NOT Operation

**Difficulty:** Easy

### Description

Perform bitwise NOT operation on a number.

### Input Format

- A single integer `n`

### Output Format

- Print ~n

### Sample Input

```
5
```

### Sample Output

```
-6
```

### Explanation

5 in binary: 000...0101
NOT: 111...1010 = -6 (two's complement)

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 12: Swap Two Numbers using XOR

**Difficulty:** Medium

### Description

Swap two numbers using bitwise XOR operator.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print swapped values

### Sample Input

```
5 10
```

### Sample Output

```
a = 10, b = 5
```

### Algorithm

```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9

---

## Problem 13: Clear Bit at Position

**Difficulty:** Medium

### Description

Clear (set to 0) the bit at a specific position.

### Input Format

- Two integers: `n` and `position` (0-based)

### Output Format

- Print the number after clearing the bit

### Sample Input

```
7 1
```

### Sample Output

```
5
```

### Explanation

7 in binary: 111
Clear bit at position 1: 101 = 5

### Algorithm

- Use `n & ~(1 << position)`

### Constraints

- 0 ≤ n ≤ 10^9
- 0 ≤ position ≤ 31

---

## Problem 14: Set Bit at Position

**Difficulty:** Medium

### Description

Set (set to 1) the bit at a specific position.

### Input Format

- Two integers: `n` and `position` (0-based)

### Output Format

- Print the number after setting the bit

### Sample Input

```
5 1
```

### Sample Output

```
7
```

### Explanation

5 in binary: 101
Set bit at position 1: 111 = 7

### Algorithm

- Use `n | (1 << position)`

### Constraints

- 0 ≤ n ≤ 10^9
- 0 ≤ position ≤ 31

---

## Problem 15: Toggle Bit at Position

**Difficulty:** Medium

### Description

Toggle (flip) the bit at a specific position.

### Input Format

- Two integers: `n` and `position` (0-based)

### Output Format

- Print the number after toggling the bit

### Sample Input

```
5 0
```

### Sample Output

```
4
```

### Explanation

5 in binary: 101
Toggle bit at position 0: 100 = 4

### Algorithm

- Use `n ^ (1 << position)`

### Constraints

- 0 ≤ n ≤ 10^9
- 0 ≤ position ≤ 31

---

## Additional Practice Problems

### Problem 16: Check if ith Bit is Set

Check if the ith bit is set (1) or not (0).

### Problem 17: Find Position of First Set Bit

Find the position of the first set bit from right.

### Problem 18: Find Position of Rightmost Set Bit

Find the position of the rightmost set bit.

### Problem 19: Count Total Set Bits from 1 to N

Count total number of set bits from 1 to n.

### Problem 20: Binary Representation

Print the 32-bit binary representation of a number.

### Problem 21: Check if Number is Power of 4

Check if a number is power of 4 using bitwise.

### Problem 22: Swap Odd and Even Bits

Swap odd and even positioned bits.

### Problem 23: Check if Two Numbers are Equal

Check if two numbers are equal using bitwise XOR.

### Problem 24: Find XOR of Numbers from 1 to N

Find XOR of all numbers from 1 to n.

### Problem 25: Check if Number is Multiple of 3

Check if a number is multiple of 3 using bitwise operations.

## Bitwise Operations Summary

| Operation       | Operator | Description                         | Example     |
| --------------- | -------- | ----------------------------------- | ----------- |
| **AND**         | `&`      | Sets bit to 1 if both bits are 1    | 5 & 3 = 1   |
| **OR**          | `\|`     | Sets bit to 1 if either bit is 1    | 5 \| 3 = 7  |
| **XOR**         | `^`      | Sets bit to 1 if bits are different | 5 ^ 3 = 6   |
| **NOT**         | `~`      | Flips all bits                      | ~5 = -6     |
| **Left Shift**  | `<<`     | Shifts bits left, adds 0s on right  | 5 << 1 = 10 |
| **Right Shift** | `>>`     | Shifts bits right, adds 0s on left  | 5 >> 1 = 2  |

## Key Takeaways

### Bitwise Applications

1. **Fast Operations**

   - Multiplication/Division by 2: `n << 1`, `n >> 1`
   - Check even/odd: `n & 1`
   - Swap numbers: `a ^= b; b ^= a; a ^= b;`

2. **Bit Manipulation**

   - Set bit: `n \| (1 << pos)`
   - Clear bit: `n & ~(1 << pos)`
   - Toggle bit: `n ^ (1 << pos)`
   - Check bit: `n & (1 << pos)`

3. **Number Theory**
   - Power of 2: `n > 0 && (n & (n-1)) == 0`
   - Count set bits: Brian Kernighan's algorithm
   - XOR properties: `a ^ a = 0`, `a ^ 0 = a`

### Common Patterns

```cpp
// Pattern 1: Check if bit is set
bool isSet = (n & (1 << pos)) != 0;

// Pattern 2: Set a bit
n = n | (1 << pos);

// Pattern 3: Clear a bit
n = n & ~(1 << pos);

// Pattern 4: Toggle a bit
n = n ^ (1 << pos);

// Pattern 5: Count set bits
int count = 0;
while(n) {
    count += n & 1;
    n >>= 1;
}
```

### Best Practices

- Use unsigned integers for bitwise operations when possible
- Be careful with signed integer shift behavior
- Use parentheses for complex bitwise expressions
- Understand two's complement representation
- Use meaningful variable names for positions

### Common Mistakes

- **Signed vs Unsigned:** Right shift behavior differs
- **Operator Precedence:** `&` has lower precedence than `==`
- **Bit Position:** 0-based indexing from right
- **Integer Overflow:** Left shift can cause overflow
- **Negative Numbers:** Bitwise operations on negative numbers

### Performance Tips

- Bitwise operations are faster than arithmetic operations
- Use lookup tables for small bit operations
- Combine multiple bitwise operations when possible
- Consider using built-in functions like `__builtin_popcount()`

### Real-World Applications

1. **Graphics Programming**

   - Pixel manipulation
   - Color operations
   - Masking operations

2. **System Programming**

   - Device drivers
   - Memory management
   - Flag operations

3. **Game Development**

   - Collision detection
   - State management
   - Optimization

4. **Cryptography**
   - Basic encryption
   - Hash functions
   - Random number generation

### Interview Tips

- **Understand Binary:** Be comfortable with binary representation
- **Practice Patterns:** Memorize common bitwise patterns
- **Edge Cases:** Handle negative numbers, zero, powers of 2
- **Optimization:** Know when bitwise is better than arithmetic
- **Applications:** Be ready to explain real-world use cases
