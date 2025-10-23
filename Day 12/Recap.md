# Day 12: Sorting Algorithms

## Topics Covered

- **Bubble Sort**: Simple comparison-based sorting algorithm
- **Selection Sort**: Finding minimum element and placing it correctly
- **Insertion Sort**: Building sorted array one element at a time
- **Counting Sort**: Efficient sorting for small range of integers
- **Inbuilt Sort**: Using STL sort function with custom comparators
- **Sorting Characters**: Applying sorting algorithms to character arrays

## Key Concepts

1. **Comparison Based Sorting**: Algorithms that compare elements
2. **Non-Comparison Sorting**: Counting sort for specific ranges
3. **Time Complexity**: Understanding performance of different algorithms
4. **Space Complexity**: Memory requirements of sorting algorithms
5. **Stability**: Whether equal elements maintain their relative order

## Code Examples

### 1. Bubble Sort

```cpp
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        bool isSwap = false;
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return;  // Early termination if no swaps
        }
    }
}

// Time Complexity: O(n²)
// Space Complexity: O(1)
// Best Case: O(n) when already sorted
```

### 2. Selection Sort

```cpp
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minimumIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
            }
        }
        swap(arr[i], arr[minimumIndex]);
    }
}

// Time Complexity: O(n²)
// Space Complexity: O(1)
// Not stable, always O(n²)
```

### 3. Insertion Sort

```cpp
void insertionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

// Time Complexity: O(n²)
// Space Complexity: O(1)
// Best Case: O(n) when already sorted
// Stable sorting algorithm
```

### 4. Counting Sort

```cpp
void countingSort(int arr[], int n) {
    int freq[100] = {0}; // range
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for(int i = minVal, j = 0; i < maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
}

// Time Complexity: O(n + range)
// Space Complexity: O(range)
// Only for positive integers with small range
```

### 5. Inbuilt Sort Function

```cpp
// Ascending order (default)
sort(arr, arr+n);

// Descending order
sort(arr, arr+n, greater<int>());

// Partial sort (from index 2 to end)
sort(arr+2, arr+n, greater<int>());

// For arrays
sort(arr, arr+n);

// For vectors
sort(v.begin(), v.end());
```

### 6. Character Array Sorting

```cpp
void insertionSort(char arr[], int n) {
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}
```

## Algorithm Complexities

| Algorithm      | Time Complexity | Space Complexity | Stable | Best Case    |
| -------------- | --------------- | ---------------- | ------ | ------------ |
| Bubble Sort    | O(n²)           | O(1)             | Yes    | O(n)         |
| Selection Sort | O(n²)           | O(1)             | No     | O(n²)        |
| Insertion Sort | O(n²)           | O(1)             | Yes    | O(n)         |
| Counting Sort  | O(n + range)    | O(range)         | Yes    | O(n + range) |
| STL Sort       | O(n log n)      | O(log n)         | No     | O(n log n)   |

## Key Takeaways

- **Bubble Sort**: Simple but inefficient for large datasets
- **Selection Sort**: Good for small arrays, minimizes swaps
- **Insertion Sort**: Efficient for nearly sorted arrays
- **Counting Sort**: Excellent for small range of integers
- **STL Sort**: Most efficient general-purpose sorting
- **Early Termination**: Bubble sort can terminate early if no swaps occur

## Common Mistakes to Avoid

- Forgetting to handle edge cases (empty arrays, single element)
- Incorrect loop bounds in nested loops
- Not updating indices correctly in insertion sort
- Using counting sort for large ranges (memory issues)
- Forgetting to pass array size to sorting functions

## When to Use Which Algorithm

- **Bubble Sort**: Educational purposes, small datasets
- **Selection Sort**: When minimizing swaps is important
- **Insertion Sort**: Nearly sorted arrays, small datasets
- **Counting Sort**: Small range of integers, when O(n) time is needed
- **STL Sort**: General purpose, most practical applications

## Array Printing Function

```cpp
void printArray(int arr[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        (i == n-1) ? cout << arr[i] : cout << arr[i] << ", ";
    }
    cout << "]\n";
}
```
