#include <iostream>
#include <set>
using namespace std;


int main() {
    set<int> s;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(2);
    // s.insert(1);
    // s.insert(1);
    // s.insert(1);

    cout << s.size() << endl;
    // s.erase(3);

    if (s.find(3) != s.end()) {
        cout << "3 Found" << endl;
    } else {
        cout << "3 Not Found" << endl;
    }

    for (auto i : s) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}