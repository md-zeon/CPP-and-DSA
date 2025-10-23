# Day 31: Binary Trees Visual Diagrams

## 1. Binary Tree Structure

```mermaid
graph TD
    A[Root: 1] --> B[Left Child: 2]
    A --> C[Right Child: 3]
    B --> D[4]
    B --> E[5]
    C --> F[6]
    C --> G[NULL]

    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
    style E fill:#fce4ec
    style F fill:#ffebee
```

### Tree Representation

```
       1
      / \
     2   3
    / \   \
   4   5   6
```

## 2. Tree Traversal Orders

### 2.1 Preorder Traversal (Root → Left → Right)

```mermaid
graph TD
    A[1] --> B[2]
    B --> C[4]
    C --> D[5]
    D --> E[3]
    E --> F[6]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
```

**Order:** 1 → 2 → 4 → 5 → 3 → 6

### 2.2 Inorder Traversal (Left → Root → Right)

```mermaid
graph TD
    A[4] --> B[2]
    B --> C[5]
    C --> D[1]
    D --> E[3]
    E --> F[6]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
```

**Order:** 4 → 2 → 5 → 1 → 3 → 6

### 2.3 Postorder Traversal (Left → Right → Root)

```mermaid
graph TD
    A[4] --> B[5]
    B --> C[2]
    C --> D[6]
    D --> E[3]
    E --> F[1]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
```

**Order:** 4 → 5 → 2 → 6 → 3 → 1

### 2.4 Level Order Traversal (BFS)

```mermaid
graph TD
    A[Level 0: 1] --> B[Level 1: 2]
    A --> C[Level 1: 3]
    B --> D[Level 2: 4]
    B --> E[Level 2: 5]
    C --> F[Level 2: 6]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
```

**Order:** 1 → 2 → 3 → 4 → 5 → 6

## 3. Binary Tree Types

### 3.1 Complete Binary Tree

```mermaid
graph TD
    A[1] --> B[2]
    A --> C[3]
    B --> D[4]
    B --> E[5]
    C --> F[6]
    C --> G[7]

    style A fill:#e8f5e8
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#e8f5e8
    style G fill:#e8f5e8
```

**Properties:** All levels filled except possibly the last, filled from left to right

### 3.2 Full Binary Tree

```mermaid
graph TD
    A[1] --> B[2]
    A --> C[3]
    B --> D[4]
    B --> E[5]
    C --> F[6]
    C --> G[7]

    style A fill:#fff3e0
    style B fill:#fff3e0
    style C fill:#fff3e0
    style D fill:#fff3e0
    style E fill:#fff3e0
    style F fill:#fff3e0
    style G fill:#fff3e0
```

**Properties:** Every node has either 0 or 2 children

### 3.3 Perfect Binary Tree

```mermaid
graph TD
    A[1] --> B[2]
    A --> C[3]
    B --> D[4]
    B --> E[5]
    C --> F[6]
    C --> G[7]
    D --> H[8]
    E --> I[9]
    F --> J[10]
    G --> K[11]

    style A fill:#fce4ec
    style B fill:#fce4ec
    style C fill:#fce4ec
    style D fill:#fce4ec
    style E fill:#fce4ec
    style F fill:#fce4ec
    style G fill:#fce4ec
    style H fill:#fce4ec
    style I fill:#fce4ec
    style J fill:#fce4ec
    style K fill:#fce4ec
```

**Properties:** All levels completely filled

## 4. Tree Views

### 4.1 Left View

```mermaid
graph TD
    A[1] --> B[2]
    A --> C[3]
    B --> D[4]
    B --> E[5]
    C --> F[6]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style D fill:#e3f2fd
```

**Left View Nodes:** 1, 2, 4

### 4.2 Right View

```mermaid
graph TD
    A[1] --> B[2]
    A --> C[3]
    B --> D[4]
    B --> E[5]
    C --> F[6]

    style A fill:#e3f2fd
    style C fill:#e3f2fd
    style F fill:#e3f2fd
```

**Right View Nodes:** 1, 3, 6

### 4.3 Top View

```mermaid
graph TD
    A[4] --> B[2]
    B --> C[1]
    C --> D[3]
    D --> E[6]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
```

**Top View Nodes:** 4, 2, 1, 3, 6

## 5. Binary Search Tree (BST)

### 5.1 BST Structure

```mermaid
graph TD
    A[8] --> B[3]
    A --> C[10]
    B --> D[1]
    B --> E[6]
    E --> F[4]
    E --> G[7]
    C --> H[14]
    H --> I[13]

    style A fill:#e8f5e8
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#e8f5e8
    style G fill:#e8f5e8
    style H fill:#e8f5e8
    style I fill:#e8f5e8
```

**BST Property:** Left child < Parent < Right child

### 5.2 BST Insertion

```mermaid
graph TD
    A[8] --> B[3]
    A --> C[10]
    B --> D[1]
    B --> E[6]
    E --> F[4]
    E --> G[7]
    C --> H[14]
    H --> I[13]

    style A fill:#c8e6c9
```

**Insert 9:** Goes to right of 8, left of 10

## 6. Tree Problems Visualization

### 6.1 Tree Diameter (Longest Path)

```mermaid
graph TD
    A[4] --> B[2]
    B --> C[1]
    C --> D[3]
    D --> E[6]

    style A fill:#ffcdd2
    style B fill:#ffcdd2
    style D fill:#ffcdd2
    style E fill:#ffcdd2
```

**Diameter Path:** 4 → 2 → 1 → 3 → 6 (Length: 4)

### 6.2 Lowest Common Ancestor

```mermaid
graph TD
    A[1] --> B[2]
    A --> C[3]
    B --> D[4]
    B --> E[5]
    C --> F[6]

    style B fill:#ffebee
    style C fill:#ffebee
```

**LCA of 4 and 6:** Node 1
**LCA of 4 and 5:** Node 2

## 7. Tree Construction from Array

### Array: [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]

```mermaid
graph TD
    A[Index 0: 1] --> B[Index 1: 2]
    A --> C[Index 8: 3]
    B --> D[Index 2: 4]
    B --> E[Index 5: 5]
    D --> F[Index 3: -1]
    D --> G[Index 4: -1]
    E --> H[Index 6: -1]
    E --> I[Index 7: -1]
    C --> J[Index 9: -1]
    C --> K[Index 10: 6]
    K --> L[Index 11: -1]
    K --> M[Index 12: -1]

    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
    style E fill:#fce4ec
    style K fill:#ffebee
```

## 8. Tree Height Calculation

### Height Calculation Process

```mermaid
graph TD
    A[Node 1<br/>Height: 3] --> B[Node 2<br/>Height: 2]
    A --> C[Node 3<br/>Height: 2]
    B --> D[Node 4<br/>Height: 1]
    B --> E[Node 5<br/>Height: 1]
    C --> F[Node 6<br/>Height: 1]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
```

**Height Calculation:**

- Leaf nodes (4, 5, 6): Height = 1
- Node 2: max(1, 1) + 1 = 2
- Node 3: max(1, 0) + 1 = 2
- Node 1: max(2, 2) + 1 = 3

## 9. Binary Tree vs Other Structures

| Feature      | Binary Tree | BST      | Heap     |
| ------------ | ----------- | -------- | -------- |
| **Ordering** | No          | Yes      | Partial  |
| **Search**   | O(n)        | O(log n) | O(n)     |
| **Insert**   | O(n)        | O(log n) | O(log n) |
| **Delete**   | O(n)        | O(log n) | O(log n) |
| **Balanced** | No          | Can be   | Always   |

## 10. Tree Applications

### 10.1 File System

```mermaid
graph TD
    A[root/] --> B[home/]
    A --> C[etc/]
    B --> D[user/]
    B --> E[documents/]
    D --> F[Downloads/]
    D --> G[Pictures/]
    E --> H[work/]
    E --> I[personal/]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
    style F fill:#e3f2fd
    style G fill:#e3f2fd
    style H fill:#e3f2fd
    style I fill:#e3f2fd
```

### 10.2 Expression Tree

```mermaid
graph TD
    A[+] --> B[*]
    A --> C[3]
    B --> D[2]
    B --> E[x]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
```

**Expression:** (2 \* x) + 3

## 11. Tree Memory Layout

### Contiguous Memory (Array)

```
Index:  0   1   2   3   4   5   6   7   8   9  10  11  12
Value: [1] [2] [4] [-1] [-1] [5] [-1] [-1] [3] [-1] [6] [-1] [-1]
```

### Linked Memory (Nodes)

```
Address: 1000      2000      3000      4000      5000
Node1: [1|2000,5000] -> Node2: [2|3000,4000] -> Node4: [4|NULL,NULL]
                     -> Node3: [3|NULL,6000] -> Node6: [6|NULL,NULL]
```

## 12. When to Use Binary Trees

### ✅ Good Choice

- Hierarchical data representation
- Fast search in BST
- Priority queue implementation (Heap)
- Expression evaluation
- Database indexing

### ❌ Avoid When

- Linear data access pattern
- Memory is severely constrained
- Simple key-value storage needed (use Hash Table)
- Random access is primary operation

## 13. Advanced Tree Concepts

### 13.1 AVL Tree (Self-Balancing)

```mermaid
graph TD
    A[30] --> B[20]
    A --> C[40]
    B --> D[10]
    B --> E[25]
    E --> F[23]
    E --> G[27]

    style A fill:#e8f5e8
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#e8f5e8
    style G fill:#e8f5e8
```

**Balance Factor:** Height(left) - Height(right) ∈ {-1, 0, 1}

### 13.2 Red-Black Tree

```mermaid
graph TD
    A[10<br/>Black] --> B[5<br/>Red]
    A --> C[15<br/>Red]
    B --> D[3<br/>Black]
    B --> E[7<br/>Black]
    C --> F[12<br/>Black]
    C --> G[17<br/>Black]

    style A fill:#ffebee
    style B fill:#ffcdd2
    style C fill:#ffcdd2
    style D fill:#ffebee
    style E fill:#ffebee
    style F fill:#ffebee
    style G fill:#ffebee
```

**Properties:** Root is black, red nodes have black children, equal black height
