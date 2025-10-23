# Day 27: Stack STL and Applications - Problems

## Problem List

### 1. Push at Bottom Using Recursion

- **Description**: Insert an element at the bottom of a stack using recursion.
- **Constraints**: 1 ≤ n ≤ 1000 (recursion depth)
- **Example**:
  - Initial: [1, 2, 3]
  - pushAtBottom(4): [4, 1, 2, 3]
- **Approach**: Use recursion to pop elements, insert at bottom, then push back.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 2. Reverse a String Using Stack

- **Description**: Reverse a given string using a stack.
- **Constraints**: 1 ≤ length ≤ 10^5
- **Example**:
  - Input: "hello"
  - Output: "olleh"
- **Approach**: Push all characters to stack, then pop to build reversed string.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 3. Reverse a Stack Using Recursion

- **Description**: Reverse the contents of a stack using recursion.
- **Constraints**: 1 ≤ n ≤ 1000
- **Example**:
  - Initial: [1, 2, 3]
  - Reverse: [3, 2, 1]
- **Approach**: Use recursion to pop elements and push at bottom.
- **Time Complexity**: O(n^2)
- **Space Complexity**: O(n)

### 4. Stock Span Problem

- **Description**: For each day, find the number of consecutive days before it with prices less than or equal to it.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ price ≤ 10^9
- **Example**:
  - Input: [100, 80, 60, 70, 60, 65, 100]
  - Output: [1, 1, 1, 2, 1, 5, 7]
- **Approach**: Use a stack to find the nearest greater element to the left.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 5. Check Balanced Parentheses

- **Description**: Check if a string of parentheses is balanced using a stack.
- **Constraints**: 1 ≤ length ≤ 10^5
- **Example**:
  - Input: "({[]})"
  - Output: true
  - Input: "({[})"
  - Output: false
- **Approach**: Push opening brackets, pop for closing, check matches.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Implement a stack that supports push, pop, and get minimum in O(1) time.
- Find the next greater element for each element in an array using a stack.
- Evaluate a postfix expression using a stack.
- Convert infix expression to postfix using a stack.
- Implement a stack using two queues.

## Notes

- Stack follows LIFO (Last In, First Out) principle.
- Use STL stack for efficient operations.
- Recursion can be used for complex manipulations like push at bottom.
- Monotonic stacks are useful for problems like stock span and next greater.
- Always handle empty stack cases in implementations.
