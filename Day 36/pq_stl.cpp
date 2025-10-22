#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    // priority_queue<int> pq; // max heap
    // priority_queue<int, vector<int>, greater<int>> pq; // min heap
    // pq.push(5);
    // pq.push(10);
    // pq.push(3);
    // pq.push(8);
    // pq.push(1);


    // priority_queue<string> pq;
    priority_queue<string, vector<string>, greater<string>> pq; // min heap
    pq.push("apple");
    pq.push("mango");
    pq.push("banana");
    pq.push("orange");
    pq.push("grapes");

    while(!pq.empty()) {
        cout << "Top: " << pq.top() << endl;
        pq.pop();
    }

    return 0;
}