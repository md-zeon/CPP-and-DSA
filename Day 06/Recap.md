# Day 06: Pattern Printing in C++

## Topics Covered

- **Nested Loops**: Using loops within loops for pattern generation
- **Pattern Analysis**: Understanding row and column relationships
- **Space Management**: Using spaces for pattern alignment
- **Number Patterns**: Sequential and palindromic number arrangements
- **Character Patterns**: Using characters in patterns
- **Hollow Patterns**: Empty spaces within shapes

## Key Concepts

1. **Pattern Structure**: Understanding rows, columns, and their relationships
2. **Loop Coordination**: Managing multiple loop variables for complex patterns
3. **Space Calculation**: Determining correct spacing for alignment
4. **Pattern Symmetry**: Creating symmetric and palindromic patterns
5. **Boolean Logic**: Using conditions for alternating patterns

## Code Examples

### 1. Square Number Pattern

```cpp
// 1 1 1 1
// 2 2 2 2
// 3 3 3 3
// 4 4 4 4

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        cout << i << " ";
    }
    cout << endl;
}
```

### 2. Right Triangle Star Pattern

```cpp
// *
// * *
// * * *
// * * * *

for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cout << "*" << " ";
    }
    cout << endl;
}
```

### 3. Inverted Right Triangle

```cpp
// * * * *
// * * *
// * *
// *

for(int i = 0; i < n; i++) {
    for(int j = n; j > i; j--) {
        cout << "*" << " ";
    }
    cout << endl;
}
```

### 4. Number Triangle Pattern

```cpp
// 1
// 1 2
// 1 2 3
// 1 2 3 4

for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cout << j+1 << " ";
    }
    cout << endl;
}
```

### 5. Character Triangle Pattern

```cpp
// A
// B C
// D E F
// G H I J

char ch = 'A';
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cout << ch << " ";
        ch++;
    }
    cout << endl;
}
```

### 6. Hollow Rectangle Pattern

```cpp
// * * * *
// *     *
// *     *
// * * * *

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        if(i == 1 || j == 1 || i == n || j == n) {
            cout << "*" << " ";
        } else {
            cout << "  ";
        }
    }
    cout << endl;
}
```

### 7. Inverted Rotated Half Pyramid

```cpp
//       *
//     * *
//   * * *
// * * * *

for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - i; j++) {
        cout << "  ";
    }
    for(int k = 0; k <= i; k++) {
        cout << "* ";
    }
    cout << endl;
}
```

### 8. Floyd's Triangle

```cpp
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15

int number = 1;
for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cout << number << " ";
        number++;
    }
    cout << endl;
}
```

### 9. Diamond Pattern

```cpp
//    *
//   * *
//  * * *
// * * * *
// * * * *
//  * * *
//   * *
//    *

for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - i; j++) {
        cout << " ";
    }
    for(int k = 0; k <= i; k++) {
        cout << "* ";
    }
    cout << endl;
}
for(int i = n; i >= 0; i--) {
    for(int j = 0; j < n - i; j++) {
        cout << " ";
    }
    for(int k = 0; k <= i; k++) {
        cout << "* ";
    }
    cout << endl;
}
```

### 10. Palindromic Number Pattern

```cpp
//        1
//      2 1 2
//    3 2 1 2 3
//  4 3 2 1 2 3 4
//5 4 3 2 1 2 3 4 5

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n-i; j++) {
        cout << "   ";
    }
    for(int k = i; k >= 1; k--) {
        cout << " " << k << " ";
    }
    for(int l = 2; l <= i; l++) {
        cout << " " << l << " ";
    }
    cout << endl;
}
```

## Key Takeaways

- **Nested Loop Logic**: Outer loop controls rows, inner loop controls columns
- **Space Management**: Use spaces or tabs for proper alignment
- **Pattern Symmetry**: Many patterns require symmetric logic
- **Number Sequences**: Understand how to generate sequential or palindromic numbers
- **Boundary Conditions**: Pay attention to first and last row/column logic

## Common Mistakes to Avoid

- Incorrect loop bounds causing off-by-one errors
- Wrong spacing calculations for alignment
- Missing proper indentation in nested loops
- Not handling edge cases (n=1, n=0)
- Confusing row and column logic
