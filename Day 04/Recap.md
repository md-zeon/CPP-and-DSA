# Day 04: Conditional Statements

## Topics Covered

- **If-Else Statements**: Basic conditional execution
- **If-Else If-Else Ladder**: Multiple conditions checking
- **Logical Operators**: `&&` (AND), `||` (OR), `!` (NOT)
- **Comparison Operators**: `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Leap Year Logic**: Complex conditional logic
- **Armstrong Number**: Mathematical problem solving with loops

## Key Concepts

1. **Conditional Flow**: Program execution based on conditions
2. **Boolean Logic**: True/False evaluations
3. **Nested Conditions**: Multiple levels of decision making
4. **Mathematical Algorithms**: Armstrong number calculation

## Code Examples

### 1. Positive/Negative/Zero Check

```cpp
int n;
cout << "Enter n: ";
cin >> n;
if(n > 0) {
    cout << "Positive";
} else if (n < 0) {
    cout << "Negative";
} else {
    cout << "Zero";
}
```

### 2. Leap Year Check

```cpp
int year;
cout << "Enter year: ";
cin >> year;
if(year % 4 == 0 || year % 100 == 0 || year % 400 == 0) {
    cout << "Leap year" << endl;
} else {
    cout << "Not a leap year" << endl;
}
```

### 3. Armstrong Number Check

```cpp
#define CUBE(x) (x * x * x)

int n = 371;
const int NUM = n;
int sum = 0;

while (n != 0) {
    int lastDigit = n % 10;
    sum += CUBE(lastDigit);
    n /= 10;
}

if(sum == NUM) {
    cout << NUM << " is an Armstrong number" << endl;
} else {
    cout << NUM << " is not an Armstrong number" << endl;
}
```

## Key Takeaways

- **Condition Evaluation**: Conditions are evaluated as true (non-zero) or false (zero)
- **Short-Circuit Evaluation**: Logical operators stop evaluation when result is determined
- **Leap Year Rules**: Divisible by 4, but not by 100 unless also by 400
- **Armstrong Number**: Sum of cubes of digits equals the original number
- **Macro Usage**: `#define` for reusable code snippets

## Common Mistakes to Avoid

- Missing braces `{}` in if-else blocks
- Incorrect logical operator precedence
- Forgetting to handle all cases in conditional ladders
- Incorrect leap year logic (OR vs AND conditions)
