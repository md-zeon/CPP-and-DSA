# Day 16: Advanced Bit Manipulation - Practice Problems

## Problem 1: Check Even or Odd using Bitwise

**Difficulty:** Easy

### Description

Check if a number is even or odd using bitwise AND operator.

### Input Format

- A single integer `num`

### Output Format

- Print "Even" or "Odd"

### Sample Input

```
7
```

### Sample Output

```
Odd
```

### Logic

- If `num & 1 == 0`, then even
- If `num & 1 == 1`, then odd

### Code Example

```cpp
void checkEvenOdd(int num) {
    if(num & 1) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
}
```

### Constraints

- -10^9 ≤ num ≤ 10^9

---

## Problem 2: Get ith Bit

**Difficulty:** Easy

### Description

Get the value of the ith bit in a number's binary representation.

### Input Format

- Two integers: `num` and `pos` (0-based position)

### Output Format

- Print the bit value (0 or 1) at given position

### Sample Input

```
6 1
```

### Sample Output

```
Bit at position 1: 1
```

### Explanation

6 in binary: 110
Position 1 (from right): 1

### Algorithm

```cpp
int getIthBit(int num, int pos) {
    int bitMask = 1 << pos;
    if(num & bitMask) {
        return 1;
    } else {
        return 0;
    }
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ pos ≤ 31

---

## Problem 3: Set ith Bit

**Difficulty:** Easy

### Description

Set the ith bit of a number to 1.

### Input Format

- Two integers: `num` and `pos`

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

```cpp
int setIthBit(int num, int pos) {
    int bitMask = 1 << pos;
    return num | bitMask;
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ pos ≤ 31

---

## Problem 4: Clear ith Bit

**Difficulty:** Easy

### Description

Clear the ith bit of a number (set to 0).

### Input Format

- Two integers: `num` and `pos`

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

```cpp
int clearIthBit(int num, int pos) {
    int bitMask = ~(1 << pos);
    return num & bitMask;
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ pos ≤ 31

---

## Problem 5: Check Power of 2

**Difficulty:** Easy

### Description

Check if a number is a power of 2 using bitwise operations.

### Input Format

- A single integer `num`

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
- Use `num > 0 && (num & (num - 1)) == 0`

### Code Example

```cpp
bool isPowerOf2(int num) {
    return num > 0 && (num & (num - 1)) == 0;
}
```

### Constraints

- 1 ≤ num ≤ 10^9

---

## Problem 6: Update ith Bit

**Difficulty:** Medium

### Description

Update the ith bit of a number with a given value (0 or 1).

### Input Format

- Three integers: `num`, `pos`, `val`

### Output Format

- Print the number after updating the bit

### Sample Input

```
7 2 0
```

### Sample Output

```
3
```

### Explanation

7 in binary: 111
Update position 2 to 0: 011 = 3

### Algorithm

1. Clear the ith bit
2. Set the ith bit to the new value

### Code Example

```cpp
void updateIthBit(int num, int pos, int val) {
    // Clear ith bit
    num = num & ~(1 << pos);
    // Set ith bit to val
    num = num | (val << pos);
    cout << num << endl;
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ pos ≤ 31
- val is 0 or 1

---

## Problem 7: Clear Last i Bits

**Difficulty:** Medium

### Description

Clear the last i bits of a number.

### Input Format

- Two integers: `num` and `i`

### Output Format

- Print the number after clearing last i bits

### Sample Input

```
15 2
```

### Sample Output

```
12
```

### Explanation

15 in binary: 1111
Clear last 2 bits: 1100 = 12

### Algorithm

```cpp
void clearLastIBits(int num, int i) {
    int bitMask = (~0) << i;
    num = num & bitMask;
    cout << num << endl;
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ i ≤ 31

---

## Problem 8: Count Set Bits

**Difficulty:** Easy

### Description

Count the number of set bits (1's) in a number's binary representation.

### Input Format

- A single integer `num`

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

7 in binary: 111 (3 set bits)

### Algorithm

```cpp
int countSetBits(int num) {
    int count = 0;
    while(num > 0) {
        count += num & 1;
        num = num >> 1;
    }
    return count;
}
```

### Constraints

- 0 ≤ num ≤ 10^9

---

## Problem 9: Fast Exponentiation

**Difficulty:** Medium

### Description

Calculate x raised to power n using fast exponentiation (binary exponentiation).

### Input Format

- Two integers: `x` and `n`

### Output Format

- Print x^n

### Sample Input

```
2 10
```

### Sample Output

```
1024
```

### Algorithm

```cpp
long long fastExpo(int x, int n) {
    long long ans = 1;
    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }
    return ans;
}
```

### Time Complexity

- O(log n) - Much faster than O(n)

### Constraints

- 1 ≤ x ≤ 10
- 0 ≤ n ≤ 30

---

## Problem 10: Toggle ith Bit

**Difficulty:** Easy

### Description

Toggle (flip) the ith bit of a number.

### Input Format

- Two integers: `num` and `pos`

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

```cpp
int toggleIthBit(int num, int pos) {
    int bitMask = 1 << pos;
    return num ^ bitMask;
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ pos ≤ 31

---

## Problem 11: Check if ith Bit is Set

**Difficulty:** Easy

### Description

Check if the ith bit of a number is set (1).

### Input Format

- Two integers: `num` and `pos`

### Output Format

- Print "Set" or "Not Set"

### Sample Input

```
6 2
```

### Sample Output

```
Set
```

### Explanation

6 in binary: 110
Position 2: 1 (set)

### Code Example

```cpp
bool isIthBitSet(int num, int pos) {
    int bitMask = 1 << pos;
    return (num & bitMask) != 0;
}
```

### Constraints

- 0 ≤ num ≤ 10^9
- 0 ≤ pos ≤ 31

---

## Problem 12: Find Position of Rightmost Set Bit

**Difficulty:** Medium

### Description

Find the position of the rightmost set bit in a number.

### Input Format

- A single integer `num`

### Output Format

- Print the position (0-based) of rightmost set bit

### Sample Input

```
10
```

### Sample Output

```
1
```

### Explanation

10 in binary: 1010
Rightmost set bit at position 1

### Algorithm

- Use `num & -num` to isolate rightmost set bit
- Find position using loop or built-in functions

### Constraints

- 1 ≤ num ≤ 10^9

---

## Problem 13: Swap Two Numbers using XOR

**Difficulty:** Easy

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
void swapUsingXOR(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9

---

## Problem 14: Check if Number is Power of 4

**Difficulty:** Medium

### Description

Check if a number is a power of 4 using bitwise operations.

### Input Format

- A single integer `num`

### Output Format

- Print "Power of 4" or "Not a Power of 4"

### Sample Input 1

```
16
```

### Sample Output 1

```
Power of 4
```

### Sample Input 2

```
8
```

### Sample Output 2

```
Not a Power of 4
```

### Logic

- Power of 4: Power of 2 AND set bit at even position
- Use `num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0`

### Constraints

- 1 ≤ num ≤ 10^9

---

## Problem 15: Generate Power Set using Bit Manipulation

**Difficulty:** Hard

### Description

Generate all subsets of a set using bit manipulation.

### Input Format

- Set size `n`
- `n` elements

### Output Format

- Print all possible subsets

### Sample Input

```
3
a b c
```

### Sample Output

```
(empty set)
a
b
a b
c
a c
b c
a b c
```

### Algorithm

- For each number from 0 to 2^n - 1
- Each bit represents whether element is included
- Print elements corresponding to set bits

### Constraints

- 1 ≤ n ≤ 20 (to avoid too much output)

---

## Problem 16: Find XOR of Numbers from 1 to N

**Difficulty:** Medium

### Description

Find XOR of all numbers from 1 to n.

### Input Format

- A single integer `n`

### Output Format

- Print the XOR result

### Sample Input

```
5
```

### Sample Output

```
1
```

### Pattern

- If n % 4 == 0: XOR = n
- If n % 4 == 1: XOR = 1
- If n % 4 == 2: XOR = n + 1
- If n % 4 == 3: XOR = 0

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 17: Check if Two Numbers Differ by One Bit

**Difficulty:** Medium

### Description

Check if two numbers differ by exactly one bit.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print "Differ by one bit" or "Differ by more than one bit"

### Sample Input

```
5 7
```

### Sample Output

```
Differ by one bit
```

### Explanation

5: 101, 7: 111 (differ only in position 1)

### Algorithm

```cpp
bool differByOneBit(int a, int b) {
    int xorResult = a ^ b;
    return xorResult && (xorResult & (xorResult - 1)) == 0;
}
```

### Constraints

- 0 ≤ a, b ≤ 10^9

---

## Problem 18: Count Total Set Bits from 1 to N

**Difficulty:** Hard

### Description

Count total number of set bits from 1 to n.

### Input Format

- A single integer `n`

### Output Format

- Print total set bits

### Sample Input

```
5
```

### Sample Output

```
7
```

### Explanation

1: 1, 2: 10, 3: 11, 4: 100, 5: 101
Total set bits: 1 + 1 + 2 + 1 + 2 = 7

### Algorithm

- Use mathematical formula or loop through all numbers

### Constraints

- 1 ≤ n ≤ 10^6

---

## Problem 19: Reverse Bits of a Number

**Difficulty:** Medium

### Description

Reverse the bits of a 32-bit number.

### Input Format

- A single integer `num`

### Output Format

- Print the number with reversed bits

### Sample Input

```
1
```

### Sample Output

```
2147483648
```

### Explanation

1 in binary: 000...0001
Reversed: 100...0000 = 2^31

### Algorithm

1. Extract bits from right to left
2. Build new number from left to right

### Constraints

- 0 ≤ num ≤ 10^9

---

## Problem 20: Find Missing Number using XOR

**Difficulty:** Medium

### Description

Find the missing number in array of 1 to n using XOR.

### Input Format

- Array size `n`
- `n-1` integers (1 to n with one missing)

### Output Format

- Print the missing number

### Sample Input

```
5
1 2 4 5
```

### Sample Output

```
3
```

### Algorithm

```cpp
int findMissingXOR(vector<int> arr, int n) {
    int xor1 = 0, xor2 = 0;

    // XOR all array elements
    for(int num : arr) {
        xor2 ^= num;
    }

    // XOR all numbers from 1 to n
    for(int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // Missing number
    return xor1 ^ xor2;
}
```

### Constraints

- 1 ≤ n ≤ 10^6

---

## Problem 21: Check if Number is Multiple of 3

**Difficulty:** Easy

### Description

Check if a number is multiple of 3 using bitwise operations.

### Input Format

- A single integer `num`

### Output Format

- Print "Multiple of 3" or "Not Multiple of 3"

### Sample Input

```
9
```

### Sample Output

```
Multiple of 3
```

### Logic

- A number is multiple of 3 if count of set bits in even positions minus count of set bits in odd positions is multiple of 3

### Constraints

- 0 ≤ num ≤ 10^9

---

## Problem 22: Swap Odd and Even Bits

**Difficulty:** Hard

### Description

Swap odd and even positioned bits in a number.

### Input Format

- A single integer `num`

### Output Format

- Print the number after swapping odd and even bits

### Sample Input

```
23
```

### Sample Output

```
43
```

### Explanation

23 in binary: 10111
Swap odd and even bits: 11010 = 26? Wait, let me calculate properly...

### Algorithm

1. Extract even and odd bits
2. Right shift even bits, left shift odd bits
3. Combine them

### Constraints

- 0 ≤ num ≤ 10^9

---

## Problem 23: Find Position of Only Set Bit

**Difficulty:** Easy

### Description

Find position of the only set bit in a number (if exactly one bit is set).

### Input Format

- A single integer `num`

### Output Format

- Print position of set bit or "Multiple bits set"

### Sample Input

```
8
```

### Sample Output

```
Position: 3
```

### Explanation

8 in binary: 1000 (only bit at position 3 is set)

### Algorithm

```cpp
int findSetBitPosition(int num) {
    if(num == 0 || (num & (num - 1)) != 0) {
        return -1; // Multiple or no bits set
    }

    int pos = 0;
    while(num > 0) {
        if(num & 1) {
            return pos;
        }
        num >>= 1;
        pos++;
    }
    return -1;
}
```

### Constraints

- 1 ≤ num ≤ 10^9

---

## Problem 24: Generate Gray Code

**Difficulty:** Hard

### Description

Generate n-bit Gray code sequence.

### Input Format

- Integer `n` (number of bits)

### Output Format

- Print all Gray code numbers

### Sample Input

```
2
```

### Sample Output

```
00 (0)
01 (1)
11 (3)
10 (2)
```

### Algorithm

- Gray code can be generated using: `i ^ (i >> 1)`

### Constraints

- 1 ≤ n ≤ 10

---

## Problem 25: Bitwise Calculator

**Difficulty:** Easy

### Description

Create a calculator for bitwise operations.

### Input Format

- Two integers: `a` and `b`
- Operation choice (1-6)

### Output Format

- Result of the selected bitwise operation

### Operations

1. AND (a & b)
2. OR (a | b)
3. XOR (a ^ b)
4. Left Shift (a << b)
5. Right Shift (a >> b)
6. NOT (~a)

### Sample Input

```
5 3
1
```

### Sample Output

```
1
```

### Constraints

- 0 ≤ a, b ≤ 10^9
- Valid operation choice

---

## Additional Practice Problems

### Problem 26: Find Two Numbers that Appear Once

In array where all numbers appear twice except two.

### Problem 27: Check if Binary Representation is Palindrome

Check if binary representation of number is palindrome.

### Problem 28: Find Next Power of 2

Find smallest power of 2 greater than given number.

### Problem 29: Bitwise Sieve for Prime

Generate primes using bitwise sieve.

### Problem 30: Check if Number is Sparse

Check if no two consecutive bits are set.

### Problem 31: Find XOR of All Subsets

Find XOR of all possible subsets of array.

### Problem 32: Minimum Flips to Make A or B Equal to C

Count minimum flips needed for bitwise operation.

### Problem 33: Single Number in Array

Find number that appears only once (others twice).

### Problem 34: Maximum XOR Pair

Find pair with maximum XOR value in array.

### Problem 35: Bit Manipulation Interview Questions

Solve common bit manipulation interview problems.

## Advanced Bit Manipulation Concepts

### 1. Bit Manipulation Tricks

- **Check even/odd:** `num & 1`
- **Multiply by 2:** `num << 1`
- **Divide by 2:** `num >> 1`
- **Swap numbers:** `a ^= b; b ^= a; a ^= b;`
- **Check power of 2:** `num & (num - 1) == 0`

### 2. Bit Masking

- **Set bit:** `num | (1 << pos)`
- **Clear bit:** `num & ~(1 << pos)`
- **Toggle bit:** `num ^ (1 << pos)`
- **Check bit:** `num & (1 << pos)`

### 3. Number Theory with Bits

- **Count set bits:** Brian Kernighan's algorithm
- **Power of 2:** Single bit check
- **XOR properties:** `a ^ a = 0`, `a ^ 0 = a`

### 4. Advanced Applications

- **Fast exponentiation:** O(log n)
- **Subset generation:** 2^n subsets
- **Gray code:** Binary reflected code
- **Bitwise sieve:** Prime generation

## Key Takeaways

### Common Patterns

```cpp
// Pattern 1: Bit checking and manipulation
bool isSet = (num & (1 << pos)) != 0;
int setBit = num | (1 << pos);
int clearBit = num & ~(1 << pos);
int toggleBit = num ^ (1 << pos);

// Pattern 2: Count set bits
int count = 0;
int temp = num;
while(temp) {
    count += temp & 1;
    temp >>= 1;
}

// Pattern 3: Fast exponentiation
long long fastPower(int base, int exp) {
    long long result = 1;
    while(exp > 0) {
        if(exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

// Pattern 4: Subset generation
for(int mask = 0; mask < (1 << n); mask++) {
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) {
            // Element i is included
        }
    }
}
```

### Best Practices

- **Use unsigned integers:** For bitwise operations when possible
- **Understand precedence:** `&` has lower precedence than comparison operators
- **Check for overflow:** Left shift can cause overflow
- **Use built-in functions:** `__builtin_popcount()`, `__builtin_clz()`

### Common Mistakes

- **Signed integer shifts:** Right shift behavior differs
- **Bit position confusion:** 0-based indexing from right
- **Operator precedence:** Missing parentheses in complex expressions
- **Infinite loops:** In bit manipulation loops

### Performance Tips

- **Bit operations are fast:** O(1) time complexity
- **Use lookup tables:** For small bit operations
- **Combine operations:** Multiple bit operations in single expression
- **Understand compiler optimizations:** Modern compilers optimize well

### Interview Tips

- **Binary representation:** Be comfortable with binary numbers
- **Bit manipulation patterns:** Memorize common patterns
- **Problem-solving approach:** Think in terms of bits
- **Edge cases:** Handle negative numbers, zero, boundary values
- **Real-world applications:** Know where bit manipulation is used

### Real-World Applications

1. **System Programming**

   - Device drivers
   - Memory management
   - Hardware interaction

2. **Game Development**

   - Collision detection
   - State management
   - Performance optimization

3. **Cryptography**

   - Encryption algorithms
   - Hash functions
   - Random number generation

4. **Data Compression**

   - Huffman coding
   - Run-length encoding
   - Dictionary coding

5. **Computer Graphics**
   - Pixel operations
   - Color manipulation
   - Image processing

### Advanced Topics

1. **Bitwise Dynamic Programming**

   - Knapsack with bit manipulation
   - State compression
   - Subset DP

2. **Advanced Bit Tricks**

   - Bit parallel algorithms
   - SIMD operations
   - GPU computing

3. **Competitive Programming**

   - Bit manipulation problems
   - Optimization techniques
   - Contest strategies

4. **Hardware-Level Programming**
   - Assembly language
   - Embedded systems
   - Low-level optimization
