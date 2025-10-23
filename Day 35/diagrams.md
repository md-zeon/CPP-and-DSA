# Day 35: Binary Search Trees Part 4 - Diagrams

## 1. Sorted Array to Balanced BST Flowchart

This shows constructing a balanced BST from a sorted array.

```mermaid
graph TD
    A[sortedArrayToBalancedBST] --> B{si > ei?}
    B -->|Yes| C[Return NULL]
    B -->|No| D[mid = (si + ei)/2]
    D --> E[root = new Node(v[mid])]
    E --> F[root->left = sortedArrayToBalancedBST(si, mid-1)]
    F --> G[root->right = sortedArrayToBalancedBST(mid+1, ei)]
    G --> H[Return root]
```

## 2. BST to Sorted Array Flowchart

This illustrates converting BST to a sorted array.

```mermaid
graph TD
    A[BSTToSortedArray] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D[BSTToSortedArray(root->left)]
    D --> E[v.push_back(root->data)]
    E --> F[BSTToSortedArray(root->right)]
```

## 3. Largest BST in Binary Tree Flowchart

This depicts finding the largest BST subtree.

```mermaid
graph TD
    A[largestBst] --> B{root == NULL?}
    B -->|Yes| C[Return NULL]
    B -->|No| D[Get leftInfo and rightInfo]
    D --> E[Calculate currMin, currMax, currSize]
    E --> F{leftInfo.isBST and rightInfo.isBST and root->data > leftInfo.max and root->data < rightInfo.min?}
    F -->|Yes| G[maxSize = max(maxSize, currSize), return new Info(true, currMin, currMax, currSize)]
    F -->|No| H[Return new Info(false, currMin, currMax, currSize)]
```

## 4. Merge Two BSTs Flowchart

This shows merging two BSTs.

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

## 5. Build BST from Inorder and Preorder Flowchart

This illustrates constructing BST from traversals.

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

## 6. Preorder Traversal Flowchart

This shows preorder traversal of BST.

```mermaid
graph TD
    A[preOrder] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D[Print root->data]
    D --> E[preOrder(root->left)]
    E --> F[preOrder(root->right)]
```

## 7. Inorder Traversal Flowchart

This shows inorder traversal of BST.

```mermaid
graph TD
    A[inOrder] --> B{root == NULL?}
    B -->|Yes| C[Return]
    B -->|No| D[inOrder(root->left)]
    D --> E[Print root->data]
    E --> F[inOrder(root->right)]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize BST transformations and operations.
- For construction, the recursive division is key.
- For merging, inorder traversal and merging are essential.
- For largest BST, tracking properties is crucial.
- Use these to understand advanced BST techniques.
