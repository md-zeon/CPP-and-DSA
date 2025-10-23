# Day 29: Queues and Deque - Problems

## Problem List

### 1. Implement Queue Using Two Stacks

- **Description**: Implement a queue using two stacks with amortized O(1) operations.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - push(1), push(2), pop() -> 1
  - push(3), front() -> 2
- **Approach**: Use one stack for enqueue, transfer to another for dequeue.
- **Time Complexity**: O(1) amortized
- **Space Complexity**: O(n)

### 2. Implement Stack Using Two Queues

- **Description**: Implement a stack using two queues with amortized O(1) operations.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - push(1), push(2), top() -> 2
  - pop(), top() -> 1
- **Approach**: Use one queue for main operations, transfer for push.
- **Time Complexity**: O(1) amortized
- **Space Complexity**: O(n)

### 3. First Non-Repeating Character in Stream

- **Description**: For each character in a stream, find the first non-repeating character.
- **Constraints**: 1 ≤ length ≤ 10^5, lowercase letters
- **Example**:
  - Input: "aabccxb"
  - Output: a, a, a, a, b, b, x
- **Approach**: Use a queue and frequency array to track non-repeating characters.
- **Time Complexity**: O(n)
- **Space Complexity**: O(26)

### 4. Interleave Queue Elements

- **Description**: Interleave the first half of the queue with the second half.
- **Constraints**: 1 ≤ n ≤ 10^5, n even
- **Example**:
  - Input: [1, 2, 3, 4, 5, 6]
  - Output: [1, 4, 2, 5, 3, 6]
- **Approach**: Use another queue to hold the first half, then interleave.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 5. Reverse a Queue Using Stack

- **Description**: Reverse the elements of a queue using a stack.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Input: [1, 2, 3, 4, 5]
  - Output: [5, 4, 3, 2, 1]
- **Approach**: Move elements to stack, then back to queue.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Implement a circular queue using an array.
- Find the maximum in a sliding window using a deque.
- Check if a string is a palindrome using a deque.
- Implement an LRU cache using a queue and hash map.
- Solve the gas station problem using a queue.

## Notes

- Queue follows FIFO (First In, First Out) principle.
- Deque allows operations at both ends, making it versatile.
- Use STL queue and deque for efficient implementations.
- Amortized analysis is important for two-stack implementations.
- Practice converting between stacks and queues.
