# Day 37: Advanced Heap Operations & Priority Queue Applications - Problems

## Problem List

### 1. Implement Heap Sort

- **Description**: Sort an array using heap sort algorithm.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [12, 11, 13, 5, 6, 7]
  - Output: [5, 6, 7, 11, 12, 13]
- **Approach**: Build max heap, then extract max repeatedly.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(1)

### 2. Find K Nearest Cars from Origin

- **Description**: Given coordinates of cars, find the K nearest cars from the origin.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ k ≤ n
- **Example**:
  - Cars: [(1,1), (2,2), (3,3)], k=2
  - Output: (1,1), (2,2)
- **Approach**: Use a max heap to keep track of K smallest distances.
- **Time Complexity**: O(n log k)
- **Space Complexity**: O(k)

### 3. Connect N Ropes with Minimum Cost

- **Description**: Connect N ropes with minimum cost, where cost of connecting two ropes is the sum of their lengths.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ length ≤ 10^9
- **Example**:
  - Ropes: [4, 3, 2, 6]
  - Output: 29 (connect 2+3=5, 4+5=9, 6+9=15, total 5+9+15=29)
- **Approach**: Use a min heap to always connect the two smallest ropes.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

### 4. Find K Weakest Rows in a Matrix

- **Description**: Find the K weakest rows in a matrix based on the number of soldiers (1s).
- **Constraints**: 1 ≤ m, n ≤ 100, 1 ≤ k ≤ m
- **Example**:
  - Matrix: [[1,1,0], [1,0,0], [1,1,1]], k=2
  - Output: Row 1, Row 0 (fewer 1s, then smaller index)
- **Approach**: Use a priority queue with custom comparator for soldier count and index.
- **Time Complexity**: O(m n log k)
- **Space Complexity**: O(k)

### 5. Sliding Window Maximum

- **Description**: Find the maximum element in each window of size K in an array.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ k ≤ n
- **Example**:
  - Array: [1,3,-1,-3,5,3,6,7], k=3
  - Output: [3,3,5,5,6,7]
- **Approach**: Use a max heap to maintain the current window's elements.
- **Time Complexity**: O(n log k)
- **Space Complexity**: O(k)

## Additional Challenges

- Implement heap sort for strings.
- Find the median of a data stream using two heaps.
- Solve the top K frequent elements problem.
- Implement a priority queue for Dijkstra's algorithm.
- Find the kth smallest element in a matrix.

## Notes

- Heap sort is an in-place sorting algorithm with O(n log n) time.
- Priority queues are essential for problems requiring ordered processing.
- Custom comparators allow handling multiple criteria.
- Sliding window problems often use heaps for efficiency.
- Always consider the time complexity of heap operations.
