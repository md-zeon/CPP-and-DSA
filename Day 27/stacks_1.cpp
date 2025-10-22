#include <iostream>
#include <vector>
#include <list>
using namespace std;

// stack implementation using vector
template <class T>
class Stack {
private:
    vector<T> vec;
public:
    void push(T val) {
        vec.push_back(val);
    }
    void pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        vec.pop_back();
    }
    T top() {
        // if(isEmpty()) {
        //     cout << "Stack is empty" << endl;
        //     return -1;
        // }
        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty() {
        return vec.size() == 0;
    }

};

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) {
        data = val;
        next = NULL;
    }
};

// stack implementation using Linked List
template <class T>
class Stack {
    // list<T> ll;
    Node<T>* head;
public:
    Stack() {
        head = NULL;
    }
    void push(T val) {
        // ll.push_front(val);
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop() {
        // ll.pop_front();
        if(head == NULL) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    T top() {
        // return ll.front();
        return head->data;
    }

    bool isEmpty() {
        // return ll.size() == 0;
        return head == NULL;
    }
};

int main() {
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);


    while(!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}