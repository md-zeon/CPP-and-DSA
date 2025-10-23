# Day 35: Binary Search Trees Part 4 - Problems

## Problem List

### 1. Convert Sorted Array to Balanced BST

- **Description**: Construct a balanced BST from a sorted array.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [1, 2, 3, 4, 5, 6, 7]
  - Output: Balanced BST with height log n
- **Approach**: Use the middle element as root and recursively build subtrees.
- **Time Complexity**: O(n)
- **Space Complexity**: O(log n)

### 2. Convert BST to Sorted Array

- **Description**: Convert the BST to a sorted array using inorder traversal.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - BST: [4,2,6,1,3,5,7]
  - Output: [1,2,3,4,5,6,7]
- **Approach**: Perform inorder traversal and collect elements in a vector.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 3. Find Largest BST in Binary Tree

- **Description**: Find the largest BST subtree in a given binary tree.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Binary Tree: [5,1,4,3,6]
  - Largest BST: [1,3,6] (size 3)
- **Approach**: Use a helper class to track BST properties and size.
- **Time Complexity**: O(n)
- **Space Complexity**: O(h)

### 4. Merge Two BSTs

- **Description**: Merge two BSTs into a single sorted array or balanced BST.
- **Constraints**: 1 ≤ n, m ≤ 10^5
- **Example**:
  - BST1: [2,1,3], BST2: [4,5,6]
  - Output: [1,2,3,4,5,6]
- **Approach**: Convert both to sorted arrays, merge, and optionally build new BST.
- **Time Complexity**: O(n + m)
- **Space Complexity**: O(n + m)

### 5. Build BST from Inorder and Preorder Traversals

- **Description**: Construct a BST from given inorder and preorder traversals.
- **Constraints**: 1 ≤ n ≤ 10^5, unique elements
- **Example**:
  - Inorder: [4,2,5,1,6,3,7]
  - Preorder: [1,2,4,5,3,6,7]
  - Output: BST with these traversals
- **Approach**: Use preorder to find root, inorder to find left/right subtrees.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Build BST from inorder and postorder traversals.
- Convert BST to a sorted doubly linked list.
- Find the kth smallest element in BST.
- Check if two BSTs are identical.
- Find the lowest common ancestor in BST.

## Notes

- Balanced BST construction ensures optimal height and performance.
- Inorder traversal is essential for converting BST to sorted structures.
- Merging BSTs can be done by converting to arrays and merging.
- Largest BST problem requires tracking BST properties recursively.
- Construction from traversals requires understanding traversal orders.
