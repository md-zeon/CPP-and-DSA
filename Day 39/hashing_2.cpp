#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

void majorityElement(vector<int> elements) {
    unordered_map<int, int> map;
    for (auto num : elements) {
        if (map.count(num)) {
            map[num]++;
        } else {
            map[num] = 1;
        }
    }

    for (auto i : map) {
        if (i.second > elements.size() / 3) {
            cout << i.first << " ";
        }
    }
    cout << endl;
} 

bool validAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }
    unordered_map<char, int> map;

    for (char c : s1) {
        if (map.count(c)) {
            map[c]++;
        } else {
            map[c] = 1;
        }
    }

    for (char c : s2) {
        if (map.count(c)) {
            map[c]--;
            if (map[c] == 0) {
                map.erase(c);
            }
        } else {
            return false;
        }
    }

    return map.size() == 0;
}

void countDistinct(vector<int> arr) {
    unordered_set<int> set;
    for (int i = 0; i < arr.size(); i++) {
        set.insert(arr[i]);
    }
    cout << "Distinct = " << set.size() << endl;

    for (auto i : set) {
        cout << i << " ";
    }
}

void printUnionAndIntersection(vector<int> set1, vector<int> set2) {
    unordered_set<int> set;
    unordered_set<int> intersection;

    for (int i = 0; i < set1.size(); i++) {
        set.insert(set1[i]);
    }

    for (int i = 0; i < set2.size(); i++) {
        if (set.count(set2[i])) {
            intersection.insert(set2[i]);
        } else {
            set.insert(set2[i]);
        }
    }

    cout << "Union set: ";
    for (auto i : set) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Intersection set: ";
    for (auto i : intersection) {
        cout << i << " ";
    }
    cout << endl;

}

void findItinerary(unordered_map<string, string> tickets) {
    //starting point
    unordered_set<string> to;

    for (auto ticket : tickets) {
        to.insert(ticket.second);
    }

    string start = "";

    for (auto ticket : tickets) {
        if (to.find(ticket.first) == to.end()) {
            start = ticket.first;
        }
    }

    // plan print
    cout << start << " -> ";
    while (tickets.count(start)) {
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << "Destination" << endl;
}

int largestSubArrayWithZeroSum(vector<int> arr) {
    unordered_map<int, int> map; // sum, idx
    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];
        if (map.count(sum)) {
            int currLen = j - map[sum]; // j - idx
            ans = max(ans, currLen);
        } else {
            map[sum] = j;
        }
    }

    return ans;
}

int subArrayCountWithK(vector<int> arr, int k) {
    unordered_map<int, int> m; // sum, count
    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];
        if (m.count(sum - k)) {
            ans += m[sum - k];
        }

        if (m.count(sum)) {
            m[sum]++;
        } else {
            m[sum] = 1;
        }
    }

    return ans;
}

int main() {
    //! Majority Element: Find elements that appear more than n/3 times
    vector<int> elements = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    // majorityElement(elements);

    //! Valid Anagram
    string s1 = "race";
    string s2 = "care";

    // if (validAnagram(s1, s2)) {
    //     cout << "Valid Anagram" << endl;
    // } else {
    //     cout << "Not Valid Anagram" << endl;
    // }

    //! Count Distinct
    vector<int> arr = {4, 3, 2, 5, 6, 7, 3, 4, 2, 1};
    // countDistinct(arr);

    //! Union & Intersection
    vector<int> set1 = {7, 3, 9};
    vector<int> set2 = {6, 3, 9, 2, 9, 4};
    // printUnionAndIntersection(set1, set2);

    //! Itinerary from Tickets
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";
    // findItinerary(tickets);

    //! Largest Sub Array with Sum 0
    vector<int> array = {15, -2, 2, -8, 1, 7, 10};
    // cout << "Largest Sub Array with 0 Sum = " << largestSubArrayWithZeroSum(array) << endl;

    //! Sub Array Sum Equals K
    vector<int> vec = {10, 2, -2, -20, 10};
    int k = -10;
    cout << "Sub Array Count with K = " << subArrayCountWithK(vec, k) << endl;


    return 0;
}