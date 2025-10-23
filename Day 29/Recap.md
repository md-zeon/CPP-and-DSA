# Day 29: Queues and Deque

## Topics Covered

- **Queue Implementations**: Linked list, array, and two stacks
- **Stack using Queues**: Alternative stack implementation
- **Deque Operations**: Double-ended queue functionality
- **First Non-Repeating Character**: Queue-based string processing
- **Queue Interleaving**: Rearranging queue elements
- **Queue Reversal**: Reversing queue using stack

## Key Concepts

1. **FIFO Principle**: First In, First Out data structure
2. **Circular Queue**: Efficient array-based implementation
3. **Two Stack Queue**: Queue using two stacks for amortized O(1) operations
4. **Queue Applications**: Real-world problem solving
5. **Deque Flexibility**: Operations at both ends

## Code Examples

### 1. Queue using Two Stacks

```cpp
class Queue {
private:
    stack<int> s1, s2;  // s1 for enqueue, s2 for dequeue

public:
    void push(int data) {
        // Move all elements from s1 to s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element to s1
        s1.push(data);

        // Move back all elements from s2 to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if(!s1.empty()) {
            s1.pop();  // Front element is at top of s1
        }
    }

    int front() {
        return s1.top();  // Top of s1 is front
    }

    bool empty() {
        return s1.empty();
    }
};

// Amortized Time Complexity: O(1) for push/pop
// Space Complexity: O(n)
```

### 2. Stack using Two Queues

```cpp
class Stack {
private:
    queue<int> q1, q2;  // q1 for main operations

public:
    void push(int data) {
        // Move all elements from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element to q1
        q1.push(data);

        // Move back all elements from q2 to q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if(!q1.empty()) {
            q1.pop();  // Remove front (which is top)
        }
    }

    int top() {
        return q1.front();  // Front of q1 is top
    }

    bool empty() {
        return q1.empty();
    }
};

// Amortized Time Complexity: O(1) for push/pop
// Space Complexity: O(n)
```

### 3. First Non-Repeating Character

```cpp
void firstNonRepeating(string str) {
    queue<char> Q;
    int freq[26] = {0};

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // Add to queue and update frequency
        Q.push(ch);
        freq[ch - 'a']++;

        // Remove characters that appear more than once
        while(!Q.empty() && freq[Q.front() - 'a'] > 1) {
            Q.pop();
        }

        // Print result
        if(Q.empty()) {
            cout << "-1\n";  // No non-repeating character
        } else {
            cout << Q.front() << endl;  // First non-repeating character
        }
    }
}

// Example: "aabccxb"
// Output: a, a, a, a, b, b, x
```

### 4. Queue Interleaving

```cpp
void interLeaveTwoQueues(queue<int> &org) {
    int n = org.size();
    queue<int> first;

    // Move first half to another queue
    for(int i = 0; i < n/2; i++) {
        first.push(org.front());
        org.pop();
    }

    // Interleave elements
    while(!first.empty()) {
        org.push(first.front());  // Add from first half
        first.pop();

        org.push(org.front());    // Add from second half
        org.pop();
    }
}

// Example: [1,2,3,4,5,6] -> [1,4,2,5,3,6]
```

### 5. Queue Reversal

```cpp
void reverseQueue(queue<int> &q) {
    stack<int> s;

    // Move all elements to stack
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Move back to queue (reversed)
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// Example: [1,2,3,4,5] -> [5,4,3,2,1]
```

### 6. Deque Operations

```cpp
deque<int> deq;

// Push operations
deq.push_front(2);  // Add to front
deq.push_front(1);  // Add to front
deq.push_back(3);   // Add to back
deq.push_back(4);   // Add to back

// Current: [1, 2, 3, 4]

// Pop operations
deq.pop_front();    // Remove from front -> [2, 3, 4]
deq.pop_back();     // Remove from back -> [2, 3]

// Access operations
cout << deq.front() << " ";  // 2 (first element)
cout << deq.back() << " ";   // 3 (last element)
```

## Queue Implementations

### 1. Array-based Queue (Linear)

- **Fixed Size**: Cannot grow beyond initial capacity
- **Memory Efficient**: No extra space per element
- **Problem**: Dequeue leaves empty spaces at front

### 2. Circular Queue (Array)

- **Circular Buffer**: Uses modulo arithmetic for wrapping
- **Efficient**: Reuses space at front after dequeue
- **Implementation**: Track front and rear indices

### 3. Linked List Queue

- **Dynamic Size**: Can grow and shrink as needed
- **Memory Overhead**: Extra pointer per node
- **Flexible**: Easy to implement and modify

### 4. Two Stacks Queue

- **Amortized O(1)**: Push/pop operations
- **Implementation**: One stack for enqueue, one for dequeue
- **Trade-off**: Expensive push operations

## Algorithm Analysis

### Time Complexity

- **Queue Operations**: O(1) for push, pop, front, back
- **Two Stack Queue**: O(1) amortized, O(n) worst case for push
- **First Non-Repeating**: O(n) total, O(26) for frequency array
- **Queue Reversal**: O(n) time and space

### Space Complexity

- **Queue Storage**: O(n) for n elements
- **Two Stack Implementation**: O(n) for both stacks
- **Frequency Array**: O(26) for character frequencies

## Key Takeaways

- **FIFO Principle**: Queue follows First In, First Out
- **Multiple Implementations**: Choose based on requirements
- **Amortized Analysis**: Consider average case performance
- **Real-time Applications**: Queues for streaming data
- **Stack-Queue Duality**: Can implement one using the other

## Common Mistakes to Avoid

- Forgetting to handle empty queue cases
- Incorrect implementation of two-stack queue
- Not understanding amortized time complexity
- Memory leaks in custom implementations
- Wrong order in queue interleaving

## Queue vs Stack

### Queue Characteristics

- **Order**: FIFO (First In, First Out)
- **Operations**: Enqueue (rear), Dequeue (front)
- **Usage**: Breadth-first search, task scheduling

### Stack Characteristics

- **Order**: LIFO (Last In, First Out)
- **Operations**: Push (top), Pop (top)
- **Usage**: Depth-first search, expression evaluation

### Implementation Trade-offs

- **Queue with Stacks**: Amortized O(1) operations
- **Stack with Queues**: Amortized O(1) operations
- **Memory**: Both use similar space
- **Performance**: Similar amortized performance

## Applications

### 1. System Applications

- **Process Scheduling**: CPU task scheduling
- **Print Queue**: Print job management
- **Network Buffers**: Data packet handling
- **Event Loops**: GUI event processing

### 2. Algorithm Applications

- **Breadth-First Search**: Graph traversal
- **Level Order Traversal**: Tree traversal
- **Sliding Window**: Moving window calculations
- **Rate Limiting**: API request throttling

### 3. Real-time Systems

- **Streaming Data**: Processing data streams
- **Message Queues**: Asynchronous communication
- **Job Queues**: Background task processing
- **Cache Systems**: LRU cache implementation

### 4. Problem Solving

- **Non-repeating Characters**: Finding unique elements in stream
- **Interleaving**: Rearranging data structures
- **Reversal**: Reversing sequences
- **Simulation**: Modeling real-world queues

## Interview Tips

- **Implementation Choice**: Know when to use each implementation
- **Amortized Analysis**: Understand average case performance
- **Edge Cases**: Handle empty and single element cases
- **Real-world Usage**: Explain practical applications
- **Performance Trade-offs**: Discuss time vs space considerations

## Problem Variations

### 1. Queue Problems

- **Circular Tour**: Gas station problem with circular queue
- **Sliding Window Maximum**: Maximum in window using deque
- **Implement Queue using Stacks**: Multiple approaches
- **Queue Reconstruction**: Reconstruct queue by height

### 2. Deque Problems

- **Maximum in Subarray**: Using deque for optimization
- **Palindrome Check**: Using deque for efficient checking
- **Min/Max in Windows**: Sliding window with deque
- **Stack Permutations**: Valid stack permutation sequences

### 3. Advanced Problems

- **LRU Cache**: Least recently used cache implementation
- **Task Scheduler**: Schedule tasks with cooldown periods
- **Moving Average**: Calculate average in sliding window
- **Snake Game**: Game state management with deque

## Performance Considerations

- **STL Queue**: Most efficient for general use
- **Custom Implementation**: Only when specific requirements
- **Memory Usage**: Consider overhead of different implementations
- **Cache Performance**: Array-based implementations are cache-friendly

## Advanced Queue Concepts

- **Priority Queue**: Queue with priority ordering
- **Double-ended Priority Queue**: Priority operations at both ends
- **Concurrent Queue**: Thread-safe queue implementations
- **Lock-free Queue**: High-performance concurrent queues
