# Day 11: Arrays Part 2 - Practice Problems

## Problem 1: Print All Subarrays

**Difficulty:** Easy

### Description

Print all possible subarrays of a given array.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print all subarrays separated by commas

### Sample Input

```
3
1 2 3
```

### Sample Output

```
1, 12, 123, 2, 23, 3,
```

### Algorithm

```cpp
for(int start = 0; start < n; start++) {
    for(int end = start; end < n; end++) {
        for(int i = start; i <= end; i++) {
            cout << arr[i];
        }
        cout << ", ";
    }
}
```

### Time Complexity

- O(n³) - Three nested loops

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 2: Maximum Subarray Sum (Brute Force)

**Difficulty:** Easy

### Description

Find the maximum sum of any contiguous subarray.

### Input Format

- Array size `n`
- `n` integers (can be negative)

### Output Format

- Print the maximum subarray sum

### Sample Input

```
6
2 -3 6 -5 4 2
```

### Sample Output

```
7
```

### Explanation

Subarray [6, -5, 4, 2] has sum = 7

### Algorithm (O(n³))

```cpp
int maxSum = INT_MIN;
for(int start = 0; start < n; start++) {
    for(int end = start; end < n; end++) {
        int currSum = 0;
        for(int i = start; i <= end; i++) {
            currSum += arr[i];
        }
        maxSum = max(maxSum, currSum);
    }
}
```

### Constraints

- 1 ≤ n ≤ 100
- -10^4 ≤ array elements ≤ 10^4

---

## Problem 3: Maximum Subarray Sum (Optimized)

**Difficulty:** Medium

### Description

Find the maximum sum using optimized approach.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the maximum subarray sum

### Sample Input

```
6
2 -3 6 -5 4 2
```

### Sample Output

```
7
```

### Algorithm (O(n²))

```cpp
int maxSum = INT_MIN;
for(int start = 0; start < n; start++) {
    int currSum = 0;
    for(int end = start; end < n; end++) {
        currSum += arr[end];
        maxSum = max(maxSum, currSum);
    }
}
```

### Constraints

- 1 ≤ n ≤ 10^4

---

## Problem 4: Maximum Subarray Sum (Kadane's Algorithm)

**Difficulty:** Medium

### Description

Find the maximum subarray sum using Kadane's algorithm.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print the maximum subarray sum

### Sample Input

```
6
2 -3 6 -5 4 2
```

### Sample Output

```
7
```

### Algorithm (O(n))

```cpp
int maxSum = INT_MIN;
int currSum = 0;
for(int i = 0; i < n; i++) {
    currSum += arr[i];
    maxSum = max(maxSum, currSum);
    if(currSum < 0) {
        currSum = 0;
    }
}
```

### Constraints

- 1 ≤ n ≤ 10^6
- -10^4 ≤ array elements ≤ 10^4

---

## Problem 5: Best Time to Buy and Sell Stock

**Difficulty:** Easy

### Description

Find the maximum profit from buying and selling stock once.

### Input Format

- Array size `n` (number of days)
- `n` integers (stock prices)

### Output Format

- Print the maximum profit

### Sample Input

```
6
7 1 5 3 6 4
```

### Sample Output

```
5
```

### Explanation

Buy on day 2 (price = 1), sell on day 5 (price = 6), profit = 5

### Algorithm

1. Track minimum price seen so far
2. Calculate profit if sold today
3. Update maximum profit

### Constraints

- 1 ≤ n ≤ 10^5
- 0 ≤ price ≤ 10^4

---

## Problem 6: Trapping Rain Water

**Difficulty:** Hard

### Description

Calculate how much water can be trapped between buildings.

### Input Format

- Array size `n`
- `n` integers (building heights)

### Output Format

- Print the total water trapped

### Sample Input

```
7
4 2 0 6 3 2 5
```

### Sample Output

```
11
```

### Explanation

Water trapped = 11 units

### Algorithm

1. Calculate left max for each position
2. Calculate right max for each position
3. Water at position = min(leftMax, rightMax) - height
4. Sum all positive water values

### Constraints

- 1 ≤ n ≤ 2×10^4
- 0 ≤ height ≤ 10^5

---

## Problem 7: Find Duplicate in Array

**Difficulty:** Easy

### Description

Check if any number appears twice in the array.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print "true" if duplicate found, "false" otherwise

### Sample Input

```
10
1 1 1 3 3 4 3 2 4 2
```

### Sample Output

```
true
```

### Algorithm (O(n²))

```cpp
for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
        if(arr[i] == arr[j]) {
            return true;
        }
    }
}
return false;
```

### Constraints

- 1 ≤ n ≤ 10^4

---

## Problem 8: Rotate Array

**Difficulty:** Easy

### Description

Rotate the array to the right by k positions.

### Input Format

- Array size `n`
- `n` integers
- Rotation count `k`

### Output Format

- Print the rotated array

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

1. Create a temporary array
2. Copy last k elements to beginning of temp
3. Copy first n-k elements to end of temp
4. Copy temp back to original array

### Constraints

- 1 ≤ n ≤ 10^4
- 0 ≤ k < n

---

## Problem 9: Find All Subarray Sums

**Difficulty:** Medium

### Description

Calculate and print sum of all possible subarrays.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print sum of each subarray

### Sample Input

```
3
1 2 3
```

### Sample Output

```
1 3 6 2 5 3
```

### Explanation

- Subarray [1]: sum = 1
- Subarray [1,2]: sum = 3
- Subarray [1,2,3]: sum = 6
- Subarray [2]: sum = 2
- Subarray [2,3]: sum = 5
- Subarray [3]: sum = 3

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 10: Maximum Circular Subarray Sum

**Difficulty:** Hard

### Description

Find maximum subarray sum considering circular array.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print maximum circular subarray sum

### Sample Input

```
7
8 -8 9 -9 10 -11 12
```

### Sample Output

```
22
```

### Explanation

Subarray [12, 8, -8, 9] sum = 21, or [10, -11, 12, 8] sum = 19, etc.

### Algorithm

1. Find maximum subarray sum (normal)
2. Find minimum subarray sum
3. Find total array sum
4. Circular max = total - minimum subarray sum
5. Return maximum of normal and circular

### Constraints

- 1 ≤ n ≤ 10^4
- -10^4 ≤ array elements ≤ 10^4

---

## Problem 11: Equilibrium Point

**Difficulty:** Medium

### Description

Find if there's an equilibrium point where left sum equals right sum.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print "YES" if equilibrium point exists, "NO" otherwise

### Sample Input

```
5
1 3 5 2 2
```

### Sample Output

```
YES
```

### Explanation

At index 2 (0-based), left sum = 1+3=4, right sum = 2+2=4

### Constraints

- 1 ≤ n ≤ 10^5
- -10^4 ≤ array elements ≤ 10^4

---

## Problem 12: Leaders in Array

**Difficulty:** Easy

### Description

Find all leader elements (greater than all elements to their right).

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print all leader elements

### Sample Input

```
6
16 17 4 3 5 2
```

### Sample Output

```
17 5 2
```

### Explanation

- 17 > 4,3,5,2
- 5 > 2
- 2 > (nothing to right)

### Algorithm

1. Start from rightmost element (always leader)
2. Track current maximum from right
3. If element > current max, it's a leader

### Constraints

- 1 ≤ n ≤ 10^4

---

## Problem 13: Frequency Count

**Difficulty:** Easy

### Description

Count frequency of each element in the array.

### Input Format

- Array size `n`
- `n` integers

### Output Format

- Print each element and its frequency

### Sample Input

```
10
1 2 2 3 3 3 4 4 4 4
```

### Sample Output

```
1: 1
2: 2
3: 3
4: 4
```

### Constraints

- 1 ≤ n ≤ 10^4
- -10^9 ≤ array elements ≤ 10^9

---

## Problem 14: Sort 0s, 1s, and 2s

**Difficulty:** Easy

### Description

Sort an array containing only 0s, 1s, and 2s.

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

### Algorithm (Dutch National Flag)

1. Use three pointers: low, mid, high
2. low: boundary of 0s
3. high: boundary of 2s
4. mid: current element

### Constraints

- 1 ≤ n ≤ 10^6

---

## Problem 15: Find Missing Number

**Difficulty:** Easy

### Description

Find the missing number in array of 1 to n.

### Input Format

- Array size `n`
- `n-1` integers (1 to n with one missing)

### Output Format

- Print the missing number

### Sample Input

```
9
1 2 3 5 6 7 8 9 10
```

### Sample Output

```
4
```

### Algorithm

1. Calculate expected sum: n(n+1)/2
2. Calculate actual sum of array
3. Missing = expected - actual

### Constraints

- 1 ≤ n ≤ 10^6

---

## Additional Practice Problems

### Problem 16: Find Pair with Given Sum

Find if there's a pair with given sum in unsorted array.

### Problem 17: Majority Element

Find element that appears more than n/2 times.

### Problem 18: Maximum Product Subarray

Find maximum product of contiguous subarray.

### Problem 19: Minimum Size Subarray Sum

Find minimum length subarray with sum >= target.

### Problem 20: Gas Station Problem

Find starting gas station for circular route.

### Problem 21: Jump Game

Check if you can reach last index from first.

### Problem 22: Merge Sorted Arrays

Merge two sorted arrays into one.

### Problem 23: Find Peak Element

Find peak element (greater than neighbors).

### Problem 24: Product of Array Except Self

Calculate product of array except self.

### Problem 25: Maximum Subarray Product

Find maximum product subarray (Kadane's variant).

## Array Algorithm Categories

### 1. Subarray Problems

- Maximum subarray sum (Kadane's)
- Maximum product subarray
- Minimum size subarray sum
- All possible subarrays

### 2. Stock Problems

- Best time to buy/sell (single transaction)
- Multiple transactions
- Transaction with cooldown
- Transaction with fee

### 3. Rain Water Problems

- Trapping rain water (1D)
- Trapping rain water (2D)
- Container with most water

### 4. Array Manipulation

- Rotate array
- Sort 0s, 1s, 2s
- Move zeros to end
- Remove duplicates

### 5. Search Problems

- Find missing number
- Find duplicate number
- Search in sorted array

## Key Takeaways

### Algorithm Complexities

| Problem                    | Time Complexity | Space Complexity | Algorithm          |
| -------------------------- | --------------- | ---------------- | ------------------ |
| **Subarray Sum (Brute)**   | O(n³)           | O(1)             | Three nested loops |
| **Subarray Sum (Better)**  | O(n²)           | O(1)             | Two nested loops   |
| **Subarray Sum (Optimal)** | O(n)            | O(1)             | Kadane's algorithm |
| **Stock Buy/Sell**         | O(n)            | O(1)             | Single pass        |
| **Trapping Rain Water**    | O(n)            | O(n)             | Two arrays for max |
| **Find Duplicate**         | O(n²)           | O(1)             | Nested loops       |

### Kadane's Algorithm

```cpp
int maxSubarraySum(int arr[], int n) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}
```

### Two Pointer Technique

```cpp
// For sorted array
int left = 0, right = n-1;
while(left < right) {
    // Process elements
    left++;
    right--;
}
```

### Best Practices

- **Choose right algorithm:** Consider time vs space trade-offs
- **Handle edge cases:** Empty array, single element, all negative
- **Understand problem constraints:** Affects algorithm choice
- **Optimize step by step:** Brute → Better → Optimal

### Common Mistakes

- **Integer overflow:** Use long long for large sums
- **Negative numbers:** In maximum subarray problems
- **Circular arrays:** Consider wrap-around
- **Index bounds:** Off-by-one errors in subarrays

### Interview Tips

- **Explain approach:** Before writing code
- **Start simple:** Brute force, then optimize
- **Handle edge cases:** Discuss before coding
- **Time complexity:** Analyze for given constraints
- **Test cases:** Consider various scenarios

### Problem Patterns

1. **Subarray problems:** Contiguous elements
2. **Two pointer:** Sorted arrays, opposite directions
3. **Prefix sum:** Range sum queries
4. **Sliding window:** Fixed/variable size windows
5. **Greedy:** Local optimal → global optimal
