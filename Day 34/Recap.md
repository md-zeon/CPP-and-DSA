# Day 34: Binary Search Trees Part 3

## Topics Covered

- **BST Construction**: Building BST from arrays
- **BST Deletion**: Complete deletion with all cases
- **BST Range Operations**: Print elements in range
- **Root to Leaf Paths**: Finding all paths from root to leaves
- **BST Validation**: Comprehensive BST property checking
- **Inorder Successor**: Finding next element in BST

## Key Concepts

1. **BST Construction**: Efficiently building BST from sorted/unsorted arrays
2. **Deletion Cases**: Handling leaf nodes, single child, and two children
3. **Range Queries**: Finding elements within specified range
4. **Path Finding**: Traversing from root to leaf nodes
5. **Validation**: Ensuring tree maintains BST properties

## Code Examples

### 1. BST Construction from Array

```cpp
Node* insert(Node* root, int val) {
    if(root == NULL) {
        return new Node(val);  // Create new node
    }

    if(val < root->data) {
        root->left = insert(root->left, val);  // Insert in left subtree
    } else {
        root->right = insert(root->right, val);  // Insert in right subtree
    }

    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;

    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);  // Insert each element
    }

    return root;
}

// Time Complexity: O(n log n) average, O(n²) worst case
// Space Complexity: O(h) for recursion stack
```

### 2. BST Deletion (All Cases)

```cpp
Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;  // Find leftmost node
    }
    return root;  // Smallest node in right subtree
}

Node* deleteNode(Node* root, int val) {
    if(root == NULL) return root;

    if(val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if(val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node found - handle deletion cases

        // Case 1: Leaf node (no children)
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Node with one child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;  // Return the child
        }
        if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;  // Return the child
        }

        // Case 3: Node with two children
        Node* successor = getInorderSuccessor(root->right);
        root->data = successor->data;  // Replace with successor
        root->right = deleteNode(root->right, successor->data);  // Delete successor
    }

    return root;
}

// Time Complexity: O(h) where h is height
// Space Complexity: O(h) for recursion stack
```

### 3. Print Elements in Range

```cpp
void printInRange(Node* root, int start, int end) {
    if(root == NULL) return;

    if(root->data >= start && root->data <= end) {
        // Current node in range - visit both subtrees
        printInRange(root->left, start, end);
        cout << root->data << " ";
        printInRange(root->right, start, end);
    } else if(root->data < start) {
        // Go to right subtree only
        printInRange(root->right, start, end);
    } else {
        // Go to left subtree only
        printInRange(root->left, start, end);
    }
}

// Example: printInRange(root, 5, 12) prints all nodes between 5 and 12
// Time Complexity: O(n) in worst case
// Space Complexity: O(h)
```

### 4. Root to Leaf Paths

```cpp
void pathHelper(Node* root, vector<int> &path) {
    if(root == NULL) return;

    path.push_back(root->data);  // Add current node to path

    if(root->left == NULL && root->right == NULL) {
        // Leaf node - print the path
        cout << "Path: ";
        for(int i : path) {
            cout << i << " ";
        }
        cout << endl;
        path.pop_back();  // Remove current node for backtracking
        return;
    }

    // Explore both subtrees
    pathHelper(root->left, path);
    pathHelper(root->right, path);
    path.pop_back();  // Remove current node after exploration
}

void rootToNodePath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

// Time Complexity: O(n) - visits all nodes
// Space Complexity: O(h) for recursion + O(n) for path vector
```

### 5. BST Validation

```cpp
bool validateHelper(Node* root, Node* min, Node* max) {
    if(root == NULL) return true;

    // Check current node constraints
    if(min != NULL && root->data <= min->data) return false;
    if(max != NULL && root->data >= max->data) return false;

    // Recursively validate subtrees
    return validateHelper(root->left, min, root) &&
           validateHelper(root->right, root, max);
}

bool isValidBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

// Time Complexity: O(n)
// Space Complexity: O(h)
```

### 6. Inorder Traversal

```cpp
void inOrder(Node* root) {
    if(root == NULL) return;

    inOrder(root->left);        // Visit left subtree
    cout << root->data << " ";  // Visit root
    inOrder(root->right);       // Visit right subtree
}

// BST Inorder traversal gives sorted order
// Example: [1, 3, 4, 5, 6, 8, 11, 14] -> sorted sequence
```

## BST Operations Analysis

### Construction

- **From Array**: O(n log n) average time for balanced tree
- **From Sorted Array**: O(n) time with optimal balance
- **Space**: O(h) recursion stack

### Deletion Cases

1. **Leaf Node**: Simply delete and return NULL
2. **Single Child**: Replace node with its child
3. **Two Children**: Replace with inorder successor/predecessor

### Range Operations

- **Range Print**: O(k + h) where k is elements in range
- **Range Count**: Similar complexity to range print
- **Range Sum**: Can be optimized with augmented BST

## Key Takeaways

- **Recursive Nature**: All BST operations use recursion
- **Inorder Property**: BST inorder traversal gives sorted sequence
- **Successor/Predecessor**: Essential for deletion and range operations
- **Validation**: Must check BST property throughout tree
- **Path Finding**: Backtracking approach for root-to-leaf paths

## Common Mistakes to Avoid

- Forgetting to handle NULL cases in recursive functions
- Incorrect successor selection in deletion
- Not updating parent pointers (though not needed in pure recursion)
- Stack overflow with very deep trees
- Not understanding the three deletion cases

## BST vs Other Trees

### BST vs Binary Tree

- **BST**: Maintains ordering property for efficient operations
- **Binary Tree**: No ordering, more flexible structure
- **Search**: BST has O(log n) search, binary tree has O(n)

### BST vs Sorted Array

- **BST**: Dynamic insertions/deletions, O(log n) operations
- **Array**: Static size, O(1) access, O(n) search
- **Use Case**: BST for dynamic data, array for static sorted data

### BST vs Hash Table

- **BST**: Ordered operations, range queries
- **Hash Table**: O(1) average search, no ordering
- **Use Case**: BST for ordered data, hash table for fast lookup

## Applications

### 1. Database Operations

- **Range Queries**: Find records between values
- **Order Statistics**: Find median, percentiles
- **Indexing**: Fast search in large datasets
- **Sorting**: Convert to sorted array via inorder

### 2. Search Applications

- **Auto-complete**: Dictionary with ordered suggestions
- **Spell Check**: Find closest matching words
- **Ranking Systems**: Maintain ordered rankings
- **Priority Queues**: BST-based priority operations

### 3. Data Analysis

- **Statistical Operations**: Find kth smallest/largest
- **Data Filtering**: Range-based data selection
- **Aggregation**: Range-based calculations
- **Sorting**: Convert to sorted sequences

### 4. System Design

- **Task Scheduling**: Priority-based task management
- **Resource Allocation**: Ordered resource distribution
- **Cache Management**: Ordered cache eviction
- **Event Processing**: Time-ordered event handling

## Interview Tips

- **Draw Trees**: Visualize BST structure clearly
- **Explain Operations**: Describe insertion/deletion steps
- **Handle Edge Cases**: Empty tree, single node, two nodes
- **Time Complexity**: Analyze based on tree height
- **Alternative Approaches**: Compare with other data structures

## Problem Variations

### 1. Search Problems

- **Search in Range**: Find all elements in [low, high]
- **Closest Element**: Find element closest to target
- **Kth Smallest/Largest**: Find element by rank
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

- **Tree Balance**: Critical for maintaining O(log n) performance
- **Skewed Trees**: Can degenerate to O(n) operations
- **Self-Balancing**: AVL, Red-Black trees maintain balance
- **Memory Usage**: Each node uses two pointers

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
