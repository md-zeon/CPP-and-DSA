# Day 28: Advanced Stack Problems - Problems

## Problem List

### 1. Next Greater Element

- **Description**: For each element in the array, find the next greater element to its right. If none exists, return -1.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [6, 8, 0, 1, 3]
  - Output: [8, -1, 1, 3, -1]
- **Approach**: Use a decreasing monotonic stack to find the next greater element.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 2. Valid Parentheses

- **Description**: Check if a string containing parentheses, brackets, and braces is valid (balanced).
- **Constraints**: 1 ≤ length ≤ 10^5
- **Example**:
  - Input: "([{}])"
  - Output: true
  - Input: "([}])"
  - Output: false
- **Approach**: Use a stack to match opening and closing brackets.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 3. Detect Duplicate Parentheses

- **Description**: Check if an expression has duplicate (redundant) parentheses.
- **Constraints**: 1 ≤ length ≤ 10^5
- **Example**:
  - Input: "((x+y)) + z"
  - Output: true
  - Input: "((a + b) + (c + d))"
  - Output: false
- **Approach**: Use a stack to track operators and parentheses.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 4. Largest Rectangle in Histogram

- **Description**: Find the largest rectangle area in a histogram where heights are given.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ height[i] ≤ 10^9
- **Example**:
  - Input: [2, 1, 5, 6, 2, 3]
  - Output: 10
- **Approach**: Use stack to find nearest smaller elements for width calculation.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 5. Next Smaller Element

- **Description**: For each element, find the next smaller element to its right. If none, return -1.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [3, 2, 1, 4]
  - Output: [2, 1, -1, -1]
- **Approach**: Use an increasing monotonic stack.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Find the previous greater element for each element.
- Implement a stack that supports push, pop, and get minimum in O(1) time.
- Remove all adjacent duplicates in a string using a stack.
- Evaluate a postfix expression using a stack.
- Find the area of the largest rectangle in a binary matrix.

## Notes

- Monotonic stacks are powerful for nearest element problems.
- Always handle edge cases like empty arrays or single elements.
- For histogram problems, calculate width using left and right boundaries.
- Practice with different stack directions (increasing/decreasing).
- Understand the difference between next greater and next smaller.
