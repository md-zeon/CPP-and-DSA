# Day 19: Recursion Part 1 - Practice Problems

## Problem 1: Factorial Calculation

**Difficulty:** Easy

### Description

Calculate factorial of a number using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print the factorial of n

### Sample Input

```
5
```

### Sample Output

```
120
```

### Algorithm

```cpp
int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}
```

### Constraints

- 0 ≤ n ≤ 20 (to avoid overflow)

---

## Problem 2: Print Decreasing Order

**Difficulty:** Easy

### Description

Print numbers from n to 1 using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print numbers in decreasing order

### Sample Input

```
5
```

### Sample Output

```
5 4 3 2 1
```

### Algorithm

```cpp
void decreasingOrder(int n) {
    if(n < 1) {
        return;
    }
    cout << n << " ";
    decreasingOrder(n-1);
}
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 3: Print Increasing Order

**Difficulty:** Easy

### Description

Print numbers from 1 to n using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print numbers in increasing order

### Sample Input

```
5
```

### Sample Output

```
1 2 3 4 5
```

### Algorithm

```cpp
void increasingOrder(int n) {
    if(n < 1) {
        return;
    }
    increasingOrder(n-1);
    cout << n << " ";
}
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 4: Sum of Natural Numbers

**Difficulty:** Easy

### Description

Calculate sum of first n natural numbers using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print the sum

### Sample Input

```
5
```

### Sample Output

```
15
```

### Algorithm

```cpp
int naturalSum(int n) {
    if(n == 1) {
        return 1;
    }
    return n + naturalSum(n-1);
}
```

### Constraints

- 1 ≤ n ≤ 10^4

---

## Problem 5: Nth Fibonacci Number

**Difficulty:** Easy

### Description

Find the nth Fibonacci number using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print the nth Fibonacci number

### Sample Input

```
7
```

### Sample Output

```
13
```

### Algorithm

```cpp
int nthFibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}
```

### Constraints

- 0 ≤ n ≤ 40 (to avoid timeout)

---

## Problem 6: Check if Array is Sorted

**Difficulty:** Easy

### Description

Check if an array is sorted in ascending order using recursion.

### Input Format

- Array size `n`
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

### Algorithm

```cpp
bool isSorted(int arr[], int n, int i) {
    if(i == n-1) {
        return true;
    }
    if(arr[i] > arr[i+1]) {
        return false;
    }
    return isSorted(arr, n, i+1);
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 7: First Occurrence in Array

**Difficulty:** Easy

### Description

Find the first occurrence of an element in an array using recursion.

### Input Format

- Array size `n`
- `n` integers
- Target element `target`

### Output Format

- Print the index of first occurrence or -1

### Sample Input

```
6
1 2 3 3 3 4
3
```

### Sample Output

```
2
```

### Algorithm

```cpp
int firstOccur(vector<int> arr, int target) {
    static int i = 0;
    if(i == arr.size()) {
        return -1;
    }
    if(arr[i] == target) {
        return i;
    }
    i++;
    return firstOccur(arr, target);
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 8: Last Occurrence in Array

**Difficulty:** Easy

### Description

Find the last occurrence of an element in an array using recursion.

### Input Format

- Array size `n`
- `n` integers
- Target element `target`

### Output Format

- Print the index of last occurrence or -1

### Sample Input

```
6
1 2 3 3 3 4
3
```

### Sample Output

```
4
```

### Algorithm

```cpp
int lastOccur(vector<int> arr, int target, int i) {
    if(i == arr.size()) {
        return -1;
    }
    int idx = lastOccur(arr, target, i+1);
    if(idx == -1 && arr[i] == target) {
        return i;
    }
    return idx;
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 9: Fast Exponentiation

**Difficulty:** Medium

### Description

Calculate x raised to power n using recursive fast exponentiation.

### Input Format

- Two integers: `x` and `n`

### Output Format

- Print x^n

### Sample Input

```
2 10
```

### Sample Output

```
1024
```

### Algorithm

```cpp
int power(int x, int n) {
    if(n == 0) {
        return 1;
    }
    int halfPower = power(x, n/2);
    int halfPowerSquare = halfPower * halfPower;
    if(n % 2 == 0) {
        return halfPowerSquare;
    }
    return x * halfPowerSquare;
}
```

### Time Complexity

- O(log n) - Much faster than O(n)

### Constraints

- 1 ≤ x ≤ 10
- 0 ≤ n ≤ 30

---

## Problem 10: Sum of Digits using Recursion

**Difficulty:** Easy

### Description

Calculate sum of digits of a number using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print the sum of digits

### Sample Input

```
12345
```

### Sample Output

```
15
```

### Algorithm

```cpp
int sumOfDigits(int n) {
    if(n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 11: Reverse a Number using Recursion

**Difficulty:** Easy

### Description

Reverse a number using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print the reversed number

### Sample Input

```
12345
```

### Sample Output

```
54321
```

### Algorithm

```cpp
int reverseNumber(int n, int rev = 0) {
    if(n == 0) {
        return rev;
    }
    return reverseNumber(n / 10, rev * 10 + n % 10);
}
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 12: Count Digits using Recursion

**Difficulty:** Easy

### Description

Count the number of digits in a number using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print the count of digits

### Sample Input

```
12345
```

### Sample Output

```
5
```

### Algorithm

```cpp
int countDigits(int n) {
    if(n == 0) {
        return 0;
    }
    return 1 + countDigits(n / 10);
}
```

### Constraints

- 0 ≤ n ≤ 10^9

---

## Problem 13: Check Palindrome using Recursion

**Difficulty:** Easy

### Description

Check if a number is palindrome using recursion.

### Input Format

- A single integer `n`

### Output Format

- Print "Palindrome" or "Not Palindrome"

### Sample Input

```
121
```

### Sample Output

```
Palindrome
```

### Algorithm

```cpp
bool isPalindrome(int n, int original, int rev = 0) {
    if(n == 0) {
        return original == rev;
    }
    return isPalindrome(n / 10, original, rev * 10 + n % 10);
}
```

### Constraints

- 1 ≤ n ≤ 10^9

---

## Problem 14: Binary Search using Recursion

**Difficulty:** Medium

### Description

Implement binary search using recursion.

### Input Format

- Sorted array size `n`
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

### Algorithm

```cpp
int binarySearch(vector<int> arr, int key, int low, int high) {
    if(low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] > key) {
        return binarySearch(arr, key, low, mid - 1);
    } else {
        return binarySearch(arr, key, mid + 1, high);
    }
}
```

### Constraints

- 1 ≤ n ≤ 10^5
- Array is sorted

---

## Problem 15: Print Array using Recursion

**Difficulty:** Easy

### Description

Print array elements using recursion.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print all array elements

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
1 2 3 4 5
```

### Algorithm

```cpp
void printArray(vector<int> arr, int i) {
    if(i == arr.size()) {
        return;
    }
    cout << arr[i] << " ";
    printArray(arr, i + 1);
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 16: Find Maximum in Array using Recursion

**Difficulty:** Easy

### Description

Find maximum element in array using recursion.

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

```cpp
int findMax(vector<int> arr, int i, int maxVal) {
    if(i == arr.size()) {
        return maxVal;
    }
    if(arr[i] > maxVal) {
        maxVal = arr[i];
    }
    return findMax(arr, i + 1, maxVal);
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 17: Find Minimum in Array using Recursion

**Difficulty:** Easy

### Description

Find minimum element in array using recursion.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the minimum element

### Sample Input

```
5
3 1 4 1 5
```

### Sample Output

```
1
```

### Algorithm

```cpp
int findMin(vector<int> arr, int i, int minVal) {
    if(i == arr.size()) {
        return minVal;
    }
    if(arr[i] < minVal) {
        minVal = arr[i];
    }
    return findMin(arr, i + 1, minVal);
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 18: Sum of Array using Recursion

**Difficulty:** Easy

### Description

Calculate sum of array elements using recursion.

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

### Algorithm

```cpp
int arraySum(vector<int> arr, int i) {
    if(i == arr.size()) {
        return 0;
    }
    return arr[i] + arraySum(arr, i + 1);
}
```

### Constraints

- 1 ≤ n ≤ 1000
- -10^4 ≤ array elements ≤ 10^4

---

## Problem 19: Check if Array is Palindrome using Recursion

**Difficulty:** Medium

### Description

Check if an array is palindrome using recursion.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print "Palindrome" or "Not Palindrome"

### Sample Input

```
5
1 2 3 2 1
```

### Sample Output

```
Palindrome
```

### Algorithm

```cpp
bool isArrayPalindrome(vector<int> arr, int start, int end) {
    if(start >= end) {
        return true;
    }
    if(arr[start] != arr[end]) {
        return false;
    }
    return isArrayPalindrome(arr, start + 1, end - 1);
}
```

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 20: Tower of Hanoi

**Difficulty:** Medium

### Description

Solve Tower of Hanoi problem using recursion.

### Input Format

- Number of disks `n`

### Output Format

- Print steps to move n disks

### Sample Input

```
3
```

### Sample Output

```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

### Algorithm

```cpp
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n-1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n-1, auxiliary, source, destination);
}
```

### Constraints

- 1 ≤ n ≤ 10 (to avoid too much output)

---

## Problem 21: Generate All Subsequences

**Difficulty:** Hard

### Description

Generate all subsequences of a string using recursion.

### Input Format

- A string `str`

### Output Format

- Print all possible subsequences

### Sample Input

```
abc
```

### Sample Output

```
(empty)
c
b
bc
a
ac
ab
abc
```

### Algorithm

```cpp
void generateSubsequences(string str, string current, int index) {
    if(index == str.length()) {
        cout << (current.empty() ? "(empty)" : current) << endl;
        return;
    }

    // Exclude current character
    generateSubsequences(str, current, index + 1);

    // Include current character
    generateSubsequences(str, current + str[index], index + 1);
}
```

### Constraints

- String length ≤ 10 (to avoid too much output)

---

## Problem 22: Generate All Subsets of Array

**Difficulty:** Hard

### Description

Generate all subsets of an array using recursion.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print all possible subsets

### Sample Input

```
3
1 2 3
```

### Sample Output

```
(empty set)
1
2
1 2
3
1 3
2 3
1 2 3
```

### Algorithm

```cpp
void generateSubsets(vector<int> arr, vector<int> current, int index) {
    if(index == arr.size()) {
        cout << "(empty set)" << endl;
        for(int num : current) {
            cout << num << " ";
        }
        if(!current.empty()) cout << endl;
        return;
    }

    // Exclude current element
    generateSubsets(arr, current, index + 1);

    // Include current element
    current.push_back(arr[index]);
    generateSubsets(arr, current, index + 1);
}
```

### Constraints

- 1 ≤ n ≤ 10 (to avoid too much output)

---

## Problem 23: String Length using Recursion

**Difficulty:** Easy

### Description

Calculate length of string using recursion.

### Input Format

- A string `str`

### Output Format

- Print the length

### Sample Input

```
hello
```

### Sample Output

```
5
```

### Algorithm

```cpp
int stringLength(string str, int i) {
    if(str[i] == '\0') {
        return 0;
    }
    return 1 + stringLength(str, i + 1);
}
```

### Constraints

- String length ≤ 100

---

## Problem 24: Reverse String using Recursion

**Difficulty:** Easy

### Description

Reverse a string using recursion.

### Input Format

- A string `str`

### Output Format

- Print the reversed string

### Sample Input

```
hello
```

### Sample Output

```
olleh
```

### Algorithm

```cpp
void reverseString(string &str, int start, int end) {
    if(start >= end) {
        return;
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}
```

### Constraints

- String length ≤ 100

---

## Problem 25: Check if String is Palindrome using Recursion

**Difficulty:** Easy

### Description

Check if a string is palindrome using recursion.

### Input Format

- A string `str`

### Output Format

- Print "Palindrome" or "Not Palindrome"

### Sample Input

```
racecar
```

### Sample Output

```
Palindrome
```

### Algorithm

```cpp
bool isStringPalindrome(string str, int start, int end) {
    if(start >= end) {
        return true;
    }
    if(str[start] != str[end]) {
        return false;
    }
    return isStringPalindrome(str, start + 1, end - 1);
}
```

### Constraints

- String length ≤ 100

---

## Additional Practice Problems

### Problem 26: Print Numbers from 1 to N

Print numbers from 1 to n using recursion.

### Problem 27: Print Numbers from N to 1

Print numbers from n to 1 using recursion.

### Problem 28: Sum of Squares using Recursion

Calculate sum of squares of first n numbers.

### Problem 29: Product of Array using Recursion

Calculate product of array elements.

### Problem 30: Count Even Numbers in Array

Count even numbers in array using recursion.

### Problem 31: Count Odd Numbers in Array

Count odd numbers in array using recursion.

### Problem 32: Find All Indices of Element

Find all indices where element appears using recursion.

### Problem 33: Check if Two Arrays are Equal

Check if two arrays are equal using recursion.

### Problem 34: Merge Sort Implementation

Implement merge sort using recursion.

### Problem 35: Quick Sort Implementation

Implement quick sort using recursion.

## Recursion Concepts

### 1. Basic Recursion

- **Base Case:** Stopping condition
- **Recursive Case:** Problem reduction
- **Stack Overflow:** Too deep recursion

### 2. Recursion Types

- **Linear Recursion:** Single recursive call
- **Tree Recursion:** Multiple recursive calls
- **Tail Recursion:** Last operation is recursive call

### 3. Recursion Patterns

- **Array Processing:** First/last element processing
- **String Processing:** Character by character
- **Mathematical:** Factorial, Fibonacci, power

### 4. Backtracking

- **Decision Making:** Try different options
- **State Management:** Track current state
- **Backtrack:** Undo decisions

## Key Takeaways

### Common Patterns

```cpp
// Pattern 1: Linear recursion
void printIncreasing(int n) {
    if(n < 1) return;
    printIncreasing(n-1);
    cout << n << " ";
}

// Pattern 2: Array processing
int arraySum(vector<int> arr, int i) {
    if(i == arr.size()) return 0;
    return arr[i] + arraySum(arr, i+1);
}

// Pattern 3: String processing
bool isPalindrome(string str, int start, int end) {
    if(start >= end) return true;
    if(str[start] != str[end]) return false;
    return isPalindrome(str, start+1, end-1);
}

// Pattern 4: Multiple recursion calls
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Pattern 5: Fast exponentiation
long long power(long long base, int exp) {
    if(exp == 0) return 1;
    long long half = power(base, exp/2);
    if(exp % 2 == 0) {
        return half * half;
    } else {
        return base * half * half;
    }
}
```

### Best Practices

- **Always define base case:** Prevents infinite recursion
- **Ensure progress:** Towards base case in each call
- **Use helper functions:** For accumulator parameters
- **Consider iterative alternative:** For performance-critical code
- **Debug with small inputs:** Understand recursion flow

### Common Mistakes

- **Missing base case:** Infinite recursion
- **Incorrect base case:** Wrong stopping condition
- **No progress:** Not reducing problem size
- **Stack overflow:** Too deep recursion for large inputs
- **Global variables:** Unintended side effects

### Performance Tips

- **Tail recursion:** Can be optimized by compiler
- **Memoization:** Cache results for overlapping subproblems
- **Iterative conversion:** For better performance
- **Input size consideration:** Recursion depth limits

### Interview Tips

- **Explain recursion tree:** Visualize the calls
- **Base case identification:** Most important part
- **Time complexity:** Number of recursive calls
- **Space complexity:** Recursion stack depth
- **Alternative approaches:** Iterative or memoized versions

### Real-World Applications

1. **Tree Traversal**

   - Preorder, inorder, postorder
   - Level order traversal
   - Tree height calculation

2. **Graph Algorithms**

   - DFS traversal
   - Path finding
   - Connected components

3. **Dynamic Programming**

   - Matrix chain multiplication
   - Longest common subsequence
   - Edit distance

4. **Backtracking**

   - N-queens problem
   - Sudoku solver
   - Permutation generation

5. **Mathematical Computing**
   - Tower of Hanoi
   - Fibonacci sequence
   - Power calculations

### Advanced Topics

1. **Memoization**

   - Top-down dynamic programming
   - Overlapping subproblems
   - Space-time trade-offs

2. **Tabulation**

   - Bottom-up dynamic programming
   - Iterative approach
   - Space optimization

3. **Backtracking**

   - State space search
   - Constraint satisfaction
   - Optimization problems

4. **Divide and Conquer**
   - Problem division
   - Recursive solution
   - Result combination

### Recursion vs Iteration

| Aspect          | Recursion              | Iteration       |
| --------------- | ---------------------- | --------------- |
| **Code Style**  | Elegant, readable      | More control    |
| **Memory**      | Stack overhead         | Minimal         |
| **Performance** | Function call overhead | Faster          |
| **Debugging**   | Harder to debug        | Easier to debug |
| **Use Case**    | Tree/graph problems    | Simple loops    |

### Debugging Recursion

1. **Add cout statements:** Track function calls
2. **Use small inputs:** Understand flow
3. **Draw recursion tree:** Visualize calls
4. **Check base case:** Ensure proper termination
5. **Stack trace:** Use debugger

### Optimization Techniques

1. **Tail Recursion Optimization**

   - Convert to iterative
   - Compiler optimization
   - Stack frame reuse

2. **Memoization**

   - Cache results
   - Avoid recomputation
   - Dynamic programming

3. **Input Size Handling**
   - Iterative for large inputs
   - Hybrid approaches
   - Early termination

### Problem-Solving Approach

1. **Identify recursive structure**

   - Self-similar problems
   - Problem can be broken down

2. **Define base case**

   - Smallest input
   - Trivial solution

3. **Define recursive case**

   - How to reduce problem
   - Combine subproblem solutions

4. **Verify with examples**

   - Small inputs
   - Edge cases

5. **Analyze complexity**
   - Time complexity
   - Space complexity

### Edge Cases in Recursion

1. **Empty input:** Array size 0, string length 0
2. **Single element:** Base case verification
3. **Large inputs:** Stack overflow prevention
4. **Invalid inputs:** Negative numbers, null pointers
5. **Boundary conditions:** First/last element handling

### Recursion in Data Structures

1. **Linked Lists**

   - Traversal
   - Length calculation
   - Element search

2. **Trees**

   - Traversal algorithms
   - Height calculation
   - Node counting

3. **Graphs**

   - DFS traversal
   - Path finding
   - Cycle detection

4. **Arrays**
   - Binary search
   - Sorted check
   - Element search

### Modern C++ and Recursion

1. **Lambda Functions**

   - Recursive lambdas
   - Immediate functions (C++20)
   - Generic lambdas

2. **Constexpr Functions**

   - Compile-time recursion
   - Template metaprogramming
   - Performance optimization

3. **Smart Pointers**

   - Recursive data structures
   - Memory management
   - Cycle prevention

4. **Exception Safety**
   - RAII in recursive functions
   - Stack unwinding
   - Resource cleanup

### Performance Considerations

- **Recursion depth:** Limited by stack size
- **Function call overhead:** Each recursive call
- **Memory usage:** Stack frames
- **Cache performance:** Recursive vs iterative

### Testing Recursive Code

1. **Unit Testing**

   - Test base cases
   - Test recursive cases
   - Test edge cases

2. **Integration Testing**

   - Test with real data
   - Test performance
   - Test memory usage

3. **Stress Testing**
   - Large inputs
   - Deep recursion
   - Memory limits

### Best Practices Summary

- **Clear base case:** Well-defined stopping condition
- **Problem reduction:** Meaningful recursive step
- **Minimal parameters:** Avoid unnecessary parameters
- **Helper functions:** For accumulator variables
- **Early termination:** When possible
- **Input validation:** Handle invalid inputs
- **Documentation:** Explain recursive logic
- **Testing:** Thorough testing with various inputs
