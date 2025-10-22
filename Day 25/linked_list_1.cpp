#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }

    ~Node() {
        // cout << "~Node: " << data << endl;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List{
    Node *head;
    Node *tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
        // cout << "~List\n";
        if(head != NULL) {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val) {
        Node *newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

    }


    void push_back(int val) {
        Node *newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node *temp = head;

        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insert(int val, int pos) {
        Node *newNode = new Node(val);

        Node *temp = head;
        for(int i = 0; i < pos-1; i++) {
            if(temp == NULL) {
                cout << "Position is invalid\n";
                return;
            }
            temp = temp->next;
        }

        // temp is now at pos-1 i.e. prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            cout << "Linked List is Empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        Node *temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        temp->next = NULL; //temp = tail's prev
        delete tail;
        tail = temp;
    }

    int searchItr(int key) {
        Node *temp = head;
        int idx = 0;
        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node *temp, int key) {
        if(temp == NULL) {
            return -1;
        }

        if(temp->data == key) {
            return 0;
        }

        int idx = helper(temp->next, key);

        if(idx == -1) {
            return -1;
        } 

        return idx + 1;
    }

    int searchRec(int key) {
        return helper(head, key);
    }

    void reverse() {
        Node *curr = head;
        Node *prev = NULL;
        
        while(curr != NULL) {
            Node *next = curr->next;
            curr->next = prev;

            //updator for next iteration
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int getSize() {
        Node *temp = head;
        int sz = 0;
        while(temp != NULL) {
            temp = temp->next;
            sz++;
        }

        return sz;
    }

    void removeNth(int n) {
        Node *prev = head;
        int size = getSize(); // 4
        // cout << "Size = " << size << endl;
        for(int i = 1; i < size-n; i++) {
            prev = prev->next;
        }

        Node *toDel = prev->next;
        // cout << "Going to Delete: " << toDel->data << endl;

        prev->next = prev->next->next;
        toDel->next = NULL;
        delete toDel;
    }

};

int main() {

    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList(); // 1 -> 2 -> 3 -> NULL

    ll.push_back(4);
    ll.push_back(5);
    ll.printList(); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ll.insert(100, 2); 
    ll.printList(); // 1 -> 2 -> 100 -> 3 -> 4 -> 5 -> NULL
    ll.pop_front();
    ll.printList(); // 2 -> 100 -> 3 -> 4 -> 5 -> NULL
    ll.pop_back();
    ll.printList(); // 2 -> 100 -> 3 -> 4 -> NULL
    cout << ll.searchItr(4) << endl;
    cout << ll.searchRec(4) << endl;
    ll.reverse();
    ll.printList(); // 4 -> 3 -> 100 -> 2 -> NULL
    ll.removeNth(2);
    ll.printList(); // 4 -> 3 -> 2 -> NULL



    return 0;
}