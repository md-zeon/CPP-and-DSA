#include <iostream>
#include <cmath>

using namespace std;

#define CUBE(x) (x * x * x); 

int main() {
    //! write a C++ program to get a number from the user and print whether it's positive, negative or zero. 
    // int n;
    // cout << "Enter n: ";
    // cin >> n;
    // if(n > 0) {
    //     cout << "Positive";
    // } else if (n < 0) {
    //     cout << "Negative";
    // } else {
    //     cout << "Zero"; 
    // }

    //! Write a c++ program that takes a year from the user  and print whether that year is a leap year or not.

    // int year;
    // cout << "Enter year: ";
    // cin >> year;
    // if(year % 4 == 0 || year % 100 == 0 || year % 400 == 0) {
    //     cout << "Leap year" << endl;
    // } else {
    //     cout << "Not a leap year" << endl;
    // }

    //! for any 3 digit number check whether it is an armstrong number or not.

    typedef const int ci;

    int n = 371;
    ci NUM = n;
    int sum = 0;

    while (n != 0) {
        int lastDigit = n % 10;
        sum += CUBE(lastDigit);
        n /= 10;
    }

    if(sum == NUM) {
        cout << NUM << " is an Armstrong number" << endl;
    } else {
        cout << NUM << " is not an Armstrong number" << endl;
    }
    

    return 0;
}