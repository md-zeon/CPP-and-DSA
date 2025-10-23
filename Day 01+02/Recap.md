# Day 01+02: C++ Basics

## Topics Covered

- **Preprocessor Directives**: `#include <iostream>` for input/output operations
- **Macro Definitions**: `#define PI 3.14` for constant values
- **Namespace**: `using namespace std;` to avoid std:: prefix
- **Data Types**:
  - **Primitive**: int (4 bytes), char (1 byte), bool (1 byte), float (4 bytes), double (8 bytes)
  - **Non-Primitive**: strings, arrays, etc.
- **Input/Output Operations**:
  - `cout` for output
  - `cin` for input
  - `endl` for new line
- **Variables and Initialization**
- **Arithmetic Operations**: addition, multiplication
- **Type Casting**: Converting data types

## Key Concepts

1. **Variables**: Store data values with specific data types
2. **Input/Output**: Interactive programs using cin and cout
3. **Arithmetic Operations**: Basic mathematical calculations
4. **Type Safety**: Importance of proper data types

## Practice Problems Solved

1. **Area of Square**: Calculate area given side length
2. **Bill Calculator**: Calculate total bill with GST (18%)
3. **Simple Interest**: Calculate interest using formula: `(P × R × T)/100`
4. **Area of Circle**: Calculate area using formula: `π × r²`

## Code Examples

```cpp
// Basic input/output
int n;
cin >> n;
cout << "Area of square: " << n*n << endl;

// Bill calculation with GST
float bill = pencil + pen + eraser;
float gst = bill * (18.0/100);
bill += gst;
cout << "Total Bill: " << bill << endl;
```

## Key Takeaways

- Always initialize variables before use
- Use appropriate data types for better memory management
- Understand the difference between primitive and non-primitive data types
- Practice input/output operations for interactive programs
