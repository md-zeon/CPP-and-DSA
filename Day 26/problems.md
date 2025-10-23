# Day 26: Doubly Linked Lists - Problems

## Problem List

### 1. Implement Push Front and Push Back

- **Description**: Implement functions to add elements at the beginning and end of a doubly linked list.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ val ≤ 10^9
- **Example**:
  - Initial: []
  - push_front(1): [1]
  - push_back(2): [1, 2]
- **Approach**: Update head/tail and prev/next pointers accordingly.
- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

### 2. Implement Pop Front and Pop Back

- **Description**: Implement functions to remove elements from the beginning and end of a doubly linked list.
- **Constraints**: List is not empty
- **Example**:
  - Initial: [1, 2, 3]
  - pop_front(): [2, 3]
  - pop_back(): [2]
- **Approach**: Update head/tail and clean up pointers.
- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

### 3. Insert at Position

- **Description**: Insert a new element at a given position in the doubly linked list.
- **Constraints**: 0 ≤ pos ≤ size, 1 ≤ n ≤ 10^5
- **Example**:
  - Initial: [1, 2, 3]
  - insert(4, 1): [1, 4, 2, 3]
- **Approach**: Traverse to the position and update pointers.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### 4. Delete at Position

- **Description**: Delete an element at a given position in the doubly linked list.
- **Constraints**: 0 ≤ pos < size, 1 ≤ n ≤ 10^5
- **Example**:
  - Initial: [1, 2, 3, 4]
  - deleteAt(2): [1, 2, 4]
- **Approach**: Traverse to the position, update links, and delete the node.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### 5. Reverse the Doubly Linked List

- **Description**: Reverse the order of elements in the doubly linked list in-place.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Initial: [1, 2, 3, 4]
  - Reverse: [4, 3, 2, 1]
- **Approach**: Swap next and prev pointers for each node.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## Additional Challenges

- Find the middle node of the doubly linked list.
- Detect if the doubly linked list has a cycle.
- Merge two sorted doubly linked lists.
- Sort the doubly linked list using merge sort.
- Implement a doubly linked list as a deque (double-ended queue).

## Notes

- Always update both next and prev pointers during insertions and deletions.
- Handle edge cases: empty list, single node, insertion at head/tail.
- Use proper memory management to avoid leaks.
- Compare with singly linked list for operations like reverse traversal.
- Practice drawing the list structure to visualize pointer changes.
