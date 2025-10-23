# Day 07: Functions in C++

## Topics Covered

- **Function Declaration**: Defining function prototypes
- **Function Definition**: Implementing function logic
- **Function Call**: Invoking functions from main or other functions
- **Return Types**: void, int, bool, char functions
- **Parameters**: Pass by value mechanism
- **Function Reuse**: Modular programming concepts

## Key Concepts

1. **Function Structure**: Declaration, definition, and calling
2. **Return Values**: Functions that return data vs void functions
3. **Parameter Passing**: Arguments and formal parameters
4. **Function Composition**: Using functions within other functions
5. **Code Organization**: Breaking down problems into smaller functions

## Code Examples

### 1. Simple Void Function

```cpp
void sayHello() {
    cout << "Hello :) \n";
}

// Function call
sayHello();
```

### 2. Function with Return Value

```cpp
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function call
cout << factorial(5) << endl; // Output: 120
```

### 3. Boolean Function (Prime Check)

```cpp
bool isPrime(int n) {
    if(n == 1) {
        return false;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
```

### 4. Function Using Another Function

```cpp
void printPrime(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Function call
printPrime(100);
```

### 5. Palindrome Check Function

```cpp
bool isPalindrome(int n) {
    int num = n;
    int reverse = 0;
    while(num != 0) {
        int lastDigit = num % 10;
        reverse = (reverse * 10) + lastDigit;
        num /= 10;
    }
    return (reverse == n);
}

// Function call
cout << isPalindrome(123) << endl; // Output: 0 (false)
cout << isPalindrome(121) << endl; // Output: 1 (true)
```

### 6. Digit Sum Function

```cpp
int digitSum(int n) {
    int digit = n;
    int sum = 0;
    while (digit != 0) {
        int lastDigit = digit % 10;
        sum += lastDigit;
        digit /= 10;
    }
    return sum;
}

// Function call
cout << digitSum(29374) << endl; // Output: 25
```

### 7. Multiple Parameters Function

```cpp
void largest(int a, int b, int c) {
    if(a > b && a > c) {
        cout << a << " is the largest number between (" << a << ", " << b << ", " << c << ")" << endl;
    } else if(b > c) {
        cout << b << " is the largest number between (" << a << ", " << b << ", " << c << ")" << endl;
    } else {
        cout << c << " is the largest number between (" << a << ", " << b << ", " << c << ")" << endl;
    }
}

// Function call
largest(12, 9, 7);
```

### 8. Character Function

```cpp
char nextChar(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        if(ch == 'z') {
            return 'a';
        } else {
            return ch+1;
        }
    } else if(ch >= 'A' && ch <= 'Z') {
        if(ch == 'Z') {
            return 'A';
        } else {
            return ch+1;
        }
    }
    return ch; // fallback
}

// Function call
cout << nextChar('z') << endl; // Output: a
cout << nextChar('Z') << endl; // Output: A
```

### 9. Mathematical Expression Function

```cpp
int abSquare(int a, int b) {
    return a*a + b*b + 2*a*b;
}

// Function call
cout << abSquare(5, 3) << endl; // Output: 25 + 9 + 30 = 64
```

## Key Takeaways

- **Function Declaration**: Must be done before function call
- **Return Statement**: Functions with non-void return types must return a value
- **Parameter Types**: Parameters are passed by value (copy)
- **Function Scope**: Variables created inside functions are local
- **Code Reusability**: Functions promote modular and reusable code
- **Function Overloading**: Same function name with different parameters (not covered in this day)

## Common Mistakes to Avoid

- Forgetting function declaration before calling
- Not returning values from non-void functions
- Modifying parameters expecting to change original values (pass by value)
- Not handling edge cases in functions
- Creating functions that are too long or do too many things
