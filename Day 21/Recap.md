# Day 21: Divide and Conquer

## Topics Covered

- **Merge Sort**: Divide and conquer sorting algorithm
- **Quick Sort**: In-place divide and conquer sorting
- **Partition Algorithm**: Core component of quick sort
- **Rotated Array Search**: Finding elements in rotated sorted arrays
- **Binary Search Variations**: Modified binary search for special cases
- **Recursive Algorithms**: Divide, conquer, and combine pattern

## Key Concepts

1. **Divide and Conquer**: Break problem into smaller subproblems
2. **Merge Process**: Combining sorted subarrays
3. **Pivot Selection**: Choosing element for partitioning
4. **Rotation Handling**: Dealing with rotated sorted arrays
5. **Time Complexity**: Logarithmic time for search, linearithmic for sorting

## Code Examples

### 1. Merge Sort Algorithm

```cpp
void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    // Merge two sorted halves
    while(i <= mid && j <= ei) {
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements
    while(i <= mid) {
        temp.push_back(arr[i++]);
    }
    while(j <= ei) {
        temp.push_back(arr[j++]);
    }

    // Copy back to original array
    for(int i = si, k = 0; k < temp.size(); i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;  // Base case
    }

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);      // Sort left half
    mergeSort(arr, mid + 1, ei);  // Sort right half
    merge(arr, si, mid, ei);      // Merge sorted halves
}

// Time Complexity: O(n log n)
// Space Complexity: O(n) - temporary array
```

### 2. Quick Sort Algorithm

```cpp
int partition(int arr[], int si, int ei) {
    int i = si - 1;
    int pivot = arr[ei];  // Last element as pivot

    for(int j = si; j < ei; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);  // Place pivot in correct position

    return i;  // Return pivot index
}

void quickSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;  // Base case
    }

    int pivotIdx = partition(arr, si, ei);
    quickSort(arr, si, pivotIdx - 1);  // Sort left part
    quickSort(arr, pivotIdx + 1, ei);  // Sort right part
}

// Time Complexity: O(n log n) average, O(n²) worst case
// Space Complexity: O(log n) - call stack
```

### 3. Search in Rotated Sorted Array

```cpp
int search(int arr[], int si, int ei, int target) {
    if(si > ei) {
        return -1;  // Base case: not found
    }

    int mid = si + (ei - si) / 2;

    if(arr[mid] == target) {
        return mid;  // Found at middle
    }

    // Check if left half is sorted
    if(arr[si] <= arr[mid]) {
        // Target in left half
        if(arr[si] <= target && target <= arr[mid]) {
            return search(arr, si, mid - 1, target);
        } else {
            // Target in right half
            return search(arr, mid + 1, ei, target);
        }
    } else {
        // Right half is sorted
        // Target in right half
        if(arr[mid] <= target && target <= arr[ei]) {
            return search(arr, mid + 1, ei, target);
        } else {
            // Target in left half
            return search(arr, si, mid - 1, target);
        }
    }
}

// Example: [4, 5, 6, 7, 0, 1, 2] search for 0
// Time Complexity: O(log n)
// Space Complexity: O(log n) - call stack
```

## Algorithm Analysis

### Merge Sort

- **Divide**: Split array into two halves
- **Conquer**: Recursively sort both halves
- **Combine**: Merge two sorted halves
- **Stable**: Maintains order of equal elements
- **Consistent**: O(n log n) time regardless of input

### Quick Sort

- **Divide**: Choose pivot and partition array
- **Conquer**: Recursively sort subarrays
- **Combine**: No combine step (in-place)
- **Unstable**: May change order of equal elements
- **Performance**: Depends on pivot selection

### Rotated Array Search

- **Challenge**: Array is sorted but rotated
- **Solution**: Determine which half is sorted
- **Decision**: Choose appropriate half to search
- **Optimization**: Single pass through sorted portions

## Divide and Conquer Pattern

### 1. Divide Phase

- **Split**: Break problem into smaller subproblems
- **Midpoint**: Calculate middle index carefully
- **Base Case**: Handle smallest possible problem

### 2. Conquer Phase

- **Recursive Calls**: Solve subproblems independently
- **Parallel**: Subproblems don't depend on each other
- **Depth**: Logarithmic depth for balanced splits

### 3. Combine Phase

- **Merge**: Combine solutions of subproblems
- **In-Place**: Some algorithms don't need extra space
- **Result**: Build final solution from subproblem results

## Key Takeaways

- **Mid Calculation**: `mid = si + (ei - si) / 2` prevents overflow
- **Pivot Selection**: Last element is simple but not optimal
- **Rotation Point**: Identify where rotation occurred
- **Space Tradeoff**: Merge sort uses extra space, quick sort is in-place
- **Stability**: Merge sort is stable, quick sort is not

## Common Mistakes to Avoid

- Integer overflow in mid calculation (`si + ei` can overflow)
- Incorrect base cases in recursive functions
- Not handling edge cases (empty arrays, single element)
- Forgetting to copy merged results back to original array
- Incorrect pivot index calculation in quick sort

## Algorithm Comparison

| Algorithm      | Time Complexity | Space Complexity | Stable | In-Place |
| -------------- | --------------- | ---------------- | ------ | -------- |
| Merge Sort     | O(n log n)      | O(n)             | Yes    | No       |
| Quick Sort     | O(n log n) avg  | O(log n)         | No     | Yes      |
| Rotated Search | O(log n)        | O(log n)         | N/A    | Yes      |

## Optimization Techniques

### Quick Sort Optimizations

- **Median of Three**: Choose better pivot
- **Random Pivot**: Avoid worst-case scenarios
- **Small Array**: Switch to insertion sort for small subarrays
- **Dual Pivot**: Use two pivots for better performance

### Merge Sort Optimizations

- **In-Place Merge**: Reduce space complexity
- **Bottom-Up**: Iterative implementation
- **Parallel Merge**: Utilize multiple processors

## Applications

### Merge Sort

- **External Sorting**: Large files that don't fit in memory
- **Stable Sorting**: When maintaining order is important
- **Linked Lists**: Natural fit for linked list sorting
- **Inversion Counting**: Count inversions in array

### Quick Sort

- **General Purpose**: Most programming languages use optimized quick sort
- **In-Place Sorting**: When memory is constrained
- **Average Case**: Best general-purpose sorting algorithm
- **Partial Sorting**: Sort only part of array

### Rotated Array Search

- **Search Engines**: Finding elements in rotated datasets
- **Database Indexing**: Searching in rotated index structures
- **Circular Buffers**: Finding elements in circular data structures
- **Log Analysis**: Searching in rotated log files

## Interview Tips

- **Pattern Recognition**: Identify divide and conquer opportunities
- **Base Cases**: Always define clear stopping conditions
- **Space Complexity**: Consider memory constraints
- **Pivot Selection**: Discuss different strategies for quick sort
- **Edge Cases**: Test with rotated arrays, duplicates, empty arrays

## Problem Variations

- **Kth Smallest Element**: Using quick sort partition
- **Merge K Sorted Arrays**: Extension of merge sort
- **Find Rotation Point**: Locate minimum in rotated array
- **Search in Nearly Sorted Array**: Modified binary search
