//! Doubly Linked List
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val) {
            data = val;
            next = prev = NULL;
        }
};

class DoublyList{
    public:
        Node* head;
        Node* tail;

        DoublyList() {
            head = tail = NULL;
        }

        void push_front(int val) {
            Node *newNode = new Node(val);

            if(head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void push_back(int val) {
            Node* newNode = new Node(val);
            if(head == NULL) {
                head = tail = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_front() {
            Node* temp = head;
            head = head->next;

            if(head != NULL) {
                head->prev = NULL;
            }

            temp->next = NULL;
            delete temp;
        }

        void pop_back() {
            if(head == NULL) {
                cout << "Invalid Action! Linked List is Empty\n" << endl;
                return;
            }
            Node* temp = tail->prev;
            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void printList() {
            Node* temp = head;

            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }

};

int main() {
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);
    dbll.printList();
    dbll.pop_front();
    dbll.printList();
    dbll.push_back(5);
    dbll.push_back(6);
    dbll.push_back(7);
    dbll.push_back(8);
    dbll.push_back(9);
    dbll.printList();
    for(int i = 0; i < 7; i++) {
        dbll.pop_back();
    }
    dbll.printList();
    DoublyList dl;
    dl.push_back(100);
    dl.printList();
    return 0;
}