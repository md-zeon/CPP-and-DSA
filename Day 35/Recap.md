# Day 35: Binary Search Trees Part 4

## Topics Covered

- **Balanced BST Construction**: Converting sorted array to balanced BST
- **BST to Array Conversion**: Converting BST back to sorted array
- **Largest BST in Binary Tree**: Finding maximum BST subtree
- **BST Merging**: Combining two BSTs efficiently
- **BST Information Class**: Tracking BST properties
- **Tree Transformation**: Converting between different tree representations

## Key Concepts

1. **Balanced Tree Construction**: Ensuring optimal height from sorted data
2. **Inorder Traversal**: Foundation for BST to array conversion
3. **BST Validation**: Checking BST properties with additional constraints
4. **Tree Merging**: Combining multiple BSTs while maintaining properties
5. **Size Tracking**: Monitoring subtree sizes for optimization

## Code Examples

### 1. Sorted Array to Balanced BST

```cpp
Node* sortedArrayToBalancedBST(vector<int> &v, int si, int ei) {
    if(si > ei) {
        return NULL;  // Base case
    }

    int mid = (si + ei) / 2;  // Choose middle element as root
    Node* root = new Node(v[mid]);

    // Recursively build left and right subtrees
    root->left = sortedArrayToBalancedBST(v, si, mid - 1);
    root->right = sortedArrayToBalancedBST(v, mid + 1, ei);

    return root;
}

// Time Complexity: O(n)
// Space Complexity: O(log n) for balanced tree
// Result: Perfectly balanced BST with minimum height
```

### 2. BST to Sorted Array

```cpp
void BSTToSortedArray(Node* root, vector<int> &v) {
    if(root == NULL) return;

    BSTToSortedArray(root->left, v);   // Left subtree
    v.push_back(root->data);           // Root
    BSTToSortedArray(root->right, v);  // Right subtree
}

// Time Complexity: O(n)
// Space Complexity: O(n) for array
// Result: Sorted array from BST inorder traversal
```

### 3. Largest BST in Binary Tree

```cpp
class Info {
public:
    bool isBST;
    int min;
    int max;
    int size;

    Info(bool isBST, int min, int max, int size) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

static int maxSize;

Info* largestBst(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL) {
        return new Info(true, root->data, root->data, 1);
    }

    Info* leftInfo = largestBst(root->left);
    Info* rightInfo = largestBst(root->right);

    int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
    int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
    int currSize = leftInfo->size + rightInfo->size + 1;

    if(leftInfo->isBST && rightInfo->isBST &&
       root->data > leftInfo->max && root->data < rightInfo->min) {
        maxSize = max(maxSize, currSize);
        return new Info(true, currMin, currMax, currSize);
    }

    return new Info(false, currMin, currMax, currSize);
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 4. Merge Two BSTs

```cpp
vector<int> mergeBSTs(Node* root1, Node* root2) {
    vector<int> bstSequence;

    // Convert both BSTs to sorted arrays
    BSTToSortedArray(root1, bstSequence);
    BSTToSortedArray(root2, bstSequence);

    // Sort the combined sequence
    sort(bstSequence.begin(), bstSequence.end());

    return bstSequence;
}

// Alternative: Build new balanced BST from merged array
Node* mergeTwoBSTs(Node* root1, Node* root2) {
    vector<int> merged = mergeBSTs(root1, root2);
    return sortedArrayToBalancedBST(merged, 0, merged.size() - 1);
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
```

### 5. Preorder Traversal

```cpp
void preOrder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";  // Visit root
    preOrder(root->left);       // Left subtree
    preOrder(root->right);      // Right subtree
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 6. Inorder Traversal

```cpp
void inOrder(Node* root) {
    if(root == NULL) return;

    inOrder(root->left);        // Left subtree
    cout << root->data << " ";  // Visit root
    inOrder(root->right);       // Right subtree
}

// BST inorder traversal gives sorted sequence
// Time Complexity: O(n)
// Space Complexity: O(h)
```

## BST Transformation Operations

### 1. Array to BST

- **Sorted Array**: Creates perfectly balanced BST
- **Unsorted Array**: Creates skewed BST (inefficient)
- **Optimal**: Use sorted array for balanced tree

### 2. BST to Array

- **Inorder Traversal**: Converts BST to sorted array
- **Level Order**: Converts BST to array by levels
- **Preorder/Postorder**: Maintains tree structure information

### 3. BST Merging

- **Method 1**: Convert to arrays, merge, sort, build new BST
- **Method 2**: Use inorder traversal and merge sorted sequences
- **Method 3**: Insert elements from one tree to another

## Algorithm Analysis

### Construction Algorithms

- **Sorted Array to BST**: O(n) time, O(log n) space
- **BST to Array**: O(n) time, O(n) space
- **Merge BSTs**: O(n + m) time, O(n + m) space

### Validation Algorithms

- **Largest BST**: O(n) time, O(h) space
- **BST Property Check**: O(n) time, O(h) space
- **Balance Check**: O(n) time, O(h) space

## Key Takeaways

- **Balance Importance**: Balanced BSTs ensure optimal performance
- **Inorder Foundation**: Many operations rely on inorder traversal
- **Size Tracking**: Essential for finding largest BST subtrees
- **Transformation**: Converting between different representations
- **Merge Strategy**: Convert to arrays for efficient merging

## Common Mistakes to Avoid

- Incorrect mid calculation in array to BST conversion
- Not handling NULL cases in recursive functions
- Forgetting to update size in BST info calculations
- Stack overflow with deep recursion
- Not understanding the relationship between traversals

## BST Transformation Patterns

### 1. Array ↔ BST

- **Sorted Array → BST**: Always creates balanced tree
- **BST → Sorted Array**: Inorder traversal gives sorted result
- **Round Trip**: Array → BST → Array maintains sorted order

### 2. Multiple BST Operations

- **Merge**: Combine two BSTs into one
- **Split**: Divide BST into two based on value
- **Balance**: Convert unbalanced BST to balanced

### 3. Tree Analysis

- **Largest BST**: Find maximum BST subtree in binary tree
- **BST Validation**: Check if tree satisfies BST properties
- **Size Calculation**: Count nodes in BST subtrees

## Applications

### 1. Data Structure Conversion

- **Database Migration**: Converting between different index types
- **Algorithm Optimization**: Converting to optimal data structure
- **Memory Management**: Efficient storage reorganization
- **Performance Tuning**: Converting to faster data structures

### 2. Tree Analysis

- **Quality Assessment**: Checking tree balance and properties
- **Optimization**: Finding optimal subtrees
- **Validation**: Ensuring data structure integrity
- **Debugging**: Analyzing tree structure issues

### 3. Data Processing

- **Sorting**: Converting to sorted arrays for processing
- **Merging**: Combining multiple sorted datasets
- **Filtering**: Extracting elements within ranges
- **Aggregation**: Computing statistics on tree data

### 4. System Design

- **Index Management**: Database index reorganization
- **Cache Optimization**: Converting to cache-friendly structures
- **Memory Layout**: Optimizing data structure layout
- **Performance Analysis**: Analyzing data structure efficiency

## Interview Tips

- **Construction Logic**: Understand how to build balanced trees
- **Traversal Knowledge**: Know when to use each traversal
- **Edge Cases**: Handle empty trees and single nodes
- **Performance**: Discuss time and space trade-offs
- **Problem Solving**: Think about multiple approaches

## Problem Variations

### 1. Construction Problems

- **Build from Traversals**: Preorder + inorder, postorder + inorder
- **Build from Level Order**: Construct from level order traversal
- **Build from Parent Array**: Construct from parent relationships
- **Cartesian Tree**: BST from array with heap property

### 2. Analysis Problems

- **Tree Diameter**: Longest path between any two nodes
- **Tree Width**: Maximum number of nodes at any level
- **Tree Balance**: Check if tree is balanced
- **Tree Symmetry**: Check if tree is mirror symmetric

### 3. Transformation Problems

- **Flatten BST**: Convert BST to sorted linked list
- **Convert to DLL**: Doubly linked list from BST
- **Tree to Array**: Multiple traversal orders
- **Array to Tree**: Different balancing strategies

### 4. Validation Problems

- **Check BST Property**: Validate BST constraints
- **Check Completeness**: Verify complete binary tree
- **Check Balance**: Verify height balance
- **Check Symmetry**: Check mirror symmetry

## Performance Considerations

- **Balanced Trees**: Ensure O(log n) operations
- **Skewed Trees**: Can cause O(n) performance degradation
- **Memory Usage**: Consider space for transformations
- **Cache Performance**: Balanced trees have better cache locality

## Advanced BST Concepts

- **Self-Balancing Trees**: AVL, Red-Black, Splay trees
- **B-Trees**: Multi-way search trees for databases
- **Trie Trees**: Prefix trees for string operations
- **Interval Trees**: BST for interval overlap queries
- **Order Statistics Trees**: BST with size information

## Real-World Usage

- **STL Map/Set**: Red-Black tree implementation
- **Database Indexes**: B-tree and variants
- **File Systems**: Directory tree structures
- **Compiler Design**: Symbol table management
- **Game Development**: Spatial partitioning

## Optimization Techniques

- **Balanced Construction**: Always build balanced trees when possible
- **Inorder Optimization**: Use inorder for sorted operations
- **Size Augmentation**: Track subtree sizes for efficiency
- **Lazy Evaluation**: Delay expensive operations until needed
