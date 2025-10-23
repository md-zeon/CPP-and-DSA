# Day 15: Vectors and Dynamic Memory

## Topics Covered

- **Dynamic Memory Allocation**: Using new and delete operators
- **Vectors**: STL dynamic arrays
- **2D Vectors**: Dynamic 2D arrays using vectors
- **Vector Operations**: push_back, pop_back, size, capacity
- **Memory Management**: Proper allocation and deallocation
- **Two Pointer Technique**: For pair sum problems

## Key Concepts

1. **Dynamic Memory**: Allocating memory at runtime
2. **Vectors**: Resizable arrays with automatic memory management
3. **Capacity vs Size**: Understanding vector growth
4. **2D Vectors**: Nested vectors for dynamic 2D arrays
5. **Memory Leaks**: Importance of proper deallocation

## Code Examples

### 1. Dynamic Memory for Single Variable

```cpp
void funcInt() {
    int *ptr = new int;  // Allocate memory for single int
    *ptr = 10;
    cout << *ptr << endl;
    delete ptr;  // Deallocate memory
}
```

### 2. Dynamic Memory for Arrays

```cpp
void funcArr() {
    int size;
    cin >> size;
    int *ptr = new int[size];  // Allocate array dynamically

    for(int i = 0; i < size; i++) {
        ptr[i] = i+1;
        cout << ptr[i] << " ";
    }
    cout << endl;

    delete[] ptr;  // Deallocate array memory
}
```

### 3. Dynamic Memory for 2D Arrays

```cpp
void func2D() {
    int rows, cols;
    cout << "Enter Rows: ";
    cin >> rows;
    cout << "Enter Cols: ";
    cin >> cols;

    int **matrix = new int *[rows];  // Array of pointers

    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  // Allocate each row
    }

    // Fill and print matrix
    int x = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];  // Delete each row
    }
    delete[] matrix;  // Delete array of pointers
}
```

### 4. Vector Basics

```cpp
vector<int> vec1;                    // Empty vector
vector<int> vec2 = {1, 2, 3, 4};    // Initialized vector
vector<int> vec3(10, -1);           // Vector of size 10 with -1

cout << "Size: " << vec2.size() << endl;        // Number of elements
cout << "Capacity: " << vec2.capacity() << endl; // Allocated memory

vec2.push_back(5);  // Add element at end
vec2.pop_back();    // Remove element from end
```

### 5. Vector Capacity vs Size

```cpp
vector<int> vec = {1, 2, 3, 4};
cout << "Size: " << vec.size() << endl;        // 4
cout << "Capacity: " << vec.capacity() << endl; // Usually 4 or more

vec.push_back(5);
cout << "Size: " << vec.size() << endl;        // 5
cout << "Capacity: " << vec.capacity() << endl; // Doubled (implementation dependent)

vec.pop_back();
cout << "Size: " << vec.size() << endl;        // 4
cout << "Capacity: " << vec.capacity() << endl; // Remains the same
```

### 6. Pair Sum using Two Pointers

```cpp
vector<int> pairSum(vector<int> arr, int target) {
    int st = 0, end = arr.size()-1;
    vector<int> ans;

    while(st < end) {
        int currSum = arr[st] + arr[end];
        if(currSum == target) {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        } else if(currSum > target) {
            end--;
        } else {
            st++;
        }
    }

    return ans;  // Empty vector if no pair found
}
```

### 7. 2D Vectors

```cpp
vector<vector<int>> matrix = {{1,2,3}, {4,5}, {6,7,8,9}};

for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}

// Accessing elements
cout << matrix[0][1] << endl;  // 2
cout << matrix[2][3] << endl;  // 9
```

## Vector Operations

### Common Vector Functions

- `vec.size()`: Returns number of elements
- `vec.capacity()`: Returns allocated memory
- `vec.push_back(element)`: Adds element at end
- `vec.pop_back()`: Removes last element
- `vec.empty()`: Checks if vector is empty
- `vec.clear()`: Removes all elements
- `vec.at(index)`: Access element with bounds checking
- `vec.front()`: Returns first element
- `vec.back()`: Returns last element

### Vector Initialization

```cpp
vector<int> v1;                    // Empty vector
vector<int> v2(5);                // Vector of size 5 with default values
vector<int> v3(5, 10);            // Vector of size 5 with all 10s
vector<int> v4 = {1, 2, 3, 4};    // Initialized with values
vector<int> v5(v4);               // Copy constructor
```

## Key Takeaways

- **Dynamic Memory**: Use `new` and `delete` for manual memory management
- **Vectors**: Automatically handle memory management
- **Capacity Growth**: Vectors double capacity when full (implementation dependent)
- **2D Vectors**: Use `vector<vector<type>>` for dynamic 2D arrays
- **Memory Leaks**: Always deallocate dynamically allocated memory
- **Two Pointers**: Efficient for sorted array problems

## Common Mistakes to Avoid

- Forgetting to deallocate dynamic memory (memory leaks)
- Accessing deleted memory (dangling pointers)
- Not using `delete[]` for arrays
- Confusing size and capacity in vectors
- Not handling empty vectors in operations

## Dynamic Memory vs Vectors

### Dynamic Memory (Manual)

- **Control**: Full control over memory management
- **Performance**: No overhead
- **Risk**: Memory leaks, dangling pointers
- **Flexibility**: Can create complex data structures

### Vectors (Automatic)

- **Safety**: Automatic memory management
- **Convenience**: Built-in functions and operators
- **Growth**: Automatic resizing
- **Performance**: Small overhead but very efficient

## When to Use

- **Dynamic Memory**: When you need precise control or creating complex data structures
- **Vectors**: For most array-like operations, especially when size changes frequently
- **2D Vectors**: When you need dynamic 2D arrays with varying row sizes
