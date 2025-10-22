/************************************************************
*  Problem: 1584. Min Cost to Connect All Points
*  Link   : https://leetcode.com/problems/min-cost-to-connect-all-points/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-11
*  ----------------------------------------------
*
*  Problem Description:
*  Given an array of points in a 2D plane, find the minimum cost to connect all the points
*  such that the cost of connecting two points is the Manhattan distance between them.
*  You need to return the minimum cost to connect all the points.
*
*  Approach:
*  This problem is equivalent to finding the Minimum Spanning Tree (MST) of a graph where:
*  - Each point is a node.
*  - The edge weight between two nodes is the Manhattan distance between the points.
*  
*  The solution uses **Prim's Algorithm** to construct the MST:
*  1. Start from an arbitrary node (point 0 in this case).
*  2. Use a priority queue to explore the least costly edges that expand the MST.
*  3. For each point, add the edge with the minimum cost that connects it to the MST.
*  4. Continue this process until all points are included in the MST.
*
*  Time Complexity: O(V^2 log V), where V is the number of points (nodes), and each edge is processed in log time due to the priority queue operations.
*  Space Complexity: O(V^2), for storing the distances in the priority queue and the mst array.
*
*  Platform: LeetCode
*  Status  : Solved
************************************************************/


#include <stdio.h>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst (V, false);
        pq.push({0, 0});
        int minCost = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if (!mst[u]) { // if u is not in mst
                mst[u] = true;
                minCost += w;

                for (int v = 0; v < V; v++) {
                    if (u != v) { // if u and v are not same point
                        int weight = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]); // distance between u and v points in 2D plane = |x1 - x2| + |y1 - y2|
                        pq.push({weight, v});
                    }
                }
            }
        }

        return minCost;
    }
};



/************************************************************
*  Problem: 1584. Min Cost to Connect All Points
*  Link   : https://leetcode.com/problems/min-cost-to-connect-all-points/description/
*  Author : Zeanur Rahaman Zeon
*  Date   : 2024-12-11
*  ----------------------------------------------
*
*  Problem Description:
*  Given an array of points in a 2D plane, find the minimum cost to connect all the points
*  such that the cost of connecting two points is the Manhattan distance between them.
*  You need to return the minimum cost to connect all the points.
*
*  Approach:
*  This problem can be solved using **Kruskal's Algorithm** to find the Minimum Spanning Tree (MST).
*  The algorithm works by:
*  1. Constructing a list of all edges, where the edge weight is the Manhattan distance between pairs of points.
*  2. Sorting the edges by their weight (distance).
*  3. Using **Union-Find** (Disjoint Set Union, DSU) to add edges one by one, ensuring no cycles are formed.
*  4. The process stops when we have added \(V-1\) edges to the MST, where \(V\) is the number of points.
*  
*  Time Complexity: O(V^2 \log V), where V is the number of points (nodes). Sorting the edges takes \(O(V^2 \log V)\), 
*  and each Union-Find operation is nearly constant time \(O(\alpha(V))\).
*  
*  Space Complexity: O(V^2) for storing the edge list, and O(V) for the Union-Find data structure.
*
*  Platform: LeetCode
*  Status  : Solved
************************************************************/





#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Union-Find (Disjoint Set Union) class
class DSU {
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
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

private:
    vector<int> parent, rank;
};

class Solution2 {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Create a list of all edges with Manhattan distances
        vector<pair<int, pair<int, int>>> edges; // {distance, {point1, point2}}
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});
            }
        }
        
        // Sort edges by distance
        sort(edges.begin(), edges.end());
        
        // Initialize Union-Find
        DSU dsu(n);
        int mstCost = 0;
        int edgesAdded = 0;
        
        // Process the edges
        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;
            
            if (dsu.find(u) != dsu.find(v)) {
                dsu.unionSet(u, v);
                mstCost += weight;
                edgesAdded++;
                
                if (edgesAdded == n - 1) {
                    break; // All points are connected
                }
            }
        }
        
        return mstCost;
    }
};
