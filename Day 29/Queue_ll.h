#include <iostream>
// #include <list>

class Node{
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};


//* Queue Implementation using Linked List
class Queue {
private:
    Node* head;
    Node* tail;
    // std::list<int> ll;
public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push(int data) {
        // ll.push_back(data);
        Node* newNode = new Node(data);

        if(head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        // ll.pop_front();
        if(empty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    int front() {
        if(empty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return head->data;

        // return ll.front();
    }

    bool empty() {
        return head == nullptr;
        // return ll.empty();
    }

};
