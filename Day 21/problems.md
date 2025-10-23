# Day 21: Divide and Conquer - Problems

## Problem List

### 1. Merge Sort

- **Description**: Implement merge sort to sort an array of integers in ascending order.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [12, 11, 13, 5, 6, 7]
  - Output: [5, 6, 7, 11, 12, 13]
- **Approach**: Divide the array into halves, recursively sort them, and merge the sorted halves.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

### 2. Quick Sort

- **Description**: Implement quick sort to sort an array of integers in ascending order.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [10, 7, 8, 9, 1, 5]
  - Output: [1, 5, 7, 8, 9, 10]
- **Approach**: Choose a pivot, partition the array around it, and recursively sort the subarrays.
- **Time Complexity**: O(n log n) average, O(n^2) worst
- **Space Complexity**: O(log n)

### 3. Search in Rotated Sorted Array

- **Description**: Search for a target value in a rotated sorted array and return its index if found, else -1.
- **Constraints**: 1 ≤ n ≤ 10^5, array is rotated at some pivot, no duplicates
- **Example**:
  - Input: nums = [4,5,6,7,0,1,2], target = 0
  - Output: 4
- **Approach**: Use modified binary search to determine which half is sorted and search accordingly.
- **Time Complexity**: O(log n)
- **Space Complexity**: O(log n)

### 4. Find Minimum in Rotated Sorted Array

- **Description**: Find the minimum element in a rotated sorted array.
- **Constraints**: 1 ≤ n ≤ 10^5, no duplicates
- **Example**:
  - Input: [3,4,5,1,2]
  - Output: 1
- **Approach**: Use binary search to find the rotation point where the minimum occurs.
- **Time Complexity**: O(log n)
- **Space Complexity**: O(log n)

### 5. Kth Smallest Element in Array

- **Description**: Find the kth smallest element in an unsorted array using quick select.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ k ≤ n
- **Example**:
  - Input: [7, 10, 4, 3, 20, 15], k = 3
  - Output: 7
- **Approach**: Use the partition function from quick sort to find the kth element.
- **Time Complexity**: O(n) average, O(n^2) worst
- **Space Complexity**: O(log n)

## Additional Challenges

- Implement merge sort for linked lists.
- Optimize quick sort with median-of-three pivot selection.
- Search for an element in a nearly sorted array (with at most k inversions).
- Merge k sorted arrays using divide and conquer.
- Count inversions in an array using merge sort.

## Notes

- Understand the divide, conquer, and combine phases.
- Pay attention to base cases in recursion.
- For quick sort, consider worst-case scenarios and optimizations.
- Practice identifying when to use merge sort vs. quick sort (stability, space).
- For rotated arrays, focus on determining the sorted half.
