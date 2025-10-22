#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;
    Node(string key, int value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int totalSize;
    int currentSize;
    Node** table;

    int hashFunction(string key) {
        int idx = 0;

        for (int i = 0; i < key.size(); i++) {
            idx = idx + (key[i] * key[i]) % totalSize;
        }
        return idx % totalSize;
    }

    void rehash() { // O(n)
        Node** oldTable = table;
        int oldSize = totalSize;
        totalSize = 2 * totalSize;
        currentSize = 0;
        table = new Node*[totalSize];

        for (int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }

        for (int i = 0; i < oldSize; i++) {
            Node* head = oldTable[i];
            while (head != NULL) {
                insert(head->key, head->value);
                head = head->next;
            }

            if (oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int size = 5) {
        totalSize = size;
        currentSize = 0;
        table = new Node*[size];

        for (int i = 0; i < totalSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) { // O(1) average
        int idx = hashFunction(key);
        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;
        currentSize++;

        double lambda = currentSize / (double)totalSize;

        if (lambda > 1) {
            rehash(); // O(n) worst case
        }
    }

    bool exists(string key) {
        int idx = hashFunction(key);
        Node* head = table[idx];
        while (head != NULL) {
            if (head->key == key) {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    void remove(string key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = temp;
        while (temp != NULL) {
            if (temp->key == key) { // erase
                if (temp == table[idx]) { // head
                    table[idx] = temp->next;
                } else { // not head
                    prev->next = temp->next;
                }
                delete temp;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    int search(string key) {
        int idx = hashFunction(key);
        Node* head = table[idx];
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return -1;
    }

    void print() {
        for (int i = 0; i < totalSize; i++) {
            cout << i << " -> ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->value << ")" << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

};

int main() {

    HashTable ht;
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);
    ht.print();
    ht.remove("China");
    cout << "--------" << endl;
    ht.print();
    ht.remove("US");
    cout << "--------" << endl;
    ht.print();

    if(ht.exists("India")) {
        cout << "India population : " << ht.search("India") << endl;
    } else {
        cout << "Not found" << endl;
    }


    return 0;
}