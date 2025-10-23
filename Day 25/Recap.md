# Day 25: Linked Lists Part 1

## Topics Covered

- **Node Structure**: Basic building block of linked lists
- **Linked List Class**: Complete implementation with operations
- **Insertion Operations**: Push front, push back, insert at position
- **Deletion Operations**: Pop front, pop back, remove nth node
- **Search Operations**: Iterative and recursive search
- **List Reversal**: In-place reversal algorithm
- **Memory Management**: Proper allocation and deallocation

## Key Concepts

1. **Dynamic Structure**: Each node contains data and pointer to next
2. **Head and Tail**: Track beginning and end of list
3. **Traversal**: Moving through nodes using next pointers
4. **Memory Management**: Manual allocation/deallocation in C++
5. **Recursive Operations**: Some operations can be implemented recursively

## Code Examples

### 1. Node Class Definition

```cpp
class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;  // Recursive deletion
            next = NULL;
        }
    }
};
```

### 2. Linked List Class

```cpp
class List {
    Node *head;
    Node *tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        if(head != NULL) {
            delete head;  // Deletes entire list
            head = NULL;
        }
    }
};
```

### 3. Push Front Operation

```cpp
void push_front(int val) {
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;  // Empty list
    } else {
        newNode->next = head;   // Link new node to current head
        head = newNode;         // Update head
    }
}

// Example: push_front(1) on [2,3,4] -> [1,2,3,4]
```

### 4. Push Back Operation

```cpp
void push_back(int val) {
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;  // Empty list
    } else {
        tail->next = newNode;   // Link current tail to new node
        tail = newNode;         // Update tail
    }
}

// Example: push_back(5) on [1,2,3,4] -> [1,2,3,4,5]
```

### 5. Insert at Position

```cpp
void insert(int val, int pos) {
    Node *newNode = new Node(val);
    Node *temp = head;

    // Traverse to position (pos-1)
    for(int i = 0; i < pos - 1; i++) {
        if(temp == NULL) {
            cout << "Position is invalid\n";
            return;
        }
        temp = temp->next;
    }

    // Insert new node
    newNode->next = temp->next;
    temp->next = newNode;
}

// Example: insert(100, 2) on [1,2,3,4] -> [1,2,100,3,4]
```

### 6. Pop Front Operation

```cpp
void pop_front() {
    if(head == NULL) {
        cout << "Linked List is Empty\n";
        return;
    }

    Node *temp = head;
    head = head->next;    // Move head to next node
    temp->next = NULL;    // Disconnect from list
    delete temp;          // Free memory
}

// Example: pop_front() on [1,2,3,4] -> [2,3,4]
```

### 7. Pop Back Operation

```cpp
void pop_back() {
    if(head == NULL) return;

    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;  // Find second last node
    }

    temp->next = NULL;      // Remove last node
    delete tail;            // Free memory
    tail = temp;            // Update tail
}

// Example: pop_back() on [1,2,3,4] -> [1,2,3]
```

### 8. Iterative Search

```cpp
int searchItr(int key) {
    Node *temp = head;
    int idx = 0;

    while(temp != NULL) {
        if(temp->data == key) {
            return idx;  // Found at index
        }
        temp = temp->next;
        idx++;
    }
    return -1;  // Not found
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

### 9. Recursive Search

```cpp
int helper(Node *temp, int key) {
    if(temp == NULL) {
        return -1;  // Base case: not found
    }

    if(temp->data == key) {
        return 0;  // Found at current position
    }

    int idx = helper(temp->next, key);  // Search in rest
    if(idx == -1) {
        return -1;  // Not found in rest
    }

    return idx + 1;  // Adjust index
}

int searchRec(int key) {
    return helper(head, key);
}

// Time Complexity: O(n)
// Space Complexity: O(n) - call stack
```

### 10. Reverse Linked List

```cpp
void reverse() {
    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {
        Node *next = curr->next;  // Store next node
        curr->next = prev;        // Reverse current node's pointer

        // Move to next nodes
        prev = curr;
        curr = next;
    }
    head = prev;  // Update head to new first node
}

// Example: [1,2,3,4] -> [4,3,2,1]
// Time Complexity: O(n)
// Space Complexity: O(1)
```

### 11. Remove Nth Node

```cpp
void removeNth(int n) {
    int size = getSize();
    Node *prev = head;

    // Traverse to (size-n)th node
    for(int i = 1; i < size - n; i++) {
        prev = prev->next;
    }

    Node *toDel = prev->next;     // Node to delete
    prev->next = prev->next->next; // Skip the node
    toDel->next = NULL;           // Disconnect
    delete toDel;                 // Free memory
}

// Example: removeNth(2) on [1,2,3,4] -> [1,2,4]
```

### 12. Get Size

```cpp
int getSize() {
    Node *temp = head;
    int sz = 0;

    while(temp != NULL) {
        temp = temp->next;
        sz++;
    }
    return sz;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
```

## Linked List Operations Complexity

| Operation          | Time Complexity | Space Complexity | Notes                           |
| ------------------ | --------------- | ---------------- | ------------------------------- |
| Push Front         | O(1)            | O(1)             | Direct head manipulation        |
| Push Back          | O(1)            | O(1)             | Direct tail manipulation        |
| Insert at Position | O(n)            | O(1)             | Need to traverse to position    |
| Pop Front          | O(1)            | O(1)             | Direct head manipulation        |
| Pop Back           | O(n)            | O(1)             | Need to traverse to second last |
| Search (Iterative) | O(n)            | O(1)             | Linear traversal                |
| Search (Recursive) | O(n)            | O(n)             | Call stack space                |
| Reverse            | O(n)            | O(1)             | In-place reversal               |
| Get Size           | O(n)            | O(1)             | Linear traversal                |

## Memory Management

### 1. Node Creation

```cpp
Node *newNode = new Node(val);  // Allocate memory
// Use newNode
delete newNode;                 // Deallocate memory
```

### 2. Destructor Implementation

```cpp
~Node() {
    if(next != NULL) {
        delete next;  // Recursive deletion
        next = NULL;
    }
}

~List() {
    if(head != NULL) {
        delete head;  // Deletes entire list
        head = NULL;
    }
}
```

### 3. Memory Leaks Prevention

- **Always delete**: Nodes removed from list
- **Set to NULL**: Avoid dangling pointers
- **Destructor**: Clean up entire list when object destroyed

## Key Takeaways

- **Dynamic Size**: Linked lists can grow/shrink as needed
- **Efficient Insertions**: O(1) at beginning and end
- **Sequential Access**: O(n) time for most operations
- **Memory Overhead**: Each node has pointer overhead
- **No Random Access**: Cannot access elements by index directly

## Common Mistakes to Avoid

- Forgetting to update head/tail pointers
- Memory leaks (not deleting removed nodes)
- Incorrect traversal in loops
- Not handling empty list cases
- Dangling pointers after deletion

## Linked List vs Array

### Linked List Advantages

- **Dynamic Size**: No need to pre-allocate space
- **Efficient Insertions**: O(1) at beginning and end
- **Memory Efficiency**: No wasted space
- **Flexible**: Can represent various data structures

### Linked List Disadvantages

- **No Random Access**: O(n) to access specific element
- **Memory Overhead**: Extra space for pointers
- **Cache Performance**: Poor cache locality
- **Complex Implementation**: More error-prone than arrays

### Array Advantages

- **Random Access**: O(1) element access
- **Cache Friendly**: Better memory access patterns
- **Simple Implementation**: Less complex code
- **Memory Efficient**: No pointer overhead

## Applications

### 1. Implementation Based

- **Stack Implementation**: Using linked list
- **Queue Implementation**: Using linked list
- **Hash Table Chains**: Collision resolution
- **Graph Adjacency Lists**: Representing graph connections

### 2. Dynamic Data

- **Browser History**: Forward/backward navigation
- **Music Playlist**: Next/previous song
- **Text Editor**: Undo/redo operations
- **File System**: Directory structure

### 3. Memory Management

- **Free List**: Memory allocation tracking
- **Process Scheduling**: Task queues
- **Event Handling**: Event queues in applications

## Interview Tips

- **Draw Diagrams**: Visualize node connections
- **Handle Edge Cases**: Empty list, single node, two nodes
- **Memory Management**: Discuss proper cleanup
- **Time Complexity**: Analyze each operation
- **Alternative Approaches**: Compare with array implementation

## Problem Variations

- **Detect Cycle**: Check if linked list has cycle
- **Find Middle**: Locate middle node efficiently
- **Merge Lists**: Combine two sorted linked lists
- **Remove Duplicates**: Delete duplicate nodes
- **Kth Node**: Find kth node from beginning or end
