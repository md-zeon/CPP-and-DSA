/************************************************************
*  Problem: 210. Course Schedule II
*  Link   : https://leetcode.com/problems/course-schedule-ii/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-07
*  ----------------------------------------------

*  Problem Description:
*  There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`.
*  Some courses may have prerequisites represented as a list `prerequisites`, where 
*  `prerequisites[i] = [a, b]` indicates that you must take course `b` before course `a`.
*  
*  Return the ordering of courses you should take to finish all courses. If it is impossible 
*  to finish all courses, return an empty array.

*  Approach:
*  - The problem is solved using **graph traversal techniques**:
*    1. **Cycle Detection:** Use Depth First Search (DFS) to check for cycles in the course dependency graph.
*       If a cycle exists, it is impossible to determine a valid course order.
*    2. **Topological Sorting:** After ensuring the graph has no cycles, perform topological sorting 
*       using DFS to determine a valid course order.
*    3. **Stack:** Use a stack to store courses in topological order as they are fully processed.

*  Time Complexity : O(V + E), where V is the number of courses and E is the number of prerequisites.
*  Space Complexity: O(V + E), for the adjacency list, visited arrays, and recursion stack.

*  Platform: LeetCode
*  Status  : Solved
************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Function to check for cycles in the graph
    bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &graph) {
        visited[src] = true;
        recPath[src] = true;

        for (int v : graph[src]) {
            if (!visited[v]) {
                if (isCycle(v, visited, recPath, graph)) {
                    return true;
                }
            } else if (recPath[v]) { // Cycle detected
                return true;
            }
        }
        recPath[src] = false; // Remove node from recursion stack
        return false;
    }

    // Function for topological sorting using DFS
    void topoLogicalSort(int src, vector<bool> &visited, stack<int> &s, vector<vector<int>> &graph) {
        visited[src] = true;

        for (int v : graph[src]) {
            if (!visited[v]) {
                topoLogicalSort(v, visited, s, graph);
            }
        }
        s.push(src); // Add course to stack after processing all dependencies
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // Step 1: Build adjacency list representation of the graph
        vector<vector<int>> graph(numCourses);
        for (auto &edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        // Step 2: Detect cycles in the graph
        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCycle(i, visited, recPath, graph)) {
                    return {}; // Return empty vector if a cycle is detected
                }
            }
        }

        // Step 3: Perform topological sort
        fill(visited.begin(), visited.end(), false); // Reset visited array
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                topoLogicalSort(i, visited, s, graph);
            }
        }

        // Step 4: Build result from the stack
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
