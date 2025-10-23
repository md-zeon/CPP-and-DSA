# Day 31: Binary Trees Part 1 - Practice Problems

## Problem 1: Binary Tree Construction from Array

**Difficulty:** Easy

### Description

Build a binary tree from a given array representation where -1 represents NULL nodes.

### Input Format

- First line: number of nodes
- Second line: array elements (use -1 for NULL nodes)

### Output Format

- Print the tree using inorder traversal

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
4 2 5 1 3 6
```

### Tree Structure

```
       1
      / \
     2   3
    / \   \
   4   5   6
```

### Array Representation: [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]

---

## Problem 2: Tree Traversals

**Difficulty:** Easy

### Description

Implement and demonstrate all four types of binary tree traversals.

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Preorder traversal
- Inorder traversal
- Postorder traversal
- Level order traversal

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
Preorder: 1 2 4 5 3 6
Inorder: 4 2 5 1 3 6
Postorder: 4 5 2 6 3 1
Level Order: 1 2 3 4 5 6
```

### Traversal Orders

- **Preorder**: Root → Left → Right
- **Inorder**: Left → Root → Right
- **Postorder**: Left → Right → Root
- **Level Order**: Level by level from left to right

---

## Problem 3: Tree Height Calculation

**Difficulty:** Easy

### Description

Calculate the height (maximum depth) of a binary tree.

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print the height of the tree

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
Height: 3
```

### Sample Input (Skewed Tree)

```
4
1 2 -1 -1 3 -1 -1
```

### Sample Output

```
Height: 3
```

### Definition

- Height of a node = maximum height of its subtrees + 1
- Height of NULL node = 0
- Height of single node tree = 1

---

## Problem 4: Count Total Nodes

**Difficulty:** Easy

### Description

Count the total number of nodes in a binary tree.

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print the total number of nodes

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
Total Nodes: 6
```

### Algorithm

- Recursively count nodes in left subtree + right subtree + 1 (for current node)

---

## Problem 5: Sum of All Node Values

**Difficulty:** Easy

### Description

Calculate the sum of all node values in a binary tree.

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print the sum of all node values

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
Sum: 21
```

### Explanation

1 + 2 + 4 + 5 + 3 + 6 = 21

---

## Problem 6: Level Order Traversal with New Lines

**Difficulty:** Medium

### Description

Print the level order traversal of a binary tree with each level on a new line.

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print each level on a new line

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
1
2 3
4 5 6
```

### Algorithm

- Use queue for BFS traversal
- Use NULL marker to separate levels
- Print newline when NULL is encountered

---

## Problem 7: Find Maximum Value in Tree

**Difficulty:** Easy

### Description

Find the maximum value in a binary tree.

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print the maximum value

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
Maximum Value: 6
```

### Edge Cases

- Single node tree
- All negative values
- Tree with duplicate values

---

## Problem 8: Tree Diameter (Longest Path)

**Difficulty:** Hard

### Description

Calculate the diameter of a binary tree (longest path between any two nodes).

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print the length of the diameter

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
Diameter: 4
```

### Explanation

Longest path: 4 → 2 → 1 → 3 → 6 (length 4)

### Algorithm

- For each node, calculate:
  - Height of left subtree
  - Height of right subtree
  - Current diameter = left height + right height
  - Update global maximum diameter

---

## Problem 9: Left View of Binary Tree

**Difficulty:** Medium

### Description

Print the left view of a binary tree (leftmost node at each level).

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print left view nodes separated by spaces

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
1 2 4
```

### Explanation

- Level 0: 1
- Level 1: 2 (leftmost)
- Level 2: 4 (leftmost)

### Algorithm

- Use level order traversal
- Print first node of each level

---

## Problem 10: Top View of Binary Tree

**Difficulty:** Medium

### Description

Print the top view of a binary tree (nodes visible from the top).

### Input Format

- First line: number of nodes
- Second line: array representation of the tree

### Output Format

- Print top view nodes in order from left to right

### Sample Input

```
7
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

### Sample Output

```
4 2 1 3 6
```

### Explanation

- Horizontal distance -2: 4
- Horizontal distance -1: 2
- Horizontal distance 0: 1
- Horizontal distance 1: 3
- Horizontal distance 2: 6

### Algorithm

- Use level order traversal with horizontal distance
- Use map to store first node at each horizontal distance

---

## Additional Practice Problems

### Problem 11: Right View of Binary Tree

Print the right view of a binary tree (rightmost node at each level).

### Problem 12: Bottom View of Binary Tree

Print the bottom view of a binary tree (nodes visible from the bottom).

### Problem 13: Vertical Order Traversal

Print nodes in vertical order (same horizontal distance together).

### Problem 14: Check if Two Trees are Identical

Check if two binary trees are identical in structure and values.

### Problem 15: Check if Tree is Balanced

Check if the binary tree is height-balanced (height difference ≤ 1 for all nodes).

### Problem 16: Lowest Common Ancestor

Find the lowest common ancestor of two nodes in a binary tree.

### Problem 17: Maximum Width of Tree

Find the maximum width of the tree (maximum nodes at any level).

### Problem 18: Print All Root to Leaf Paths

Print all paths from root to leaf nodes.

### Problem 19: Sum of Left Leaves

Calculate the sum of all left leaf nodes.

### Problem 20: Check if Tree is Complete

Check if the binary tree is a complete binary tree.
