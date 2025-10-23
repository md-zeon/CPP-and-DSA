# Day 05: Loops in C++

## Topics Covered

- **While Loops**: Indefinite iteration based on condition
- **For Loops**: Definite iteration with counter
- **Loop Control**: Breaking and continuing loop execution
- **Number Manipulation**: Digit extraction, reversal, sum calculation
- **Prime Numbers**: Algorithm for prime checking
- **Factorial Calculation**: Iterative multiplication
- **Fibonacci Series**: Sequence generation using loops

## Key Concepts

1. **Loop Types**: Different loop structures for different scenarios
2. **Number Digit Manipulation**: Extracting and processing individual digits
3. **Prime Algorithm**: Efficient prime checking using sqrt optimization
4. **Mathematical Sequences**: Fibonacci number generation
5. **Loop Optimization**: Breaking early when conditions are met

## Code Examples

### 1. Sum of Digits

```cpp
int n = 10829;
int sum = 0;
while (n != 0) {
    int lastDigit = n % 10;
    sum += lastDigit;
    n /= 10;
}
cout << "Digit Sum = " << sum << endl;
```

### 2. Reverse a Number

```cpp
int n = 10829;
int reverse = 0;
while (n != 0) {
    int lastDigit = n % 10;
    reverse = (reverse * 10) + lastDigit;
    n /= 10;
}
cout << "Reverse = " << reverse << endl;
```

### 3. Prime Number Check

```cpp
int n = 5;
bool isPrime = true;
for(int i = 2; i <= sqrt(n); i++) {
    if(n % i == 0) {
        isPrime = false;
        break;
    }
}
if(isPrime) {
    cout << "Number is prime" << endl;
} else {
    cout << "Number is not prime" << endl;
}
```

### 4. Factorial Calculation

```cpp
int number;
cout << "Enter number: ";
cin >> number;
int factorial = 1;
for(int i = 1; i <= number; i++) {
    factorial *= i;
}
cout << "Factorial of " << number << " is: " << factorial;
```

### 5. Fibonacci Series

```cpp
int n;
cout << "Enter n: ";
cin >> n;
int first = 0;
int second = 1;
cout << first << " " << second << " ";

for(int i = 2; i < n; i++) {
    int third = first + second;
    cout << third << " ";
    first = second;
    second = third;
}
```

## Key Takeaways

- **While Loop**: Use when number of iterations is unknown
- **For Loop**: Use when number of iterations is known
- **Digit Extraction**: Use modulo 10 to get last digit, divide by 10 to remove it
- **Prime Optimization**: Only check divisibility up to square root of number
- **Fibonacci Logic**: Each number is sum of previous two numbers
- **Early Termination**: Use break to exit loops when condition is met

## Common Mistakes to Avoid

- Infinite loops (forgot to update loop condition)
- Off-by-one errors in loop bounds
- Not handling edge cases (n=0, n=1 for factorial)
- Inefficient prime checking (checking beyond sqrt(n))
- Incorrect digit manipulation logic
