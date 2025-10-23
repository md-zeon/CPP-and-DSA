# Day 42: Advanced Graph Algorithms

## Topics Covered

- Cycle Detection in Graphs
- Bipartite Graph Checking
- Finding All Paths
- Disconnected Graph Handling

## 1. Cycle Detection in Undirected Graphs

### Problem

Detect if an undirected graph contains a cycle.

### Algorithm

- Use DFS with parent tracking
- If we find a visited neighbor that's not the parent, cycle exists

```cpp
bool undirectedCycleHelper(int source, int parent, vector<bool> &visited) {
    visited[source] = true;

    for (int v : l[source]) {
        if (!visited[v]) {
            if (undirectedCycleHelper(v, source, visited)) {
                return true;
            }
        } else {
            if (v != parent) { // Found cycle
                return true;
            }
        }
    }
    return false;
}

bool isCycleUndirected() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (undirectedCycleHelper(i, -1, visited)) {
                return true;
            }
        }
    }
    return false;
}
```

### Time Complexity: O(V + E)

### Space Complexity: O(V)

## 2. Cycle Detection in Directed Graphs

### Problem:

Detect if a directed graph contains a cycle.

### Algorithm:

- Use DFS with two arrays: visited and recursion path
- If we find a node in current recursion path, cycle exists

```cpp
bool directedCycleHelper(int source, vector<bool> &visited, vector<bool> &recPath) {
    visited[source] = true;
    recPath[source] = true;

    for (int v : l[source]) {
        if (!visited[v]) {
            if (directedCycleHelper(v, visited, recPath)) {
                return true;
            }
        } else if (recPath[v]) {
            return true; // Cycle found
        }
    }
    recPath[source] = false;
    return false;
}

bool isCycleDirected() {
    vector<bool> visited(V, false);
    vector<bool> recPath(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (directedCycleHelper(i, visited, recPath)) {
                return true;
            }
        }
    }
    return false;
}
```

### Time Complexity: O(V + E)

### Space Complexity: O(V)

## 3. Bipartite Graph

### What is Bipartite Graph?

- Graph whose vertices can be divided into two disjoint sets
- No two vertices within same set are adjacent
- Can be colored using two colors

### Algorithm:

- Use BFS with coloring
- Assign opposite color to adjacent vertices
- If same color found for adjacent vertices, not bipartite

```cpp
bool isBipartite() {
    vector<bool> visited(V, false);
    queue<int> q;
    vector<int> color(V, -1);

    q.push(0);
    color[0] = 0;
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : l[u]) {
            if (!visited[v]) {
                visited[v] = true;
                color[v] = !color[u]; // Opposite color
                q.push(v);
            } else {
                if (color[v] == color[u]) {
                    return false; // Same color found
                }
            }
        }
    }

    return true;
}
```

### Applications:

- **Scheduling problems** (tasks vs workers)
- **Network flow** problems
- **Map coloring** verification

## 4. Finding All Paths from Source to Destination

### Problem:

Print all possible paths from source to destination in a graph.

### DFS Approach:

```cpp
void printAllPathsHelperDFS(int src, int dest, vector<bool> &visited, string &path) {
    if (src == dest) {
        cout << path << dest << endl;
        return;
    }

    visited[src] = true;
    path += to_string(src);

    for (int v : l[src]) {
        if (!visited[v]) {
            printAllPathsHelperDFS(v, dest, visited, path);
        }
    }

    // Backtrack
    path = path.substr(0, path.size() - 1);
    visited[src] = false;
}
```

### BFS Approach (Level-wise paths):

```cpp
void printAllPathsBFS(int src, int dest) {
    queue<pair<int, string>> q;
    q.push({src, to_string(src)});

    while (!q.empty()) {
        int curr = q.front().first;
        string path = q.front().second;
        q.pop();

        if (curr == dest) {
            cout << path << endl;
            continue;
        }

        for (auto neighbor : l[curr]) {
            if (path.find(to_string(neighbor)) == string::npos) {
                q.push({neighbor, path + to_string(neighbor)});
            }
        }
    }
}
```

## 5. Handling Disconnected Graphs

### Problem:

Many graph algorithms need to handle disconnected components.

### Solution:

- Iterate through all vertices in main function
- Process each unvisited vertex as starting point

```cpp
void dfs() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsHelper(i, visited);
            cout << endl; // New component
        }
    }
}

void bfs() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfsHelper(i, visited);
            cout << endl; // New component
        }
    }
}
```

## Graph Types Summary:

| Graph Type     | Cycle Detection     | Bipartite Check   | Applications    |
| -------------- | ------------------- | ----------------- | --------------- |
| **Undirected** | Parent tracking     | BFS coloring      | Social networks |
| **Directed**   | Recursion path      | DAG properties    | Task scheduling |
| **Weighted**   | Modified algorithms | Cost optimization | Network routing |
| **Unweighted** | Standard algorithms | Connectivity      | Basic traversal |

## Key Algorithms Comparison:

### Cycle Detection:

- **Undirected**: Parent tracking in DFS
- **Directed**: Recursion path tracking in DFS

### Path Finding:

- **Single Path**: Standard DFS/BFS
- **All Paths**: Backtracking with visited reset
- **Shortest Path**: BFS (unweighted), Dijkstra (weighted)

## Applications of Advanced Graph Algorithms:

### Cycle Detection:

1. **Deadlock detection** in operating systems
2. **Constraint satisfaction** problems
3. **Circuit detection** in digital electronics
4. **Dependency resolution** in package managers

### Bipartite Graphs:

1. **Job scheduling** (jobs vs machines)
2. **Social network analysis** (dating recommendations)
3. **Map coloring** verification
4. **Network flow** algorithms

### All Paths:

1. **Network routing** (all possible routes)
2. **Game solving** (all possible moves)
3. **Path counting** in graphs
4. **Reliability analysis** (alternative paths)

## Implementation Tips:

1. **Visited Arrays**: Always use for cycle detection and traversal
2. **Parent Tracking**: Essential for undirected cycle detection
3. **Recursion Path**: Required for directed cycle detection
4. **Backtracking**: Reset visited state for all paths
5. **Component Handling**: Process all vertices for disconnected graphs

## Common Interview Problems:

1. **Detect Cycle in Graph** (Undirected/Directed)
2. **Check Bipartite Graph**
3. **Find All Paths from Source to Destination**
4. **Number of Connected Components**
5. **Course Schedule** (Topological sort with cycle detection)
6. **Word Ladder** (Shortest path with transformations)
7. **Clone Graph** (Deep copy of graph)

## Advanced Topics:

- **Topological Sort** using DFS/BFS
- **Strongly Connected Components** (Kosaraju's algorithm)
- **Bridges and Articulation Points**
- **Eulerian Path** and **Circuit**
- **Minimum Spanning Tree** (Kruskal's, Prim's)
- **Shortest Path Algorithms** (Dijkstra, Bellman-Ford, Floyd-Warshall)
