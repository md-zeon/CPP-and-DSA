#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Heap {
private:
    vector<int> vec;
    void heapify(int parentIdx) {
        if (parentIdx >= vec.size()) {
            return;
        }
        int leftChild = 2*parentIdx + 1;
        int rightChild = 2*parentIdx + 2;

        int maxIdx = parentIdx;
        if (leftChild < vec.size() && vec[leftChild] > vec[maxIdx]) {
            maxIdx = leftChild;
        }

        if (rightChild < vec.size() && vec[rightChild] > vec[maxIdx]) {
            maxIdx = rightChild;
        }

        if (maxIdx != parentIdx) {
            swap(vec[maxIdx], vec[parentIdx]);
            heapify(maxIdx);
        }
    }
public:
    void push(int val) { // O(log n)
        vec.push_back(val);
        int childIdx = vec.size() - 1;
        int parentIdx = (childIdx - 1) / 2;

        while (childIdx > 0 && vec[childIdx] > vec[parentIdx]) {
            swap(vec[childIdx], vec[parentIdx]);
            childIdx = parentIdx;
            parentIdx = (childIdx - 1) / 2;
        }
    }


    void pop() {
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();

        heapify(0);
    }

    int top() { // O(1)
        return vec[0];
    }

    bool empty() { // O(1)
        return vec.size() == 0;
    }
};


class Student {
public:
    string name;
    int marks;
    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &s) const {
        return this->marks < s.marks; // ascending order (default max heap) use > inside for min heap
    }
};

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second; // ascending order (default max heap) use > inside for min heap
    }
};

int main() {
    /*
    Heap h;
    h.push(5);
    h.push(10);
    h.push(3);
    h.push(8);
    h.push(1);


    while(!h.empty()) {
        cout << "Top = " << h.top() << endl;
        h.pop();
    }
    */

    //! PQ for Pair / Objects

    // priority_queue<Student> pq;
    // pq.push(Student("Aman", 85));
    // pq.push(Student("Akbar", 95));
    // pq.push(Student("Anthony", 65));

    // while (!pq.empty()) {
    //     cout << pq.top().name << " " << pq.top().marks << endl;
    //     pq.pop();
    // }


    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;
    pq.push(make_pair("Aman", 85));
    pq.push(make_pair("Akbar", 95));
    pq.push(make_pair("Anthony", 65));

    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}