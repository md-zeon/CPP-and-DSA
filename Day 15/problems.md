# Day 15: Vectors - Practice Problems

## Problem 1: Vector Creation and Basic Operations

**Difficulty:** Easy

### Description

Create a vector and perform basic operations like push_back, pop_back, size, capacity.

### Input Format

- Number of elements `n`
- `n` integers to insert

### Output Format

- Print vector size and capacity after each operation

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Initial size: 0, capacity: 0
After push_back 1: size: 1, capacity: 1
After push_back 2: size: 2, capacity: 2
After push_back 3: size: 3, capacity: 4
After push_back 4: size: 4, capacity: 4
After push_back 5: size: 5, capacity: 8
After pop_back: size: 4, capacity: 8
```

### Code Example

```cpp
vector<int> vec;
cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

for(int i = 0; i < 5; i++) {
    vec.push_back(i+1);
    cout << "After push_back " << i+1 << ": size: " << vec.size() << ", capacity: " << vec.capacity() << endl;
}

vec.pop_back();
cout << "After pop_back: size: " << vec.size() << ", capacity: " << vec.capacity() << endl;
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 2: Vector Initialization Methods

**Difficulty:** Easy

### Description

Demonstrate different ways to initialize vectors.

### Input Format

- No input required

### Output Format

- Print vectors created using different methods

### Sample Output

```
Empty vector: size = 0
Initialized with values: 1 2 3 4 5
Initialized with size 5, value -1: -1 -1 -1 -1 -1
```

### Code Example

```cpp
vector<int> vec1; // Empty vector
vector<int> vec2 = {1, 2, 3, 4, 5}; // List initialization
vector<int> vec3(5, -1); // Size and initial value

cout << "Empty vector: size = " << vec1.size() << endl;
cout << "Initialized with values: ";
for(int x : vec2) cout << x << " ";
cout << endl;
cout << "Initialized with size 5, value -1: ";
for(int x : vec3) cout << x << " ";
cout << endl;
```

---

## Problem 3: Vector Element Access

**Difficulty:** Easy

### Description

Access vector elements using different methods.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print elements using [], at(), front(), back()

### Sample Input

```
5
10 20 30 40 50
```

### Sample Output

```
vec[0] = 10
vec[2] = 30
vec.at(4) = 50
vec.front() = 10
vec.back() = 50
```

### Code Example

```cpp
vector<int> vec = {10, 20, 30, 40, 50};
cout << "vec[0] = " << vec[0] << endl;
cout << "vec[2] = " << vec[2] << endl;
cout << "vec.at(4) = " << vec.at(4) << endl;
cout << "vec.front() = " << vec.front() << endl;
cout << "vec.back() = " << vec.back() << endl;
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 4: Vector Modification Operations

**Difficulty:** Easy

### Description

Demonstrate vector modification operations.

### Input Format

- Initial vector size `n`
- `n` integers
- Operations to perform

### Output Format

- Print vector after each operation

### Sample Input

```
5
1 2 3 4 5
insert 10 at position 2
erase element at position 3
```

### Sample Output

```
Original: 1 2 3 4 5
After insert: 1 2 10 3 4 5
After erase: 1 2 10 4 5
```

### Code Example

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
cout << "Original: ";
for(int x : vec) cout << x << " ";
cout << endl;

// Insert 10 at position 2
vec.insert(vec.begin() + 2, 10);
cout << "After insert: ";
for(int x : vec) cout << x << " ";
cout << endl;

// Erase element at position 3
vec.erase(vec.begin() + 3);
cout << "After erase: ";
for(int x : vec) cout << x << " ";
cout << endl;
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 5: Pair Sum using Two Pointers

**Difficulty:** Medium

### Description

Find a pair of elements in a sorted vector that sum to a target value.

### Input Format

- Vector size `n`
- `n` integers (sorted)
- Target sum `target`

### Output Format

- Print indices of pair that sum to target, or "No pair found"

### Sample Input

```
4
2 7 11 15
9
```

### Sample Output

```
Pair found at indices: 0 and 1
```

### Algorithm

```cpp
vector<int> pairSum(vector<int> arr, int target) {
    int start = 0, end = arr.size() - 1;
    vector<int> ans;

    while(start < end) {
        int currSum = arr[start] + arr[end];
        if(currSum == target) {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        } else if(currSum > target) {
            end--;
        } else {
            start++;
        }
    }

    return ans; // Empty vector if no pair found
}
```

### Constraints

- 1 ≤ n ≤ 10^5
- Vector is sorted

---

## Problem 6: 2D Vector Creation

**Difficulty:** Easy

### Description

Create and manipulate a 2D vector (jagged array).

### Input Format

- Number of rows `rows`
- For each row: number of columns, then column values

### Output Format

- Print the 2D vector

### Sample Input

```
3
3 1 2 3
2 4 5
4 6 7 8 9
```

### Sample Output

```
Row 0: 1 2 3
Row 1: 4 5
Row 2: 6 7 8 9
```

### Code Example

```cpp
int rows;
cin >> rows;
vector<vector<int>> matrix;

for(int i = 0; i < rows; i++) {
    int cols;
    cin >> cols;
    vector<int> row;
    for(int j = 0; j < cols; j++) {
        int val;
        cin >> val;
        row.push_back(val);
    }
    matrix.push_back(row);
}

// Print 2D vector
for(int i = 0; i < matrix.size(); i++) {
    cout << "Row " << i << ": ";
    for(int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

### Constraints

- 1 ≤ rows ≤ 100
- 1 ≤ cols per row ≤ 100

---

## Problem 7: Vector vs Dynamic Array

**Difficulty:** Easy

### Description

Compare vector operations with manual dynamic array management.

### Input Format

- Array size `n`

### Output Format

- Demonstrate vector ease vs manual array complexity

### Sample Input

```
5
```

### Sample Output

```
Vector: Easy to use, automatic memory management
Dynamic Array: Complex, manual memory management required
```

### Code Comparison

```cpp
// Vector approach
vector<int> vec;
for(int i = 0; i < n; i++) {
    vec.push_back(i);
}
// No need to delete, automatically managed

// Dynamic array approach
int *arr = new int[n];
for(int i = 0; i < n; i++) {
    arr[i] = i;
}
// Must remember to delete[] arr;
```

---

## Problem 8: Vector Capacity Management

**Difficulty:** Medium

### Description

Demonstrate vector capacity behavior and memory management.

### Input Format

- Number of elements to insert `n`

### Output Format

- Print size and capacity after each insertion

### Sample Input

```
10
```

### Sample Output

```
After insertion 1: size=1, capacity=1
After insertion 2: size=2, capacity=2
After insertion 3: size=3, capacity=4
After insertion 4: size=4, capacity=4
After insertion 5: size=5, capacity=8
After insertion 6: size=6, capacity=8
After insertion 7: size=7, capacity=8
After insertion 8: size=8, capacity=8
After insertion 9: size=9, capacity=16
After insertion 10: size=10, capacity=16
```

### Explanation

- Vector capacity doubles when size exceeds current capacity
- Demonstrates exponential growth strategy

---

## Problem 9: Vector Range-based Loop

**Difficulty:** Easy

### Description

Iterate through vector using range-based for loop.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print elements using range-based loop

### Sample Input

```
5
10 20 30 40 50
```

### Sample Output

```
Using range-based loop: 10 20 30 40 50
```

### Code Example

```cpp
vector<int> vec = {10, 20, 30, 40, 50};
cout << "Using range-based loop: ";
for(int x : vec) {
    cout << x << " ";
}
cout << endl;
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 10: Vector Iterator Operations

**Difficulty:** Medium

### Description

Demonstrate vector iterator operations.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print elements using different iterator methods

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Using begin(): 1
Using end(): 5
Using rbegin(): 5
Using rend(): 1
```

### Code Example

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
cout << "Using begin(): " << *vec.begin() << endl;
cout << "Using end(): " << *(vec.end() - 1) << endl;
cout << "Using rbegin(): " << *vec.rbegin() << endl;
cout << "Using rend(): " << *(vec.rend() - 1) << endl;
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 11: Find Element in Vector

**Difficulty:** Easy

### Description

Search for an element in a vector and return its index.

### Input Format

- Vector size `n`
- `n` integers
- Element to find `key`

### Output Format

- Print index if found, "Not found" otherwise

### Sample Input

```
5
10 20 30 40 50
30
```

### Sample Output

```
Found at index: 2
```

### Algorithm

```cpp
vector<int> vec = {10, 20, 30, 40, 50};
int key = 30;

auto it = find(vec.begin(), vec.end(), key);
if(it != vec.end()) {
    cout << "Found at index: " << it - vec.begin() << endl;
} else {
    cout << "Not found" << endl;
}
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 12: Sort Vector Elements

**Difficulty:** Easy

### Description

Sort vector elements in ascending and descending order.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print original, ascending sorted, and descending sorted

### Sample Input

```
5
3 1 4 1 5
```

### Sample Output

```
Original: 3 1 4 1 5
Ascending: 1 1 3 4 5
Descending: 5 4 3 1 1
```

### Code Example

```cpp
vector<int> vec = {3, 1, 4, 1, 5};

// Ascending sort
sort(vec.begin(), vec.end());

// Descending sort
sort(vec.rbegin(), vec.rend());
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 13: Remove Duplicates from Vector

**Difficulty:** Easy

### Description

Remove duplicate elements from a vector.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print vector after removing duplicates

### Sample Input

```
8
1 2 2 3 3 3 4 4
```

### Sample Output

```
1 2 3 4
```

### Algorithm

```cpp
vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 4};

// Remove duplicates
auto it = unique(vec.begin(), vec.end());
vec.resize(it - vec.begin());
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 14: Reverse Vector

**Difficulty:** Easy

### Description

Reverse the elements of a vector.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print original and reversed vector

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Original: 1 2 3 4 5
Reversed: 5 4 3 2 1
```

### Code Example

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
cout << "Original: ";
for(int x : vec) cout << x << " ";
cout << endl;

// Reverse vector
reverse(vec.begin(), vec.end());
cout << "Reversed: ";
for(int x : vec) cout << x << " ";
cout << endl;
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 15: Rotate Vector

**Difficulty:** Medium

### Description

Rotate vector elements by k positions.

### Input Format

- Vector size `n`
- `n` integers
- Rotation count `k`

### Output Format

- Print rotated vector

### Sample Input

```
5
1 2 3 4 5
2
```

### Sample Output

```
4 5 1 2 3
```

### Algorithm

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
int k = 2;

// Left rotate by k positions
rotate(vec.begin(), vec.begin() + k, vec.end());
```

### Constraints

- 1 ≤ n ≤ 10^5
- 0 ≤ k < n

---

## Problem 16: Vector of Strings

**Difficulty:** Easy

### Description

Create and manipulate a vector of strings.

### Input Format

- Number of strings `n`
- `n` strings

### Output Format

- Print strings and their lengths

### Sample Input

```
3
apple
banana
cherry
```

### Sample Output

```
apple (length: 5)
banana (length: 6)
cherry (length: 6)
```

### Code Example

```cpp
vector<string> words;
int n;
cin >> n;
for(int i = 0; i < n; i++) {
    string word;
    cin >> word;
    words.push_back(word);
}

for(string word : words) {
    cout << word << " (length: " << word.length() << ")" << endl;
}
```

### Constraints

- 1 ≤ n ≤ 100
- String length ≤ 100

---

## Problem 17: Merge Two Vectors

**Difficulty:** Easy

### Description

Merge two sorted vectors into one sorted vector.

### Input Format

- Size of first vector `n1`
- `n1` integers (sorted)
- Size of second vector `n2`
- `n2` integers (sorted)

### Output Format

- Print merged sorted vector

### Sample Input

```
3
1 3 5
4
2 4 6 8
```

### Sample Output

```
1 2 3 4 5 6 8
```

### Algorithm

```cpp
vector<int> mergeVectors(vector<int> a, vector<int> b) {
    vector<int> result;
    int i = 0, j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    while(j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;
}
```

### Constraints

- 1 ≤ n1, n2 ≤ 10^4

---

## Problem 18: Find Maximum Element

**Difficulty:** Easy

### Description

Find maximum element in a vector.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print maximum element and its index

### Sample Input

```
6
3 1 4 1 5 9
```

### Sample Output

```
Maximum: 9 at index: 5
```

### Code Example

```cpp
vector<int> vec = {3, 1, 4, 1, 5, 9};
auto maxIt = max_element(vec.begin(), vec.end());
cout << "Maximum: " << *maxIt << " at index: " << maxIt - vec.begin() << endl;
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 19: Find Minimum Element

**Difficulty:** Easy

### Description

Find minimum element in a vector.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print minimum element and its index

### Sample Input

```
6
3 1 4 1 5 9
```

### Sample Output

```
Minimum: 1 at index: 1
```

### Code Example

```cpp
vector<int> vec = {3, 1, 4, 1, 5, 9};
auto minIt = min_element(vec.begin(), vec.end());
cout << "Minimum: " << *minIt << " at index: " << minIt - vec.begin() << endl;
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 20: Count Frequency in Vector

**Difficulty:** Easy

### Description

Count frequency of each element in a vector.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print each element and its frequency

### Sample Input

```
8
1 2 2 3 3 3 4 4
```

### Sample Output

```
1: 1
2: 2
3: 3
4: 2
```

### Algorithm

```cpp
vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 4};
sort(vec.begin(), vec.end());

for(int i = 0; i < vec.size(); ) {
    int j = i;
    while(j < vec.size() && vec[j] == vec[i]) {
        j++;
    }
    cout << vec[i] << ": " << (j - i) << endl;
    i = j;
}
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 21: Vector Binary Search

**Difficulty:** Easy

### Description

Perform binary search on a sorted vector.

### Input Format

- Vector size `n`
- `n` integers (sorted)
- Element to search `key`

### Output Format

- Print index if found, "Not found" otherwise

### Sample Input

```
5
1 2 3 4 5
3
```

### Sample Output

```
Found at index: 2
```

### Code Example

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
int key = 3;

auto it = lower_bound(vec.begin(), vec.end(), key);
if(it != vec.end() && *it == key) {
    cout << "Found at index: " << it - vec.begin() << endl;
} else {
    cout << "Not found" << endl;
}
```

### Constraints

- 1 ≤ n ≤ 10^5
- Vector is sorted

---

## Problem 22: Remove Specific Element

**Difficulty:** Easy

### Description

Remove all occurrences of a specific element from vector.

### Input Format

- Vector size `n`
- `n` integers
- Element to remove `key`

### Output Format

- Print vector after removal

### Sample Input

```
6
1 2 3 2 4 2
2
```

### Sample Output

```
1 3 4
```

### Algorithm

```cpp
vector<int> vec = {1, 2, 3, 2, 4, 2};
int key = 2;

// Remove all occurrences of key
vec.erase(remove(vec.begin(), vec.end(), key), vec.end());
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 23: Vector Partial Sum

**Difficulty:** Easy

### Description

Calculate partial sums of vector elements.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print partial sums

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
1 3 6 10 15
```

### Algorithm

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
vector<int> partialSums;

int sum = 0;
for(int x : vec) {
    sum += x;
    partialSums.push_back(sum);
}

for(int s : partialSums) {
    cout << s << " ";
}
cout << endl;
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 24: Check if Vector is Sorted

**Difficulty:** Easy

### Description

Check if a vector is sorted in ascending order.

### Input Format

- Vector size `n`
- `n` integers

### Output Format

- Print "Sorted" or "Not Sorted"

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Sorted
```

### Code Example

```cpp
vector<int> vec = {1, 2, 3, 4, 5};
bool isSorted = true;

for(int i = 1; i < vec.size(); i++) {
    if(vec[i] < vec[i-1]) {
        isSorted = false;
        break;
    }
}

cout << (isSorted ? "Sorted" : "Not Sorted") << endl;
```

### Constraints

- 1 ≤ n ≤ 10^5

---

## Problem 25: Vector Intersection

**Difficulty:** Medium

### Description

Find intersection of two vectors (common elements).

### Input Format

- Size of first vector `n1`
- `n1` integers
- Size of second vector `n2`
- `n2` integers

### Output Format

- Print common elements

### Sample Input

```
5
1 2 3 4 5
4
3 4 5 6
```

### Sample Output

```
3 4 5
```

### Algorithm

1. Sort both vectors
2. Use two pointer technique to find common elements

### Constraints

- 1 ≤ n1, n2 ≤ 10^4

---

## Additional Practice Problems

### Problem 26: Vector Union

Find union of two vectors (all unique elements).

### Problem 27: Vector Difference

Find elements in first vector but not in second.

### Problem 28: Rotate Vector Left

Rotate vector left by k positions.

### Problem 29: Find All Positions of Element

Find all indices where a specific element appears.

### Problem 30: Vector Prefix Sum

Calculate prefix sum array from vector.

### Problem 31: Check if Two Vectors are Equal

Check if two vectors have same elements in same order.

### Problem 32: Remove Consecutive Duplicates

Remove consecutive duplicate elements.

### Problem 33: Vector of Pairs

Work with vector of pairs (roll number, marks).

### Problem 34: Sort Vector of Pairs

Sort vector of pairs by different criteria.

### Problem 35: Vector Sliding Window

Implement sliding window operations on vector.

## Vector Concepts

### 1. Vector Basics

- **Dynamic size:** Can grow and shrink
- **Contiguous memory:** Stored in contiguous locations
- **Random access:** O(1) access time
- **Automatic management:** Memory handled automatically

### 2. Vector vs Array

- **Array:** Fixed size, manual memory management
- **Vector:** Dynamic size, automatic memory management
- **Performance:** Similar for most operations

### 3. Vector Operations

- **Access:** `vec[i]`, `vec.at(i)`, `vec.front()`, `vec.back()`
- **Modification:** `push_back()`, `pop_back()`, `insert()`, `erase()`
- **Capacity:** `size()`, `capacity()`, `reserve()`, `resize()`
- **Search:** `find()`, `binary_search()`

### 4. Vector Algorithms

- **Sorting:** `sort()`, `stable_sort()`, `partial_sort()`
- **Searching:** `find()`, `binary_search()`, `lower_bound()`, `upper_bound()`
- **Modifying:** `reverse()`, `rotate()`, `unique()`, `remove()`
- **Numeric:** `accumulate()`, `partial_sum()`, `adjacent_difference()`

## Key Takeaways

### Common Patterns

```cpp
// Pattern 1: Vector creation and input
vector<int> vec;
int n;
cin >> n;
for(int i = 0; i < n; i++) {
    int val;
    cin >> val;
    vec.push_back(val);
}

// Pattern 2: Vector iteration
for(int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
}
cout << endl;

// Range-based for loop
for(int x : vec) {
    cout << x << " ";
}
cout << endl;

// Pattern 3: Vector modification
vec.push_back(newElement);
vec.pop_back();
vec.insert(vec.begin() + pos, element);
vec.erase(vec.begin() + pos);

// Pattern 4: Vector search
auto it = find(vec.begin(), vec.end(), key);
if(it != vec.end()) {
    cout << "Found at: " << it - vec.begin() << endl;
}

// Pattern 5: Vector sort
sort(vec.begin(), vec.end()); // Ascending
sort(vec.begin(), vec.end(), greater<int>()); // Descending
```

### Best Practices

- **Use vectors instead of arrays:** When size is unknown or dynamic
- **Reserve capacity:** When approximate size is known
- **Use appropriate access method:** `[]` for performance, `at()` for safety
- **Prefer algorithms over manual loops:** Use STL algorithms when possible
- **Check bounds:** Before accessing elements

### Common Mistakes

- **Invalid access:** Accessing beyond vector size
- **Iterator invalidation:** After vector modification
- **Capacity confusion:** Size vs capacity misunderstanding
- **Inefficient operations:** Frequent insertions at beginning

### Performance Tips

- **Pre-reserve capacity:** `vec.reserve(approximate_size)`
- **Use emplace_back():** Instead of push_back() for objects
- **Batch insertions:** Use insert with range when possible
- **Algorithm selection:** Choose appropriate STL algorithm

### Interview Tips

- **Vector basics:** Creation, access, modification
- **Memory management:** Automatic vs manual
- **Algorithm usage:** Know common STL algorithms
- **Time complexity:** Understand operation complexities
- **Real-world usage:** When to prefer vectors over arrays

### Applications

1. **Dynamic Arrays**

   - Variable size requirements
   - Stack-based memory
   - Frequent insertions at end

2. **Data Processing**

   - Element storage and manipulation
   - Sorting and searching
   - Statistical operations

3. **Algorithm Implementation**

   - Graph algorithms (adjacency lists)
   - Dynamic programming
   - Backtracking

4. **System Programming**
   - Buffer management
   - Data structure implementation
   - Memory pools

### Advanced Topics

1. **Vector of Vectors**

   - 2D dynamic arrays
   - Jagged arrays
   - Matrix operations

2. **Vector Optimization**

   - Move semantics
   - Emplace operations
   - Custom allocators

3. **Vector Algorithms**

   - Partition algorithms
   - Heap operations
   - Set operations

4. **Memory Management**
   - Copy-on-write
   - Small vector optimization
   - Custom memory allocation
