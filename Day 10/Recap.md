# Day 10: Arrays Part 1

## Topics Covered

- **Array Declaration**: Static and dynamic array creation
- **Array Traversal**: Accessing elements using indices
- **Linear Search**: Sequential search algorithm O(n)
- **Binary Search**: Divide and conquer search algorithm O(log n)
- **Array Reversal**: Two approaches - with and without extra space
- **Min/Max Finding**: Finding smallest and largest elements
- **Two Pointer Technique**: Efficient array manipulation

## Key Concepts

1. **Array Basics**: Contiguous memory allocation for elements
2. **Search Algorithms**: Linear vs Binary search complexity
3. **Array Manipulation**: Reversing and modifying array elements
4. **Time Complexity**: Understanding algorithmic performance
5. **Space Complexity**: Memory usage considerations

## Code Examples

### 1. Finding Min/Max in Array

```cpp
int marks[] = {1, 2, 3, 5, 7};
int n = sizeof(marks) / sizeof(int);

int max = marks[0];
int min = marks[0];

for(int i = 0; i < n; i++) {
    if(marks[i] > max) max = marks[i];
    if(marks[i] < min) min = marks[i];
}

cout << "Largest = " << max << endl;
cout << "Smallest = " << min << endl;
```

### 2. Linear Search Algorithm

```cpp
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

### 3. Array Reversal (Two Pointer Approach)

```cpp
// Reverse without extra space
int si = 0, ei = size-1;
while(si < ei) {
    swap(arr[si], arr[ei]);
    si++;
    ei--;
}
printArray(arr, size);
```

### 4. Binary Search Algorithm

```cpp
int binarySearch(int arr[], int size, int key) {
    int si = 0, ei = size-1;

    while(si <= ei) {
        int mid = (si + ei) / 2;

        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            ei = mid - 1;
        } else {
            si = mid + 1;
        }
    }
    return -1;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
// Requirements: Sorted array
```

### 5. Array Printing Function

```cpp
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        (i == size-1) ? cout << arr[i] : cout << arr[i] << ", ";
    }
    cout << "\n";
}
```

## Algorithm Complexities

### Linear Search

- **Best Case**: O(1) - element found at first position
- **Worst Case**: O(n) - element not found or at last position
- **Average Case**: O(n)
- **Space**: O(1) - constant extra space

### Binary Search

- **Best Case**: O(1) - element found at middle in first comparison
- **Worst Case**: O(log n) - logarithmic time
- **Average Case**: O(log n)
- **Space**: O(1) - constant extra space
- **Requirement**: Array must be sorted

## Key Takeaways

- **Array Size**: Use `sizeof(array)/sizeof(data_type)` to get size
- **Index Range**: Array indices start from 0 to size-1
- **Pass by Reference**: Arrays are always passed by reference in functions
- **Search Choice**: Use binary search for sorted arrays, linear search for unsorted
- **Two Pointers**: Efficient technique for array reversal and other operations

## Common Mistakes to Avoid

- Array index out of bounds errors
- Forgetting to pass array size to functions
- Using binary search on unsorted arrays
- Incorrect calculation of middle index in binary search
- Not handling edge cases (empty array, single element)

## When to Use Which Search

- **Linear Search**: Small arrays, unsorted arrays, frequent insertions/deletions
- **Binary Search**: Large sorted arrays, read-heavy operations, when sorting overhead is acceptable
