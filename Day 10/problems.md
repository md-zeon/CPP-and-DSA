# Day 10: Arrays Part 1 - Practice Problems

## Problem 1: Find Minimum and Maximum in Array

**Difficulty:** Easy

### Description

Given an array of integers, find the minimum and maximum elements.

### Input Format

- First line: integer `n` (size of array)
- Second line: `n` integers representing array elements

### Output Format

- Print the largest and smallest elements in the format:
  ```
  Largest = [max]
  Smallest = [min]
  ```

### Sample Input

```
5
1 2 3 5 7
```

### Sample Output

```
Largest = 7
Smallest = 1
```

### Constraints

- 1 ≤ n ≤ 1000
- -10^9 ≤ array elements ≤ 10^9

---

## Problem 2: Linear Search

**Difficulty:** Easy

### Description

Search for a given key element in the array using linear search algorithm.

### Input Format

- First line: integer `n` (size of array)
- Second line: `n` integers representing array elements
- Third line: integer `key` to search

### Output Format

- Print the index (0-based) where the key is found, or -1 if not found

### Sample Input

```
8
2 4 6 8 10 12 14 16
10
```

### Sample Output

```
4
```

### Sample Input (Not Found)

```
8
2 4 6 8 10 12 14 16
100
```

### Sample Output

```
-1
```

### Time Complexity

- Best Case: O(1) - element found at first position
- Worst Case: O(n) - element not found or at last position
- Space Complexity: O(1)

### Constraints

- 1 ≤ n ≤ 10^5
- -10^9 ≤ array elements, key ≤ 10^9

---

## Problem 3: Array Reversal (Two Pointer Approach)

**Difficulty:** Easy

### Description

Reverse the given array using the two-pointer technique without using extra space.

### Input Format

- First line: integer `n` (size of array)
- Second line: `n` integers representing array elements

### Output Format

- Print the reversed array elements separated by commas

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
5, 4, 3, 2, 1
```

### Algorithm

1. Initialize start = 0, end = n-1
2. While start < end:
   - Swap arr[start] and arr[end]
   - start++, end--

### Time Complexity

- O(n/2) = O(n)
- Space Complexity: O(1)

### Constraints

- 1 ≤ n ≤ 1000

---

## Problem 4: Binary Search

**Difficulty:** Medium

### Description

Search for a given key element in a **sorted** array using binary search algorithm.

### Input Format

- First line: integer `n` (size of array)
- Second line: `n` integers in **sorted order**
- Third line: integer `key` to search

### Output Format

- Print the index (0-based) where the key is found, or -1 if not found

### Sample Input

```
8
2 4 6 8 10 12 14 16
10
```

### Sample Output

```
4
```

### Sample Input (Not Found)

```
8
2 4 6 8 10 12 14 16
100
```

### Sample Output

```
-1
```

### Algorithm

1. Initialize start = 0, end = n-1
2. While start ≤ end:
   - Calculate mid = (start + end) / 2
   - If arr[mid] == key, return mid
   - If arr[mid] > key, end = mid - 1
   - Else, start = mid + 1
3. Return -1 if not found

### Time Complexity

- Best Case: O(1) - element found at middle in first comparison
- Worst Case: O(log n)
- Space Complexity: O(1)

### Constraints

- 1 ≤ n ≤ 10^6
- -10^9 ≤ array elements, key ≤ 10^9
- **Array must be sorted in ascending order**

---

## Additional Practice Problems

### Problem 5: Find Second Largest Element

Find the second largest element in an array.

**Note:** Handle cases where all elements are same or array has less than 2 elements.

### Problem 6: Count Frequency

Count the frequency of each element in the array.

### Problem 7: Check if Array is Sorted

Check if the given array is sorted in ascending order.

### Problem 8: Remove Duplicates from Sorted Array

Remove duplicate elements from a sorted array in-place.

### Problem 9: Find All Occurrences

Find all indices where a given key element appears in the array.

### Problem 10: Array Rotation

Rotate the array to the right by k positions.

**Example:** [1,2,3,4,5] rotated by 2 positions: [4,5,1,2,3]
