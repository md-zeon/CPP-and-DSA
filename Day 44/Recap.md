# Day 44: Minimum Spanning Tree & Shortest Path Algorithms

## Topics Covered

- Minimum Spanning Tree (MST)
- Prim's Algorithm
- Kruskal's Algorithm
- Dijkstra's Algorithm
- Bellman-Ford Algorithm
- Union-Find (Disjoint Set Union)

## 1. Minimum Spanning Tree (MST)

### What is MST?

- **Subset of edges** that connects all vertices
- **No cycles** (acyclic)
- **Minimum total weight** among all possible spanning trees
- **Tree**: Exactly V-1 edges for V vertices

### Applications

1. **Network design** (minimum cost connections)
2. **Circuit design** (minimum wire length)
3. **Transportation** (minimum cost routes)
4. **Clustering** (minimum distance connections)

## 2. Prim's Algorithm

### Algorithm Overview

- **Greedy approach** to build MST
- **Start from arbitrary vertex**
- **Grow MST** by adding minimum weight edge
- **Use priority queue** to select next edge

### Implementation

```cpp
void primsAlgo(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> mst(V, false);

    pq.push({0, src}); // {weight, vertex}
    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (!mst[u]) {
            mst[u] = true;
            totalWeight += w;

            // Add all adjacent edges to priority queue
            for (pair<int, int> neighbor : l[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!mst[v]) {
                    pq.push({weight, v});
                }
            }
        }
    }
}
```

### Time Complexity: O((V+E) log V) with binary heap

### Space Complexity: O(V + E)

## 3. Kruskal's Algorithm

### Algorithm Overview

- **Sort all edges** by weight
- **Add edges** in increasing order
- **Skip edges** that form cycles
- **Use Union-Find** for cycle detection

### Union-Find (Disjoint Set Union)

```cpp
class DSU {
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
```

### Kruskal's Implementation

```cpp
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<pair<int, pair<int, int>>> edges;

    // Create all possible edges
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) +
                      abs(points[i][1] - points[j][1]);
            edges.push_back({dist, {i, j}});
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mstCost = 0;
    int edgesAdded = 0;

    for (auto& edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int weight = edge.first;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.unionSet(u, v);
            mstCost += weight;
            edgesAdded++;

            if (edgesAdded == n - 1) break;
        }
    }

    return mstCost;
}
```

### Time Complexity: O(E log E) for sorting

### Space Complexity: O(V + E)

## 4. Dijkstra's Algorithm

### Problem:

Find shortest paths from source to all other vertices in weighted graph with **non-negative weights**.

### Algorithm:

- **Priority queue** for next vertex selection
- **Relaxation** of edge weights
- **Greedy** approach - always pick minimum distance vertex

```cpp
void dijkstra(vector<vector<Edge>> graph, int src, int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (Edge edge : graph[u]) {
            int v = edge.v;
            int w = edge.w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
```

### Time Complexity: O((V+E) log V) with binary heap

### Space Complexity: O(V + E)

## 5. Bellman-Ford Algorithm

### Problem:

Find shortest paths in graph with **negative weights** (no negative cycles).

### Algorithm:

- **Relax all edges** V-1 times
- **Detect negative cycles** in Vth iteration
- **Dynamic programming** approach

```cpp
void bellmanFord(vector<vector<Edge>> graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Edge edge : graph[u]) {
                int v = edge.v;
                int w = edge.w;

                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < V; u++) {
        for (Edge edge : graph[u]) {
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                cout << "Negative cycle detected!" << endl;
                return;
            }
        }
    }
}
```

### Time Complexity: O(V \* E)

### Space Complexity: O(V)

## 6. Minimum Cost to Connect All Points

### Problem (LeetCode 1584):

Connect all points in 2D plane with minimum cost using Manhattan distance.

### Manhattan Distance:

```cpp
int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
```

### Solutions:

1. **Prim's Algorithm**: Start from point 0, grow MST
2. **Kruskal's Algorithm**: Sort all edges, use Union-Find

## Algorithm Comparison:

| Algorithm        | Time           | Space  | Use Case                       |
| ---------------- | -------------- | ------ | ------------------------------ |
| **Prim's**       | O((V+E) log V) | O(V+E) | Dense graphs                   |
| **Kruskal's**    | O(E log E)     | O(V+E) | Sparse graphs                  |
| **Dijkstra's**   | O((V+E) log V) | O(V+E) | Shortest paths (no negative)   |
| **Bellman-Ford** | O(V \* E)      | O(V)   | Shortest paths (with negative) |

## Key Concepts:

### Minimum Spanning Tree Properties:

1. **Connected**: All vertices included
2. **Acyclic**: No cycles
3. **Minimum weight**: Sum of edge weights minimized
4. **Unique path**: Between any two vertices

### Shortest Path Properties:

1. **Source to destination**: Minimum weight path
2. **Non-negative weights**: Dijkstra's algorithm
3. **Negative weights**: Bellman-Ford algorithm
4. **Negative cycles**: Bellman-Ford detection

## Applications:

### MST Applications:

1. **Network Design**: Minimum cost network
2. **Clustering**: Minimum distance connections
3. **Image Segmentation**: Minimum cut
4. **Circuit Design**: Minimum wire length

### Shortest Path Applications:

1. **GPS Navigation**: Shortest route
2. **Network Routing**: Optimal path
3. **Resource Allocation**: Minimum cost flow
4. **Game Theory**: Optimal strategies

## Implementation Tips:

1. **Priority Queue**: Use for Prim's and Dijkstra's
2. **Union-Find**: Essential for Kruskal's algorithm
3. **Edge List**: Store all edges for Kruskal's
4. **Visited/MST Arrays**: Track included vertices
5. **Distance Arrays**: Store shortest distances

## Common Interview Problems:

1. **Min Cost to Connect All Points** (LeetCode 1584)
2. **Network Delay Time** (Dijkstra's)
3. **Cheapest Flights Within K Stops** (BFS/Dijkstra's)
4. **Path with Minimum Effort** (Modified Dijkstra's)
5. **Swim in Rising Water** (Priority queue)
6. **Minimum Cost to Make at Least One Valid Path** (0-1 BFS)

## Advanced Topics:

- **Floyd-Warshall Algorithm** (All-pairs shortest paths)
- **Johnson's Algorithm** (All-pairs with negative weights)
- **A\* Search Algorithm** (Heuristic-based search)
- **D\* Algorithm** (Dynamic A\* for changing graphs)
- **Minimum Cost Flow** (Network flow with costs)
