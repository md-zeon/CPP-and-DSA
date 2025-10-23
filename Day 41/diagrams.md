# Day 41: Graphs Visual Diagrams

## 1. Graph Representation

### 1.1 Adjacency List Representation

```mermaid
graph TD
    A[0] --> B[1]
    A --> C[2]
    B --> D[3]
    C --> E[4]
    D --> F[4]
    D --> G[5]
    E --> H[5]
    G --> I[6]

    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
    style E fill:#fce4ec
    style G fill:#ffebee
    style I fill:#ffecb3
```

**Adjacency List:**

- 0: [1, 2]
- 1: [0, 3]
- 2: [0, 4]
- 3: [1, 4, 5]
- 4: [2, 3, 5]
- 5: [3, 4, 6]
- 6: [5]

### 1.2 Adjacency Matrix Representation

```
    0  1  2  3  4  5  6
  +---------------------
0 | 0  1  1  0  0  0  0
1 | 1  0  0  1  0  0  0
2 | 1  0  0  0  1  0  0
3 | 0  1  0  0  1  1  0
4 | 0  0  1  1  0  1  0
5 | 0  0  0  1  1  0  1
6 | 0  0  0  0  0  1  0
```

## 2. Graph Traversal Algorithms

### 2.1 Breadth-First Search (BFS)

```mermaid
graph TD
    A[Start: 0<br/>Queue: []<br/>Visited: [0]] --> B[Visit 1<br/>Queue: [2]<br/>Visited: [0,1]]
    B --> C[Visit 2<br/>Queue: [3,4]<br/>Visited: [0,1,2]]
    C --> D[Visit 3<br/>Queue: [4,4,5]<br/>Visited: [0,1,2,3]]
    D --> E[Visit 4<br/>Queue: [4,5,5]<br/>Visited: [0,1,2,3,4]]
    E --> F[Visit 5<br/>Queue: [4,5,6]<br/>Visited: [0,1,2,3,4,5]]
    F --> G[Visit 6<br/>Queue: [4,5]<br/>Visited: [0,1,2,3,4,5,6]]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
    style G fill:#c8e6c9
```

**BFS Order:** 0 → 1 → 2 → 3 → 4 → 5 → 6

### 2.2 Depth-First Search (DFS)

```mermaid
graph TD
    A[Start: 0<br/>Stack: []<br/>Visited: [0]] --> B[Visit 1<br/>Stack: [2]<br/>Visited: [0,1]]
    B --> C[Visit 3<br/>Stack: [2,4]<br/>Visited: [0,1,3]]
    C --> D[Visit 4<br/>Stack: [2,4,5]<br/>Visited: [0,1,3,4]]
    D --> E[Visit 5<br/>Stack: [2,4,5,6]<br/>Visited: [0,1,3,4,5]]
    E --> F[Visit 6<br/>Stack: [2,4,5]<br/>Visited: [0,1,3,4,5,6]]
    F --> G[Backtrack to 5<br/>Stack: [2,4]<br/>Visited: [0,1,3,4,5,6]]
    G --> H[Backtrack to 4<br/>Stack: [2]<br/>Visited: [0,1,3,4,5,6]]
    H --> I[Backtrack to 2<br/>Stack: []<br/>Visited: [0,1,3,4,5,6]]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
    style G fill:#c8e6c9
    style H fill:#c8e6c9
    style I fill:#c8e6c9
```

**DFS Order:** 0 → 1 → 3 → 4 → 5 → 6 → 2

## 3. Weighted Graph

### 3.1 Weighted Graph Structure

```mermaid
graph TD
    A[0] -->|5| B[1]
    A -->|3| C[2]
    B -->|1| D[3]
    C -->|2| E[4]
    D -->|4| F[4]
    D -->|6| G[5]
    E -->|1| H[5]

    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
    style E fill:#fce4ec
    style G fill:#ffebee
    style H fill:#ffecb3
```

**Weighted Adjacency List:**

- 0: [(1,5), (2,3)]
- 1: [(0,5), (3,1)]
- 2: [(0,3), (4,2)]
- 3: [(1,1), (4,4), (5,6)]
- 4: [(2,2), (3,4), (5,1)]
- 5: [(3,6), (4,1)]

## 4. Graph Types

### 4.1 Undirected Graph

```mermaid
graph TD
    A[0] --- B[1]
    A --- C[2]
    B --- D[3]
    C --- E[4]
    D --- F[4]
    D --- G[5]

    style A fill:#e8f5e8
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#e8f5e8
    style G fill:#e8f5e8
```

**Properties:** Bidirectional edges, no direction

### 4.2 Directed Graph (Digraph)

```mermaid
graph TD
    A[0] --> B[1]
    A --> C[2]
    B --> D[3]
    C --> E[4]
    D --> F[4]
    D --> G[5]
    F --> H[5]

    style A fill:#fff3e0
    style B fill:#fff3e0
    style C fill:#fff3e0
    style D fill:#fff3e0
    style E fill:#fff3e0
    style F fill:#fff3e0
    style G fill:#fff3e0
    style H fill:#fff3e0
```

**Properties:** Unidirectional edges, direction matters

### 4.3 Cyclic Graph

```mermaid
graph TD
    A[0] --> B[1]
    B --> C[2]
    C --> D[0]

    style A fill:#fce4ec
    style B fill:#fce4ec
    style C fill:#fce4ec
    style D fill:#fce4ec
```

**Cycle:** 0 → 1 → 2 → 0

### 4.4 Acyclic Graph (DAG)

```mermaid
graph TD
    A[0] --> B[1]
    A --> C[2]
    B --> D[3]
    C --> E[4]
    D --> F[5]
    E --> G[5]

    style A fill:#ffebee
    style B fill:#ffebee
    style C fill:#ffebee
    style D fill:#ffebee
    style E fill:#ffebee
    style F fill:#ffebee
    style G fill:#ffebee
```

**Properties:** No cycles, topological ordering possible

## 5. Connected Components

### 5.1 Connected Graph

```mermaid
graph TD
    A[0] --- B[1]
    A --- C[2]
    B --- D[3]
    C --- E[4]
    D --- F[5]
    E --- G[6]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
    style F fill:#e3f2fd
    style G fill:#e3f2fd
```

**Connected Components:** 1

### 5.2 Disconnected Graph

```mermaid
graph TD
    A[0] --- B[1]
    A --- C[2]
    D[3] --- E[4]
    F[5] --- G[6]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#ffcdd2
    style E fill:#ffcdd2
    style F fill:#ffebee
    style G fill:#ffebee
```

**Connected Components:** 3

## 6. Shortest Path Algorithms

### 6.1 BFS Shortest Path in Unweighted Graph

```mermaid
graph TD
    A[0] -->|1| B[1]
    A -->|1| C[2]
    B -->|1| D[3]
    C -->|1| E[4]
    D -->|1| F[5]
    E -->|1| G[6]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
    style G fill:#c8e6c9
```

**Shortest Path from 0 to 6:** 0 → 2 → 4 → 6 (Distance: 3)

### 6.2 Dijkstra's Algorithm (Weighted)

```mermaid
graph TD
    A[0] -->|4| B[1]
    A -->|2| C[2]
    B -->|3| D[3]
    C -->|1| E[4]
    D -->|5| F[5]
    E -->|2| G[6]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
    style G fill:#c8e6c9
```

**Shortest Path from 0 to 6:** 0 → 2 → 4 → 6 (Distance: 5)

## 7. Minimum Spanning Tree (MST)

### 7.1 Kruskal's Algorithm

```mermaid
graph TD
    A[0] -->|2| B[1]
    B -->|3| C[2]
    C -->|1| D[3]
    D -->|4| E[4]
    E -->|5| F[5]

    style A fill:#e8f5e8
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#e8f5e8
```

**MST Edges:** (0-1:2), (2-3:1), (3-4:4), (1-2:3), (4-5:5)
**Total Weight:** 15

### 7.2 Prim's Algorithm

```mermaid
graph TD
    A[0] -->|2| B[1]
    B -->|3| C[2]
    C -->|1| D[3]
    D -->|4| E[4]
    E -->|5| F[5]

    style A fill:#e8f5e8
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#e8f5e8
    style F fill:#e8f5e8
```

**MST Construction Order:** 0 → 1 → 2 → 3 → 4 → 5

## 8. Graph Problems Visualization

### 8.1 Cycle Detection

```mermaid
graph TD
    A[0] --> B[1]
    B --> C[2]
    C --> D[0]

    style A fill:#ffcdd2
    style B fill:#ffcdd2
    style C fill:#ffcdd2
    style D fill:#ffcdd2
```

**Cycle Detected:** 0 → 1 → 2 → 0

### 8.2 Bipartite Graph (2-Colorable)

```mermaid
graph TD
    A[0] --> B[1]
    A --> C[2]
    B --> D[3]
    C --> E[4]

    style A fill:#c8e6c9
    style B fill:#e3f2fd
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#e3f2fd
```

**Color Assignment:** 0:Red, 1:Blue, 2:Red, 3:Red, 4:Blue

### 8.3 Topological Sort (DAG)

```mermaid
graph TD
    A[0] --> B[1]
    A --> C[2]
    B --> D[3]
    C --> E[4]
    D --> F[5]
    E --> G[5]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
    style F fill:#e3f2fd
    style G fill:#e3f2fd
```

**Topological Order:** 0 → 1 → 2 → 3 → 4 → 5

## 9. Graph Memory Layout

### Adjacency List Memory

```
Vertex 0: [1, 2] -> Next: [0, 3] -> Next: [0, 4] -> Next: [1, 4, 5] -> ...
Vertex 1: [0, 3] -> Next: [2, 4] -> Next: [0, 4] -> Next: [2, 3, 5] -> ...
```

### Adjacency Matrix Memory

```
Row 0: [0, 1, 1, 0, 0, 0, 0]
Row 1: [1, 0, 0, 1, 0, 0, 0]
Row 2: [1, 0, 0, 0, 1, 0, 0]
Row 3: [0, 1, 0, 0, 1, 1, 0]
...
```

## 10. Graph Applications

### 10.1 Social Network

```mermaid
graph TD
    A[Alice] --- B[Bob]
    A --- C[Charlie]
    B --- D[Diana]
    C --- E[Eve]
    D --- F[Frank]
    E --- G[Grace]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
    style F fill:#e3f2fd
    style G fill:#e3f2fd
```

**Friendship Graph:** Nodes = People, Edges = Friendships

### 10.2 Computer Network

```mermaid
graph TD
    A[Router A] --- B[Router B]
    A --- C[Router C]
    B --- D[Router D]
    C --- E[Router E]
    D --- F[Computer 1]
    E --- G[Computer 2]

    style A fill:#fff3e0
    style B fill:#fff3e0
    style C fill:#fff3e0
    style D fill:#fff3e0
    style E fill:#fff3e0
    style F fill:#e8f5e8
    style G fill:#e8f5e8
```

**Network Topology:** Routers connected in mesh

### 10.3 Dependency Graph

```mermaid
graph TD
    A[Foundation] --> B[Frame]
    A --> C[Utilities]
    B --> D[Walls]
    C --> E[Electrical]
    D --> F[Roof]
    E --> G[Interior]

    style A fill:#fce4ec
    style B fill:#fce4ec
    style C fill:#fce4ec
    style D fill:#fce4ec
    style E fill:#fce4ec
    style F fill:#fce4ec
    style G fill:#fce4ec
```

**Construction Dependencies:** Must follow topological order

## 11. Graph Algorithm Comparison

| Algorithm          | Time Complexity  | Space Complexity | Use Case                            |
| ------------------ | ---------------- | ---------------- | ----------------------------------- |
| **BFS**            | O(V + E)         | O(V)             | Shortest path in unweighted graph   |
| **DFS**            | O(V + E)         | O(V)             | Topological sort, cycle detection   |
| **Dijkstra**       | O((V + E) log V) | O(V)             | Shortest path in weighted graph     |
| **Bellman-Ford**   | O(V × E)         | O(V)             | Shortest path with negative weights |
| **Floyd-Warshall** | O(V³)            | O(V²)            | All pairs shortest paths            |
| **Kruskal**        | O(E log E)       | O(V + E)         | Minimum spanning tree               |
| **Prim**           | O((V + E) log V) | O(V)             | Minimum spanning tree               |

## 12. When to Use Graphs

### ✅ Good Choice

- Modeling relationships and connections
- Path finding and routing problems
- Network analysis and optimization
- Dependency management
- Social network analysis

### ❌ Avoid When

- Simple linear data processing
- Memory constraints are severe
- Hierarchical data (use trees)
- Key-value storage (use hash tables)

## 13. Advanced Graph Concepts

### 13.1 Strongly Connected Components

```mermaid
graph TD
    A[0] --> B[1]
    B --> C[2]
    C --> D[0]
    E[3] --> F[4]
    F --> G[5]
    G --> H[3]

    style A fill:#ffebee
    style B fill:#ffebee
    style C fill:#ffebee
    style D fill:#ffebee
    style E fill:#e8f5e8
    style F fill:#e8f5e8
    style G fill:#e8f5e8
    style H fill:#e8f5e8
```

**SCC 1:** {0, 1, 2}
**SCC 2:** {3, 4, 5}

### 13.2 Graph Coloring

```mermaid
graph TD
    A[0<br/>Red] --- B[1<br/>Blue]
    A --- C[2<br/>Blue]
    B --- D[3<br/>Red]
    C --- E[4<br/>Red]

    style A fill:#ffcdd2
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#ffcdd2
    style E fill:#ffcdd2
```

**3-Colorable:** Red, Blue, Red

## 14. Interview Tips Visualization

### 14.1 Common Graph Patterns

```mermaid
graph TD
    A[Understand Problem] --> B[Identify Graph Type]
    B --> C[Choose Representation]
    C --> D[Select Algorithm]
    D --> E[Analyze Complexity]
    E --> F[Handle Edge Cases]

    style A fill:#c8e6c9
    style B fill:#c8e6c9
    style C fill:#c8e6c9
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#c8e6c9
```

### 14.2 Edge Cases to Consider

```mermaid
graph TD
    A[Empty Graph<br/>V=0, E=0] --> B[Single Node<br/>V=1, E=0]
    A --> C[Two Nodes<br/>Connected/Disconnected]
    B --> D[Complete Graph<br/>All nodes connected]
    C --> E[Self Loops<br/>Node connected to itself]
    D --> F[Multiple Components<br/>Disconnected graph]

    style A fill:#ffebee
    style B fill:#ffebee
    style C fill:#ffebee
    style D fill:#ffebee
    style E fill:#ffebee
    style F fill:#ffebee
```

## 15. Performance Comparison

### Memory Usage

| Graph Type                 | Adjacency List | Adjacency Matrix |
| -------------------------- | -------------- | ---------------- |
| **Sparse Graph** (E << V²) | O(V + E)       | O(V²)            |
| **Dense Graph** (E ≈ V²)   | O(V + E)       | O(V²)            |
| **Space Efficient**        | ✅ Yes         | ❌ No            |

### Time Complexity

| Operation       | Adjacency List | Adjacency Matrix |
| --------------- | -------------- | ---------------- |
| **Add Edge**    | O(1)           | O(1)             |
| **Remove Edge** | O(degree)      | O(1)             |
| **Check Edge**  | O(degree)      | O(1)             |
| **Space**       | O(V + E)       | O(V²)            |

## 16. Real-World Applications

### 16.1 Google Maps Routing

```mermaid
graph TD
    A[Source] -->|10| B[City A]
    A -->|15| C[City B]
    B -->|5| D[City C]
    C -->|8| E[City D]
    D -->|3| F[Destination]
    E -->|6| G[Destination]

    style A fill:#e3f2fd
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#e3f2fd
    style E fill:#e3f2fd
    style F fill:#ffcdd2
    style G fill:#ffcdd2
```

**Shortest Path:** Source → City A → City C → Destination

### 16.2 Social Network Analysis

```mermaid
graph TD
    A[User A<br/>Influencer] --> B[User B<br/>Follower]
    A --> C[User C<br/>Follower]
    B --> D[User D<br/>Friend]
    C --> E[User E<br/>Friend]
    D --> F[User F<br/>Mutual]

    style A fill:#ffebee
    style B fill:#e3f2fd
    style C fill:#e3f2fd
    style D fill:#c8e6c9
    style E fill:#c8e6c9
    style F fill:#fff3e0
```

**Analysis:** Influence propagation, community detection

### 16.3 Compiler Optimization

```mermaid
graph TD
    A[Variable A] --> B[Instruction 1]
    A --> C[Instruction 2]
    B --> D[Variable B]
    C --> E[Variable C]
    D --> F[Output]
    E --> G[Output]

    style A fill:#fce4ec
    style B fill:#fce4ec
    style C fill:#fce4ec
    style D fill:#fce4ec
    style E fill:#fce4ec
    style F fill:#e8f5e8
    style G fill:#e8f5e8
```

**Dependency Graph:** For register allocation and optimization
