# Day 34: Binary Search Trees Part 3 - Diagrams

## 1. Build BST from Array Flowchart

This shows constructing BST from an array.

```mermaid
graph TD
    A[buildBST] --> B[Initialize root = NULL]
    B --> C[Loop through array]
    C --> D[root = insert(root, arr[i])]
    D --> E[Continue for next element]
    E --> F[Return root]
```

## 2. BST Deletion Flowchart

This illustrates deleting a node in BST.

```mermaid
graph TD
    A[deleteNode] --> B{root == NULL?}
    B -->|Yes| C[Return root]
    B -->|No| D{val < root->data?}
    D -->|Yes| E[root->left = deleteNode(root->left, val)]
    D -->|No| F{val > root->data?}
    F -->|Yes| G[root->right = deleteNode(root->right, val)]
    F -->|No| H[Handle cases]
    H --> I{Leaf node?}
    I -->|Yes| J[Delete, return NULL]
    I -->|No| K{One child?}
    K -->|Yes| L[Return child]
    K -->|No| M[Find successor, replace, delete successor]
    E --> N[Return root]
    G --> N
    J --> N
    L --> N
    M --> N
```

## 3. Print in Range Flowchart

This depicts printing elements in a range.

```mermaid
graph TD
    A[printInRange] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D{root->data in [start, end]?}
    D -->|Yes| E[printInRange(left), print root, printInRange(right)]
    D -->|No| F{root->data < start?}
    F -->|Yes| G[printInRange(right)]
    F -->|No| H[printInRange(left)]
```

## 4. Root to Leaf Paths Flowchart

This shows finding all root to leaf paths.

```mermaid
graph TD
    A[pathHelper] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D[path.push_back(root->data)]
    D --> E{Leaf node?}
    E -->|Yes| F[Print path, path.pop_back()]
    E -->|No| G[pathHelper(left), pathHelper(right)]
    G --> H[path.pop_back()]
```

## 5. BST Validation Flowchart

This illustrates validating BST.

```mermaid
graph TD
    A[validateHelper] --> B{root == NULL?}
    B -->|Yes| C[Return true]
    B -->|No| D{root->data <= min or root->data >= max?}
    D -->|Yes| E[Return false]
    D -->|No| F[Return validateHelper(left, min, root) and validateHelper(right, root, max)]
```

## 6. Inorder Traversal Flowchart

This shows inorder traversal of BST.

```mermaid
graph TD
    A[inOrder] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D[inOrder(root->left)]
    D --> E[Print root->data]
    E --> F[inOrder(root->right)]
```

## 7. BST Construction from Array

This depicts the process of building BST.

```mermaid
graph TD
    A[insert] --> B{root == NULL?}
    B -->|Yes| C[Return new Node(val)]
    B -->|No| D{val < root->data?}
    D -->|Yes| E[root->left = insert(left, val)]
    D -->|No| F[root->right = insert(right, val)]
    E --> G[Return root]
    F --> G
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize BST construction and operations.
- For deletion, note the handling of different cases.
- For range and paths, recursive traversal is key.
- For validation, min/max bounds ensure BST property.
- Use these to understand BST manipulation techniques.
