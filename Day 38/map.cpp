#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    m["China"] = 150;
    m["India"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;
    m["UK"] = 20;
    m["Bangladesh"] = 20;
    m["Bangladesh"] = 25;
    m.erase("Nepal");

    for (pair<string, int> country : m) {
        cout << country.first << " : " << country.second << endl;
    }

    if (m.count("Nepal")) {
        cout << "Nepal Exists" << endl;
    } else {
        cout << "Nepal does not exist" << endl;
    }

    return 0;
}