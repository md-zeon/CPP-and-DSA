#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adjList;
    bool isUndirected;
public:
    Graph (int V, bool isUndirected = true) {
        this->V = V;
        this->isUndirected = isUndirected;
        adjList = new list<int>[V];
    }

    void addEdge (int u, int v) {
        adjList[u].push_back(v);
        if (isUndirected) {
            adjList[v].push_back(u);
        }
    }

    void topoLogicalSortHelper(int u, vector<bool> &visited, stack<int> &s) {
        visited[u] = true;

        for (int v : adjList[u]) {
            if (!visited[v]) {
                topoLogicalSortHelper(v, visited, s);
            }
        }
        s.push(u);
    }

    void topologicalSort() { // dfs
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoLogicalSortHelper(i, visited, s);
            }
        }

        // print topological order
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void calculateInDegree(vector<int> &inDegree) {
        for (int u = 0; u < V; u++) {
            for (int v : adjList[u]) {
                inDegree[v]++;
            }
        }
    }

    void topoLogicalSort2() { // Kahn's algorithm
        vector<int> inDegree(V, 0);
        calculateInDegree(inDegree);
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            list<int> neighbors = adjList[u];
            for (int v : neighbors) {
                inDegree[v]--;
                if (inDegree[v] == 0) { // v has no more incoming edges
                    q.push(v);
                }
            }
        }
        cout << endl;

        //! if there is a cycle, inDegree will not be zero
        // for (int i = 0; i < V; i++) {
        //     if (inDegree[i] != 0) {
        //         cout << "There is a cycle in the graph" << endl;
        //         return;
        //     }
        // } 
    }
    

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto x : adjList[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

};

int main () {
    // DAG
    Graph g(6, false);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.topologicalSort();
    g.topoLogicalSort2();

    //! Course Schedule: For given courses & their prerequisites, return if it is possible to finish them or not.
    
    return 0;
}