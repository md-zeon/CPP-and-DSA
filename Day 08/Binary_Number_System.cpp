#include <iostream>
#include <cmath>

using namespace std;

int binaryToDecimal(int n) {
    int binaryNum = n;
    int decimalNum = 0;
    int power = 0;
    while(binaryNum != 0) {
        int lastDigit = binaryNum % 10;
        decimalNum += (lastDigit * (int)pow(2, power));
        power++;
        binaryNum /= 10;
    }
    return decimalNum;
}

int decimalToBinary(int n) {
    if(n == 0) {
        return 0;
    }
    int decimalNum = n;
    int binaryNum = 0;
    int power = 1;
    while(decimalNum > 0) {
        int remainder = decimalNum % 2;
        binaryNum += (remainder * power);
        decimalNum /= 2;
        power *= 10;
    }
    return binaryNum;
}

int main() {
    cout << binaryToDecimal(100) << endl;
    cout << decimalToBinary(4) << endl;

    return 0;
}