/************************************************************
*  Problem: 207. Course Schedule
*  Link   : https://leetcode.com/problems/course-schedule/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-07
*  ----------------------------------------------

*  Problem Description:
*  Given the number of courses `numCourses` and an array of prerequisites where each pair 
*  [a, b] indicates that course `a` depends on course `b`, determine if it's possible to 
*  finish all courses. This boils down to detecting if there is a cycle in a directed 
*  graph representation of the courses.

*  Approach:
*  - Model the problem as a directed graph where each course is a node and each prerequisite 
*    pair [a, b] represents a directed edge from `b` to `a`.
*  - Use Depth First Search (DFS) to detect cycles:
*    - Traverse through the entire edge list to identify neighbors.
*    - Maintain a `visited` array to track nodes that have been processed.
*    - Use a `recPath` (recursion stack) array to detect back edges (cycles).
*  - If a cycle is found during traversal, return `false`.
*  - Otherwise, return `true`.

*  Time Complexity:
*  - Traversing the edge list for neighbors: O(V × E), where `V` is the number of courses 
*    and `E` is the number of prerequisites.
*  - Overall: O(V × E).

*  Space Complexity:
*  - Recursion stack and visited arrays: O(V).
*  - Overall: O(V).

*  Platform: LeetCode
*  Status  : Solved
************************************************************/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>>& graph) {
        visited[src] = true;
        recPath[src] = true;

        for (int i = 0; i < graph.size(); i++) {
            int u = graph[i][1];
            int v = graph[i][0];

            if (u == src) {
                if (!visited[v]) {
                    if (isCycle(v, visited, recPath, graph)) {
                        return true;
                    }
                } else {
                    if (recPath[v]) {
                        return true;
                    }
                }
            }
        }
        recPath[src] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses; // [v, u] v <-- u
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if(isCycle(i, visited, recPath, prerequisites)) {
                    return false;
                }
            }
        }
        return true;
    }
};


/************************************************************
*  Problem: 207. Course Schedule
*  Link   : https://leetcode.com/problems/course-schedule/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-07
*  ----------------------------------------------

*  Problem Description:
*  Given the number of courses `numCourses` and an array of prerequisites where each pair 
*  [a, b] indicates that course `a` depends on course `b`, determine if it's possible to 
*  finish all courses. This boils down to detecting if there is a cycle in a directed 
*  graph representation of the courses.

*  Approach:
*  - Model the problem as a directed graph where each course is a node and each prerequisite 
*    pair [a, b] represents a directed edge from `b` to `a`.
*  - Build an adjacency list representation of the graph for efficient traversal.
*  - Use Depth First Search (DFS) to detect cycles:
*    - Maintain a `visited` array to track nodes that have been processed.
*    - Use a `recPath` (recursion stack) array to detect back edges (cycles).
*  - If a cycle is found during traversal, return `false`.
*  - Otherwise, return `true`.

*  Time Complexity:
*  - Building the adjacency list: O(E), where `E` is the number of prerequisites.
*  - DFS traversal: O(V + E), where `V` is the number of courses.
*  - Overall: O(V + E).

*  Space Complexity:
*  - Adjacency list storage: O(V + E).
*  - Recursion stack and visited arrays: O(V).
*  - Overall: O(V + E).

*  Platform: LeetCode
*  Status  : Solved
************************************************************/


class Solution2 {
    bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>>& adjList) {
        visited[src] = true;
        recPath[src] = true;

        for (int neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                if (isCycle(neighbor, visited, recPath, adjList)) {
                    return true;
                }
            } else if (recPath[neighbor]) {
                return true;
            }
        }
        recPath[src] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (auto &edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]); // u --> v
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if(isCycle(i, visited, recPath, adjList)) {
                    return false;
                }
            }
        }
        return true;
    }
};