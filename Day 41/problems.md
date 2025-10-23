# Day 41: Graph Data Structure & Traversal Algorithms - Problems

## Problem List

### 1. Implement BFS Traversal

- **Description**: Perform breadth-first search traversal on a graph starting from a source node.
- **Constraints**: 1 ≤ V ≤ 10^5, 1 ≤ E ≤ 10^5
- **Example**:
  - Graph: 0-1, 0-2, 1-3, 2-4, 3-4, 3-5, 4-5, 5-6
  - BFS from 0: 0, 1, 2, 3, 4, 5, 6
- **Approach**: Use a queue to visit nodes level by level.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

### 2. Implement DFS Traversal

- **Description**: Perform depth-first search traversal on a graph starting from a source node.
- **Constraints**: 1 ≤ V ≤ 10^5, 1 ≤ E ≤ 10^5
- **Example**:
  - Graph: 0-1, 0-2, 1-3, 2-4, 3-4, 3-5, 4-5, 5-6
  - DFS from 0: 0, 1, 3, 4, 2, 5, 6
- **Approach**: Use recursion or stack to visit nodes depth by depth.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

### 3. Check if Path Exists Between Two Nodes

- **Description**: Check if there is a path between source and destination nodes.
- **Constraints**: 1 ≤ V ≤ 10^5, 1 ≤ E ≤ 10^5
- **Example**:
  - Graph: 0-1, 1-2, 2-3, Source: 0, Dest: 3
  - Output: true
- **Approach**: Use DFS or BFS to search for the destination.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

### 4. Find Shortest Path in Unweighted Graph Using BFS

- **Description**: Find the shortest path length from source to destination in an unweighted graph.
- **Constraints**: 1 ≤ V ≤ 10^5, 1 ≤ E ≤ 10^5
- **Example**:
  - Graph: 0-1, 1-2, 2-3, Source: 0, Dest: 3
  - Output: 3 (0-1-2-3)
- **Approach**: Use BFS, track distance from source.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

### 5. Detect Cycles in Graph Using DFS

- **Description**: Detect if there is a cycle in the graph using DFS.
- **Constraints**: 1 ≤ V ≤ 10^5, 1 ≤ E ≤ 10^5
- **Example**:
  - Graph: 0-1, 1-2, 2-0 (cycle)
  - Output: true
- **Approach**: Use DFS with visited and recursion stack tracking.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

## Additional Challenges

- Count the number of connected components in a graph.
- Find the number of islands in a matrix (BFS/DFS).
- Implement topological sort using DFS.
- Find the shortest path in a weighted graph using Dijkstra's.
- Check if a graph is bipartite using BFS.

## Notes

- Graphs can be represented using adjacency list or matrix.
- BFS uses queue, DFS uses stack or recursion.
- BFS finds shortest path in unweighted graphs.
- DFS is useful for cycle detection and topological sort.
- Always use visited array to avoid infinite loops.
