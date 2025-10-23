# Day 32: Binary Search Trees Part 1

## Topics Covered

- **BST Structure**: Binary tree with ordering property
- **BST Operations**: Insert, delete, search operations
- **BST Traversal**: Inorder traversal for sorted order
- **BST Validation**: Checking if tree is valid BST
- **BST Construction**: Building BST from sorted array
- **BST Properties**: Height, balance, completeness

## Key Concepts

1. **BST Property**: Left subtree < root < right subtree
2. **Recursive Operations**: All BST operations are naturally recursive
3. **Inorder Successor/Predecessor**: Finding next/previous elements
4. **Tree Balancing**: Ensuring optimal height for performance
5. **Search Efficiency**: O(log n) average case, O(n) worst case

## Code Examples

### 1. BST Node Structure

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

### 2. BST Insertion

```cpp
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);  // Create new node
    }

    if(val < root->data) {
        root->left = insert(root->left, val);  // Insert in left subtree
    } else if(val > root->data) {
        root->right = insert(root->right, val);  // Insert in right subtree
    }
    // If val == root->data, ignore (no duplicates)

    return root;
}

// Time Complexity: O(h) where h is height
// Space Complexity: O(h) for recursion stack
```

### 3. BST Search

```cpp
Node* search(Node* root, int key) {
    if(root == NULL || root->data == key) {
        return root;  // Found or not found
    }

    if(key < root->data) {
        return search(root->left, key);  // Search in left subtree
    } else {
        return search(root->right, key);  // Search in right subtree
    }
}

// Iterative version
Node* searchIterative(Node* root, int key) {
    while(root != NULL) {
        if(root->data == key) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// Time Complexity: O(h)
// Space Complexity: O(h) recursive, O(1) iterative
```

### 4. BST Deletion

```cpp
Node* deleteNode(Node* root, int key) {
    if(root == NULL) return root;

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found - handle deletion cases

        // Case 1: Leaf node
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Node with one child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children
        // Find inorder successor (smallest in right subtree)
        Node* temp = root->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;  // Replace with successor
        root->right = deleteNode(root->right, temp->data);  // Delete successor
    }

    return root;
}

// Time Complexity: O(h)
// Space Complexity: O(h)
```

### 5. BST Validation

```cpp
bool isValidBST(Node* root, long long minVal, long long maxVal) {
    if(root == NULL) return true;

    if(root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    return isValidBST(root->left, minVal, root->data) &&
           isValidBST(root->right, root->data, maxVal);
}

bool isValidBST(Node* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 6. Inorder Successor

```cpp
Node* inorderSuccessor(Node* root, Node* target) {
    Node* successor = NULL;

    while(root != NULL) {
        if(target->data < root->data) {
            successor = root;  // Potential successor
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return successor;
}

// Time Complexity: O(h)
// Space Complexity: O(1)
```

### 7. Inorder Predecessor

```cpp
Node* inorderPredecessor(Node* root, Node* target) {
    Node* predecessor = NULL;

    while(root != NULL) {
        if(target->data > root->data) {
            predecessor = root;  // Potential predecessor
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return predecessor;
}

// Time Complexity: O(h)
// Space Complexity: O(1)
```

### 8. Build BST from Sorted Array

```cpp
Node* buildBST(vector<int> arr, int start, int end) {
    if(start > end) return NULL;

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBST(arr, start, mid - 1);
    root->right = buildBST(arr, mid + 1, end);

    return root;
}

Node* sortedArrayToBST(vector<int> arr) {
    return buildBST(arr, 0, arr.size() - 1);
}

// Time Complexity: O(n)
// Space Complexity: O(log n) for balanced tree
```

### 9. Find Minimum and Maximum

```cpp
Node* findMin(Node* root) {
    if(root == NULL) return NULL;

    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
    if(root == NULL) return NULL;

    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Time Complexity: O(h)
// Space Complexity: O(1)
```

### 10. Check if BST is Balanced

```cpp
int height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight == -1 || rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node* root) {
    return height(root) != -1;
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

## BST Operations Complexity

| Operation         | Time Complexity | Space Complexity               | Notes                        |
| ----------------- | --------------- | ------------------------------ | ---------------------------- |
| Search            | O(h)            | O(h) recursive, O(1) iterative | h is height                  |
| Insert            | O(h)            | O(h)                           | Same as search               |
| Delete            | O(h)            | O(h)                           | More complex than insert     |
| Find Min/Max      | O(h)            | O(1)                           | Go to leftmost/rightmost     |
| Inorder Traversal | O(n)            | O(h)                           | Visits nodes in sorted order |
| Validation        | O(n)            | O(h)                           | Check BST property           |

## BST vs Binary Tree

### Binary Search Tree

- **Ordering Property**: Left < root < right
- **Search**: Efficient search operations
- **Traversal**: Inorder gives sorted sequence
- **Applications**: Database indexing, priority operations

### Binary Tree

- **No Ordering**: Any arrangement of nodes
- **Search**: Linear search required
- **Traversal**: No specific order guarantee
- **Applications**: Expression trees, file systems

## Key Takeaways

- **BST Property**: Essential for maintaining search efficiency
- **Recursive Implementation**: Natural for tree operations
- **Height Impact**: Performance depends on tree balance
- **Inorder Traversal**: Always gives sorted order in BST
- **Successor/Predecessor**: Useful for range queries

## Common Mistakes to Avoid

- Forgetting BST property in insertion/deletion
- Not handling edge cases (empty tree, single node)
- Incorrect successor/predecessor logic
- Not updating parent pointers in deletion
- Stack overflow with skewed trees (use iterative when possible)

## BST Applications

### 1. Database Systems

- **Indexing**: Fast search in large datasets
- **Range Queries**: Finding elements in range
- **Sorting**: Inorder traversal gives sorted order
- **Duplicate Handling**: Modified BST for duplicates

### 2. Priority Operations

- **Order Statistics**: Find kth smallest element
- **Dynamic Sets**: Insert/delete with fast search
- **Dictionary**: Key-value mapping with ordering
- **Multiset**: BST with duplicate handling

### 3. Algorithm Implementation

- **Sorting**: Tree sort algorithm
- **Priority Queue**: BST-based priority queue
- **Interval Trees**: For interval overlap queries
- **Segment Trees**: For range update/query operations

### 4. Real-time Systems

- **Online Algorithms**: Dynamic data with fast operations
- **Cache Management**: LRU cache with BST
- **Event Scheduling**: Time-based event management
- **Resource Allocation**: Priority-based allocation

## Interview Tips

- **Draw Trees**: Visualize BST structure and operations
- **Understand Property**: Explain BST invariant clearly
- **Edge Cases**: Handle empty trees and boundary conditions
- **Performance**: Discuss balanced vs unbalanced trees
- **Implementation**: Know both recursive and iterative approaches

## Problem Variations

### 1. Search Problems

- **Search in Range**: Find all elements in [low, high]
- **Kth Smallest**: Find kth smallest element
- **Floor/Ceiling**: Find closest smaller/larger elements
- **Count in Range**: Count elements in given range

### 2. Construction Problems

- **Build from Preorder**: Construct BST from preorder traversal
- **Build from Postorder**: Construct BST from postorder traversal
- **Build from Level Order**: Construct from level order traversal
- **Cartesian Tree**: BST from array with heap property

### 3. Modification Problems

- **Delete Range**: Delete all elements in range
- **Insert Multiple**: Insert array elements efficiently
- **Tree Rotation**: Rotate nodes to balance tree
- **Mirror Tree**: Create mirror image of BST

### 4. Validation Problems

- **Check BST Property**: Validate BST constraints
- **Check Completeness**: Verify complete binary tree
- **Check Balance**: Verify height balance
- **Check Symmetry**: Check mirror symmetry

## Performance Considerations

- **Tree Balance**: Balanced BST has O(log n) height
- **Skewed Trees**: Can degenerate to O(n) height
- **Self-Balancing**: AVL, Red-Black trees maintain balance
- **Cache Performance**: Better with balanced trees

## Advanced BST Concepts

- **Self-Balancing Trees**: AVL, Red-Black, Splay trees
- **B-Trees**: Multi-way search trees for databases
- **Trie Trees**: Prefix trees for string operations
- **Interval Trees**: BST for interval overlap queries
- **Order Statistics Trees**: BST with size information
