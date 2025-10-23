# Day 20: Recursion Part 2 - Problems

## Problem List

### 1. Tiling Problem

- **Description**: Given a 2×n board, find the number of ways to tile it using 2×1 tiles. Tiles can be placed horizontally or vertically.
- **Constraints**: 1 ≤ n ≤ 40
- **Example**:
  - Input: n = 3
  - Output: 3
  - Explanation: Possible ways: VVV, HH, VH (V=Vertical, H=Horizontal)
- **Approach**: Use recursion with base cases for n=0 and n=1.
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n)

### 2. Remove Duplicates from String

- **Description**: Remove all duplicate characters from a string using recursion, preserving the order of first occurrence.
- **Constraints**: String length ≤ 100, lowercase letters only
- **Example**:
  - Input: "aabbcc"
  - Output: "abc"
- **Approach**: Use a boolean array to track seen characters and build the result recursively.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 3. Friends Pairing Problem

- **Description**: Given n friends, find the number of ways to pair them up. Each friend can either remain single or pair with another friend.
- **Constraints**: 1 ≤ n ≤ 20
- **Example**:
  - Input: n = 3
  - Output: 4
  - Explanation: (A,B,C), (AB,C), (AC,B), (A,BC)
- **Approach**: Recursion where each person can be single or pair with one of the remaining.
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n)

### 4. Generate Binary Strings Without Consecutive 1s

- **Description**: Generate all binary strings of length n where no two consecutive characters are '1'.
- **Constraints**: 1 ≤ n ≤ 20
- **Example**:
  - Input: n = 3
  - Output: 000, 001, 010, 100, 101
- **Approach**: Use recursion with a parameter to track the last placed character.
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n)

### 5. Optimized Versions with Memoization

- **Description**: Implement the above problems using memoization to optimize time complexity.
- **Approach**: Use an array or map to store computed results for each subproblem.
- **Time Complexity**: O(n) for each
- **Space Complexity**: O(n)

## Additional Challenges

- Modify the tiling problem to use 2×1 and 2×2 tiles.
- Generate all permutations of a string without duplicates using recursion.
- Solve the subset sum problem using recursion (find if a subset sums to a target).
- Implement a recursive solution for the knapsack problem (0/1 knapsack).

## Notes

- Focus on identifying base cases and recursive cases.
- Use additional parameters to manage state (e.g., last placed, seen characters).
- Practice drawing recursion trees to visualize the calls.
- Consider when to use memoization or dynamic programming for optimization.
