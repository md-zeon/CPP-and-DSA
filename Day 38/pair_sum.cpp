#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 7, 11, 15, 5, 9};
    unordered_map<int, int> m;
    int target = 9;
    for (int i = 0; i < arr.size(); i++) {
        if (m.count(target - arr[i])) {
            cout << "ANS = [" << m[target - arr[i]] << ", " << i << "]" << endl;
            break;
        } else {
            m[arr[i]] = i;
        }
    }
    return 0;
}