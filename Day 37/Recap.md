# Day 37: Advanced Heap Operations & Priority Queue Applications

## Topics Covered

- Heap Sort Implementation
- Priority Queue Applications
- Custom Comparators
- Sliding Window Maximum

## 1. Heap Sort Implementation

### Key Concepts

- **Heapify**: Maintains max-heap property by comparing parent with children
- **Build Max Heap**: Converts array into max-heap (O(n) time)
- **Heap Sort**: Sorts array using heap operations (O(n log n) time)

### Algorithm Steps

```cpp
void heapSort(vector<int> &arr) {
    int n = arr.size();
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Step 2: Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

## 2. Nearby Cars Problem

### Problem

Find K nearest cars from origin based on their coordinates.

### Solution Approach

- Calculate distance squared for each car: `x² + y²`
- Use priority queue to maintain K smallest distances
- Custom comparator for min-heap based on distance

```cpp
class Car {
public:
    int idx;
    int distSq;
    bool operator < (const Car &c) const {
        return this->distSq > c.distSq; // min heap
    }
};
```

## 3. Connect N Ropes Problem

### Problem

Find minimum cost to connect N ropes where cost of connecting two ropes equals sum of their lengths.

### Solution Approach

- Use min-heap (priority queue) to always connect two smallest ropes
- Add the cost and push the combined rope back to heap
- Repeat until one rope remains

### Time Complexity: O(n log n)

```cpp
priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());
while (pq.size() > 1) {
    int min1 = pq.top(); pq.pop();
    int min2 = pq.top(); pq.pop();
    cost += min1 + min2;
    pq.push(min1 + min2);
}
```

## 4. Weakest Soldier Problem

### Problem

For an M×N matrix, find K weakest rows based on:

1. Number of soldiers (1s) in the row
2. If tie, smaller row index

### Solution Approach:

- Count soldiers in each row
- Use priority queue with custom comparator
- Min-heap based on soldier count and index

```cpp
class Row {
public:
    int soldiers;
    int idx;
    bool operator < (const Row &r) const {
        if (this->soldiers == r.soldiers) {
            return this->idx > r.idx; // smaller index first
        } else {
            return this->soldiers > r.soldiers; // fewer soldiers first
        }
    }
};
```

## 5. Sliding Window Maximum

### Problem:

Find maximum element in each window of size K in an array.

### Solution Approach:

- Use max-heap (priority queue) to store elements with their indices
- Remove elements outside current window
- Maintain heap of current window elements

### Time Complexity: O(n log k)

```cpp
priority_queue<pair<int, int>> pq; // {value, index}
for (int i = 0; i < k; i++) {
    pq.push({arr[i], i});
}
cout << pq.top().first << " ";

for (int i = k; i < arr.size(); i++) {
    // Remove elements outside window
    while (!pq.empty() && pq.top().second <= (i-k)) {
        pq.pop();
    }
    pq.push({arr[i], i});
    cout << pq.top().first << " ";
}
```

## Key Takeaways:

1. **Heapify** is crucial for maintaining heap properties
2. **Priority queues** are powerful for problems requiring ordered processing
3. **Custom comparators** enable flexible ordering based on multiple criteria
4. **Index tracking** is important for sliding window problems
5. **Time complexity** considerations are vital for heap operations

## Applications:

- Sorting algorithms (Heap Sort)
- Finding K smallest/largest elements
- Optimization problems (minimum cost)
- Sliding window problems
- Real-time processing with priority requirements

## Complexity Analysis:

- **Heap Sort**: O(n log n) time, O(1) extra space
- **Priority Queue operations**: O(log n) for insert/delete
- **Sliding Window Maximum**: O(n log k) time
- **Space complexity**: O(n) for priority queue storage
