# Day 36: Heaps and Priority Queues Part 1 - Diagrams

## 1. Heap Push Flowchart

This shows the process of pushing an element into a max heap.

```mermaid
graph TD
    A[push(val)] --> B[vec.push_back(val)]
    B --> C[childIdx = vec.size()-1]
    C --> D[parentIdx = (childIdx-1)/2]
    D --> E{childIdx > 0 and vec[childIdx] > vec[parentIdx]?}
    E -->|Yes| F[swap(vec[childIdx], vec[parentIdx])]
    F --> G[childIdx = parentIdx, parentIdx = (childIdx-1)/2]
    G --> H[Continue loop]
    E -->|No| I[Done]
```

## 2. Heap Pop Flowchart

This illustrates popping the maximum element from a max heap.

```mermaid
graph TD
    A[pop()] --> B{vec.empty()?}
    B -->|Yes| C[Return]
    B -->|No| D[swap(vec[0], vec.back())]
    D --> E[vec.pop_back()]
    E --> F[heapify(0)]
```

## 3. Heapify Flowchart

This depicts the heapify process to maintain heap property.

```mermaid
graph TD
    A[heapify(parentIdx)] --> B{parentIdx >= vec.size()?}
    B -->|Yes| C[Return]
    B -->|No| D[leftChild = 2*parentIdx+1, rightChild = 2*parentIdx+2]
    D --> E[maxIdx = parentIdx]
    E --> F{leftChild < vec.size() and vec[leftChild] > vec[maxIdx]?}
    F -->|Yes| G[maxIdx = leftChild]
    F -->|No| H{rightChild < vec.size() and vec[rightChild] > vec[maxIdx]?}
    H -->|Yes| I[maxIdx = rightChild]
    H -->|No| J{maxIdx != parentIdx?}
    J -->|Yes| K[swap(vec[maxIdx], vec[parentIdx]), heapify(maxIdx)]
    J -->|No| L[Return]
```

## 4. Priority Queue with Custom Objects Flowchart

This shows using priority queue with custom objects.

```mermaid
graph TD
    A[Priority Queue with Custom Objects] --> B[Define class with operator<]
    B --> C[Create priority_queue<Class>]
    C --> D[pq.push(object1), pq.push(object2)]
    D --> E[pq.top() returns highest priority]
    E --> F[pq.pop() removes highest priority]
```

## 5. Priority Queue with Pairs and Comparator Flowchart

This illustrates priority queue with pairs and custom comparator.

```mermaid
graph TD
    A[Priority Queue with Pairs] --> B[Define comparator struct]
    B --> C[Create priority_queue<pair, vector<pair>, Comparator>]
    C --> D[pq.push(make_pair(name, marks))]
    D --> E[pq.top() returns highest priority pair]
    E --> F[pq.pop() removes highest priority pair]
```

## 6. Find Kth Largest Using Min Heap Flowchart

This depicts finding kth largest element.

```mermaid
graph TD
    A[Find Kth Largest] --> B[Create min heap of size k]
    B --> C[Loop through array]
    C --> D{heap.size() < k?}
    D -->|Yes| E[heap.push(arr[i])]
    D -->|No| F{arr[i] > heap.top()?}
    F -->|Yes| G[heap.pop(), heap.push(arr[i])]
    F -->|No| H[Continue]
    G --> I[After loop, heap.top() is kth largest]
```

## 7. Merge K Sorted Arrays Flowchart

This shows merging k sorted arrays using priority queue.

```mermaid
graph TD
    A[Merge K Sorted Arrays] --> B[Create priority queue with first elements]
    B --> C[While pq not empty]
    C --> D[result.push_back(pq.top().val)]
    D --> E[If next element in array, pq.push(next)]
    E --> F[pq.pop()]
    F --> G[Continue until all elements processed]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize heap operations and priority queue usage.
- For push and pop, the bubble up and heapify are key.
- For custom objects, comparators define the ordering.
- For kth largest, maintaining a min heap of size k is efficient.
- Use these to understand heap-based algorithms.
