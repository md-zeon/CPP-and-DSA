# Day 32: Binary Search Trees Part 1 - Problems

## Problem List

### 1. Insert a Node in BST

- **Description**: Insert a new node with given value into the BST while maintaining BST property.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ val ≤ 10^9
- **Example**:
  - Initial BST: [4,2,6,1,3,5,7]
  - Insert 8: [4,2,6,1,3,5,7,8]
- **Approach**: Recursively find the correct position and insert.
- **Time Complexity**: O(h)
- **Space Complexity**: O(h)

### 2. Search for a Node in BST

- **Description**: Search for a node with given key in the BST.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ key ≤ 10^9
- **Example**:
  - BST: [4,2,6,1,3,5,7], key=5
  - Output: Found
- **Approach**: Recursively or iteratively traverse based on BST property.
- **Time Complexity**: O(h)
- **Space Complexity**: O(h) recursive, O(1) iterative

### 3. Delete a Node in BST

- **Description**: Delete a node with given key from the BST while maintaining BST property.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ key ≤ 10^9
- **Example**:
  - BST: [4,2,6,1,3,5,7], delete 2
  - Output: [4,1,6,3,5,7]
- **Approach**: Handle cases: leaf, one child, two children (use successor).
- **Time Complexity**: O(h)
- **Space Complexity**: O(h)

### 4. Validate BST

- **Description**: Check if a given binary tree is a valid BST.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Tree: [2,1,3] -> true
  - Tree: [5,1,4,3,6] -> false (3 < 5 but in right subtree)
- **Approach**: Recursively check BST property with min/max bounds.
- **Time Complexity**: O(n)
- **Space Complexity**: O(h)

### 5. Find Inorder Successor and Predecessor

- **Description**: Find the inorder successor and predecessor of a given node in BST.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - BST: [4,2,6,1,3,5,7], node=3
  - Successor: 4, Predecessor: 2
- **Approach**: For successor, go right then leftmost; for predecessor, go left then rightmost.
- **Time Complexity**: O(h)
- **Space Complexity**: O(1)

## Additional Challenges

- Build a BST from a sorted array.
- Find the kth smallest element in BST.
- Check if two BSTs are identical.
- Find the lowest common ancestor in BST.
- Convert a BST to a sorted doubly linked list.

## Notes

- BST property: left subtree < root < right subtree.
- All operations are O(h) where h is the height of the tree.
- Inorder traversal gives sorted order in BST.
- Handle edge cases: empty tree, single node, skewed tree.
- Consider iterative implementations for better space efficiency.
