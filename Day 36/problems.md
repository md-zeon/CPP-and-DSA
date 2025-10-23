# Day 36: Heaps and Priority Queues Part 1 - Problems

## Problem List

### 1. Implement Custom Max Heap

- **Description**: Implement a max heap with push, pop, top, and empty operations.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ val ≤ 10^9
- **Example**:
  - push(5), push(10), push(3)
  - top(): 10, pop(), top(): 5
- **Approach**: Use array representation with heapify and bubble up.
- **Time Complexity**: Push/Pop O(log n), Top O(1)
- **Space Complexity**: O(n)

### 2. Priority Queue with Custom Objects

- **Description**: Use priority queue with custom objects (e.g., Student with name and marks).
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Students: (Aman,85), (Akbar,95), (Anthony,65)
  - Top: Akbar 95
- **Approach**: Overload operator< or use custom comparator.
- **Time Complexity**: O(log n) for operations
- **Space Complexity**: O(n)

### 3. Priority Queue with Pairs and Custom Comparator

- **Description**: Use priority queue with pairs and a custom comparator.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Pairs: (Aman,85), (Akbar,95), (Anthony,65)
  - Top: Akbar 95
- **Approach**: Define a comparator struct for the priority queue.
- **Time Complexity**: O(log n) for operations
- **Space Complexity**: O(n)

### 4. Find Kth Largest Element Using Min Heap

- **Description**: Find the kth largest element in an array using a min heap.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ k ≤ n
- **Example**:
  - Array: [3,2,1,5,6,4], k=2
  - Output: 5
- **Approach**: Maintain a min heap of size k, replace if larger.
- **Time Complexity**: O(n log k)
- **Space Complexity**: O(k)

### 5. Merge K Sorted Arrays Using Priority Queue

- **Description**: Merge k sorted arrays into a single sorted array using a priority queue.
- **Constraints**: 1 ≤ k ≤ 100, 1 ≤ n ≤ 10^5 total elements
- **Example**:
  - Arrays: [1,4,5], [1,3,4], [2,6]
  - Output: [1,1,2,3,4,4,5,6]
- **Approach**: Use a priority queue to always pick the smallest from the arrays.
- **Time Complexity**: O(n log k)
- **Space Complexity**: O(k)

## Additional Challenges

- Implement a min heap.
- Find the kth smallest element using a max heap.
- Implement heap sort.
- Use priority queue for Dijkstra's algorithm.
- Implement a median heap (two heaps for median).

## Notes

- Heaps maintain the heap property: parent >= children for max heap.
- Priority queue in STL is implemented as a max heap by default.
- Custom comparators allow flexible ordering.
- Heaps are useful for priority-based operations.
- Practice implementing heaps from scratch for better understanding.
