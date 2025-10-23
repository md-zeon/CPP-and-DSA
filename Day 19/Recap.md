# Day 19: Recursion Part 1

## Topics Covered

- **Recursion Basics**: Function calling itself
- **Base Cases**: Stopping conditions for recursion
- **Recursive Cases**: Problems broken into smaller subproblems
- **Factorial Calculation**: Classic recursive example
- **Fibonacci Series**: Multiple recursive calls
- **Array Operations**: Checking sorted array, finding occurrences
- **Fast Exponentiation**: Optimized power calculation

## Key Concepts

1. **Recursive Function**: Function that calls itself
2. **Base Case**: Condition that stops recursion
3. **Recursive Case**: Problem reduced to smaller instance
4. **Call Stack**: Memory management during recursion
5. **Time Complexity**: Exponential vs linear recursion

## Code Examples

### 1. Factorial using Recursion

```cpp
int factorial(int n) {
    // Base case
    if(n == 0) {
        return 1;
    }
    // Recursive case
    return n * factorial(n-1);
}

// Example: factorial(5)
// 5 * factorial(4)
// 5 * 4 * factorial(3)
// 5 * 4 * 3 * factorial(2)
// 5 * 4 * 3 * 2 * factorial(1)
// 5 * 4 * 3 * 2 * 1 * factorial(0)
// 5 * 4 * 3 * 2 * 1 * 1 = 120
```

### 2. Print Numbers in Decreasing Order

```cpp
void decreasingOrder(int n) {
    if(n < 1) {
        return;  // Base case
    }
    cout << n << " ";
    decreasingOrder(n-1);  // Recursive call
}

// Example: decreasingOrder(5)
// Output: 5 4 3 2 1
```

### 3. Print Numbers in Increasing Order

```cpp
void increasingOrder(int n) {
    if(n < 1) {
        return;  // Base case
    }
    increasingOrder(n-1);  // Recursive call first
    cout << n << " ";      // Then print
}

// Example: increasingOrder(5)
// Output: 1 2 3 4 5
```

### 4. Sum of Natural Numbers

```cpp
int naturalSum(int n) {
    if(n == 1) {
        return 1;  // Base case
    }
    return (n + naturalSum(n-1));  // Recursive case
}

// Example: naturalSum(5)
// 5 + naturalSum(4)
// 5 + 4 + naturalSum(3)
// 5 + 4 + 3 + naturalSum(2)
// 5 + 4 + 3 + 2 + naturalSum(1)
// 5 + 4 + 3 + 2 + 1 = 15
```

### 5. Fibonacci Series

```cpp
int nthFibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;  // Base cases
    }
    return nthFibonacci(n-1) + nthFibonacci(n-2);  // Recursive case
}

// Example: nthFibonacci(5)
// F(5) = F(4) + F(3)
// F(5) = (F(3) + F(2)) + (F(2) + F(1))
// F(5) = ((F(2) + F(1)) + (F(1) + F(0))) + ((F(1) + F(0)) + F(1))
// F(5) = ((1 + 1) + 1) + 1 = 5
```

### 6. Check if Array is Sorted

```cpp
bool isSorted(int arr[], int n, int i) {
    if(i == n-1) {
        return true;  // Base case: reached end
    }
    if(arr[i] > arr[i+1]) {
        return false;  // Not sorted
    }
    return isSorted(arr, n, i+1);  // Recursive case
}

// Example: isSorted({1,2,3,4,5}, 5, 0)
// Check arr[0] <= arr[1], then recurse to next index
```

### 7. First Occurrence in Vector

```cpp
int firstOccur(vector<int> arr, int target) {
    static int i = 0;  // Static variable maintains state
    if(i == arr.size()) {
        return -1;  // Base case: not found
    }
    if(arr[i] == target) {
        return i;  // Found at current index
    }
    i++;  // Move to next index
    return firstOccur(arr, target);  // Recursive call
}
```

### 8. Last Occurrence in Vector

```cpp
int lastOccur(vector<int> arr, int target, int i) {
    if(i == arr.size()) {
        return -1;  // Base case: not found
    }
    int idx = lastOccur(arr, target, i+1);  // Search in rest of array
    if(idx == -1 && arr[i] == target) {
        return i;  // Found at current index
    }
    return idx;  // Return found index from recursive call
}
```

### 9. Fast Exponentiation (Optimized Power)

```cpp
int power(int x, int n) {
    if(n == 0) {
        return 1;  // Base case
    }

    int halfPower = power(x, n/2);  // Recursive call
    int halfPowerSquare = halfPower * halfPower;

    if(n % 2 == 0) {
        return halfPowerSquare;  // Even power
    }
    return x * halfPowerSquare;  // Odd power
}

// Example: power(5, 3)
// power(5, 1) = 5 * power(5, 0) = 5 * 1 = 5
// power(5, 3) = 5 * power(5, 1) = 5 * 5 = 25
// Time Complexity: O(log n)
```

## Recursion Components

### 1. Base Case

- **Purpose**: Stops infinite recursion
- **Location**: Usually at beginning of function
- **Examples**: `if(n == 0)`, `if(i == size)`, `if(n == 1)`

### 2. Recursive Case

- **Purpose**: Breaks problem into smaller subproblems
- **Pattern**: Function calls itself with modified parameters
- **Progress**: Parameters should move towards base case

### 3. Return Statement

- **Direct Return**: For simple recursive functions
- **Computed Return**: Combine current result with recursive result

## Recursion Types

### 1. Linear Recursion

- **Calls**: Single recursive call
- **Examples**: Factorial, sum of natural numbers
- **Stack Depth**: O(n)

### 2. Tree Recursion

- **Calls**: Multiple recursive calls
- **Examples**: Fibonacci (two calls)
- **Stack Depth**: O(n)
- **Time Complexity**: O(2^n) - exponential

### 3. Tail Recursion

- **Pattern**: Recursive call is last operation
- **Optimization**: Can be optimized to iterative
- **Example**: `return factorial(n-1) * n;`

## Key Takeaways

- **Base Case**: Essential to prevent infinite recursion
- **Stack Overflow**: Too many recursive calls can crash program
- **Problem Reduction**: Each call should reduce problem size
- **Return Path**: Values propagate back through call stack
- **Static Variables**: Maintain state across recursive calls
- **Optimization**: Fast exponentiation uses divide and conquer

## Common Mistakes to Avoid

- Missing or incorrect base case
- Not reducing problem size in recursive calls
- Stack overflow due to deep recursion
- Incorrect return statements
- Not handling edge cases (n=0, n=1, empty arrays)

## Time Complexities

| Function     | Time Complexity | Space Complexity | Type             |
| ------------ | --------------- | ---------------- | ---------------- |
| Factorial    | O(n)            | O(n)             | Linear           |
| Fibonacci    | O(2^n)          | O(n)             | Tree             |
| Power (Fast) | O(log n)        | O(log n)         | Divide & Conquer |
| Array Search | O(n)            | O(n)             | Linear           |
| Sorted Check | O(n)            | O(n)             | Linear           |

## Recursion vs Iteration

### Recursion

- **Pros**: Elegant, easier to understand for some problems
- **Cons**: Stack overflow risk, function call overhead
- **Use**: Tree problems, divide and conquer, backtracking

### Iteration

- **Pros**: No stack overflow, usually more efficient
- **Cons**: Sometimes harder to implement
- **Use**: Simple loops, large datasets

## Optimization Techniques

- **Memoization**: Cache results of expensive function calls
- **Dynamic Programming**: Bottom-up approach using iteration
- **Tail Recursion**: Can be optimized by compiler
- **Divide and Conquer**: Break into smaller independent subproblems

## Call Stack Visualization

### Factorial(5)

```
factorial(5) -> 5 * factorial(4)
factorial(4) -> 4 * factorial(3)
factorial(3) -> 3 * factorial(2)
factorial(2) -> 2 * factorial(1)
factorial(1) -> 1 * factorial(0)
factorial(0) -> 1 (base case)
```

### Return Path

```
1 (from base case)
1 * 1 = 1 (factorial(1))
2 * 1 = 2 (factorial(2))
3 * 2 = 6 (factorial(3))
4 * 6 = 24 (factorial(4))
5 * 24 = 120 (factorial(5))
```
