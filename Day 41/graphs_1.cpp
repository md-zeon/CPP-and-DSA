#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) { // u-----v
        l[u].push_back(v);
        l[v].push_back(u);
    } 

    void print() {
        for (int u = 0; u < V; u++) { // 0, 1, 2, 3, 4
            list<int> neighbors = l[u];
            cout << u << " : ";
            for (int v : neighbors) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfs() { // O(V + E)
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int u = q.front(); // curr vertex
            q.pop();
            cout << u << " ";
            list<int> neighbors = l[u]; // u-----v
            for (int v : neighbors) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &visited) { // O(V + E)
        visited[u] = true;
        cout << u << " ";
        list<int> neighbors = l[u];
        for (int v : neighbors) {
            if (!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs() { // O(V + E)
        vector<bool> visited(V, false);
        dfsHelper(0, visited);
        cout << endl;
    }

    bool pathHelper(int source, int destination, vector<bool> &visited) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        list<int> neighbors = l[source];
        for (int v : neighbors) {
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
};

class WeightedGraph {
    int V;
    list <pair<int, int>> *l; // (neighbour, weight)
public:
    WeightedGraph(int V) {
        this->V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back(make_pair(v, w));
        l[v].push_back(make_pair(u, w));
    }

    void print() {
        for (int u = 0; u < V; u++) { // 0, 1, 2, 3, 4
            list<pair<int, int>> neighbors = l[u];
            cout << u << " : ";
            for (pair<int, int> neighbor : neighbors) {
                cout << neighbor.first << "(" << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.print();
    graph.bfs();
    graph.dfs();
    cout << endl;

    WeightedGraph wgraph(5);
    wgraph.addEdge(0, 1, 5);
    wgraph.addEdge(1, 2, 1);
    wgraph.addEdge(1, 3, 3);
    wgraph.addEdge(2, 3, 1);
    wgraph.addEdge(2, 4, 2);

    // wgraph.print();


    //! HasPath Problem: Tell if path exists from source to destination
    int source, destination;
    cin >> source >> destination;
    if (graph.hasPath(source, destination)) {
        cout << "Path exists" << endl;
    } else {
        cout << "Path does not exist" << endl;
    }
    
    return 0;
}