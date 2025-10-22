#include <iostream>

using namespace std;

void multiplyBy2(int &a, int &b, int &c) {
    a *= 2;
    b *= 2;
    c *= 2;
}

int main() {
    // int x;
    // int *ptr;
    // x = 7;
    // ptr = &x;
    // cout << ptr; // 7

    // int x = 1, y = 2, z = 3;
    // multiplyBy2(x, y, z);
    // cout << x << " " << y << " " << z << endl; // 2, 4, 6

    int a = 32;
    int *ptr = &a;

    char ch = 'A';
    char &cho = ch;

    cho += a;

    *ptr += ch;

    cout << a << ", " << ch << endl;

    return 0;
}