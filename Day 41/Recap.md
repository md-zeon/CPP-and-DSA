# Day 41: Graph Data Structure & Traversal Algorithms

## Topics Covered

- Graph Representation (Adjacency List)
- Breadth First Search (BFS)
- Depth First Search (DFS)
- Path Finding
- Weighted Graphs

## 1. Graph Data Structure

### What is a Graph?

- **Graph** is a non-linear data structure with vertices and edges
- **Vertices/Nodes**: Represent entities
- **Edges**: Represent relationships between entities
- **Types**: Directed, Undirected, Weighted, Unweighted

### Graph Representation - Adjacency List

```cpp
class Graph {
    int V;           // Number of vertices
    list<int> *l;    // Array of lists for adjacency list

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);  // Undirected graph
    }
};
```

### Time Complexity:

- **Add Edge**: O(1)
- **Space**: O(V + E) where V = vertices, E = edges

## 2. Breadth First Search (BFS)

### Algorithm Overview:

- **Level-order traversal** of graph
- Uses **queue** data structure
- Explores all neighbors at present level before moving to next level

### Implementation:

```cpp
void bfs() {
    queue<int> q;
    vector<bool> visited(V, false);

    q.push(0);           // Start from vertex 0
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Visit all unvisited neighbors
        for (int v : l[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
```

### BFS Traversal Order:

For graph with edges: (0-1), (0-2), (1-3), (2-4), (3-4), (3-5), (4-5), (5-6)

**BFS Order**: 0 → 1 → 2 → 3 → 4 → 5 → 6

### Time Complexity: O(V + E)

### Space Complexity: O(V)

## 3. Depth First Search (DFS)

### Algorithm Overview:

- **Depth-first traversal** of graph
- Uses **recursion** (implicit stack) or explicit stack
- Explores as far as possible along each branch before backtracking

### Implementation:

```cpp
void dfsHelper(int u, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : l[u]) {
        if (!visited[v]) {
            dfsHelper(v, visited);
        }
    }
}

void dfs() {
    vector<bool> visited(V, false);
    dfsHelper(0, visited);
}
```

### DFS Traversal Order:

For same graph: **DFS Order**: 0 → 1 → 3 → 4 → 2 → 5 → 6

### Time Complexity: O(V + E)

### Space Complexity: O(V) for recursion stack

## 4. Path Finding

### Problem:

Check if path exists between source and destination vertices.

### Implementation:

```cpp
bool pathHelper(int source, int destination, vector<bool> &visited) {
    if (source == destination) {
        return true;
    }

    visited[source] = true;

    for (int v : l[source]) {
        if (!visited[v]) {
            if (pathHelper(v, destination, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int source, int destination) {
    vector<bool> visited(V, false);
    return pathHelper(source, destination, visited);
}
```

## 5. Weighted Graph

### Representation:

```cpp
class WeightedGraph {
    int V;
    list<pair<int, int>> *l;  // (neighbor, weight)

public:
    WeightedGraph(int V) {
        this->V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }
};
```

### Applications:

- **Network routing** with bandwidth/cost
- **Transportation** with distance/time
- **Social networks** with relationship strength

## Graph Traversal Comparison:

| Feature            | BFS                                 | DFS                            |
| ------------------ | ----------------------------------- | ------------------------------ |
| **Data Structure** | Queue                               | Stack/Recursion                |
| **Traversal**      | Level by level                      | Depth by depth                 |
| **Shortest Path**  | Yes (unweighted)                    | No                             |
| **Memory**         | O(V)                                | O(V) worst case                |
| **Use Cases**      | Shortest path, Connected components | Topological sort, Maze solving |

## Applications of Graph Traversal:

### BFS Applications:

1. **Shortest Path** in unweighted graphs
2. **Connected Components** counting
3. **Social Network Analysis** (friend suggestions)
4. **Web Crawling** (breadth-first crawling)
5. **GPS Navigation** (shortest route)
6. **Network Broadcasting**

### DFS Applications:

1. **Maze Solving** algorithms
2. **Topological Sorting** of dependencies
3. **Path Finding** in puzzle games
4. **Connected Components** in undirected graphs
5. **Cycle Detection** in graphs
6. **Backtracking** problems

## Key Points:

### BFS:

- **Level-order** traversal
- **Queue** based implementation
- **Complete** when all nodes at current level are visited
- **Optimal** for finding shortest path in unweighted graphs

### DFS:

- **Depth-first** traversal
- **Stack/Recursion** based implementation
- **Complete** when entire branch is explored
- **Memory efficient** for tall graphs

## Implementation Considerations:

1. **Visited Array**: Prevents infinite loops in cyclic graphs
2. **Adjacency List**: Efficient for sparse graphs
3. **Error Handling**: Check vertex bounds
4. **Memory Management**: Delete dynamically allocated arrays
5. **Input Format**: Handle various graph input formats

## Common Interview Problems:

1. **Number of Islands** (Matrix as graph)
2. **Course Schedule** (Topological sort)
3. **Clone Graph** (Deep copy with BFS/DFS)
4. **Word Ladder** (Shortest path in word graph)
5. **Pacific Atlantic Water Flow** (Multi-source BFS)
6. **Graph Valid Tree** (No cycles, connected)
7. **Number of Connected Components**

## Advanced Topics:

- **Bidirectional Search** (BFS from both ends)
- **Iterative Deepening DFS** (Memory efficient)
- **A\* Search Algorithm** (Heuristic-based search)
- **Graph Coloring** (Assignment problems)
- **Minimum Spanning Tree** (Prim's, Kruskal's)
