# Day 7: Functions - Practice Problems

## Problem 1: Sum of Two Numbers

**Difficulty:** Easy

### Description

Write a function to calculate the sum of two numbers.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Return the sum of a and b

### Sample Input

```
10 5
```

### Sample Output

```
15
```

### Function Signature

```cpp
int sum(int a, int b) {
    return a + b;
}
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9

---

## Problem 2: Check Even or Odd

**Difficulty:** Easy

### Description

Write a function to check if a number is even or odd.

### Input Format

- A single integer `n`

### Output Format

- Return true if even, false if odd

### Sample Input

```
6
```

### Sample Output

```
true
```

### Function Signature

```cpp
bool isEven(int n) {
    return n % 2 == 0;
}
```

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 3: Factorial Calculation

**Difficulty:** Easy

### Description

Write a function to calculate factorial of a number.

### Input Format

- A single integer `n`

### Output Format

- Return the factorial of n

### Sample Input

```
5
```

### Sample Output

```
120
```

### Function Signature

```cpp
long long factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}
```

### Constraints

- 0 ≤ n ≤ 20

---

## Problem 4: Prime Check Function

**Difficulty:** Easy

### Description

Write a function to check if a number is prime.

### Input Format

- A single integer `n`

### Output Format

- Return true if prime, false otherwise

### Sample Input

```
17
```

### Sample Output

```
true
```

### Function Signature

```cpp
bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
```

### Constraints

- 1 ≤ n ≤ 10^6

---

## Problem 5: Power Function

**Difficulty:** Easy

### Description

Write a function to calculate a raised to power b.

### Input Format

- Two integers: `base` and `exponent`

### Output Format

- Return base^exponent

### Sample Input

```
2 3
```

### Sample Output

```
8
```

### Function Signature

```cpp
long long power(int base, int exp) {
    long long result = 1;
    for(int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
```

### Constraints

- 0 ≤ base ≤ 10
- 0 ≤ exponent ≤ 20

---

## Problem 6: Fibonacci Function

**Difficulty:** Easy

### Description

Write a function to get the nth Fibonacci number.

### Input Format

- A single integer `n`

### Output Format

- Return the nth Fibonacci number

### Sample Input

```
6
```

### Sample Output

```
8
```

### Function Signature

```cpp
int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

### Constraints

- 0 ≤ n ≤ 40

---

## Problem 7: GCD Function

**Difficulty:** Medium

### Description

Write a function to calculate GCD of two numbers using Euclidean algorithm.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Return the GCD

### Sample Input

```
48 18
```

### Sample Output

```
6
```

### Function Signature

```cpp
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

### Constraints

- 1 ≤ a, b ≤ 10^9

---

## Problem 8: Reverse Number Function

**Difficulty:** Easy

### Description

Write a function to reverse a given number.

### Input Format

- A single integer `n`

### Output Format

- Return the reversed number

### Sample Input

```
12345
```

### Sample Output

```
54321
```

### Function Signature

```cpp
int reverseNumber(int n) {
    int reversed = 0;
    while(n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 9: Count Digits Function

**Difficulty:** Easy

### Description

Write a function to count the number of digits in a number.

### Input Format

- A single integer `n`

### Output Format

- Return the count of digits

### Sample Input

```
12345
```

### Sample Output

```
5
```

### Function Signature

```cpp
int countDigits(int n) {
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
```

### Constraints

- 0 ≤ n ≤ 10^9

---

## Problem 10: Palindrome Check Function

**Difficulty:** Easy

### Description

Write a function to check if a number is palindrome.

### Input Format

- A single integer `n`

### Output Format

- Return true if palindrome, false otherwise

### Sample Input

```
121
```

### Sample Output

```
true
```

### Function Signature

```cpp
bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;
    while(n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return original == reversed;
}
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 11: Armstrong Number Function

**Difficulty:** Medium

### Description

Write a function to check if a number is Armstrong.

### Input Format

- A single integer `n`

### Output Format

- Return true if Armstrong, false otherwise

### Sample Input

```
153
```

### Sample Output

```
true
```

### Function Signature

```cpp
bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = countDigits(n);

    while(n != 0) {
        int digit = n % 10;
        sum += power(digit, digits);
        n /= 10;
    }
    return original == sum;
}
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 12: Binary to Decimal Function

**Difficulty:** Medium

### Description

Write a function to convert binary number to decimal.

### Input Format

- A single integer `binary` (binary number)

### Output Format

- Return the decimal equivalent

### Sample Input

```
1010
```

### Sample Output

```
10
```

### Function Signature

```cpp
int binaryToDecimal(int binary) {
    int decimal = 0;
    int base = 1;

    while(binary != 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}
```

### Constraints

- Binary number contains only 0s and 1s

---

## Problem 13: Decimal to Binary Function

**Difficulty:** Medium

### Description

Write a function to convert decimal number to binary.

### Input Format

- A single integer `decimal`

### Output Format

- Return the binary equivalent

### Sample Input

```
10
```

### Sample Output

```
1010
```

### Function Signature

```cpp
int decimalToBinary(int decimal) {
    int binary = 0;
    int base = 1;

    while(decimal != 0) {
        int remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }
    return binary;
}
```

### Constraints

- 0 ≤ decimal ≤ 10^9

---

## Problem 14: Swap Two Numbers

**Difficulty:** Easy

### Description

Write a function to swap two numbers using pass by reference.

### Input Format

- Two integers: `a` and `b`

### Output Format

- Swap the values of a and b

### Sample Input

```
5 10
```

### Sample Output

```
a = 10, b = 5
```

### Function Signature

```cpp
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9

---

## Problem 15: Array Sum Function

**Difficulty:** Easy

### Description

Write a function to calculate sum of array elements.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Return the sum of array elements

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
15
```

### Function Signature

```cpp
int arraySum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
```

### Constraints

- 1 ≤ n ≤ 1000
- -10^9 ≤ array elements ≤ 10^9

---

## Additional Practice Problems

### Problem 16: Linear Search Function

Implement linear search in an array.

### Problem 17: Maximum in Array Function

Find maximum element in an array.

### Problem 18: Minimum in Array Function

Find minimum element in an array.

### Problem 19: Array Reverse Function

Reverse an array using functions.

### Problem 20: String Length Function

Calculate length of a string.

### Problem 21: String Copy Function

Copy one string to another.

### Problem 22: String Concatenation Function

Concatenate two strings.

### Problem 23: Check Vowel Function

Check if a character is vowel.

### Problem 24: Calculator Functions

Create separate functions for each arithmetic operation.

### Problem 25: Recursive Power Function

Calculate power using recursion.

## Function Types

### 1. Void Functions

- Do not return any value
- Used for performing actions
- Example: `void printMessage()`

### 2. Value-Returning Functions

- Return a single value
- Use return statement
- Example: `int sum(int a, int b)`

### 3. Parameterized Functions

- Accept parameters
- Can be pass by value or reference

### 4. Non-Parameterized Functions

- No parameters
- Example: `int getRandomNumber()`

## Key Takeaways

### Function Declaration Syntax

```cpp
return_type function_name(parameter_type parameter_name) {
    // function body
    return value; // if return_type is not void
}
```

### Parameter Passing

1. **Pass by Value**

   ```cpp
   void func(int x) { // x is a copy
       x = 10; // original unchanged
   }
   ```

2. **Pass by Reference**
   ```cpp
   void func(int &x) { // x is reference
       x = 10; // original changed
   }
   ```

### Function Categories

1. **Built-in Functions**

   - `sqrt()`, `pow()`, `abs()`
   - `strlen()`, `strcmp()`, `strcpy()`

2. **User-defined Functions**

   - Custom functions written by programmer

3. **Recursive Functions**
   - Functions that call themselves

### Best Practices

- Use meaningful function names
- Keep functions small and focused
- Use parameters for inputs
- Return meaningful values
- Avoid global variables in functions
- Use function prototypes for organization

### Common Mistakes

- **Missing return statement:** For non-void functions
- **Incorrect parameter types:** Type mismatches
- **Variable scope issues:** Local vs global variables
- **Infinite recursion:** No base case
- **Side effects:** Unexpected changes to variables

### Function Organization

1. **Function Prototype**

   ```cpp
   return_type function_name(parameters);
   ```

2. **Function Definition**

   ```cpp
   return_type function_name(parameters) {
       // implementation
   }
   ```

3. **Function Call**
   ```cpp
   function_name(arguments);
   ```

### Recursion Guidelines

- **Base case:** Stopping condition
- **Recursive case:** Problem reduction
- **Progress:** Towards base case
- **Stack overflow:** Avoid deep recursion

### Performance Considerations

- **Inline functions:** Small functions for performance
- **Function overhead:** Call stack management
- **Tail recursion:** Optimization technique
- **Lambda functions:** Modern C++ feature
