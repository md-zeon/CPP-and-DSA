#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool isUndirected;
public:
    Graph(int V, bool isUndirected = true) {
        this->V = V;
        l = new list<int> [V];
        this->isUndirected = isUndirected;
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (isUndirected) {
            l[v].push_back(u);
        }
    }

    void dfsHelper(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";
        for (auto i : l[v]) {
            if (!visited[i]) {
                dfsHelper(i, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) { // for disconnected graph
            if (!visited[i]) {
                dfsHelper(i, visited);
                cout << endl;
            }
        }
        cout << endl;
    }

    void bfsHelper(int v, vector<bool> &visited) {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for (auto i : l[curr]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void bfs() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) { // for disconnected graph
            if (!visited[i]) {
                bfsHelper(i, visited);
                cout << endl;
            }
        }
        cout << endl;
    }

    bool undirectedCycleHelper(int source, int parent, vector<bool> &visited) {
        visited[source] = true;
        list<int> neighbors = l[source];
        for (int v : neighbors) {
            if (!visited[v]) {
                if (undirectedCycleHelper(v, source, visited)) {
                    return true;
                }
            } else {
                if (v != parent) { // cycle condition
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

    bool directedCycleHelper(int source, vector<bool> &visited, vector<bool> &recPath) {
        visited[source] = true;
        recPath[source] = true;
        list<int> neighbors = l[source];
        for (auto v : neighbors) {
            if (!visited[v]) {
                if (directedCycleHelper(v, visited, recPath)) {
                    return true;
                } else {
                    if (recPath[v]) {
                        return true;
                    }
                }
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
            list<int> neighbors = l[u];

            for (int v : neighbors) {
                if (!visited[v]) {
                    visited[v] = true;
                    color[v] = !color[u];
                    q.push(v);
                } else {
                    if (color[v] == color[u]) {
                        return false;
                    }
                }
            } 
        }
        
        return true;
    }

    void printAllPathsHelperDFS(int src, int dest, vector<bool> &visited, string &path) {
        if (src == dest) {
            cout << path << dest << endl;
            return;
        }
        visited[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];
        for (int v : neighbors) {
            if (!visited[v]) {
                printAllPathsHelperDFS(v, dest, visited, path);
            }
        }
        path = path.substr(0, path.size() - 1);
        visited[src] = false;
    }

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
                if (path.find(to_string(neighbor)) == string::npos) { // Avoid revisiting nodes in the current path
                    q.push({neighbor, path + to_string(neighbor)});
                }
            }
        }
    }


    void printAllPaths(int src, int dest) {
        vector<bool> visited(V, false);
        string path = "";
        printAllPathsHelperDFS(src, dest, visited, path);
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (auto j : l[i]) {
                cout  << "[" << j << "] ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(10);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    // g.dfs();
    // g.bfs();
    // if (g.isCycleUndirected()) {
    //     cout << "Graph contains cycle" << endl;
    // } else {
    //     cout << "Graph doesn't contain cycle" << endl;
    // }
    // g.print();

    // Graph graph(4, false);
    // graph.addEdge(1, 0);
    // graph.addEdge(0, 2);
    // graph.addEdge(2, 3);
    // graph.addEdge(3, 0);


    // if (graph.isCycleDirected()) {
    //     cout << "Directed Graph contains cycle" << endl;
    // } else {
    //     cout << "Directed Graph doesn't contain cycle" << endl;
    // }


    //! Bipartite Graph

    Graph bg(5);
    bg.addEdge(0, 1);
    bg.addEdge(0, 2);
    bg.addEdge(1, 3);
    bg.addEdge(2, 3);
    // bg.addEdge(0, 3);
    
    // if (bg.isBipartite()) {
    //     cout << "Bipartite Graph" << endl;
    // } else {
    //     cout << "Non Bipartite Graph" << endl;
    // }

    //! All paths problem: Print all paths from src to dest for a directed graph
    Graph graph(6, false);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPaths(5, 1);
    graph.printAllPathsBFS(5, 1);


    return 0;
}