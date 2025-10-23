# Day 9: Pointers - Practice Problems

## Problem 1: Basic Pointer Operations

**Difficulty:** Easy

### Description

Demonstrate basic pointer operations and memory addressing.

### Input Format

- A single integer `n`

### Output Format

- Print value of n, address of n, value at address

### Sample Input

```
5
```

### Sample Output

```
Value of n: 5
Address of n: 0x7ffd12345678
Value at address: 5
```

### Code Example

```cpp
int n = 5;
int *ptr = &n;
cout << "Value: " << n << endl;
cout << "Address: " << ptr << endl;
cout << "Value at address: " << *ptr << endl;
```

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 2: Pointer Arithmetic

**Difficulty:** Easy

### Description

Demonstrate pointer arithmetic with integers.

### Input Format

- Array of 5 integers

### Output Format

- Print array elements using pointer arithmetic

### Sample Input

```
1 2 3 4 5
```

### Sample Output

```
Element 0: 1
Element 1: 2
Element 2: 3
Element 3: 4
Element 4: 5
```

### Code Example

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
for(int i = 0; i < 5; i++) {
    cout << "Element " << i << ": " << *ptr << endl;
    ptr++; // Move to next element
}
```

### Constraints

- Array size ≤ 100

---

## Problem 3: Swap Two Numbers using Pointers

**Difficulty:** Easy

### Description

Swap two numbers using pointers and pass by reference.

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
After swap: a = 10, b = 5
```

### Function Signature

```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9

---

## Problem 4: Array Sum using Pointers

**Difficulty:** Easy

### Description

Calculate sum of array elements using pointers.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the sum

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
15
```

### Code Example

```cpp
int sum = 0;
int *ptr = arr;
for(int i = 0; i < n; i++) {
    sum += *ptr;
    ptr++;
}
```

### Constraints

- 1 ≤ n ≤ 1000
- -10^9 ≤ array elements ≤ 10^9

---

## Problem 5: Find Maximum using Pointers

**Difficulty:** Easy

### Description

Find the maximum element in an array using pointers.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the maximum element

### Sample Input

```
5
3 1 4 1 5
```

### Sample Output

```
5
```

### Algorithm

1. Initialize max = first element
2. Traverse array using pointer
3. Update max if current element is greater

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 6: Reverse Array using Pointers

**Difficulty:** Medium

### Description

Reverse an array using pointer manipulation.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the reversed array

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
5 4 3 2 1
```

### Algorithm

1. Initialize two pointers: start and end
2. While start < end:
   - Swap elements at start and end
   - Move start forward, end backward

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 7: Pointer to Pointer

**Difficulty:** Medium

### Description

Demonstrate the use of pointer to pointer (double pointer).

### Input Format

- A single integer `n`

### Output Format

- Print value, address, and pointer values

### Sample Input

```
5
```

### Sample Output

```
Value of n: 5
Address of n: 0x7ffd12345678
Value of ptr: 0x7ffd12345678
Address of ptr: 0x7ffd12345680
Value of ptr2: 0x7ffd12345680
```

### Code Example

```cpp
int n = 5;
int *ptr = &n;
int **ptr2 = &ptr;
```

### Constraints

- -10^9 ≤ n ≤ 10^9

---

## Problem 8: Dynamic Memory Allocation

**Difficulty:** Medium

### Description

Demonstrate dynamic memory allocation for arrays.

### Input Format

- Array size `n`

### Output Format

- Print array elements after input

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Array elements: 1 2 3 4 5
```

### Code Example

```cpp
int n;
cin >> n;
int *arr = new int[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
// Use array
delete[] arr; // Don't forget to free memory
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 9: Function returning Pointer

**Difficulty:** Medium

### Description

Create a function that returns a pointer to an array.

### Input Format

- Array size `n`

### Output Format

- Print array elements

### Sample Input

```
3
10 20 30
```

### Sample Output

```
Array: 10 20 30
```

### Function Signature

```cpp
int* createArray(int n) {
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }
    return arr;
}
```

### Note

- Remember to free the allocated memory

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 10: Pointer and Strings

**Difficulty:** Easy

### Description

Demonstrate pointer operations with strings.

### Input Format

- A string `str`

### Output Format

- Print string using pointer

### Sample Input

```
Hello
```

### Sample Output

```
String: Hello
Length: 5
```

### Code Example

```cpp
char str[] = "Hello";
char *ptr = str;
while(*ptr != '\0') {
    cout << *ptr;
    ptr++;
}
```

### Constraints

- String length ≤ 100

---

## Problem 11: Array of Pointers

**Difficulty:** Medium

### Description

Create an array of pointers and demonstrate its usage.

### Input Format

- Number of strings `n`
- `n` strings

### Output Format

- Print all strings using array of pointers

### Sample Input

```
3
Apple
Banana
Cherry
```

### Sample Output

```
Apple
Banana
Cherry
```

### Code Example

```cpp
const int n = 3;
string fruits[n] = {"Apple", "Banana", "Cherry"};
string *ptrs[n];

for(int i = 0; i < n; i++) {
    ptrs[i] = &fruits[i];
}

for(int i = 0; i < n; i++) {
    cout << *ptrs[i] << endl;
}
```

### Constraints

- 1 ≤ n ≤ 100
- String length ≤ 100

---

## Problem 12: Pointer to Structure

**Difficulty:** Medium

### Description

Demonstrate pointers with structures.

### Input Format

- Student details: roll number, name, marks

### Output Format

- Print student details using pointer

### Sample Input

```
101
John Doe
85
```

### Sample Output

```
Roll: 101
Name: John Doe
Marks: 85
```

### Code Example

```cpp
struct Student {
    int roll;
    string name;
    float marks;
};

Student s = {101, "John Doe", 85.0};
Student *ptr = &s;

cout << "Roll: " << ptr->roll << endl;
cout << "Name: " << ptr->name << endl;
cout << "Marks: " << ptr->marks << endl;
```

### Constraints

- Valid input values

---

## Problem 13: Function Pointers

**Difficulty:** Hard

### Description

Demonstrate the use of function pointers.

### Input Format

- Two numbers `a` and `b`
- Operation choice (1: add, 2: subtract, 3: multiply)

### Output Format

- Result of the selected operation

### Sample Input

```
10 5
1
```

### Sample Output

```
15
```

### Code Example

```cpp
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int (*operation)(int, int);

if(choice == 1) operation = add;
else if(choice == 2) operation = subtract;
else operation = multiply;

cout << operation(a, b) << endl;
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9
- 1 ≤ choice ≤ 3

---

## Problem 14: Memory Leak Detection

**Difficulty:** Medium

### Description

Demonstrate proper memory management to avoid leaks.

### Input Format

- Array size `n`

### Output Format

- Print array elements and confirm memory freed

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Array: 1 2 3 4 5
Memory freed successfully
```

### Code Example

```cpp
int *arr = new int[n];
// Use array
delete[] arr; // Free memory
arr = nullptr; // Avoid dangling pointer
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 15: Pointer Comparison

**Difficulty:** Easy

### Description

Compare pointers and understand their behavior.

### Input Format

- Two integers `a` and `b`

### Output Format

- Print comparison results

### Sample Input

```
5 10
```

### Sample Output

```
Address of a: 0x7ffd12345678
Address of b: 0x7ffd12345680
a < b: true
&a < &b: true
```

### Code Example

```cpp
int a = 5, b = 10;
int *ptr1 = &a, *ptr2 = &b;

cout << "a < b: " << (a < b) << endl;
cout << "&a < &b: " << (ptr1 < ptr2) << endl;
```

### Constraints

- -10^9 ≤ a, b ≤ 10^9

---

## Additional Practice Problems

### Problem 16: Dangling Pointer

Demonstrate the concept of dangling pointers.

### Problem 17: NULL Pointer Check

Check for NULL pointers before dereferencing.

### Problem 18: Pointer to Constant

Demonstrate pointer to constant vs constant pointer.

### Problem 19: Generic Swap Function

Create a generic swap function using void pointers.

### Problem 20: Linked List with Pointers

Implement a simple linked list using pointers.

### Problem 21: Matrix using Pointers

Create and manipulate 2D array using pointers.

### Problem 22: String Manipulation with Pointers

Implement string functions using pointers.

### Problem 23: Call by Value vs Call by Reference

Demonstrate the difference between call by value and call by reference.

### Problem 24: Return Multiple Values

Return multiple values from a function using pointers.

### Problem 25: Smart Pointers Introduction

Demonstrate basic concepts of smart pointers (C++11).

## Pointer Types and Concepts

### 1. Basic Pointers

- `int *ptr;` - Pointer to integer
- `char *ptr;` - Pointer to character
- `double *ptr;` - Pointer to double

### 2. Pointer to Pointer

- `int **ptr;` - Pointer to pointer to integer
- Used for 2D arrays, command line arguments

### 3. Void Pointers

- `void *ptr;` - Generic pointer
- Can point to any data type
- Must be cast before dereferencing

### 4. Function Pointers

- `int (*func)(int, int);` - Pointer to function
- Used for callbacks, strategy pattern

### 5. Smart Pointers (C++11)

- `unique_ptr` - Exclusive ownership
- `shared_ptr` - Shared ownership
- `weak_ptr` - Non-owning reference

## Key Takeaways

### Pointer Declaration and Initialization

```cpp
// Declaration
int *ptr;

// Initialization
int n = 5;
ptr = &n; // Address of n

// NULL pointer
int *nullPtr = nullptr;
```

### Pointer Operations

1. **Address Operator:** `&` - Get address of variable
2. **Dereference Operator:** `*` - Access value at address
3. **Pointer Arithmetic:** `ptr++`, `ptr--`, `ptr + n`, `ptr - n`

### Memory Management

1. **Dynamic Allocation**

   ```cpp
   int *arr = new int[n];  // Allocate
   delete[] arr;           // Deallocate
   ```

2. **Avoid Memory Leaks**

   - Always free dynamically allocated memory
   - Set pointers to nullptr after deletion

3. **Dangling Pointers**
   - Pointers pointing to freed memory
   - Avoid using after delete

### Common Patterns

```cpp
// Pattern 1: Array traversal
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr;
for(int i = 0; i < 5; i++) {
    cout << *ptr << " ";
    ptr++;
}

// Pattern 2: Function with pointer parameter
void modifyValue(int *x) {
    *x = *x * 2;
}

// Pattern 3: Dynamic array
int n;
cin >> n;
int *arr = new int[n];
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}
delete[] arr;
```

### Best Practices

- Always initialize pointers (to nullptr if nothing else)
- Check for NULL before dereferencing
- Free dynamically allocated memory
- Avoid returning pointers to local variables
- Use const pointers when data shouldn't change
- Prefer references over pointers for function parameters

### Common Mistakes

- **Uninitialized pointers:** Using wild pointers
- **Memory leaks:** Forgetting to free memory
- **Dangling pointers:** Using freed memory
- **Wrong pointer arithmetic:** Incorrect offset calculations
- **Type mismatches:** Assigning wrong type pointers

### Performance Considerations

- Pointers are fast but error-prone
- Dynamic allocation is slower than stack allocation
- Cache performance with pointer chasing
- Memory fragmentation with frequent allocation/deallocation

### Real-World Applications

1. **Data Structures**

   - Linked lists, trees, graphs
   - Dynamic arrays, hash tables

2. **System Programming**

   - Memory management
   - Device drivers
   - Operating systems

3. **Game Development**

   - Entity management
   - Resource management
   - Performance optimization

4. **Embedded Systems**
   - Hardware interaction
   - Memory-mapped I/O
   - Real-time systems

### Interview Tips

- **Pointer Basics:** Understand declaration and usage
- **Memory Management:** Dynamic allocation and deallocation
- **Common Pitfalls:** Memory leaks, dangling pointers
- **Pointer Arithmetic:** Array traversal, offset calculations
- **Function Pointers:** Callbacks, strategy pattern
- **Smart Pointers:** Modern C++ memory management

### Debugging Tips

- Use debugger to inspect pointer values
- Print addresses and values for debugging
- Use tools like Valgrind for memory leak detection
- Initialize pointers to nullptr to catch errors
- Use static analysis tools to detect issues
