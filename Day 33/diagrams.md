# Day 33: Binary Search Trees Part 2 - Diagrams

## 1. Floor and Ceiling Flowchart

This shows finding floor and ceiling in BST.

```mermaid
graph TD
    A[floor(root, key)] --> B[Initialize floor = NULL]
    B --> C{root != NULL?}
    C -->|Yes| D{root->data == key?}
    D -->|Yes| E[Return root]
    D -->|No| F{root->data < key?}
    F -->|Yes| G[floor = root, root = root->right]
    F -->|No| H[root = root->left]
    G --> I[Continue loop]
    H --> I
    C -->|No| J[Return floor]
```

## 2. Kth Smallest Element Flowchart

This illustrates finding the kth smallest element.

```mermaid
graph TD
    A[kthSmallestUtil] --> B{root == NULL or count >= k?}
    B -->|Yes| C[Return]
    B -->|No| D[kthSmallestUtil(root->left)]
    D --> E[count++]
    E --> F{count == k?}
    F -->|Yes| G[result = root->data]
    F -->|No| H[kthSmallestUtil(root->right)]
```

## 3. Count in Range Flowchart

This depicts counting elements in a range.

```mermaid
graph TD
    A[countInRange] --> B{root == NULL?}
    B -->|Yes| C[Return 0]
    B -->|No| D{root->data in [low, high]?}
    D -->|Yes| E[Return 1 + countInRange(left) + countInRange(right)]
    D -->|No| F{root->data < low?}
    F -->|Yes| G[Return countInRange(right)]
    F -->|No| H[Return countInRange(left)]
```

## 4. Build BST from Inorder and Preorder Flowchart

This shows constructing BST from traversals.

```mermaid
graph TD
    A[buildTree] --> B{inStart > inEnd?}
    B -->|Yes| C[Return NULL]
    B -->|No| D[root = new Node(preorder[preIndex])]
    D --> E[preIndex++]
    E --> F[Find inIndex in inorder]
    F --> G[root->left = buildTree(inStart, inIndex-1)]
    G --> H[root->right = buildTree(inIndex+1, inEnd)]
    H --> I[Return root]
```

## 5. BST to Sorted Array Flowchart

This illustrates converting BST to array.

```mermaid
graph TD
    A[inorderToArray] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D[inorderToArray(root->left)]
    D --> E[arr.push_back(root->data)]
    E --> F[inorderToArray(root->right)]
```

## 6. Merge Two BSTs Flowchart

This depicts merging two BSTs.

```mermaid
graph TD
    A[mergeBSTs] --> B[Convert root1 to arr1 via inorder]
    B --> C[Convert root2 to arr2 via inorder]
    C --> D[Merge arr1 and arr2]
    D --> E[While i < arr1.size() and j < arr2.size()]
    E --> F{arr1[i] < arr2[j]?}
    F -->|Yes| G[result.push_back(arr1[i++])]
    F -->|No| H[result.push_back(arr2[j++])]
    G --> I[Add remaining from arr1 and arr2]
    H --> I
```

## 7. Lowest Common Ancestor Flowchart

This shows finding LCA in BST.

```mermaid
graph TD
    A[LCA] --> B{root == NULL?}
    B -->|Yes| C[Return NULL]
    B -->|No| D{root->data > p->data and root->data > q->data?}
    D -->|Yes| E[Return LCA(root->left)]
    D -->|No| F{root->data < p->data and root->data < q->data?}
    F -->|Yes| G[Return LCA(root->right)]
    F -->|No| H[Return root]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize advanced BST operations.
- For floor/ceiling and kth smallest, traversal is key.
- For range operations, recursive counting is used.
- For construction, identify root and build subtrees.
- Use these to understand complex BST algorithms.
