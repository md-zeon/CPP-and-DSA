#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void printList(list<int> ll) {
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++) {
        cout << (*itr) << " -> ";
    }
    cout << "NULL" << endl;
}

int main() {
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    printList(ll);

    cout << "List Size = " << ll.size() << endl;

    cout << "Head = " << ll.front() << endl;
    cout << "Tail = " << ll.back() << endl;
    ll.pop_front();
    printList(ll);
    ll.pop_back();
    printList(ll);

    // H.W. insert

    return 0;
}