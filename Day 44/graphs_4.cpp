#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <climits>
using namespace std;

class Edge {
public:
    int v;
    int w;
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

class Graph {
    int V;
    list<pair<int, int>> *l;
    bool isUndirected;
public:
    Graph(int V, bool isUndirected = true) {
        this->V = V;
        this->isUndirected = isUndirected;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back(make_pair(v, w));
        if (isUndirected) {
            l[v].push_back(make_pair(u, w));
        }
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
        vector<bool> mst(V, false);
        pq.push(make_pair(0, src));
        int totalWeight = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if (!mst[u]) { // if u is not in mst
                mst[u] = true;
                totalWeight += w;
                list<pair<int, int>> neighbors = l[u]; // neighbors of u
                // add neighbors of u to priority queue
                for (pair<int, int> neighbor : neighbors) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (!mst[v]) { // if v is not in mst
                        pq.push(make_pair(weight, v));
                    }
                }
            }
        }

        cout << "Total Cost of MST: " << totalWeight << endl;
    }
};

void dijkstra(vector<vector<Edge>> graph, int src, int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (Edge edge : graph[u]) {
            int v = edge.v;
            int w = edge.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int d : dist) {
        cout << d << " ";
    }
    cout << endl;
}

void bellmanFord(vector<vector<Edge>> graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Edge edge : graph[u]) {
                int v = edge.v;
                int w = edge.w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int d : dist) {
        cout << d << " ";
    }
    cout << endl;
}

int main() {
    // Directed weighted graph for dijkstra
    int V = 6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));
    
    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[4].push_back(Edge(3, 2));
    graph[4].push_back(Edge(5, 5));

    dijkstra(graph, 0, V);

    // Directed weighted graph for bellman ford
    V = 5;
    vector<vector<Edge>> graph2(V);

    graph2[0].push_back(Edge(1, 2));
    graph2[0].push_back(Edge(2, 4));
    
    graph2[1].push_back(Edge(2, -4));

    graph2[2].push_back(Edge(3, 2));

    graph2[3].push_back(Edge(4, 4));

    graph2[4].push_back(Edge(1, -1));

    bellmanFord(graph2, 0, V);

    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.primsAlgo(0);

}