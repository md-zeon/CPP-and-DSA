#include <iostream>

using namespace std;

void oddOrEven(int num) {
    if(num & 1) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
}

int getIthBit(int num, int pos) {
    int bitMask = 1 << pos;

    if(!(num & bitMask)) {
        return 0;
    } else {
        return 1;
    }
}

int setIthBit(int num, int pos) {
    int bitMask = 1 << pos;
    return num | bitMask;
}

int clearIthBit(int num, int pos) {
    int bitMask = ~(1 << pos);
    return num & bitMask;
}

bool isPowerOf2(int num) {
    if(num & num-1) {
        return false;
    } else {
        return true;
    }
}

void updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i); // clear ith bit

    num = num | (val << i);
    cout << num << endl;
}

void clearIBits(int num, int i) {
    int bitMask = (~0) << i;
    num = num & bitMask;

    cout << num << endl;
}

void countSetBits(int num) {
    int count = 0;
    while(num > 0) {
        int lastDigit = num & 1;
        count += lastDigit;
        num = num >> 1;
    }

    cout << count << endl;
}

void fastExpo(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit) {
            ans *= x;
        }
        x = x * x;
        n = n >> 1;
    }

    cout << ans << endl;
}

int main() {
    //? Bitwise Operators

    /**
     ** Bitwise AND &
     ** Bitwise OR |
     ** Bitwise XOR ^
     */

    // cout << (3 & 5) << endl;
    // cout << (3 | 5) << endl;
    // cout << (3 ^ 5) << endl;

    //? One's complement
    /**
     ** Binary NOT ~
     ** ~0 -> 1
     ** ~1 -> 0
     */
    // cout << (~6) << endl;
    // cout << (~0) << endl;

    //? Binary Shift Operators
    /**
     ** Left Shift << [a << b => a * 2^b]
     ** Right Shift >> [a >> b => a / 2^b]
    **/

//    cout << (7 << 2) << endl;
//    cout << (7 >> 2) << endl;

   //! Check if a number is odd or even
   //* even & 1 => 0 and odd & 1 => 1
    // oddOrEven(5);
    // oddOrEven(10);

    //!Get ith bit in a number
    int num = 6;
    int pos = 3;
    // cout << getIthBit(num, pos) << endl;

    //! Set ith bit
    // cout << setIthBit(num, pos) << endl;

    //! Clear ith bit
    // cout << clearIthBit(num, 1) << endl;

    //! Check for Power of 2
    // cout << isPowerOf2(4) << endl;
    // cout << isPowerOf2(17) << endl;

    //! WAF to update the ith bit in a number according to given value (0 or 1)
    // updateIthBit(7, 3, 1);

    //! WAF to clear last i bits of a number
    // clearIBits(15, 2);

    //! Count Set Bits
    // countSetBits(10);

    //! Fast Exponentiation (X^n)
    fastExpo(3, 4);

    

    return 0;
}