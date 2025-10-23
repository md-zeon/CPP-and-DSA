# Day 25: Linked List Visual Diagrams

## 1. Singly Linked List Structure

```mermaid
graph TD
    A[Head: 1] --> B[2]
    B --> C[3]
    C --> D[4]
    D --> E[5]
    E --> F[NULL]

    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
    style E fill:#fce4ec
```

### Description

- Each node contains data and a pointer to the next node
- Last node points to NULL
- Head pointer points to the first node

## 2. Linked List Operations

### 2.1 Push Front (Insert at Beginning)

```mermaid
graph TD
    A[New Node: 0] --> B[Previous Head: 1]
    B --> C[2]
    C --> D[3]
    D --> E[NULL]

    style A fill:#c8e6c9
```

**Before:** 1 → 2 → 3 → NULL
**After:** 0 → 1 → 2 → 3 → NULL

### 2.2 Push Back (Insert at End)

```mermaid
graph TD
    A[1] --> B[2]
    B --> C[3]
    C --> D[New Node: 4]
    D --> E[NULL]

    style D fill:#c8e6c9
```

**Before:** 1 → 2 → 3 → NULL
**After:** 1 → 2 → 3 → 4 → NULL

### 2.3 Insert at Position (Position 3)

```mermaid
graph TD
    A[1] --> B[2]
    B --> C[New Node: 100]
    C --> D[3]
    D --> E[4]
    E --> F[NULL]

    style C fill:#c8e6c9
```

**Before:** 1 → 2 → 3 → 4 → NULL
**After:** 1 → 2 → 100 → 3 → 4 → NULL

## 3. Linked List Deletion Operations

### 3.1 Pop Front (Delete from Beginning)

```mermaid
graph TD
    A[Tail: 5] --> B[4]
    B --> C[3]
    C --> D[2]
    D --> E[1 → NULL]

    style E fill:#ffcdd2
```

**Before:** 1 → 2 → 3 → 4 → 5 → NULL
**After:** 2 → 3 → 4 → 5 → NULL

### 3.2 Pop Back (Delete from End)

```mermaid
graph TD
    A[1] --> B[2]
    B --> C[3]
    C --> D[4 → NULL]

    style D fill:#ffcdd2
```

**Before:** 1 → 2 → 3 → 4 → 5 → NULL
**After:** 1 → 2 → 3 → 4 → NULL

## 4. Linked List Reversal

### Before Reversal

```mermaid
graph LR
    A[1] --> B[2]
    B --> C[3]
    C --> D[4]
    D --> E[5]
    E --> F[NULL]
```

### After Reversal

```mermaid
graph LR
    A[5] --> B[4]
    B --> C[3]
    C --> D[2]
    D --> E[1]
    E --> F[NULL]
```

## 5. Linked List vs Array Comparison

| Feature                | Linked List         | Array  |
| ---------------------- | ------------------- | ------ |
| **Memory Allocation**  | Dynamic             | Static |
| **Insertion/Deletion** | O(1) at ends        | O(n)   |
| **Random Access**      | O(n)                | O(1)   |
| **Memory Overhead**    | High (next pointer) | Low    |
| **Cache Friendly**     | No                  | Yes    |

## 6. Memory Layout

### Linked List in Memory

```
Memory Address: 1000    2000    3000    4000
Node 1: [Data: 1] -> [Next: 2000]
Node 2: [Data: 2] -> [Next: 3000]
Node 3: [Data: 3] -> [Next: 4000]
Node 4: [Data: 4] -> [Next: NULL]
```

### Array in Memory

```
Memory Address: 1000    1004    1008    1012    1016
Array: [1] [2] [3] [4] [5]
```

## 7. Common Linked List Patterns

### 7.1 Fast and Slow Pointers (Floyd's Algorithm)

```mermaid
graph TD
    A[Slow] --> B[Fast]
    B --> C[Fast moves 2 steps]
    C --> D[Slow moves 1 step]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
```

**Use Case:** Detect cycles, find middle element

### 7.2 Three Pointers (Reversal)

```mermaid
graph TD
    A[Previous] --> B[Current]
    B --> C[Next]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
```

**Use Case:** Reverse linked list

## 8. Linked List Types

### 8.1 Singly Linked List

```mermaid
graph TD
    A[Head] --> B[Node1]
    B --> C[Node2]
    C --> D[Node3]
    D --> E[NULL]

    style A fill:#ffecb3
```

### 8.2 Doubly Linked List

```mermaid
graph TD
    A[NULL] --> B[Node1] --> C[Node2] --> D[Node3] --> E[NULL]
    B --> A
    C --> B
    D --> C

    style B fill:#ffecb3
    style C fill:#ffecb3
    style D fill:#ffecb3
```

### 8.3 Circular Linked List

```mermaid
graph TD
    A[Node1] --> B[Node2]
    B --> C[Node3]
    C --> A

    style A fill:#ffecb3
    style B fill:#ffecb3
    style C fill:#ffecb3
```

## 9. Time Complexity Comparison

| Operation           | Singly Linked List | Doubly Linked List | Array                   |
| ------------------- | ------------------ | ------------------ | ----------------------- |
| Access              | O(n)               | O(n)               | O(1)                    |
| Insert at Beginning | O(1)               | O(1)               | O(n)                    |
| Insert at End       | O(n)               | O(1)               | O(1) if capacity allows |
| Delete at Beginning | O(1)               | O(1)               | O(n)                    |
| Delete at End       | O(n)               | O(1)               | O(1)                    |
| Search              | O(n)               | O(n)               | O(n)                    |

## 10. When to Use Linked List

### ✅ Good Choice

- Dynamic size requirements
- Frequent insertions/deletions at beginning
- Memory efficient for variable sizes
- Implementing stacks and queues

### ❌ Avoid When

- Random access needed frequently
- Memory overhead is a concern
- Cache performance is critical
- Simple sequential access is sufficient (use array/vector)
