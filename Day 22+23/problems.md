# Day 22+23: Time and Space Complexity - Problems

## Problem List

### 1. Analyze Time Complexity of Bubble Sort

- **Description**: Given the bubble sort algorithm, determine its time complexity in best, worst, and average cases.
- **Code Snippet**:
  ```cpp
  void bubbleSort(int arr[], int n) {
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n - i - 1; j++) {
              if(arr[j] > arr[j + 1]) {
                  swap(arr[j], arr[j + 1]);
              }
          }
      }
  }
  ```
- **Expected Answer**: Best: O(n), Worst: O(n^2), Average: O(n^2)
- **Approach**: Count the number of comparisons and swaps in nested loops.

### 2. Analyze Space Complexity of Merge Sort

- **Description**: Determine the space complexity of merge sort and suggest optimizations.
- **Code Snippet**:
  ```cpp
  void mergeSort(int arr[], int n) {
      if(n <= 1) return;
      int mid = n / 2;
      mergeSort(arr, mid);
      mergeSort(arr + mid, n - mid);
      merge(arr, mid, n - mid);
  }
  ```
- **Expected Answer**: O(n) space due to temporary array in merge, but can be optimized to O(1) with in-place merge.
- **Approach**: Consider auxiliary space for merging and recursion stack.

### 3. Find Time Complexity of Recursive Fibonacci

- **Description**: Analyze the time complexity of the naive recursive Fibonacci function.
- **Code Snippet**:
  ```cpp
  int fibonacci(int n) {
      if(n <= 1) return n;
      return fibonacci(n-1) + fibonacci(n-2);
  }
  ```
- **Expected Answer**: O(2^n) due to overlapping subproblems.
- **Approach**: Draw the recursion tree and count the number of calls.

### 4. Optimize Algorithm for Better Complexity

- **Description**: Given a function that finds the maximum element using nested loops, optimize it for better time complexity.
- **Code Snippet**:
  ```cpp
  int findMax(int arr[], int n) {
      int max = arr[0];
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
              if(arr[i] > max) max = arr[i];
          }
      }
      return max;
  }
  ```
- **Expected Answer**: Original: O(n^2), Optimized: O(n) by removing inner loop.
- **Approach**: Identify redundant operations and simplify.

### 5. Analyze Space Complexity of 2D Array Operations

- **Description**: Determine the space complexity of creating and traversing a 2D array.
- **Code Snippet**:
  ```cpp
  void processMatrix(int n) {
      int** matrix = new int*[n];
      for(int i = 0; i < n; i++) {
          matrix[i] = new int[n];
      }
      // Process matrix
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
              // Some operation
          }
      }
  }
  ```
- **Expected Answer**: O(n^2) space for the matrix.
- **Approach**: Count the memory allocated for the 2D array.

## Additional Challenges

- Analyze the complexity of quick sort in best, worst, and average cases.
- Determine the space complexity of a recursive function with multiple parameters.
- Find the time complexity of matrix multiplication using nested loops.
- Optimize a given algorithm to reduce space complexity without increasing time complexity significantly.
- Compare the complexities of different sorting algorithms and choose the best for a given scenario.

## Notes

- Always consider best, worst, and average cases for time complexity.
- For space complexity, include input space, auxiliary space, and recursion stack.
- Use Big O notation and drop constants and lower-order terms.
- Practice solving recurrence relations for recursive algorithms.
- Consider real-world constraints like memory limits in interviews.
