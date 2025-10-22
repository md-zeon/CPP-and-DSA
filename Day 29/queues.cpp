#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <queue>
#include <deque> // Double Ended Queue

using namespace std;

/*
class Node{
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};
*/

/*
//* Queue Implementation using Linked List
class Queue {
private:
    // Node* head;
    // Node* tail;
    list<int> ll;
public:
    // Queue() {
        // head = tail = NULL;
    // }

    void push(int data) {
        ll.push_back(data);
        // Node* newNode = new Node(data);

        // if(head == NULL) {
            // head = tail = newNode;
        // } else {
            // tail->next = newNode;
            // tail = newNode;
        // }
    }

    void pop() {
        ll.pop_front();
        // if(empty()) {
        //     cout << "Queue is empty" << endl;
        //     return;
        // }
        // Node* temp = head;
        // head = head->next;
        // temp->next = NULL;
        // delete temp;
    }

    int front() {
        // if(empty()) {
        //     cout << "Queue is empty" << endl;
        //     return -1;
        // }
        // return head->data;

        return ll.front();
    }

    bool empty() {
        // return head == NULL;
        return ll.empty();
    }

};
*/

//* Circular Queue Implementation using Array
/*
class Queue {
private:
    int* arr;
    int frontIndex, rearIndex, currSize, capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        frontIndex = 0;
        rearIndex = -1;
    }
    
    ~Queue() {
        delete[] arr;
    }

    void push(int data) {
        if(currSize == capacity) {
            cout << "Queue is full" << endl;
            return;
        }
        rearIndex = (rearIndex+1) % capacity;
        arr[rearIndex] = data;
        currSize++;
    }

    void pop() {
        if(empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        currSize--;
    }
    int front() {
        if(empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[frontIndex];
    }
    bool empty() {
        return currSize == 0;
    }

    void printRear() {
        cout << arr[rearIndex] << endl;
    }
};
*/

//* Queue Using two stacks

class Queue {
private:
    stack<int> s1, s2;

public:
    void push(int data) {
        // s1 -> s2
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        // s2 -> s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    int front() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }

};

//* Stack Using Two Queues

class Stack {
private:
    queue<int> q1, q2;
public:
    void push(int data) {
        // Q1 -> Q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(data);

        // Q2 -> Q1

        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop() {
        q1.pop();
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty(); 
    }
};

void firstNonRepeating(string str) {
    queue<char> Q;
    int freq[26] = {0};

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        Q.push(ch);
        freq[ch - 'a']++;

        while(!Q.empty() && freq[Q.front() - 'a'] > 1) {
            Q.pop();
        }

        if(Q.empty()) {
            cout << "-1\n";
        } else {
            cout << Q.front() << endl;
        }
    }
}

void interLeaveTwoQueues(queue<int> &org) {
    int n = org.size();
    queue<int> first;
    for(int i = 0; i < n/2; i++) {
        first.push(org.front());
        org.pop();
    }

    while(!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }

}

void reverseQueue(queue<int> &q) {
    stack<int> s;

    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}


int main() {
    //! Queue using Linked List
/*
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
*/


    //! Circular Queue Implementation using Array
/*
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    cout << q.front() << endl;
    q.printRear();
*/

    //! Queue Using two stacks
/*
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
*/

    //! Stack Using Two Queues
/*
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

*/


    //! Non-Repeating Letter: Find 1st non-repeating letter in a stream of characters
    string str = "aabccxb";
    // firstNonRepeating(str);

    //! Interleave 2 Queues: Interleave 2 halves of a Queue of even size

    // queue<int> org;
    // for(int i = 1; i <= 10; i++) {
    //     org.push(i);
    // }

    // interLeaveTwoQueues(org);

    // for(int i = 1; i <= 10; i++) {
    //     cout << org.front() << " ";
    //     org.pop();
    // }
    // cout << endl;

    //! Queue Reversal: reverse a queue
    // queue<int> q;

    // for(int i = 1; i <= 5; i++) {
    //     q.push(i);
    // }

    // reverseQueue(q);

    // for(int i = 1; i <= 5; i++) {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // cout << endl;

    //! Double Ended Queue

    deque<int> deq;

    deq.push_front(2);
    deq.push_front(1);
    deq.push_back(3);
    deq.push_back(4);

    // 1 2 3 4

    deq.pop_front();
    deq.pop_back();

    // 2 3

    cout << deq.front() << " ";
    cout << deq.back() << " ";


    //* H.W
    //! Queue using Deque
    //! Stack using Deque


    return 0;
}