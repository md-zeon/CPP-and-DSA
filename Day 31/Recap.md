# Day 31: Binary Trees Part 1

## Topics Covered

- **Binary Tree Structure**: Node with at most two children
- **Tree Traversal**: Preorder, inorder, postorder traversals
- **Tree Construction**: Building trees from traversals
- **Tree Properties**: Height, size, diameter calculations
- **Level Order Traversal**: Breadth-first traversal using queue
- **Tree Views**: Left view, right view, top view, bottom view

## Key Concepts

1. **Binary Tree Definition**: Each node has at most two children (left, right)
2. **Recursive Structure**: Trees are naturally recursive data structures
3. **Traversal Orders**: Different ways to visit nodes (pre, in, post)
4. **Tree Metrics**: Height, depth, diameter, size calculations
5. **Level Order**: BFS traversal using queue

## Code Examples

### 1. Binary Tree Node Structure

```cpp
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

### 2. Preorder Traversal (Root, Left, Right)

```cpp
void preorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";  // Visit root
    preorder(root->left);       // Traverse left
    preorder(root->right);      // Traverse right
}

// Example: Tree with root 1, left 2, right 3
// Output: 1 2 3
```

### 3. Inorder Traversal (Left, Root, Right)

```cpp
void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);        // Traverse left
    cout << root->data << " ";  // Visit root
    inorder(root->right);       // Traverse right
}

// Example: Tree with root 1, left 2, right 3
// Output: 2 1 3
```

### 4. Postorder Traversal (Left, Right, Root)

```cpp
void postorder(Node* root) {
    if(root == NULL) return;

    postorder(root->left);      // Traverse left
    postorder(root->right);     // Traverse right
    cout << root->data << " ";  // Visit root
}

// Example: Tree with root 1, left 2, right 3
// Output: 2 3 1
```

### 5. Level Order Traversal (BFS)

```cpp
void levelOrder(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}

// Example: Tree with root 1, left 2, right 3
// Output: 1 2 3
```

### 6. Tree Height Calculation

```cpp
int height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is height
```

### 7. Tree Size (Total Nodes)

```cpp
int size(Node* root) {
    if(root == NULL) return 0;

    int leftSize = size(root->left);
    int rightSize = size(root->right);

    return 1 + leftSize + rightSize;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 8. Maximum Value in Tree

```cpp
int maxValue(Node* root) {
    if(root == NULL) return INT_MIN;

    int result = root->data;
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);

    return max({result, leftMax, rightMax});
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 9. Tree Diameter (Longest Path)

```cpp
int diameter(Node* root, int* height) {
    if(root == NULL) {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ld = diameter(root->left, &lh);
    int rd = diameter(root->right, &rh);

    *height = 1 + max(lh, rh);

    // Diameter through current node
    int currDiameter = lh + rh;

    return max({currDiameter, ld, rd});
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 10. Left View of Tree

```cpp
void leftViewUtil(Node* root, int level, int* maxLevel) {
    if(root == NULL) return;

    if(*maxLevel < level) {
        cout << root->data << " ";
        *maxLevel = level;
    }

    leftViewUtil(root->left, level + 1, maxLevel);
    leftViewUtil(root->right, level + 1, maxLevel);
}

void leftView(Node* root) {
    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
}

// Prints leftmost nodes at each level
```

### 11. Right View of Tree

```cpp
void rightViewUtil(Node* root, int level, int* maxLevel) {
    if(root == NULL) return;

    if(*maxLevel < level) {
        cout << root->data << " ";
        *maxLevel = level;
    }

    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}

void rightView(Node* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
}

// Prints rightmost nodes at each level
```

### 12. Top View of Tree

```cpp
void topView(Node* root) {
    if(root == NULL) return;

    map<int, int> m;  // horizontal distance -> node data
    queue<pair<Node*, int>> q;  // node, horizontal distance

    q.push({root, 0});

    while(!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        if(m.find(hd) == m.end()) {
            m[hd] = node->data;
        }

        if(node->left != NULL) q.push({node->left, hd - 1});
        if(node->right != NULL) q.push({node->right, hd + 1});
    }

    for(auto p : m) {
        cout << p.second << " ";
    }
}
```

## Tree Traversal Analysis

### Traversal Complexities

- **All Traversals**: O(n) time, O(h) space (recursion stack)
- **Level Order**: O(n) time, O(w) space where w is maximum width
- **Morris Traversal**: O(n) time, O(1) space (threaded traversal)

### Traversal Applications

- **Preorder**: Copy tree, expression evaluation
- **Inorder**: BST sorting, expression infix notation
- **Postorder**: Delete tree, expression postfix notation
- **Level Order**: Print level by level, find width

## Tree Properties

### 1. Complete Binary Tree

- All levels filled except possibly last level
- Last level filled from left to right
- Can be implemented efficiently with arrays

### 2. Full Binary Tree

- Every node has 0 or 2 children
- No node has exactly one child
- Maximum number of nodes: 2^(h+1) - 1

### 3. Perfect Binary Tree

- All levels completely filled
- All leaf nodes at same level
- Maximum number of nodes: 2^(h+1) - 1

## Key Takeaways

- **Recursive Nature**: Trees are naturally recursive
- **Multiple Traversals**: Each traversal has specific use cases
- **Height vs Depth**: Height from bottom, depth from top
- **Level Order**: Uses queue for BFS traversal
- **View Problems**: Use horizontal distance for top/bottom views

## Common Mistakes to Avoid

- Forgetting null checks in recursive functions
- Incorrect base cases in recursion
- Not understanding traversal order differences
- Stack overflow with deep recursion (use iterative when possible)
- Not handling empty tree cases

## Tree vs Other Data Structures

### Binary Tree vs BST

- **Binary Tree**: No ordering constraint
- **BST**: Left < root < right ordering
- **Operations**: BST has efficient search, tree has flexible structure

### Binary Tree vs Array

- **Binary Tree**: Dynamic size, pointer overhead
- **Array**: Fixed size, fast access, memory efficient
- **Use Case**: Tree for hierarchical data, array for sequential

### Binary Tree vs Linked List

- **Binary Tree**: 2D structure, multiple children
- **Linked List**: 1D structure, single next pointer
- **Traversal**: Tree has multiple traversal orders

## Applications

### 1. File Systems

- **Directory Structure**: Hierarchical file organization
- **Path Navigation**: Moving through directory tree
- **File Search**: Finding files in directory structure

### 2. Database Systems

- **B-Tree Indexes**: Database indexing for fast search
- **Expression Trees**: Mathematical expression representation
- **Query Optimization**: Query execution planning

### 3. Computer Graphics

- **Scene Graphs**: 3D scene representation
- **Quad Trees**: Spatial partitioning for collision detection
- **Octrees**: 3D spatial partitioning

### 4. Network Routing

- **Routing Tables**: Network path optimization
- **Decision Trees**: Machine learning classification
- **Game Trees**: Game state representation

## Interview Tips

- **Draw Trees**: Visualize tree structure clearly
- **Traversal Knowledge**: Know all four traversal methods
- **Recursive Thinking**: Practice recursive tree problems
- **Edge Cases**: Handle empty trees and single nodes
- **Optimization**: Consider iterative vs recursive approaches

## Problem Variations

### 1. Construction Problems

- **Build from Traversals**: Construct tree from inorder/preorder
- **Build from Parent Array**: Construct from parent relationships
- **Build Expression Tree**: From postfix/prefix expressions

### 2. Property Problems

- **Tree Diameter**: Longest path between any two nodes
- **Tree Width**: Maximum number of nodes at any level
- **Tree Balance**: Check if tree is balanced
- **Tree Symmetry**: Check if tree is mirror symmetric

### 3. Search Problems

- **Find Path**: Find path from root to target node
- **Lowest Common Ancestor**: Find LCA of two nodes
- **Kth Smallest**: Find kth smallest element
- **Range Queries**: Count nodes in range

### 4. Modification Problems

- **Tree Flipping**: Flip tree horizontally/vertically
- **Tree Pruning**: Remove subtrees based on conditions
- **Tree Transformation**: Convert to different tree types
- **Node Deletion**: Delete nodes while maintaining structure

## Performance Considerations

- **Recursion Depth**: Trees can be very deep (skewed)
- **Stack Overflow**: Use iterative traversal for very deep trees
- **Memory Usage**: Each recursive call uses stack space
- **Cache Performance**: Level order traversal is cache-friendly

## Advanced Tree Concepts

- **Threaded Binary Trees**: Reduce space by using null pointers
- **Self-Balancing Trees**: AVL, Red-Black trees
- **B-Trees**: Multi-way search trees for databases
- **Trie Trees**: Prefix trees for string operations
