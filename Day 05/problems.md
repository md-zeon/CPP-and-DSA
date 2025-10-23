# Day 5: Loops - Practice Problems

## Problem 1: Sum of Digits

**Difficulty:** Easy

### Description

Calculate the sum of digits of a given number using a while loop.

### Input Format

- A single integer `n`

### Output Format

- Print the sum of digits

### Sample Input

```
12345
```

### Sample Output

```
15
```

### Explanation

1 + 2 + 3 + 4 + 5 = 15

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 2: Sum of Odd Digits

**Difficulty:** Easy

### Description

Calculate the sum of only the odd digits of a given number.

### Input Format

- A single integer `n`

### Output Format

- Print the sum of odd digits

### Sample Input

```
12345
```

### Sample Output

```
9
```

### Explanation

1 + 3 + 5 = 9 (2 and 4 are even, so excluded)

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 3: Reverse a Number

**Difficulty:** Easy

### Description

Print the digits of a number in reverse order.

### Input Format

- A single integer `n`

### Output Format

- Print the digits in reverse order

### Sample Input

```
12345
```

### Sample Output

```
54321
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 4: Reverse and Store

**Difficulty:** Easy

### Description

Reverse a number and store it in another variable.

### Input Format

- A single integer `n`

### Output Format

- Print the reversed number

### Sample Input

```
12345
```

### Sample Output

```
54321
```

### Algorithm

1. Initialize reverse = 0
2. While n != 0:
   - Extract last digit: digit = n % 10
   - Add to reverse: reverse = (reverse \* 10) + digit
   - Remove last digit: n = n / 10

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 5: Prime Number Check

**Difficulty:** Easy

### Description

Check if a given number is prime or not.

### Input Format

- A single integer `n`

### Output Format

- Print "Prime" or "Not Prime"

### Sample Input 1

```
17
```

### Sample Output 1

```
Prime
```

### Sample Input 2

```
15
```

### Sample Output 2

```
Not Prime
```

### Algorithm

1. If n ≤ 1, not prime
2. For i from 2 to √n:
   - If n % i == 0, not prime
3. If no divisor found, prime

### Constraints

- 1 ≤ n ≤ 10^6

---

## Problem 6: Factorial Calculation

**Difficulty:** Easy

### Description

Calculate the factorial of a given number.

### Input Format

- A single integer `n`

### Output Format

- Print the factorial of n

### Sample Input

```
5
```

### Sample Output

```
120
```

### Explanation

5! = 5 × 4 × 3 × 2 × 1 = 120

### Constraints

- 0 ≤ n ≤ 20 (to avoid overflow)

---

## Problem 7: Multiplication Table

**Difficulty:** Easy

### Description

Print the multiplication table of a given number.

### Input Format

- A single integer `n`

### Output Format

- Print multiplication table from 1 to 10

### Sample Input

```
5
```

### Sample Output

```
5 X 1 = 5
5 X 2 = 10
5 X 3 = 15
5 X 4 = 20
5 X 5 = 25
5 X 6 = 30
5 X 7 = 35
5 X 8 = 40
5 X 9 = 45
5 X 10 = 50
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 8: Print Primes up to N

**Difficulty:** Medium

### Description

Print all prime numbers from 2 to n.

### Input Format

- A single integer `n`

### Output Format

- Print all prime numbers separated by spaces

### Sample Input

```
20
```

### Sample Output

```
2 3 5 7 11 13 17 19
```

### Algorithm

For each number i from 2 to n:

- Check if i is prime
- If prime, print it

### Constraints

- 2 ≤ n ≤ 1000

---

## Problem 9: Fibonacci Series

**Difficulty:** Easy

### Description

Print the first n Fibonacci numbers.

### Input Format

- A single integer `n`

### Output Format

- Print first n Fibonacci numbers separated by spaces

### Sample Input

```
8
```

### Sample Output

```
0 1 1 2 3 5 8 13
```

### Fibonacci Sequence

- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1

### Constraints

- 1 ≤ n ≤ 50

---

## Problem 10: Sum of Series

**Difficulty:** Easy

### Description

Calculate the sum of series: 1 + 2 + 3 + ... + n

### Input Format

- A single integer `n`

### Output Format

- Print the sum

### Sample Input

```
5
```

### Sample Output

```
15
```

### Formula

Sum = n × (n + 1) / 2

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 11: Count Digits

**Difficulty:** Easy

### Description

Count the number of digits in a given number.

### Input Format

- A single integer `n`

### Output Format

- Print the count of digits

### Sample Input 1

```
123
```

### Sample Output 1

```
3
```

### Sample Input 2

```
0
```

### Sample Output 2

```
1
```

### Algorithm

1. If n == 0, return 1
2. Initialize count = 0
3. While n != 0:
   - n = n / 10
   - count++
4. Return count

### Constraints

- 0 ≤ n ≤ 10^9

---

## Problem 12: Check Palindrome Number

**Difficulty:** Easy

### Description

Check if a number is palindrome (reads same forwards and backwards).

### Input Format

- A single integer `n`

### Output Format

- Print "Palindrome" or "Not Palindrome"

### Sample Input 1

```
121
```

### Sample Output 1

```
Palindrome
```

### Sample Input 2

```
123
```

### Sample Output 2

```
Not Palindrome
```

### Algorithm

1. Store original number
2. Reverse the number
3. Compare original with reversed
4. If equal, palindrome

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 13: Armstrong Number (N-Digit)

**Difficulty:** Medium

### Description

Check if a number is an Armstrong number (sum of its digits raised to power of number of digits equals the number).

### Input Format

- A single integer `n`

### Output Format

- Print "Armstrong" or "Not Armstrong"

### Sample Input 1

```
153
```

### Sample Output 1

```
Armstrong
```

### Sample Input 2

```
123
```

### Sample Output 2

```
Not Armstrong
```

### Explanation for 153

- Number of digits: 3
- 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 14: GCD of Two Numbers

**Difficulty:** Medium

### Description

Find the Greatest Common Divisor (GCD) of two numbers using Euclidean algorithm.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print the GCD

### Sample Input

```
48 18
```

### Sample Output

```
6
```

### Euclidean Algorithm

gcd(a, b) = gcd(b, a % b) until b == 0, then gcd is a

### Constraints

- 1 ≤ a, b ≤ 10^9

---

## Problem 15: LCM of Two Numbers

**Difficulty:** Medium

### Description

Find the Least Common Multiple (LCM) of two numbers.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Print the LCM

### Sample Input

```
4 5
```

### Sample Output

```
20
```

### Formula

LCM(a, b) = (a × b) / GCD(a, b)

### Constraints

- 1 ≤ a, b ≤ 10^9

---

## Additional Practice Problems

### Problem 16: Sum of Even Digits

Calculate sum of even digits in a number.

### Problem 17: Number of Trailing Zeros in Factorial

Count trailing zeros in n!.

### Problem 18: Perfect Number Check

Check if a number is perfect (sum of divisors equals number).

### Problem 19: Sum of Squares of Digits

Calculate sum of squares of digits.

### Problem 20: Print Pattern

Print various number patterns using nested loops.

### Problem 21: Binary to Decimal Conversion

Convert binary number to decimal.

### Problem 22: Decimal to Binary Conversion

Convert decimal number to binary.

### Problem 23: Sum of First N Natural Numbers

Calculate sum using formula and loop (compare both).

### Problem 24: Check Prime (Optimized)

Check prime using optimized algorithm (6k ± 1).

### Problem 25: Print Fibonacci up to N

Print Fibonacci numbers until sum exceeds N.

## Loop Types and Use Cases

### While Loop

- **Use when:** Number of iterations not known
- **Example:** Sum of digits, reverse number

### For Loop

- **Use when:** Number of iterations known
- **Example:** Multiplication table, factorial

### Do-While Loop

- **Use when:** At least one execution required
- **Example:** Menu-driven programs

## Key Takeaways

### Loop Control Statements

- **break:** Exit loop immediately
- **continue:** Skip current iteration
- **goto:** Jump to label (avoid when possible)

### Common Patterns

```cpp
// Pattern 1: Sum calculation
int sum = 0;
for(int i = 1; i <= n; i++) {
    sum += i;
}

// Pattern 2: Digit extraction
while(n != 0) {
    int digit = n % 10;
    // process digit
    n /= 10;
}

// Pattern 3: Prime check
bool isPrime = true;
for(int i = 2; i*i <= n; i++) {
    if(n % i == 0) {
        isPrime = false;
        break;
    }
}
```

### Best Practices

- Initialize loop variables before loop
- Use meaningful variable names for counters
- Avoid infinite loops (ensure exit condition)
- Use break and continue judiciously
- Consider time complexity for large inputs

### Common Mistakes

- **Off-by-one errors:** Loop bounds
- **Infinite loops:** Incorrect update condition
- **Variable scope:** Loop variable accessibility
- **Integer overflow:** Large factorial calculations
- **Division by zero:** In loop conditions

### Optimization Tips

- Use `i*i <= n` instead of `i <= sqrt(n)` in prime check
- Pre-calculate repeated values outside loops
- Use appropriate data types to avoid overflow
- Consider early termination conditions
