# Day 04: Conditional Statements DRY Run

This file provides step-by-step dry runs of the programs in `Conditional_Statements.cpp`.

## 1. Positive, Negative, or Zero

**Code Snippet:**

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

**Dry Run Example:**

- Input: n = 5
- Step 1: cin >> n; → n = 5
- Step 2: if(5 > 0) → true → cout << "Positive";
- Output: "Positive"

**Another Example:**

- Input: n = -3
- if(-3 > 0) → false
- else if(-3 < 0) → true → cout << "Negative";
- Output: "Negative"

**Edge Case:**

- Input: n = 0
- if(0 > 0) → false
- else if(0 < 0) → false
- else → cout << "Zero";
- Output: "Zero"

## 2. Leap Year Check

**Code Snippet:**

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

**Dry Run Example:**

- Input: year = 2024
- Step 1: cin >> year; → year = 2024
- Step 2: 2024 % 4 == 0 → true
- Step 3: if(true || ... ) → true → cout << "Leap year";
- Output: "Leap year"

**Another Example:**

- Input: year = 1900
- 1900 % 4 == 0 → true
- 1900 % 100 == 0 → true
- 1900 % 400 == 0 → false
- if(true || true || false) → true → "Leap year" (Note: Actually not leap, code has error)

**Corrected Logic Dry Run:**

- Correct: if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
- For 1900: (true && false) || false → false → "Not a leap year"

## 3. Armstrong Number

**Code Snippet:**

```cpp
#define CUBE(x) (x * x * x);

int n = 371;
typedef const int ci;
ci NUM = n;
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

**Dry Run Example:**

- n = 371, NUM = 371, sum = 0
- Step 1: while(371 != 0) → true
  - lastDigit = 371 % 10 = 1
  - sum += 1*1*1 = 1
  - n = 371 / 10 = 37
- Step 2: while(37 != 0) → true
  - lastDigit = 37 % 10 = 7
  - sum += 7*7*7 = 343 → sum = 1 + 343 = 344
  - n = 37 / 10 = 3
- Step 3: while(3 != 0) → true
  - lastDigit = 3 % 10 = 3
  - sum += 3*3*3 = 27 → sum = 344 + 27 = 371
  - n = 3 / 10 = 0
- Step 4: while(0 != 0) → false
- Step 5: if(371 == 371) → true → cout << "371 is an Armstrong number";
- Output: "371 is an Armstrong number"

**Another Example:**

- n = 153
- Digits: 1,5,3
- 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
- Output: "153 is an Armstrong number"

## Tips

- Test with boundary values.
- Verify logical conditions manually.
- Check for off-by-one errors in loops.
