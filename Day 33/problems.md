# Day 33: Binary Search Trees Part 2 - Problems

## Problem List

### 1. Find Floor and Ceiling in BST

- **Description**: Find the floor (largest <= key) and ceiling (smallest >= key) of a given key in BST.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ key ≤ 10^9
- **Example**:
  - BST: [4,2,6,1,3,5,7], key=5
  - Floor: 5, Ceiling: 5
- **Approach**: Traverse the tree, updating floor and ceiling based on comparisons.
- **Time Complexity**: O(h)
- **Space Complexity**: O(1)

### 2. Find Kth Smallest Element in BST

- **Description**: Find the kth smallest element in the BST.
- **Constraints**: 1 ≤ n ≤ 10^5, 1 ≤ k ≤ n
- **Example**:
  - BST: [4,2,6,1,3,5,7], k=3
  - Output: 4
- **Approach**: Use inorder traversal with a counter to find the kth element.
- **Time Complexity**: O(h + k)
- **Space Complexity**: O(h)

### 3. Count Elements in Range in BST

- **Description**: Count the number of elements in the BST that lie within a given range [low, high].
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ low, high ≤ 10^9
- **Example**:
  - BST: [4,2,6,1,3,5,7], range=[2,5]
  - Output: 4 (2,3,4,5)
- **Approach**: Recursively count nodes that fall within the range.
- **Time Complexity**: O(h + k)
- **Space Complexity**: O(h)

### 4. Build BST from Inorder and Preorder Traversals

- **Description**: Construct a BST from given inorder and preorder traversals.
- **Constraints**: 1 ≤ n ≤ 10^5, unique elements
- **Example**:
  - Inorder: [4,2,5,1,6,3,7]
  - Preorder: [1,2,4,5,3,6,7]
  - Output: BST with these traversals
- **Approach**: Use preorder to find root, inorder to find left/right subtrees.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

### 5. Convert BST to Sorted Array

- **Description**: Convert the BST to a sorted array using inorder traversal.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - BST: [4,2,6,1,3,5,7]
  - Output: [1,2,3,4,5,6,7]
- **Approach**: Perform inorder traversal and collect elements in a vector.
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Additional Challenges

- Build BST from inorder and postorder traversals.
- Find the lowest common ancestor of two nodes in BST.
- Implement a BST iterator for inorder traversal.
- Merge two BSTs into a single sorted array.
- Check if a BST is complete.

## Notes

- Inorder traversal is key for many BST operations as it gives sorted order.
- For construction from traversals, identify the root and recursively build subtrees.
- Use iterative approaches for better space efficiency where possible.
- Handle edge cases: empty tree, single node, range boundaries.
- Understand the relationship between different traversal orders.
