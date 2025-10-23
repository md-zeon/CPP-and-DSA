# Day 36: Heaps and Priority Queues Part 1

## Topics Covered

- **Heap Implementation**: Custom max heap with array representation
- **Priority Queue STL**: Using priority_queue for custom objects
- **Heap Operations**: Push, pop, top, heapify operations
- **Custom Comparators**: Defining comparison logic for objects
- **Heap Properties**: Complete binary tree with heap order property
- **Time Complexity**: Analysis of heap operations

## Key Concepts

1. **Heap Property**: Parent nodes are greater than children (max heap)
2. **Complete Binary Tree**: All levels filled except possibly last level
3. **Array Representation**: Efficient storage using 0-based indexing
4. **Heapify**: Maintaining heap property after operations
5. **Priority Queue**: STL implementation using heap

## Code Examples

### 1. Custom Max Heap Implementation

```cpp
class Heap {
private:
    vector<int> vec;

    void heapify(int parentIdx) {
        if(parentIdx >= vec.size()) return;

        int leftChild = 2 * parentIdx + 1;
        int rightChild = 2 * parentIdx + 2;
        int maxIdx = parentIdx;

        // Find maximum among parent and children
        if(leftChild < vec.size() && vec[leftChild] > vec[maxIdx]) {
            maxIdx = leftChild;
        }
        if(rightChild < vec.size() && vec[rightChild] > vec[maxIdx]) {
            maxIdx = rightChild;
        }

        // If heap property violated, swap and recurse
        if(maxIdx != parentIdx) {
            swap(vec[maxIdx], vec[parentIdx]);
            heapify(maxIdx);  // Recurse on affected subtree
        }
    }

public:
    void push(int val) {
        vec.push_back(val);  // Add to end

        // Bubble up to maintain heap property
        int childIdx = vec.size() - 1;
        int parentIdx = (childIdx - 1) / 2;

        while(childIdx > 0 && vec[childIdx] > vec[parentIdx]) {
            swap(vec[childIdx], vec[parentIdx]);
            childIdx = parentIdx;
            parentIdx = (childIdx - 1) / 2;
        }
    }

    void pop() {
        if(vec.empty()) return;

        // Move last element to root
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();

        // Heapify from root
        heapify(0);
    }

    int top() {
        return vec.empty() ? -1 : vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }
};

// Time Complexity: Push O(log n), Pop O(log n), Top O(1)
// Space Complexity: O(n)
```

### 2. Priority Queue with Custom Objects

```cpp
class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    // Custom comparison for max heap (higher marks first)
    bool operator < (const Student &s) const {
        return this->marks < s.marks;
    }
};

// Usage
priority_queue<Student> pq;
pq.push(Student("Aman", 85));
pq.push(Student("Akbar", 95));
pq.push(Student("Anthony", 65));

while(!pq.empty()) {
    cout << pq.top().name << " " << pq.top().marks << endl;
    pq.pop();
}

// Output: Akbar 95, Aman 85, Anthony 65
```

### 3. Priority Queue with Pairs and Custom Comparator

```cpp
struct ComparePair {
    bool operator()(pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;  // Compare by second element
    }
};

// Usage
priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
pq.push(make_pair("Aman", 85));
pq.push(make_pair("Akbar", 95));
pq.push(make_pair("Anthony", 65));

while(!pq.empty()) {
    cout << pq.top().first << " " << pq.top().second << endl;
    pq.pop();
}

// Output: Akbar 95, Aman 85, Anthony 65
```

## Heap Data Structure

### 1. Max Heap

- **Property**: Parent ≥ Children for all nodes
- **Root**: Maximum element in the heap
- **Operations**: Extract max, insert, increase key
- **Applications**: Priority queues, sorting

### 2. Min Heap

- **Property**: Parent ≤ Children for all nodes
- **Root**: Minimum element in the heap
- **Operations**: Extract min, insert, decrease key
- **Applications**: Dijkstra's algorithm, Prim's algorithm

### 3. Array Representation

- **Left Child**: 2\*i + 1
- **Right Child**: 2\*i + 2
- **Parent**: (i-1)/2
- **Complete Binary Tree**: Efficient array storage

## Priority Queue STL

### Basic Usage

```cpp
priority_queue<int> pq;  // Max heap by default

pq.push(5);
pq.push(10);
pq.push(3);

cout << pq.top() << endl;  // 10 (maximum)
pq.pop();
cout << pq.top() << endl;  // 5 (next maximum)
```

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;

minHeap.push(5);
minHeap.push(10);
minHeap.push(3);

cout << minHeap.top() << endl;  // 3 (minimum)
```

### Custom Objects

```cpp
// Method 1: Overload operator<
class Student {
public:
    string name;
    int marks;
    Student(string n, int m) : name(n), marks(m) {}

    bool operator<(const Student& s) const {
        return this->marks < s.marks;  // Max heap by marks
    }
};

// Method 2: Custom comparator
struct CompareStudent {
    bool operator()(Student s1, Student s2) {
        return s1.marks < s2.marks;  // Max heap by marks
    }
};

priority_queue<Student, vector<Student>, CompareStudent> pq;
```

## Algorithm Analysis

### Heap Operations

- **Push**: O(log n) - bubble up operation
- **Pop**: O(log n) - heapify down operation
- **Top**: O(1) - direct access to root
- **Build Heap**: O(n) - efficient construction

### Priority Queue Operations

- **All Operations**: O(log n) amortized
- **Peek**: O(1) - access top element
- **Size**: O(1) - track number of elements

## Key Takeaways

- **Heap Property**: Parent-child relationships maintain order
- **Complete Binary Tree**: Efficient array representation
- **Logarithmic Operations**: All operations are O(log n)
- **Custom Comparators**: Flexible ordering for different data types
- **STL Integration**: Priority queue is heap-based

## Common Mistakes to Avoid

- Incorrect parent/child index calculations
- Forgetting to handle empty heap cases
- Wrong comparison operators in custom comparators
- Not understanding max heap vs min heap behavior
- Memory issues with large heaps

## Heap vs Other Data Structures

### Heap vs BST

- **Heap**: Priority operations, no ordering
- **BST**: Ordered operations, search capability
- **Use Case**: Heap for priority, BST for ordered search

### Heap vs Array

- **Heap**: Dynamic size, priority operations
- **Array**: Fixed size, random access
- **Use Case**: Heap for priority queues, array for direct access

### Heap vs Stack

- **Heap**: Priority-based ordering
- **Stack**: LIFO ordering
- **Use Case**: Heap for priority, stack for function calls

## Applications

### 1. Priority Scheduling

- **Task Scheduling**: Schedule tasks by priority
- **CPU Scheduling**: Priority-based process scheduling
- **Job Queues**: Manage jobs by importance
- **Event Processing**: Handle events by priority

### 2. Algorithm Implementation

- **Dijkstra's Algorithm**: Shortest path with priority queue
- **Prim's Algorithm**: Minimum spanning tree
- **Huffman Coding**: Priority-based compression
- **Kth Largest Element**: Using min heap

### 3. Data Management

- **Top K Elements**: Find k largest/smallest elements
- **Median Maintenance**: Maintain running median
- **Duplicate Removal**: Remove duplicates efficiently
- **Sorting**: Heap sort algorithm

### 4. System Design

- **Load Balancing**: Distribute work by priority
- **Cache Management**: Evict least important items
- **Resource Allocation**: Allocate by priority
- **Message Queues**: Priority-based message processing

## Interview Tips

- **Implementation**: Know how to implement heap from scratch
- **STL Usage**: Understand priority_queue operations
- **Custom Comparators**: Practice with different data types
- **Time Complexity**: Explain logarithmic behavior
- **Problem Solving**: Recognize when heap is optimal solution

## Problem Variations

### 1. Heap Construction

- **Build from Array**: Convert array to heap
- **Build from Stream**: Online heap construction
- **Merge Heaps**: Combine multiple heaps
- **Heap Sort**: Sorting using heap

### 2. Priority Operations

- **Kth Largest**: Find kth largest element
- **Top K Elements**: Find k largest elements
- **Median Stream**: Maintain median in data stream
- **Running Median**: Median of sliding window

### 3. Graph Algorithms

- **Dijkstra's Algorithm**: Shortest path with priority queue
- **Prim's Algorithm**: Minimum spanning tree
- **A\* Search**: Heuristic search with priority
- **Kruskal's Algorithm**: MST with union-find

### 4. Optimization Problems

- **Resource Allocation**: Assign resources by priority
- **Task Scheduling**: Schedule with constraints
- **Load Balancing**: Distribute work optimally
- **Profit Maximization**: Select highest profit items

## Performance Considerations

- **Heap Operations**: O(log n) for insert/delete
- **Build Heap**: O(n) using efficient algorithm
- **Memory Usage**: O(n) for n elements
- **Cache Performance**: Array representation is cache-friendly

## Advanced Heap Concepts

- **Binary Heap**: Standard 2-child heap
- **Binomial Heap**: Collection of binomial trees
- **Fibonacci Heap**: Advanced heap with amortized O(1) operations
- **Pairing Heap**: Self-adjusting heap structure
- **Skew Heap**: Self-adjusting with merge operation

## Real-World Usage

- **STL Priority Queue**: Used in many C++ applications
- **Operating Systems**: Process scheduling
- **Network Routers**: Packet prioritization
- **Database Systems**: Query optimization
- **Game Development**: Pathfinding algorithms
