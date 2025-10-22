#include <iostream>

using namespace std;

int main() {
    int x = 10, y = 5;

    int exp1 = (x * y / x);
    int exp2 = (x * (y / x));
    int exp3 = (y * (x / y + x / y));
    int exp4 = (y * x / y + y * x / y);

    cout << exp1 << ", " << exp2 << ", " << exp3 << ", " << exp4 << endl;

    return 0;
}