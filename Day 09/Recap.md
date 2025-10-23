# Day 09: Pointers in C++

## Topics Covered

- **Pointer Declaration**: Creating pointer variables
- **Address Operator**: Using `&` to get memory addresses
- **Dereference Operator**: Using `*` to access pointed values
- **Reference Variables**: Alternative to pointers using `&`
- **Pass by Reference**: Modifying original variables through functions
- **Pointer Arithmetic**: Basic operations with pointers

## Key Concepts

1. **Memory Addresses**: Every variable has a memory location
2. **Pointer Variables**: Store memory addresses of other variables
3. **Reference Variables**: Aliases for existing variables
4. **Function Parameters**: Passing by reference vs by value
5. **Dereferencing**: Accessing values through pointers

## Code Examples

### 1. Basic Pointer Usage

```cpp
int x = 7;
int *ptr = &x;  // ptr stores address of x

cout << ptr;    // prints memory address
cout << *ptr;   // prints value at address (7)
```

### 2. Pass by Reference Function

```cpp
void multiplyBy2(int &a, int &b, int &c) {
    a *= 2;
    b *= 2;
    c *= 2;
}

int x = 1, y = 2, z = 3;
multiplyBy2(x, y, z);
cout << x << " " << y << " " << z << endl; // Output: 2 4 6
```

### 3. Reference Variables

```cpp
char ch = 'A';
char &cho = ch;  // cho is a reference to ch

cho += 32;  // modifies ch as well
cout << ch;  // Output: a (ASCII value changed)
```

### 4. Pointer Modification

```cpp
int a = 32;
int *ptr = &a;

*ptr += 65;  // modifies a through pointer
cout << a;   // Output: 97 (32 + 65)
```

### 5. Complex Operations

```cpp
int a = 32;
int *ptr = &a;
char ch = 'A';
char &cho = ch;

cho += a;    // ch = 'A' + 32 = 'a' (ASCII)
*ptr += ch;  // a = 32 + 97 = 129

cout << a << ", " << ch << endl; // Output: 129, a
```

## Key Takeaways

- **Pointer Declaration**: `type *pointer_name` declares a pointer
- **Address Operator**: `&variable` gives memory address
- **Dereference Operator**: `*pointer` accesses value at address
- **Reference Variables**: `type &ref = variable` creates alias
- **Pass by Reference**: Functions can modify original variables
- **Memory Manipulation**: Direct access to memory locations

## Common Mistakes to Avoid

- Dereferencing uninitialized pointers (causes crashes)
- Forgetting to use `&` when passing by reference
- Confusing pointers (`*`) with dereference operator (`*`)
- Not initializing pointers before use
- Mixing up reference and pointer syntax

## Memory and Performance

- **Pointers**: Store memory addresses, can be null, need dereferencing
- **References**: Must be initialized, always refer to valid object, automatic dereferencing
- **Pass by Reference**: More efficient than pass by value for large objects
- **Function Parameters**: References avoid copying large data structures
