# Day 22+23: Time and Space Complexity

## Topics Covered

- **Time Complexity**: Analysis of algorithm execution time
- **Space Complexity**: Analysis of memory usage
- **Big O Notation**: Asymptotic complexity analysis
- **Common Complexities**: O(1), O(log n), O(n), O(n log n), O(n²), O(2^n)
- **Complexity Analysis**: Best, worst, and average case
- **Optimization Techniques**: Trade-offs between time and space

## Key Concepts

1. **Asymptotic Analysis**: Focus on growth rate as input size increases
2. **Big O Notation**: Upper bound on time/space complexity
3. **Complexity Classes**: Constant, logarithmic, linear, etc.
4. **Best/Worst/Average Case**: Different scenarios for analysis
5. **Space-Time Tradeoffs**: Choosing between memory and speed

## Time Complexity Analysis

### 1. Constant Time - O(1)

```cpp
// Accessing array element
int getElement(int arr[], int n, int index) {
    return arr[index];  // O(1)
}

// Arithmetic operations
int add(int a, int b) {
    return a + b;  // O(1)
}
```

### 2. Logarithmic Time - O(log n)

```cpp
// Binary search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;  // O(log n)
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### 3. Linear Time - O(n)

```cpp
// Linear search
int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {  // O(n)
        if(arr[i] == target) return i;
    }
    return -1;
}

// Sum of array elements
int sumArray(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {  // O(n)
        sum += arr[i];
    }
    return sum;
}
```

### 4. Linearithmic Time - O(n log n)

```cpp
// Merge sort
void mergeSort(int arr[], int n) {
    if(n <= 1) return;

    int mid = n / 2;
    mergeSort(arr, mid);           // T(n/2)
    mergeSort(arr + mid, n - mid); // T(n/2)
    merge(arr, mid, n - mid);      // O(n)

    // Total: T(n) = 2T(n/2) + O(n) = O(n log n)
}
```

### 5. Quadratic Time - O(n²)

```cpp
// Bubble sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {           // O(n)
        for(int j = 0; j < n - i - 1; j++) { // O(n)
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // Total: O(n²)
}

// Nested loops
void printPairs(int arr[], int n) {
    for(int i = 0; i < n; i++) {      // O(n)
        for(int j = 0; j < n; j++) {  // O(n)
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
    // Total: O(n²)
}
```

### 6. Exponential Time - O(2^n)

```cpp
// Fibonacci (naive recursion)
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);  // O(2^n)
}

// Subset generation
void generateSubsets(int arr[], int n, int index, vector<int> current) {
    if(index == n) {
        // Process current subset
        return;
    }

    // Exclude current element
    generateSubsets(arr, n, index + 1, current);

    // Include current element
    current.push_back(arr[index]);
    generateSubsets(arr, n, index + 1, current);
    current.pop_back();
}
```

## Space Complexity Analysis

### 1. Constant Space - O(1)

```cpp
// In-place operations
void swap(int &a, int &b) {
    int temp = a;  // O(1) extra space
    a = b;
    b = temp;
}

// Mathematical calculations
int factorial(int n) {
    int result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;  // O(1) extra space
    }
    return result;
}
```

### 2. Linear Space - O(n)

```cpp
// Array creation
int* createArray(int n) {
    int* arr = new int[n];  // O(n) space
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

// Recursion call stack
void printNumbers(int n) {
    if(n == 0) return;
    printNumbers(n-1);  // O(n) call stack space
    cout << n << " ";
}
```

### 3. Quadratic Space - O(n²)

```cpp
// 2D array creation
int** createMatrix(int n) {
    int** matrix = new int*[n];
    for(int i = 0; i < n; i++) {
        matrix[i] = new int[n];  // O(n²) space
    }
    return matrix;
}

// Recursive tree problems
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);  // O(n) call stack
}
```

## Complexity Notation Rules

### Big O Notation

- **O(1)**: Constant time - doesn't depend on input size
- **O(log n)**: Logarithmic - halves/doubles each step
- **O(n)**: Linear - grows proportionally with input
- **O(n log n)**: Linearithmic - n times log n
- **O(n²)**: Quadratic - square of input size
- **O(2^n)**: Exponential - doubles with each addition

### Complexity Rules

1. **Drop Constants**: O(2n) = O(n), O(n² + n) = O(n²)
2. **Drop Lower Terms**: O(n² + n) = O(n²)
3. **Different Inputs**: O(n + m) for two different inputs
4. **Recursive Complexity**: Solve recurrence relations

## Best, Worst, and Average Case

### 1. Best Case

- **Definition**: Minimum time/space for given input size
- **Example**: Linear search finds element at first position
- **Notation**: Ω(1) for best case linear search

### 2. Worst Case

- **Definition**: Maximum time/space for given input size
- **Example**: Linear search doesn't find element (searches all)
- **Notation**: O(n) for worst case linear search

### 3. Average Case

- **Definition**: Expected time/space over all possible inputs
- **Example**: Linear search finds element at random position
- **Notation**: Θ(n/2) = Θ(n) for average case linear search

## Common Complexity Examples

### Searching Algorithms

- **Linear Search**: O(n) time, O(1) space
- **Binary Search**: O(log n) time, O(1) space
- **Hash Table Search**: O(1) average time, O(n) space

### Sorting Algorithms

- **Bubble Sort**: O(n²) time, O(1) space
- **Merge Sort**: O(n log n) time, O(n) space
- **Quick Sort**: O(n log n) average time, O(log n) space

### Data Structures

- **Array Access**: O(1) time, O(n) space
- **Linked List Traversal**: O(n) time, O(n) space
- **Binary Tree Operations**: O(log n) average time, O(n) space

## Recurrence Relations

### 1. Linear Recursion

```cpp
T(n) = T(n-1) + O(1)
T(n) = O(n)
```

**Example**: Factorial, linear search

### 2. Divide and Conquer

```cpp
T(n) = 2T(n/2) + O(n)
T(n) = O(n log n)
```

**Example**: Merge sort, quick sort

### 3. Exponential Recursion

```cpp
T(n) = 2T(n-1) + O(1)
T(n) = O(2^n)
```

**Example**: Fibonacci, subset generation

## Space Complexity Considerations

### 1. Input Space

- **Arrays**: O(n) space for input
- **Recursion Stack**: O(n) space for call stack
- **Auxiliary Space**: Extra space used by algorithm

### 2. Memory Hierarchy

- **Cache**: Fast access, limited size
- **RAM**: Main memory, larger but slower
- **Disk**: Slow access, very large

### 3. Trade-off Examples

- **Merge Sort**: O(n log n) time, O(n) space
- **Quick Sort**: O(n log n) time, O(log n) space
- **Hash Table**: O(1) time, O(n) space

## Optimization Techniques

### 1. Time Optimization

- **Precomputation**: Compute values once, use multiple times
- **Caching**: Store results of expensive operations
- **Algorithm Selection**: Choose best algorithm for problem

### 2. Space Optimization

- **In-place Algorithms**: Modify input without extra space
- **Streaming**: Process data without storing all
- **Compression**: Reduce memory usage

### 3. Hybrid Approaches

- **Time-Space Tradeoff**: Accept more space for faster time
- **Approximation**: Accept less accuracy for better performance
- **Parallelization**: Use multiple processors

## Common Complexity Classes

| Complexity | Time Examples                  | Space Examples       | When to Use           |
| ---------- | ------------------------------ | -------------------- | --------------------- |
| O(1)       | Array access, arithmetic       | Variables, constants | Simple operations     |
| O(log n)   | Binary search, tree operations | Recursion stack      | Large datasets        |
| O(n)       | Linear search, array traversal | Input arrays         | Sequential processing |
| O(n log n) | Efficient sorting              | Merge sort auxiliary | General sorting       |
| O(n²)      | Nested loops, simple sorting   | 2D arrays            | Small datasets        |
| O(2^n)     | Subset generation, recursion   | Recursion tree       | Very small n          |

## Key Takeaways

- **Asymptotic Analysis**: Focus on growth rate, not constants
- **Best Practice**: Analyze both time and space complexity
- **Trade-offs**: Sometimes need to choose between time and space
- **Scalability**: Consider how algorithm performs with large inputs
- **Optimization**: Always look for better algorithms

## Common Mistakes to Avoid

- Forgetting to consider space complexity
- Ignoring constants in small input cases
- Not analyzing all code paths
- Confusing worst case with average case
- Forgetting about recursion stack space

## Interview Tips

- **Always specify**: Best, worst, or average case
- **Consider constraints**: Time limits, memory limits
- **Think scalability**: How does it perform with large n?
- **Compare alternatives**: Is there a better algorithm?
- **Edge cases**: Test with n=0, n=1, n=2

## Real-World Applications

- **Database Systems**: Query optimization, indexing
- **Web Services**: API response times, scalability
- **Machine Learning**: Training time, memory usage
- **Game Development**: Frame rates, memory management
- **Network Systems**: Routing, data transmission

## Performance Guidelines

- **O(1)**: Always acceptable
- **O(log n)**: Excellent for large datasets
- **O(n)**: Good for linear operations
- **O(n log n)**: Acceptable for sorting
- **O(n²)**: Only for small datasets (n < 1000)
- **O(2^n)**: Only for very small datasets (n < 20)
