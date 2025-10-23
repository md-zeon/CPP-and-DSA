# Day 43: Topological Sort & Course Schedule Problems

## Topics Covered

- Topological Sort (DFS & BFS)
- Course Schedule Problems
- Directed Acyclic Graph (DAG)
- Kahn's Algorithm
- Cycle Detection in Course Dependencies

## 1. Topological Sort

### What is Topological Sort?

- **Linear ordering** of vertices in a Directed Acyclic Graph (DAG)
- Vertex **u** comes before vertex **v** if there's a directed edge from u to v
- Only possible for **DAGs** (graphs without cycles)

### Applications:

1. **Course scheduling** (prerequisites)
2. **Task scheduling** (dependencies)
3. **Build systems** (compilation order)
4. **Version control** (merge order)

## 2. Topological Sort using DFS

### Algorithm:

1. **DFS traversal** with stack to store finishing times
2. **Push node to stack** after processing all its dependencies
3. **Stack contains** topological order when reversed

```cpp
void topoLogicalSortHelper(int u, vector<bool> &visited, stack<int> &s) {
    visited[u] = true;

    for (int v : adjList[u]) {
        if (!visited[v]) {
            topoLogicalSortHelper(v, visited, s);
        }
    }
    s.push(u); // Push after processing dependencies
}

void topologicalSort() {
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topoLogicalSortHelper(i, visited, s);
        }
    }

    // Print in topological order
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
```

### Time Complexity: O(V + E)

### Space Complexity: O(V)

## 3. Kahn's Algorithm (BFS-based Topological Sort)

### Algorithm:

1. **Calculate in-degrees** for all vertices
2. **Enqueue** vertices with in-degree 0
3. **Process** vertices in queue, reduce in-degrees of neighbors
4. **Enqueue** new vertices with in-degree 0

```cpp
void calculateInDegree(vector<int> &inDegree) {
    for (int u = 0; u < V; u++) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }
}

void topoLogicalSort2() {
    vector<int> inDegree(V, 0);
    calculateInDegree(inDegree);
    queue<int> q;

    // Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
}
```

### Time Complexity: O(V + E)

### Space Complexity: O(V)

## 4. Course Schedule I (LeetCode 207)

### Problem:

Determine if it's possible to finish all courses given prerequisites.

### Approach:

1. **Model as graph**: Courses as nodes, prerequisites as directed edges
2. **Cycle detection**: If cycle exists, impossible to finish
3. **Return boolean**: true if no cycle, false otherwise

```cpp
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    for (auto &edge : prerequisites) {
        adjList[edge[1]].push_back(edge[0]); // b -> a (b before a)
    }

    // Cycle detection using DFS
    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (isCycle(i, visited, recPath, adjList)) {
                return false;
            }
        }
    }
    return true;
}
```

## 5. Course Schedule II (LeetCode 210)

### Problem:

Return the ordering of courses to finish all courses, or empty array if impossible.

### Approach:

1. **Cycle detection** first (same as Course Schedule I)
2. **Topological sort** if no cycle exists
3. **Return course order** from topological sort

```cpp
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Step 1: Build adjacency list
    vector<vector<int>> graph(numCourses);
    for (auto &edge : prerequisites) {
        graph[edge[1]].push_back(edge[0]);
    }

    // Step 2: Detect cycles
    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (isCycle(i, visited, recPath, graph)) {
                return {}; // Return empty if cycle detected
            }
        }
    }

    // Step 3: Topological sort
    fill(visited.begin(), visited.end(), false);
    stack<int> s;

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            topoLogicalSort(i, visited, s, graph);
        }
    }

    // Step 4: Build result
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
```

## 6. In-Degree Calculation

### Purpose:

- **Count incoming edges** for each vertex
- **Essential for Kahn's algorithm**
- **Detect cycles** (non-zero in-degrees after processing)

```cpp
void calculateInDegree(vector<int> &inDegree) {
    for (int u = 0; u < V; u++) {
        for (int v : adjList[u]) {
            inDegree[v]++;
        }
    }
}
```

## Comparison: DFS vs BFS Topological Sort

| Feature             | DFS Approach       | BFS (Kahn's) Approach |
| ------------------- | ------------------ | --------------------- |
| **Method**          | Stack-based        | Queue-based           |
| **Cycle Detection** | During traversal   | After traversal       |
| **Implementation**  | Recursive          | Iterative             |
| **Memory**          | Recursion stack    | Queue                 |
| **Order**           | Reverse post-order | Level by level        |

## Key Concepts:

### Directed Acyclic Graph (DAG):

- **No cycles** in the graph
- **Topological order** always exists
- **Linear extension** of partial order

### In-Degree:

- **Number of incoming edges** to a vertex
- **Zero in-degree** vertices are starting points
- **Source vertices** in the graph

### Cycle Detection in Course Scheduling:

- **Cycle means deadlock** in dependencies
- **Impossible to schedule** if cycle exists
- **DFS with recursion path** for detection

## Applications:

### Course Scheduling:

1. **University course planning**
2. **Training program sequencing**
3. **Certification requirements**

### Task Management:

1. **Project planning** with dependencies
2. **Build systems** (Make, Maven)
3. **Workflow management**

### Other Applications:

1. **Spreadsheet calculation** order
2. **Instruction scheduling** in compilers
3. **Package installation** order

## Implementation Tips:

1. **Adjacency List**: Use vector of vectors for directed graphs
2. **Visited Arrays**: Separate arrays for visited and recursion path
3. **Stack for DFS**: Push nodes after processing dependencies
4. **Queue for BFS**: Process nodes with zero in-degree first
5. **Cycle Detection**: Check both visited and recursion path

## Common Interview Problems:

1. **Course Schedule** (LeetCode 207)
2. **Course Schedule II** (LeetCode 210)
3. **Alien Dictionary** (Topological sort with custom order)
4. **Minimum Time to Complete Courses**
5. **Parallel Courses** (Multiple starting points)
6. **Longest Chain** (Job sequencing)
7. **Build Dependencies** (Package management)

## Advanced Topics:

- **Multiple Topological Orders** (All possible valid orders)
- **Critical Path Method** (Project management)
- **Parallel Topological Sort** (Multiple processors)
- **Topological Sort with Constraints** (Partial orders)
