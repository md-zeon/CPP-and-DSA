# Day 33: Binary Search Trees Part 2

## Topics Covered

- **BST Advanced Operations**: Floor, ceiling, kth smallest element
- **BST Range Queries**: Count elements in range, range sum
- **BST Modification**: Delete range, insert from array
- **BST Validation**: Check if tree is valid BST with constraints
- **BST Construction**: Build from inorder and preorder traversals
- **BST Utilities**: Convert BST to sorted array, merge BSTs

## Key Concepts

1. **Order Statistics**: Finding kth smallest/largest elements
2. **Range Operations**: Efficient queries on BST ranges
3. **Tree Reconstruction**: Building BST from traversal sequences
4. **BST Merging**: Combining multiple BSTs efficiently
5. **Inorder Successor/Predecessor**: Finding adjacent elements

## Code Examples

### 1. Floor and Ceiling in BST

```cpp
Node* floor(Node* root, int key) {
    Node* floor = NULL;

    while(root != NULL) {
        if(root->data == key) {
            return root;  // Exact match
        } else if(root->data < key) {
            floor = root;  // Potential floor
            root = root->right;  // Look for larger values
        } else {
            root = root->left;  // Look for smaller values
        }
    }

    return floor;  // Largest value smaller than key
}

Node* ceiling(Node* root, int key) {
    Node* ceiling = NULL;

    while(root != NULL) {
        if(root->data == key) {
            return root;  // Exact match
        } else if(root->data > key) {
            ceiling = root;  // Potential ceiling
            root = root->left;  // Look for smaller values
        } else {
            root = root->right;  // Look for larger values
        }
    }

    return ceiling;  // Smallest value larger than key
}

// Time Complexity: O(h)
// Space Complexity: O(1)
```

### 2. Kth Smallest Element in BST

```cpp
void kthSmallestUtil(Node* root, int k, int& count, int& result) {
    if(root == NULL || count >= k) return;

    // Inorder traversal: left, root, right
    kthSmallestUtil(root->left, k, count, result);

    count++;
    if(count == k) {
        result = root->data;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(Node* root, int k) {
    int count = 0;
    int result = -1;
    kthSmallestUtil(root, k, count, result);
    return result;
}

// Time Complexity: O(h + k) average, O(n) worst case
// Space Complexity: O(h)
```

### 3. Count Elements in Range

```cpp
int countInRange(Node* root, int low, int high) {
    if(root == NULL) return 0;

    if(root->data >= low && root->data <= high) {
        // Current node in range
        return 1 + countInRange(root->left, low, high) +
                   countInRange(root->right, low, high);
    } else if(root->data < low) {
        // Go to right subtree
        return countInRange(root->right, low, high);
    } else {
        // Go to left subtree
        return countInRange(root->left, low, high);
    }
}

// Time Complexity: O(h + k) where k is elements in range
// Space Complexity: O(h)
```

### 4. Build BST from Inorder and Preorder

```cpp
Node* buildTree(vector<int> inorder, vector<int> preorder, int inStart, int inEnd, int& preIndex) {
    if(inStart > inEnd) return NULL;

    // Create root from preorder
    Node* root = new Node(preorder[preIndex]);
    preIndex++;

    // Find root in inorder
    int inIndex = inStart;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // Build left and right subtrees
    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

Node* buildTree(vector<int> inorder, vector<int> preorder) {
    int preIndex = 0;
    return buildTree(inorder, preorder, 0, inorder.size() - 1, preIndex);
}

// Time Complexity: O(n)
// Space Complexity: O(n)
```

### 5. Build BST from Inorder and Postorder

```cpp
Node* buildTree(vector<int> inorder, vector<int> postorder, int inStart, int inEnd, int& postIndex) {
    if(inStart > inEnd) return NULL;

    // Create root from postorder (last element)
    Node* root = new Node(postorder[postIndex]);
    postIndex--;

    // Find root in inorder
    int inIndex = inStart;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // Build right and left subtrees (reverse order for postorder)
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

Node* buildTree(vector<int> inorder, vector<int> postorder) {
    int postIndex = postorder.size() - 1;
    return buildTree(inorder, postorder, 0, inorder.size() - 1, postIndex);
}

// Time Complexity: O(n)
// Space Complexity: O(n)
```

### 6. BST to Sorted Array

```cpp
void inorderToArray(Node* root, vector<int>& arr) {
    if(root == NULL) return;

    inorderToArray(root->left, arr);
    arr.push_back(root->data);
    inorderToArray(root->right, arr);
}

vector<int> BSTtoArray(Node* root) {
    vector<int> arr;
    inorderToArray(root, arr);
    return arr;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
```

### 7. Merge Two BSTs

```cpp
vector<int> mergeBSTs(Node* root1, Node* root2) {
    vector<int> arr1, arr2;

    // Convert both BSTs to sorted arrays
    inorderToArray(root1, arr1);
    inorderToArray(root2, arr2);

    // Merge two sorted arrays
    vector<int> result;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            result.push_back(arr1[i++]);
        } else {
            result.push_back(arr2[j++]);
        }
    }

    // Add remaining elements
    while(i < arr1.size()) result.push_back(arr1[i++]);
    while(j < arr2.size()) result.push_back(arr2[j++]);

    return result;
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
```

### 8. Lowest Common Ancestor (LCA)

```cpp
Node* LCA(Node* root, Node* p, Node* q) {
    if(root == NULL) return NULL;

    if(root->data > p->data && root->data > q->data) {
        return LCA(root->left, p, q);  // Both in left subtree
    } else if(root->data < p->data && root->data < q->data) {
        return LCA(root->right, p, q);  // Both in right subtree
    } else {
        return root;  // Current node is LCA
    }
}

// Time Complexity: O(h)
// Space Complexity: O(h)
```

### 9. BST Iterator

```cpp
class BSTIterator {
private:
    stack<Node*> s;

    void pushLeft(Node* node) {
        while(node != NULL) {
            s.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(Node* root) {
        pushLeft(root);
    }

    int next() {
        Node* top = s.top();
        s.pop();

        if(top->right != NULL) {
            pushLeft(top->right);
        }

        return top->data;
    }

    bool hasNext() {
        return !s.empty();
    }
};

// Time Complexity: O(1) amortized for next()
// Space Complexity: O(h)
```

### 10. Check if BST is Complete

```cpp
bool isCompleteBST(Node* root) {
    if(root == NULL) return true;

    queue<Node*> q;
    q.push(root);

    bool foundNull = false;

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            foundNull = true;
        } else {
            if(foundNull) return false;  // Non-null after null

            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return true;
}

// Time Complexity: O(n)
// Space Complexity: O(w) where w is maximum width
```

## BST Advanced Operations

### Order Statistics

- **Kth Smallest**: Inorder traversal with counter
- **Kth Largest**: Reverse inorder or use node counts
- **Rank**: Position of element in sorted order
- **Select**: Find element by rank

### Range Operations

- **Range Count**: Count elements in [low, high]
- **Range Sum**: Sum of elements in [low, high]
- **Range Update**: Update elements in range
- **Range Delete**: Delete elements in range

### Construction Methods

- **From Sorted Array**: Balanced BST construction
- **From Traversals**: Preorder + inorder, postorder + inorder
- **From Parent Array**: Build from parent relationships
- **From Level Order**: Build from level order traversal

## Key Takeaways

- **Inorder Traversal**: Foundation for many BST operations
- **Recursive Construction**: Building trees from traversal sequences
- **Iterator Pattern**: Efficient traversal without recursion
- **Range Queries**: Efficient queries using BST properties
- **Order Statistics**: Finding elements by their position

## Common Mistakes to Avoid

- Incorrect traversal order in construction algorithms
- Not handling edge cases in range queries
- Forgetting to update indices in traversal-based construction
- Stack overflow with deep recursion (use iterative when possible)
- Not understanding the relationship between traversals

## BST vs Other Tree Types

### BST vs AVL Tree

- **BST**: No balance guarantee
- **AVL**: Self-balancing with height difference ≤ 1
- **Performance**: AVL has guaranteed O(log n) operations

### BST vs Red-Black Tree

- **BST**: Simple but can be unbalanced
- **Red-Black**: Self-balancing with color constraints
- **Usage**: Red-Black used in STL map/set

### BST vs Heap

- **BST**: Ordered traversal, search operations
- **Heap**: Priority operations, no ordering
- **Application**: BST for search, heap for priority

## Applications

### 1. Database Systems

- **Range Queries**: Find records in value range
- **Order Statistics**: Find median, percentiles
- **Indexing**: Fast search in large datasets
- **Sorting**: Inorder traversal gives sorted order

### 2. Search Applications

- **Autocomplete**: Dictionary with prefix search
- **Spell Check**: Finding closest words
- **Auto-suggest**: Finding related terms
- **Ranking Systems**: Order-based ranking

### 3. Data Analysis

- **Statistical Operations**: Median, quartiles, percentiles
- **Data Filtering**: Range-based filtering
- **Sorting**: Converting to sorted arrays
- **Aggregation**: Range-based aggregations

### 4. System Design

- **Priority Scheduling**: Task scheduling by priority
- **Resource Management**: Resource allocation by priority
- **Cache Management**: LRU cache with BST
- **Event Processing**: Time-based event management

## Interview Tips

- **Traversal Knowledge**: Understand all traversal methods
- **Construction Logic**: Practice building trees from traversals
- **Edge Cases**: Handle empty trees and single nodes
- **Performance**: Discuss balanced vs unbalanced trees
- **Implementation**: Know both recursive and iterative approaches

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

- **Tree Balance**: Critical for performance
- **Skewed Trees**: Can cause O(n) operations
- **Self-Balancing**: Use AVL or Red-Black for guarantees
- **Memory Usage**: Each node has two pointers

## Advanced BST Concepts

- **Self-Balancing Trees**: AVL, Red-Black, Splay trees
- **B-Trees**: Multi-way search trees for databases
- **Trie Trees**: Prefix trees for string operations
- **Interval Trees**: BST for interval overlap queries
- **Order Statistics Trees**: BST with size information
