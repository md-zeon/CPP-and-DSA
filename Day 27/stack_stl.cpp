#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


void pushAtBottom(stack<int> &s, int val) {
    if(s.empty()) {
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(top);
}

string reverseString(string str) {
    string ans;
    stack<char> s;
    for(int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    while(!s.empty()) {
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
}

void reverse(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void stockSpanProblem(vector<int> stock, vector<int> span) {
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for(int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];
        while(!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            span[i] = i + 1;
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
    }

    for(int i = 0; i < span.size(); i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    //! push at Bottom of Stock
    pushAtBottom(s, 4);
    printStack(s);

    //! reverse a string using a stack
    string str = "abcd";
    cout << "Reverse = " << reverseString(str) << endl;

    //! reverse a stack
    reverse(s);
    printStack(s);

    //! stock Span problem
    vector<int> stock = {100, 80, 60, 70, 60, 65, 100};
    vector<int> span = {0, 0, 0, 0, 0, 0, 0};
    stockSpanProblem(stock, span);

    return 0;
}