# Day 37: Advanced Heap Operations & Priority Queue Applications - Diagrams

## 1. Heap Sort Flowchart

This shows the heap sort algorithm.

```mermaid
graph TD
    A[heapSort] --> B[Build max heap from array]
    B --> C[Loop i = n-1 to 0]
    C --> D[swap(arr[0], arr[i])]
    D --> E[heapify(arr, i, 0)]
    E --> F[Continue loop]
    F --> G[Array is now sorted]
```

## 2. Connect N Ropes Flowchart

This illustrates the minimum cost to connect ropes.

```mermaid
graph TD
    A[connectRopes] --> B[Create min heap with ropes]
    B --> C{pq.size() > 1?}
    C -->|Yes| D[min1 = pq.top(), pq.pop()]
    D --> E[min2 = pq.top(), pq.pop()]
    E --> F[cost += min1 + min2]
    F --> G[pq.push(min1 + min2)]
    G --> H[Continue loop]
    C -->|No| I[Return cost]
```

## 3. K Nearest Cars Flowchart

This depicts finding K nearest cars.

```mermaid
graph TD
    A[findKNearestCars] --> B[Create max heap for distances]
    B --> C[Loop through cars]
    C --> D[Calculate distance squared]
    D --> E{heap.size() < k?}
    E -->|Yes| F[heap.push(car)]
    E -->|No| G{car.dist < heap.top().dist?}
    G -->|Yes| H[heap.pop(), heap.push(car)]
    G -->|No| I[Continue]
    H --> J[After loop, heap contains K nearest]
```

## 4. K Weakest Rows Flowchart

This shows finding K weakest rows in a matrix.

```mermaid
graph TD
    A[findKWeakestRows] --> B[Create min heap for rows]
    B --> C[Loop through rows]
    C --> D[Count soldiers in row]
    D --> E[heap.push(Row(soldiers, idx))]
    E --> F{heap.size() > k?}
    F -->|Yes| G[heap.pop()]
    F -->|No| H[Continue]
    G --> I[After loop, heap contains K weakest]
```

## 5. Sliding Window Maximum Flowchart

This illustrates finding maximum in each window.

```mermaid
graph TD
    A[slidingWindowMax] --> B[Create max heap]
    B --> C[Add first k elements to heap]
    C --> D[Print heap.top()]
    D --> E[Loop i = k to n-1]
    E --> F[Remove elements outside window]
    F --> G[heap.push(arr[i])]
    G --> H[Print heap.top()]
    H --> I[Continue loop]
```

## 6. Priority Queue with Custom Comparator Flowchart

This shows using priority queue with custom ordering.

```mermaid
graph TD
    A[Priority Queue with Custom Comparator] --> B[Define comparator for ordering]
    B --> C[Create priority_queue with comparator]
    C --> D[pq.push(elements)]
    D --> E[pq.top() returns highest priority]
    E --> F[pq.pop() removes highest priority]
    F --> G[Continue until pq.empty()]
```

## 7. Heapify Flowchart

This depicts the heapify process.

```mermaid
graph TD
    A[heapify(i)] --> B[Find largest among i, left, right]
    B --> C{largest != i?}
    C -->|Yes| D[swap(arr[i], arr[largest])]
    D --> E[heapify(largest)]
    C -->|No| F[Return]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize advanced heap and priority queue operations.
- For heap sort, the build and extract phases are key.
- For connect ropes, always connecting smallest is greedy.
- For sliding window, maintaining the window in heap is crucial.
- Use these to understand heap-based problem-solving.
