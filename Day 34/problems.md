# Day 34: Binary Search Trees Part 3 - Problems

## Problem List

### 1. Build BST from Array

- **Description**: Construct a BST by inserting elements from an array.
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ arr[i] ≤ 10^9
- **Example**:
  - Input: [4, 2, 6, 1, 3, 5, 7]
  - Output: BST with these elements
- **Approach**: Insert each element into the BST using the insert function.
- **Time Complexity**: O(n log n) average, O(n^2) worst
- **Space Complexity**: O(h)

### 2. Delete a Node in BST

- **Description**: Delete a node with given value from the BST, handling all cases (leaf, one child, two children).
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ val ≤ 10^9
- **Example**:
  - BST: [4,2,6,1,3,5,7], delete 2
  - Output: [4,1,6,3,5,7]
- **Approach**: Find the node, handle deletion cases, use inorder successor for two children.
- **Time Complexity**: O(h)
- **Space Complexity**: O(h)

### 3. Print Elements in Range in BST

- **Description**: Print all elements in the BST that lie within a given range [low, high].
- **Constraints**: 1 ≤ n ≤ 10^5, -10^9 ≤ low, high ≤ 10^9
- **Example**:
  - BST: [4,2,6,1,3,5,7], range=[2,5]
  - Output: 2, 3, 4, 5
- **Approach**: Recursively traverse and print nodes within the range.
- **Time Complexity**: O(h + k)
- **Space Complexity**: O(h)

### 4. Find All Root to Leaf Paths in BST

- **Description**: Find and print all paths from the root to leaf nodes in the BST.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - BST: [4,2,6,1,3,5,7]
  - Output: 4-2-1, 4-2-3, 4-6-5, 4-6-7
- **Approach**: Use backtracking to explore paths and print at leaves.
- **Time Complexity**: O(n)
- **Space Complexity**: O(h)

### 5. Validate BST

- **Description**: Check if a given binary tree is a valid BST.
- **Constraints**: 1 ≤ n ≤ 10^5
- **Example**:
  - Tree: [2,1,3] -> true
  - Tree: [5,1,4,3,6] -> false
- **Approach**: Recursively check BST property with min/max bounds.
- **Time Complexity**: O(n)
- **Space Complexity**: O(h)

## Additional Challenges

- Find the inorder successor of a node in BST.
- Convert BST to a sorted doubly linked list.
- Find the kth smallest element in BST.
- Check if two BSTs are identical.
- Find the lowest common ancestor in BST.

## Notes

- BST operations rely on the ordering property for efficiency.
- Deletion requires handling three cases: leaf, one child, two children.
- Range operations use the BST structure to prune unnecessary subtrees.
- Path finding uses backtracking to explore all possible paths.
- Validation ensures the tree maintains BST invariants.
