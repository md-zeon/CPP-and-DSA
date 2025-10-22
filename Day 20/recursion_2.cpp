#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tilingProblem(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    int vertical = tilingProblem(n-1);
    int horizontal = tilingProblem(n-2);
    int ways = vertical + horizontal;
    return ways;
}

void removeDuplicates(string str, string ans, int i, bool map[]) {
    if(i == str.size()) {
        cout << "Ans : " << ans << endl;
        return;
    }
    int mapIdx = (int) (str[i] - 'a');
    if(map[mapIdx]) { // is Duplicate
        removeDuplicates(str, ans, i+1, map);
    } else { // not Duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ans+str[i], i+1, map);
    }
}

void removeDuplicates(string str, string ans, bool map[]) {
    if(str.size() == 0) {
        cout << "Ans : " << ans << endl;
        return;
    }
    int n = str.size();
    char ch = str[n-1];
    int mapIdx = (int) (ch - 'a');
    str = str.substr(0, n-1);
    if(map[mapIdx]) { // is Duplicate
        removeDuplicates(str, ans, map);
    } else { // not Duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ch+ans, map);
    }
}

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }
    int single = friendsPairing(n-1);
    int pair = friendsPairing(n-2) * (n-1);
    return single + pair;
}

void binaryString(int n, int lastPlace, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }   
    if(lastPlace != 1) {
        binaryString(n-1, 0, ans + '0');
        binaryString(n-1, 1, ans + '1');
    } else {
        binaryString(n-1, 0, ans + '0');
    }
}

int main() {
    //!Tiling Problem: Count total ways to tile a floor (2 X n) with tiles (2 X 1)
    // cout << tilingProblem(3) << endl;
    // cout << tilingProblem(4) << endl;
    //!Remove Duplicates from a string
    // string str = "appnnacollege";
    // string ans = "";
    // bool map[26] = {false};
    // removeDuplicates(str, ans, 0, map);
    // str = "appnnacollege";
    // ans = "";
    // for(int i = 0; i < 26; i++) {
    //     map[i] = false;
    // }
    // removeDuplicates(str, ans, map);
    
    //!Friends Pairing Problem: Find total ways in which n friends can be paired up. Each friend can only be paired once.
    // cout << friendsPairing(3) << endl;

    //!Binary String Problem: Print all binary strings of size N without any consecutive 1's.
    binaryString(3, 0, "");

    return 0;
}