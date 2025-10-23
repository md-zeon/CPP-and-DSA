# Day 30: Greedy Algorithms - Problems

## Problem List

### 1. Activity Selection Problem

- **Description**: Select the maximum number of activities that don't overlap, given start and end times.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Input: [(1,3), (2,5), (3,9), (6,8)]
  - Output: 2 (select (1,3) and (6,8))
- **Approach**: Sort by end time and greedily select non-overlapping activities.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

### 2. Fractional Knapsack Problem

- **Description**: Maximize the total value in a knapsack of capacity W, where items can be taken fractionally.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ W ≤ 10^9
- **Example**:
  - Input: items = [(10,60), (20,100), (30,120)], W=50
  - Output: 240 (take full 20kg and 30kg of 30kg item)
- **Approach**: Sort by value/weight ratio and take items greedily.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

### 3. Huffman Coding

- **Description**: Build a Huffman tree for data compression given character frequencies.
- **Constraints**: 1 ≤ n ≤ 26 (for letters)
- **Example**:
  - Input: [('a',5), ('b',9), ('c',12), ('d',13), ('e',16), ('f',45)]
  - Output: Huffman codes for each character
- **Approach**: Use a priority queue to build the Huffman tree.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)

### 4. Job Sequencing Problem

- **Description**: Schedule jobs to maximize profit, given deadlines and profits.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Input: [(1,4,20), (2,1,10), (3,1,40), (4,1,30)]
  - Output: [3,1] (profit 70)
- **Approach**: Sort by profit and schedule in latest possible slot.
- **Time Complexity**: O(n^2)
- **Space Complexity**: O(n)

### 5. Kruskal's Algorithm for MST

- **Description**: Find the minimum spanning tree of a graph using Kruskal's algorithm.
- **Constraints**: 1 ≤ V ≤ 10^5, 1 ≤ E ≤ 10^5
- **Example**: Given edges with weights, find MST weight.
- **Approach**: Sort edges by weight and add if no cycle using Union-Find.
- **Time Complexity**: O(E log E)
- **Space Complexity**: O(V + E)

## Additional Challenges

- Implement Prim's algorithm for MST.
- Solve the coin change problem using greedy (for canonical systems).
- Find the minimum number of platforms required for trains.
- Implement the Egyptian fraction problem using greedy.
- Solve the interval covering problem.

## Notes

- Greedy algorithms make locally optimal choices leading to global optimum.
- Always sort the input based on a greedy criterion.
- Prove correctness using greedy choice property and optimal substructure.
- Compare with dynamic programming for overlapping subproblems.
- Practice with different sorting criteria for the same problem.
