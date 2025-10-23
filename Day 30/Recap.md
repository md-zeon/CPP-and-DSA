# Day 30: Greedy Algorithms

## Topics Covered

- **Greedy Strategy**: Making locally optimal choices
- **Activity Selection**: Scheduling problems with greedy approach
- **Fractional Knapsack**: Optimization with greedy method
- **Huffman Coding**: Data compression using greedy algorithm
- **Job Sequencing**: Scheduling jobs to maximize profit
- **Minimum Spanning Tree**: Kruskal's and Prim's algorithms

## Key Concepts

1. **Greedy Choice Property**: Locally optimal leads to globally optimal
2. **Optimal Substructure**: Problem can be broken into optimal subproblems
3. **Comparison with Dynamic Programming**: When to use greedy vs DP
4. **Proof of Correctness**: Mathematical validation of greedy approach
5. **Implementation Techniques**: Priority queues and sorting

## Code Examples

### 1. Activity Selection Problem

```cpp
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;  // Sort by finish time
}

int activitySelection(vector<pair<int, int>> activities) {
    // Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    int count = 1;  // First activity is always selected
    int lastFinish = activities[0].second;

    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].first >= lastFinish) {
            count++;
            lastFinish = activities[i].second;
        }
    }

    return count;
}

// Example: activities = [(1,3), (2,5), (3,9), (6,8)]
// Selected: (1,3), (6,8) -> 2 activities
// Time Complexity: O(n log n) due to sorting
```

### 2. Fractional Knapsack Problem

```cpp
struct Item {
    int weight;
    int value;
    double ratio;  // value/weight
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;  // Sort by value/weight ratio
}

double fractionalKnapsack(vector<Item> items, int capacity) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for(auto item : items) {
        if(currentWeight + item.weight <= capacity) {
            // Take whole item
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of item
            int remaining = capacity - currentWeight;
            totalValue += item.ratio * remaining;
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) excluding input
```

### 3. Huffman Coding

```cpp
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Min-heap based on frequency
    }
};

void printCodes(Node* root, string str) {
    if(root == NULL) return;

    if(root->ch != '$') {  // Leaf node
        cout << root->ch << ": " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCoding(vector<pair<char, int>> chars) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes and add to priority queue
    for(auto p : chars) {
        pq.push(new Node(p.first, p.second));
    }

    // Build Huffman tree
    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create internal node
        Node* internal = new Node('$', left->freq + right->freq);
        internal->left = left;
        internal->right = right;

        pq.push(internal);
    }

    // Print codes
    printCodes(pq.top(), "");
}

// Example: chars = [('a',5), ('b',9), ('c',12), ('d',13), ('e',16), ('f',45)]
// Time Complexity: O(n log n)
```

### 4. Job Sequencing Problem

```cpp
struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;  // Sort by profit (descending)
}

vector<int> jobSequencing(vector<Job> jobs) {
    // Sort jobs by profit
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for(auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> schedule(maxDeadline + 1, -1);  // -1 means empty slot
    vector<int> result;

    for(auto job : jobs) {
        // Find empty slot before deadline
        for(int j = job.deadline; j > 0; j--) {
            if(schedule[j] == -1) {
                schedule[j] = job.id;
                result.push_back(job.id);
                break;
            }
        }
    }

    return result;
}

// Example: jobs = [(1,4,20), (2,1,10), (3,1,40), (4,1,30)]
// Result: [3, 1] (jobs 3 and 1 for maximum profit)
// Time Complexity: O(n²) in worst case
```

### 5. Kruskal's Algorithm (MST)

```cpp
struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;  // Sort by weight
}

int findParent(int node, vector<int>& parent) {
    if(parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);  // Path compression
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalMST(vector<Edge> edges, int vertices) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    // Initialize parent array
    for(int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    int edgesUsed = 0;

    for(auto edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int w = edge.weight;

        // Check if adding edge creates cycle
        if(findParent(u, parent) != findParent(v, parent)) {
            unionSets(u, v, parent, rank);
            mstWeight += w;
            edgesUsed++;

            if(edgesUsed == vertices - 1) break;  // MST complete
        }
    }

    return mstWeight;
}

// Time Complexity: O(E log E) where E is number of edges
// Space Complexity: O(V + E)
```

### 6. Prim's Algorithm (MST)

```cpp
int primMST(vector<vector<pair<int, int>>> graph, int vertices) {
    vector<int> key(vertices, INT_MAX);
    vector<bool> mstSet(vertices, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;  // Start from vertex 0
    pq.push({0, 0});  // {weight, vertex}

    int mstWeight = 0;

    while(!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if(mstSet[u]) continue;  // Already in MST
        mstSet[u] = true;
        mstWeight += weight;

        // Update adjacent vertices
        for(auto [v, w] : graph[u]) {
            if(!mstSet[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    return mstWeight;
}

// Time Complexity: O((V + E) log V) with binary heap
// Space Complexity: O(V + E)
```

## Greedy Algorithm Characteristics

### 1. Greedy Choice Property

- **Definition**: Locally optimal choice leads to globally optimal solution
- **Validation**: Must prove that greedy choice is safe
- **Examples**: Activity selection, fractional knapsack

### 2. Optimal Substructure

- **Definition**: Optimal solution contains optimal solutions to subproblems
- **Requirement**: Problem must have this property for greedy to work
- **Examples**: All greedy problems have this property

### 3. No Backtracking

- **Advantage**: No need to explore all possibilities
- **Speed**: Usually very fast algorithms
- **Trade-off**: May not always find optimal solution

## Algorithm Analysis

### Time Complexity

- **Activity Selection**: O(n log n) due to sorting
- **Fractional Knapsack**: O(n log n) due to sorting
- **Huffman Coding**: O(n log n) with priority queue
- **Job Sequencing**: O(n²) in worst case
- **Kruskal's MST**: O(E log E) with sorting
- **Prim's MST**: O((V + E) log V) with binary heap

### Space Complexity

- **Most Algorithms**: O(n) for input storage
- **Huffman Coding**: O(n) for priority queue
- **MST Algorithms**: O(V + E) for graph representation

## Key Takeaways

- **Greedy Choice**: Make locally optimal decisions
- **Proof Required**: Must prove greedy choice leads to optimal
- **Sorting Often Used**: Many greedy algorithms start with sorting
- **Optimal for Some Problems**: Perfect for specific problem types
- **Not Always Optimal**: May not work for all optimization problems

## Common Mistakes to Avoid

- Assuming greedy always works (need to prove correctness)
- Incorrect sorting criteria
- Not considering all constraints
- Forgetting edge cases (empty input, single element)
- Confusing greedy with dynamic programming

## Greedy vs Dynamic Programming

### Greedy Algorithm

- **Choice**: Make locally optimal choice
- **Memory**: No need to remember past choices
- **Speed**: Usually faster
- **Correctness**: Must prove greedy choice property

### Dynamic Programming

- **Choice**: Consider all possibilities
- **Memory**: Store results of subproblems
- **Speed**: Usually slower but more general
- **Correctness**: Guaranteed if optimal substructure exists

### When to Use Greedy

- **Mathematical Proof**: Can prove greedy choice is optimal
- **No Overlapping**: Subproblems don't share state
- **Simple Constraints**: Easy to make local decisions
- **Performance Critical**: Need fast solution

## Applications

### 1. Resource Allocation

- **CPU Scheduling**: Shortest job first
- **Memory Management**: Best fit, worst fit algorithms
- **Network Routing**: Shortest path routing
- **Load Balancing**: Distributing work across servers

### 2. Data Compression

- **Huffman Coding**: Lossless data compression
- **LZW Compression**: Dictionary-based compression
- **Run Length Encoding**: Simple compression technique
- **Arithmetic Coding**: Advanced compression method

### 3. Network Design

- **Minimum Spanning Tree**: Connecting all nodes with minimum cost
- **Shortest Path**: Finding optimal routes
- **Network Flow**: Maximum flow algorithms
- **Clustering**: Grouping similar data points

### 4. Scheduling Problems

- **Task Scheduling**: Assigning tasks to processors
- **Meeting Scheduling**: Finding optimal meeting times
- **Project Scheduling**: Critical path method
- **Resource Scheduling**: Optimal resource allocation

## Interview Tips

- **Explain Choice**: Clearly explain why greedy choice is optimal
- **Compare Approaches**: Discuss why greedy vs DP vs other methods
- **Edge Cases**: Test with small inputs and boundary conditions
- **Proof Sketch**: Be ready to explain why algorithm works
- **Implementation**: Know how to implement efficiently

## Problem Variations

### 1. Interval Problems

- **Interval Scheduling**: Maximum number of non-overlapping intervals
- **Interval Partitioning**: Minimum resources for interval covering
- **Weighted Interval Scheduling**: Maximum weight with no overlap

### 2. Selection Problems

- **Knapsack Variations**: 0/1 knapsack, unbounded knapsack
- **Coin Change**: Minimum coins for given amount
- **Activity Selection**: Variations with different constraints

### 3. Graph Problems

- **MST Variations**: Kruskal's vs Prim's algorithm
- **Shortest Path**: Dijkstra's algorithm (greedy)
- **Network Design**: Minimum cost spanning tree variations

### 4. Optimization Problems

- **Resource Allocation**: Assigning limited resources
- **Load Balancing**: Distributing work evenly
- **Profit Maximization**: Maximum profit with constraints

## Performance Considerations

- **Sorting Overhead**: Many greedy algorithms require O(n log n) sorting
- **Priority Queue**: Efficient for selection problems
- **Union-Find**: Essential for MST algorithms
- **Space Usage**: Usually O(n) space complexity

## Advanced Greedy Concepts

- **Matroid Theory**: Mathematical foundation for greedy algorithms
- **Greedy with Preprocessing**: Combining with other techniques
- **Approximation Algorithms**: Greedy for NP-hard problems
- **Online Algorithms**: Greedy for streaming data
