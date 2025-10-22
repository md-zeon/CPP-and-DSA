#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void nextGreater(vector<int> arr, vector<int> ans) {
    stack<int> s;
    int idx = arr.size() - 1;
    ans[idx] = -1;
    s.push(arr[idx]);
    for(idx = idx - 1; idx >= 0; idx--) {
        int curr = arr[idx];
        while(!s.empty() && s.top() <= curr) {
            s.pop();
        }
        if(s.empty()) {
            ans[idx] = -1;
        } else {
            ans[idx] = s.top();
        }

        s.push(curr);
    }

    for(int i = 0; i < arr.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

bool isValidParenthesis(string str) {
    stack<char> s;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else {
            if(s.empty()) {
                return false;
            }
            char top = s.top();
            if(top == '(' && str[i] == ')' || top == '{' && str[i] == '}' || top == '[' && str[i] == ']') {
                s.pop();
            } else {
                return false;
            }
        }
    }

    // if(s.empty()) {
    //     return true;
    // } else {
    //     return false;
    // }
    return s.empty();
}

bool isDuplicateParenthesis(string str) {
    stack<char> s;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(ch != ')') {
            s.push(ch);
        } else {
            if(s.top() == '(') {
                return true;
            }

            while(s.top() != '(') {
                s.pop();
            }

            s.pop();
        }
    }

    return false;
}

void maxAreaHistogram(vector<int> height) {
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    // next smaller left
        nsl[0] = -1;
        s.push(0);
    for(int i = 1; i < height.size(); i++) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }

        s.push(i);
    }

    // empty the stack
    while(!s.empty()) {
        s.pop();
    }

    //next smaller right
    s.push(n-1);
    nsr[n - 1] = n;
    for(int i = n-2; i >= 0; i--) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }

        s.push(i);
    }

    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht * width;
        maxArea = max(area, maxArea);
    }

    cout << "Max Area Of Histogram : " << maxArea << endl;
}

int main() {
    //! Next Greater Element
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans = {0, 0, 0, 0, 0};
    // nextGreater(arr, ans);

    //! Valid Parenthesis
    /*
        * Given a string s containing just the characters '(',')','{','}','[' and ']',
        * determine if the input string is valid.
        * 
        * An input string is valid if:
           & Open brackets must be closed by the same type of brackets.
           & Open brackets must be closed in the correct order.
           & Every close bracket has a corresponding open bracket of the same type. 
    */

    string str1 = "([}])"; // valid false;
    string str2 = "([{}])"; // valid true;
    // cout << "Valid : " << isValidParenthesis(str1) << endl;
    // cout << "Valid : " << isValidParenthesis(str2) << endl;

    //! Duplicate Parenthesis
    /*
        * Given a balanced expression that can contain opening and closing parenthesis,
        * check if it contains any duplicate parenthesis or not.
        * 
        * Input: ((x+y)) + z
        * Output: true 
        * Explanation: Duplicate () found in subexpression ((x+y))
        * 
        * Input: (x+y)
        * Output: false
        * Explanation: No duplicate () is found
        * 
        * Input: ((x + y) + ((z)))
        * Output: true
        * Explanation: Duplicate () found in subexpression ((z))
    */

    string str3 = "((x+y)) + z";
    string str4 = "((a + b) + (c + d))";
    // cout << "Duplicate Parenthesis: " << isDuplicateParenthesis(str3) << endl;
    // cout << "Duplicate Parenthesis: " << isDuplicateParenthesis(str4) << endl;


    //! Max Area in Histogram
    //* return the area of the largest rectangle in histogram.

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    maxAreaHistogram(heights);

    return 0;
}