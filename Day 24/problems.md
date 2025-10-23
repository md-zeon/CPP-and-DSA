# Day 24: Backtracking - Problems

## Problem List

### 1. Generate All Subsets

- **Description**: Given a string or array, generate all possible subsets (power set).
- **Constraints**: 1 ≤ n ≤ 20 (since 2^n can be large)
- **Example**:
  - Input: "abc"
  - Output: "", "a", "b", "c", "ab", "ac", "bc", "abc"
- **Approach**: Use backtracking to include or exclude each element.
- **Time Complexity**: O(2^n)
- **Space Complexity**: O(n)

### 2. Generate All Permutations

- **Description**: Generate all unique permutations of a string or array.
- **Constraints**: 1 ≤ n ≤ 10 (n! grows fast)
- **Example**:
  - Input: "abc"
  - Output: "abc", "acb", "bac", "bca", "cab", "cba"
- **Approach**: Use backtracking to choose each character and recurse on the remaining.
- **Time Complexity**: O(n!)
- **Space Complexity**: O(n)

### 3. N-Queens Problem

- **Description**: Place n queens on an n×n chessboard such that no two queens attack each other.
- **Constraints**: 1 ≤ n ≤ 10
- **Example**:
  - Input: n = 4
  - Output: Solutions where no queens share row, column, or diagonal.
- **Approach**: Use backtracking to place queens row by row, checking safety.
- **Time Complexity**: O(n!)
- **Space Complexity**: O(n^2)

### 4. Count Paths in a Grid

- **Description**: Count the number of ways to reach from (0,0) to (n-1,m-1) in a grid, moving only right or down.
- **Constraints**: 1 ≤ n, m ≤ 20
- **Example**:
  - Input: n=3, m=3
  - Output: 6 (RRDD, RDRD, RDDR, DRRD, DRDR, DDRR)
- **Approach**: Use backtracking to explore right and down moves.
- **Time Complexity**: O(2^(n+m))
- **Space Complexity**: O(n+m)

### 5. Sudoku Solver

- **Description**: Solve a 9×9 Sudoku puzzle using backtracking.
- **Constraints**: Standard 9×9 grid with some cells filled.
- **Example**: Given a partially filled grid, find a complete solution.
- **Approach**: Use backtracking to try digits 1-9 in empty cells, checking row, column, and 3×3 constraints.
- **Time Complexity**: O(9^(n^2)) worst case
- **Space Complexity**: O(n^2)

## Additional Challenges

- Find all paths in a maze from start to end.
- Solve the Knight's Tour problem (visit all squares on a chessboard).
- Generate all combinations of k elements from n elements.
- Solve the subset sum problem (find subsets that sum to a target).
- Implement a backtracking solution for the Hamiltonian Path problem.

## Notes

- Backtracking is useful for constraint satisfaction problems.
- Always implement constraint checking to prune invalid branches.
- Use recursion to explore all possibilities and backtrack to undo choices.
- For optimization, consider the order of choices and early termination.
- Practice with small inputs to understand the decision tree.
