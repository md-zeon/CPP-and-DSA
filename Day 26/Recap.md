# Day 26: Doubly Linked Lists

## Topics Covered

- **Doubly Linked List Structure**: Nodes with prev and next pointers
- **Bidirectional Traversal**: Moving forward and backward through list
- **Insertion Operations**: Push front, push back with proper linking
- **Deletion Operations**: Pop front, pop back with cleanup
- **Memory Management**: Proper handling of bidirectional pointers
- **Comparison with Singly Linked Lists**: Advantages and trade-offs

## Key Concepts

1. **Bidirectional Links**: Each node points to both next and previous nodes
2. **Head and Tail**: Track both ends of the list
3. **Pointer Management**: Update both next and prev pointers during operations
4. **Traversal Flexibility**: Can move in both directions
5. **Memory Overhead**: Extra pointer per node compared to singly linked list

## Code Examples

### 1. Node Class for Doubly Linked List

```cpp
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;  // Initialize both pointers
    }
};
```

### 2. Doubly Linked List Class

```cpp
class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = tail = NULL;  // Both pointers initially null
    }
};
```

### 3. Push Front Operation

```cpp
void push_front(int val) {
    Node *newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;  // Empty list case
    } else {
        newNode->next = head;   // New node points to current head
        head->prev = newNode;   // Current head's prev points to new node
        head = newNode;         // Update head
    }
}

// Example: push_front(1) on [2,3,4] -> [1,2,3,4]
// Links: 1->2->3->4, 4->3->2->1 (bidirectional)
```

### 4. Push Back Operation

```cpp
void push_back(int val) {
    Node* newNode = new Node(val);

    if(head == NULL) {
        head = tail = newNode;  // Empty list case
    } else {
        newNode->prev = tail;   // New node points back to current tail
        tail->next = newNode;   // Current tail points to new node
        tail = newNode;         // Update tail
    }
}

// Example: push_back(5) on [1,2,3,4] -> [1,2,3,4,5]
// Links: 1<->2<->3<->4<->5 (bidirectional)
```

### 5. Pop Front Operation

```cpp
void pop_front() {
    if(head == NULL) return;  // Empty list

    Node* temp = head;
    head = head->next;        // Move head to next node

    if(head != NULL) {
        head->prev = NULL;    // Remove backward link
    } else {
        tail = NULL;          // List becomes empty
    }

    temp->next = NULL;        // Clean up pointers
    delete temp;              // Free memory
}

// Example: pop_front() on [1,2,3,4] -> [2,3,4]
```

### 6. Pop Back Operation

```cpp
void pop_back() {
    if(head == NULL) {
        cout << "Invalid Action! Linked List is Empty\n";
        return;
    }

    Node* temp = tail->prev;  // Second last node
    temp->next = NULL;        // Remove forward link
    delete tail;              // Delete last node
    tail = temp;              // Update tail

    if(tail == NULL) {
        head = NULL;          // List became empty
    }
}

// Example: pop_back() on [1,2,3,4] -> [1,2,3]
```

### 7. Print List (Forward Traversal)

```cpp
void printList() {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;  // Move forward
    }
    cout << "NULL\n";
}

// Example: [1,2,3,4] -> 1 -> 2 -> 3 -> 4 -> NULL
```

## Doubly Linked List Operations Complexity

| Operation          | Time Complexity | Space Complexity | Notes                        |
| ------------------ | --------------- | ---------------- | ---------------------------- |
| Push Front         | O(1)            | O(1)             | Direct head manipulation     |
| Push Back          | O(1)            | O(1)             | Direct tail manipulation     |
| Pop Front          | O(1)            | O(1)             | Direct head manipulation     |
| Pop Back           | O(1)            | O(1)             | Direct tail manipulation     |
| Insert at Position | O(n)            | O(1)             | Need to traverse to position |
| Delete at Position | O(n)            | O(1)             | Need to traverse to position |
| Search             | O(n)            | O(1)             | Linear traversal             |
| Reverse Traversal  | O(n)            | O(1)             | Can traverse backward        |

## Comparison: Singly vs Doubly Linked List

### Singly Linked List

```cpp
class Node {
    int data;
    Node* next;  // Only forward pointer
};
```

### Doubly Linked List

```cpp
class Node {
    int data;
    Node* next;  // Forward pointer
    Node* prev;  // Backward pointer
};
```

### Memory Comparison

- **Singly Linked List**: 8 bytes (data) + 8 bytes (pointer) = 16 bytes per node
- **Doubly Linked List**: 8 bytes (data) + 8 bytes (next) + 8 bytes (prev) = 24 bytes per node
- **Overhead**: 50% more memory per node

## Key Takeaways

- **Bidirectional Traversal**: Can move forward and backward
- **Efficient Deletions**: Easy to delete nodes with prev pointers
- **Memory Overhead**: Extra pointer per node
- **Flexible Operations**: More operations possible than singly linked list
- **Consistent Performance**: O(1) for end operations in both directions

## Common Mistakes to Avoid

- Forgetting to update both next and prev pointers
- Memory leaks (not deleting nodes properly)
- Incorrect null checks for head and tail
- Not handling empty list cases
- Mixing up next and prev pointer assignments

## Doubly Linked List vs Singly Linked List

### Doubly Linked List Advantages

- **Bidirectional Traversal**: Can move backward and forward
- **Easy Deletions**: Can delete nodes without knowing previous node
- **Reverse Operations**: Easy to traverse in reverse order
- **More Flexible**: Supports more operations efficiently

### Doubly Linked List Disadvantages

- **Memory Overhead**: Extra pointer per node (50% more memory)
- **Complex Implementation**: More pointer management
- **Slower Operations**: Slightly slower due to extra pointer updates
- **Cache Performance**: Worse cache locality due to scattered memory

### When to Use Doubly Linked List

- **Frequent Reverse Traversal**: Need to move backward often
- **Easy Deletions**: Need to delete nodes efficiently
- **Browser History**: Forward/backward navigation
- **Music Player**: Previous/next song functionality
- **Undo/Redo**: Text editors, design software

## Advanced Operations

### 1. Insert at Position

```cpp
void insert(int val, int pos) {
    Node* newNode = new Node(val);

    if(pos == 0) {
        push_front(val);  // Use existing function
        return;
    }

    Node* temp = head;
    for(int i = 0; i < pos - 1; i++) {
        if(temp == NULL) return;
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
```

### 2. Delete at Position

```cpp
void deleteAt(int pos) {
    if(head == NULL) return;

    if(pos == 0) {
        pop_front();  // Use existing function
        return;
    }

    Node* temp = head;
    for(int i = 0; i < pos; i++) {
        if(temp == NULL) return;
        temp = temp->next;
    }

    // Update links
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Update head/tail if necessary
    if(temp == head) head = temp->next;
    if(temp == tail) tail = temp->prev;

    delete temp;
}
```

### 3. Reverse Traversal

```cpp
void printReverse() {
    Node* temp = tail;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->prev;  // Move backward
    }
    cout << "NULL\n";
}
```

## Applications

### 1. Navigation Systems

- **Browser History**: Forward/backward navigation
- **Music Players**: Previous/next song
- **Image Viewers**: Previous/next image
- **File Browsers**: Directory navigation

### 2. Text Processing

- **Text Editors**: Cursor movement in both directions
- **Undo/Redo**: Stack implementation with efficient navigation
- **Word Processors**: Document navigation
- **Code Editors**: Jump to previous/next error

### 3. Data Structures Implementation

- **Deque (Double-ended Queue)**: Efficient operations at both ends
- **LRU Cache**: Most recently used tracking
- **Browser Tabs**: Tab switching and management
- **Playlist Management**: Song ordering and navigation

### 4. System Applications

- **Memory Management**: Free list management
- **Process Scheduling**: Task queue with priority
- **File System**: Directory traversal
- **Database Systems**: Index navigation

## Interview Tips

- **Draw Diagrams**: Show bidirectional links clearly
- **Handle Edge Cases**: Empty list, single node, two nodes
- **Memory Management**: Discuss proper cleanup of both pointers
- **Performance Trade-offs**: Compare with singly linked list
- **Real-world Usage**: Explain when doubly linked list is preferred

## Problem Variations

- **Reverse Doubly Linked List**: Reverse in-place
- **Sort Doubly Linked List**: Sort while maintaining links
- **Merge Two Doubly Linked Lists**: Combine two sorted lists
- **Find Middle Node**: Locate middle efficiently
- **Detect Cycle**: Check for cycles in bidirectional list

## Performance Considerations

- **Memory Usage**: 50% more memory than singly linked list
- **Cache Performance**: Worse than arrays but better than some structures
- **Operation Speed**: Slightly slower due to extra pointer operations
- **Scalability**: Good for dynamic data with frequent insertions/deletions
