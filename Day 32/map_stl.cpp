#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> m;
    m[101] = "Rahul";
    m[110] = "Neha";
    m[131] = "Rahul";
    m[131] = "Rajat";

    cout << m[131] << endl; // Rajat
    cout << m.count(100) << endl; // 0
    cout << m.count(101) << endl; // 1
    cout << m.size() << endl;

    //for each loop
    for (auto i : m) {
        cout << "Key = " << i.first << ", Value = " << i.second << endl;
    }


    return 0;
}