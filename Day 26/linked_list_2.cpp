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
public:
    Node *head;
    Node *tail;
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

};

void printList(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

bool isCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            cout << "Cycle Exists\n";
            return true;
        }
    }

    cout << "Cycle doesn't exists\n";
    return false;
}

void removeCycle(Node *head) {
    //detect Cycle
    Node *slow = head;
    Node *fast = head;
    bool isCycle = false;
    while(head != NULL && head->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            cout << "Cycle exists\n";
            isCycle = true;
            break;
        }
    }

    if(!isCycle) {
        cout << "Cycle doesn't exists" << endl;
        return;
    }

    // step 2

    slow = head;
    if(slow == fast) { // special case: tail is connected to head
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL; // remove cycle
    } else {
        Node *prev = fast;
        while(slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL; // remove cycle
    }
}


Node *splitAtMid(Node *head) {
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL; // split at middle
    }

    return slow; // slow = right head
}

Node *merge(Node *left, Node *right) {
    List ans;
    Node *i = left;
    Node *j = right;

    while(i != NULL && j != NULL) {
        if(i->data < j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }
    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }
    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    printList(ans.head);
    return ans.head;
}

Node *mergeSort(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *rightHead = splitAtMid(head);
    Node *left = mergeSort(head); //left head
    Node *right = mergeSort(rightHead); // right head
    return merge(left, right); // head of sorted LL
}

Node* reverse(Node* head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        //updator for next iteration
        prev = curr;
        curr = next;
    }
    return prev; // prev is head of reversed LL
}

Node* zigZagLL(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightHeadRev = reverse(rightHead);

    // alternate merging
    Node* left = head;
    Node* right = rightHead;
    Node* tail = right;

    while(left != NULL && right != NULL) {
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;

        tail = right;

        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {
        tail->next = right;
    }

    return head;
}


int main() {
    //! Use Floyd's Cycle Finding Algorithm to Detect Cycle/Loop in a LL 
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    // ll.tail->next = ll.head;
    // isCycle(ll.head);

    //! Remove cycle in a Linked List
    // removeCycle(ll.head); // Cycle exists
    printList(ll.head); // 1 -> 2 -> 3 -> 4 -> NULL

    //!Merge Sort on ll
    // ll.push_back(5);
    // printList(ll.head);
    // ll.head = mergeSort(ll.head);
    // printList(ll.head);


    //! Zig-Zag Linked List
    //* For a linked list of the form: L(1) -> L(2) -> L(3) -> L(4)....L(n-1) -> L(n)
    //* Convert it into a zig-zag form i.e.: L(1) -> L(n) -> L(2) -> L(n-1) -> L(3) -> L(n-2)...
    // ll.head = zigZagLL(ll.head);
    // printList(ll.head);



    return 0;
}