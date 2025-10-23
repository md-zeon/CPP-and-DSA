# Day 12: Sorting - Practice Problems

## Problem 1: Bubble Sort Implementation

**Difficulty:** Easy

### Description

Implement bubble sort algorithm to sort an array in ascending order.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the array after each pass of bubble sort

### Sample Input

```
5
64 34 25 12 22
```

### Sample Output

```
After pass 1: 34 25 12 22 64
After pass 2: 25 12 22 34 64
After pass 3: 12 22 25 34 64
After pass 4: 12 22 25 34 64
```

### Algorithm

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
        if(!isSwap) return;
    }
}
```

### Time Complexity

- Worst Case: O(n²)
- Best Case: O(n) (already sorted)

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 2: Selection Sort Implementation

**Difficulty:** Easy

### Description

Implement selection sort algorithm.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print array after each iteration

### Sample Input

```
6
64 25 12 22 11 34
```

### Sample Output

```
After iteration 1: 11 25 12 22 64 34
After iteration 2: 11 12 25 22 64 34
After iteration 3: 11 12 22 25 64 34
After iteration 4: 11 12 22 25 64 34
After iteration 5: 11 12 22 25 34 64
```

### Algorithm

```cpp
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 3: Insertion Sort Implementation

**Difficulty:** Easy

### Description

Implement insertion sort algorithm.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print array after each insertion

### Sample Input

```
6
12 11 13 5 6 7
```

### Sample Output

```
After inserting 11: 11 12 13 5 6 7
After inserting 13: 11 12 13 5 6 7
After inserting 5: 5 11 12 13 6 7
After inserting 6: 5 6 11 12 13 7
After inserting 7: 5 6 7 11 12 13
```

### Algorithm

```cpp
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 4: Counting Sort Implementation

**Difficulty:** Medium

### Description

Implement counting sort for positive integers.

### Input Format

- Array size `n`
- `n` positive integers

### Output Format

- Print the sorted array

### Sample Input

```
8
4 2 2 8 3 3 1 1
```

### Sample Output

```
1 1 2 2 3 3 4 8
```

### Algorithm

1. Find min and max values
2. Create frequency array
3. Fill frequency array
4. Reconstruct sorted array

### Constraints

- 1 ≤ n ≤ 10^5
- 1 ≤ array elements ≤ 100

---

## Problem 5: Sort Characters in Descending Order

**Difficulty:** Easy

### Description

Sort an array of characters in descending order using insertion sort.

### Input Format

- Array size `n`
- `n` characters

### Output Format

- Print the sorted array in descending order

### Sample Input

```
6
f b a e c d
```

### Sample Output

```
f e d c b a
```

### Algorithm

- Modify insertion sort for descending order
- Change comparison from `>` to `<`

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 6: Built-in Sort with Custom Comparator

**Difficulty:** Easy

### Description

Use C++ built-in sort with custom comparator.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print array sorted in descending order

### Sample Input

```
5
3 1 4 1 5
```

### Sample Output

```
5 4 3 1 1
```

### Code Example

```cpp
sort(arr, arr+n, greater<int>());
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 7: Sort Array Partially

**Difficulty:** Easy

### Description

Sort only part of an array using built-in sort.

### Input Format

- Array size `n`
- `n` integers
- Start and end indices

### Output Format

- Print array with specified range sorted

### Sample Input

```
6
3 1 4 1 5 9
2 5
```

### Sample Output

```
3 1 1 4 5 9
```

### Code Example

```cpp
sort(arr+start, arr+end);
```

### Constraints

- 1 ≤ n ≤ 10^5
- 0 ≤ start ≤ end ≤ n

---

## Problem 8: Check if Array is Sorted

**Difficulty:** Easy

### Description

Check if an array is already sorted in ascending order.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print "Sorted" or "Not Sorted"

### Sample Input 1

```
5
1 2 3 4 5
```

### Sample Output 1

```
Sorted
```

### Sample Input 2

```
5
1 3 2 4 5
```

### Sample Output 2

```
Not Sorted
```

### Algorithm

```cpp
bool isSorted(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            return false;
        }
    }
    return true;
}
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 9: Find Kth Smallest Element

**Difficulty:** Medium

### Description

Find the kth smallest element in an unsorted array.

### Input Format

- Array size `n`
- `n` integers
- Integer `k`

### Output Format

- Print the kth smallest element

### Sample Input

```
7
7 10 4 3 20 15 1
3
```

### Sample Output

```
4
```

### Algorithm

1. Sort the array
2. Return element at index k-1

### Constraints

- 1 ≤ n ≤ 10^4
- 1 ≤ k ≤ n

---

## Problem 10: Sort Array of 0s, 1s, and 2s

**Difficulty:** Easy

### Description

Sort an array containing only 0s, 1s, and 2s (Dutch National Flag problem).

### Input Format

- Array size `n`
- `n` integers (only 0, 1, 2)

### Output Format

- Print the sorted array

### Sample Input

```
9
0 1 2 0 1 2 0 1 2
```

### Sample Output

```
0 0 0 1 1 1 2 2 2
```

### Algorithm (Three Pointer Technique)

```cpp
void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n-1;
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
```

### Constraints

- 1 ≤ n ≤ 10^6

---

## Problem 11: Sort Strings Lexicographically

**Difficulty:** Easy

### Description

Sort an array of strings in lexicographical order.

### Input Format

- Number of strings `n`
- `n` strings

### Output Format

- Print strings in sorted order

### Sample Input

```
5
apple
banana
cherry
date
elderberry
```

### Sample Output

```
apple
banana
cherry
date
elderberry
```

### Code Example

```cpp
string words[n];
for(int i = 0; i < n; i++) {
    cin >> words[i];
}
sort(words, words+n);
```

### Constraints

- 1 ≤ n ≤ 1000
- String length ≤ 100

---

## Problem 12: Sort by String Length

**Difficulty:** Medium

### Description

Sort strings by their length (shortest first).

### Input Format

- Number of strings `n`
- `n` strings

### Output Format

- Print strings sorted by length

### Sample Input

```
4
a
bbb
cc
dddd
```

### Sample Output

```
a
cc
bbb
dddd
```

### Custom Comparator

```cpp
bool compareByLength(string a, string b) {
    return a.length() < b.length();
}

sort(words, words+n, compareByLength);
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 13: Sort Negative and Positive Numbers

**Difficulty:** Medium

### Description

Sort an array such that all negative numbers come before positive numbers.

### Input Format

- Array size `n`
- `n` integers (positive and negative)

### Output Format

- Print the sorted array

### Sample Input

```
8
-1 2 -3 4 5 -6 -7 8
```

### Sample Output

```
-1 -3 -6 -7 2 4 5 8
```

### Algorithm

1. Use two pointer approach
2. Place negative numbers on left, positive on right

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 14: Sort Even and Odd Numbers

**Difficulty:** Medium

### Description

Sort even numbers in ascending and odd numbers in descending order.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the sorted array

### Sample Input

```
8
1 2 3 4 5 6 7 8
```

### Sample Output

```
2 4 6 8 7 5 3 1
```

### Algorithm

1. Separate even and odd numbers
2. Sort even numbers in ascending order
3. Sort odd numbers in descending order
4. Combine them

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 15: Stable Sort Demonstration

**Difficulty:** Medium

### Description

Demonstrate stable sort using structures.

### Input Format

- Number of students `n`
- `n` lines of roll number and name

### Output Format

- Print students sorted by roll number (stable)

### Sample Input

```
5
101 John
103 Bob
102 John
104 Alice
105 Bob
```

### Sample Output

```
101 John
102 John
103 Bob
104 Alice
105 Bob
```

### Code Example

```cpp
struct Student {
    int roll;
    string name;
};

bool compare(Student a, Student b) {
    return a.roll < b.roll;
}

stable_sort(students, students+n, compare);
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Additional Practice Problems

### Problem 16: Sort Array in Wave Form

Sort array in wave form (a[0] >= a[1] <= a[2] >= a[3] <= a[4]...)

### Problem 17: Sort by Frequency

Sort elements by their frequency in the array.

### Problem 18: Sort Dates

Sort dates in chronological order.

### Problem 19: Sort Fractions

Sort fractions in ascending order.

### Problem 20: Sort with Custom Criteria

Sort based on multiple criteria (marks, then name).

### Problem 21: Bucket Sort

Implement bucket sort for floating point numbers.

### Problem 22: Radix Sort

Implement radix sort for integers.

### Problem 23: External Sorting

Concept of sorting large files that don't fit in memory.

### Problem 24: Sort Nearly Sorted Array

Sort array where each element is at most k positions away.

### Problem 25: Sort Matrix Diagonally

Sort matrix elements diagonally.

## Sorting Algorithm Comparison

| Algorithm          | Time Complexity | Space Complexity | Stable | In-Place |
| ------------------ | --------------- | ---------------- | ------ | -------- |
| **Bubble Sort**    | O(n²)           | O(1)             | Yes    | Yes      |
| **Selection Sort** | O(n²)           | O(1)             | No     | Yes      |
| **Insertion Sort** | O(n²)           | O(1)             | Yes    | Yes      |
| **Merge Sort**     | O(n log n)      | O(n)             | Yes    | No       |
| **Quick Sort**     | O(n log n)      | O(log n)         | No     | Yes      |
| **Heap Sort**      | O(n log n)      | O(1)             | No     | Yes      |
| **Counting Sort**  | O(n + k)        | O(k)             | Yes    | No       |

## Key Takeaways

### When to Use Which Algorithm

1. **Bubble Sort**

   - Small arrays
   - Already sorted arrays (adaptive)
   - Educational purposes

2. **Selection Sort**

   - Small arrays
   - Minimize swaps
   - Memory writes are expensive

3. **Insertion Sort**

   - Small arrays
   - Nearly sorted arrays
   - Online sorting (new elements added)

4. **Merge Sort**

   - Large arrays
   - Stable sort required
   - Linked lists

5. **Quick Sort**

   - Large arrays
   - Average case performance
   - In-place sorting needed

6. **Heap Sort**
   - Large arrays
   - In-place sorting needed
   - Memory constrained

### Built-in Sort Usage

```cpp
// Ascending order
sort(arr, arr+n);

// Descending order
sort(arr, arr+n, greater<int>());

// Partial sort
sort(arr, arr+k); // Sort first k elements

// Custom comparator
sort(arr, arr+n, compareFunction);

// Stable sort
stable_sort(arr, arr+n, compareFunction);
```

### Common Patterns

```cpp
// Pattern 1: Basic sort
sort(arr, arr+n);

// Pattern 2: Custom comparator
bool compare(int a, int b) {
    return a > b; // Descending
}
sort(arr, arr+n, compare);

// Pattern 3: Structure sorting
struct Point {
    int x, y;
};
bool compare(Point a, Point b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
sort(points, points+n, compare);
```

### Best Practices

- **Choose right algorithm:** Consider data size and constraints
- **Use built-in sort:** For most practical purposes
- **Understand stability:** When order matters
- **Consider space:** In-place vs out-of-place
- **Handle duplicates:** Depending on requirement

### Common Mistakes

- **Wrong range:** `sort(arr, arr+n)` not `sort(arr, n)`
- **Comparator logic:** Incorrect return values
- **Data types:** Overflow in comparisons
- **Stability misunderstanding:** When order preservation matters

### Optimization Tips

- Use insertion sort for small subarrays in hybrid sorts
- Choose pivot carefully in quicksort
- Use counting sort for small range integers
- Consider radix sort for large numbers

### Interview Tips

- **Explain algorithm:** Step by step
- **Time complexity:** Best, worst, average cases
- **Space complexity:** In-place or not
- **Stability:** When it matters
- **Edge cases:** Already sorted, reverse sorted, duplicates

### Real-World Applications

1. **Databases**

   - ORDER BY queries
   - Index maintenance
   - Join operations

2. **Search Engines**

   - Ranking algorithms
   - Result ordering
   - Relevance scoring

3. **E-commerce**

   - Price sorting
   - Rating sorting
   - Recommendation systems

4. **Multimedia**

   - Playlist ordering
   - Photo album sorting
   - File management

5. **Gaming**
   - Leaderboard maintenance
   - Score sorting
   - Tournament brackets

### Advanced Topics

1. **External Sorting**

   - Sorting large files
   - Multi-way merge
   - Distributed sorting

2. **Parallel Sorting**

   - Multi-threaded sorting
   - GPU sorting
   - Cluster sorting

3. **Approximate Sorting**

   - Partial sorting
   - Top-k elements
   - Quantile finding

4. **Adaptive Sorting**
   - Already sorted detection
   - Nearly sorted optimization
   - Hybrid algorithms
