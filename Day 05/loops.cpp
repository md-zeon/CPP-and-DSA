// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    //! Print the Sum of digits of a number using a while loop.
    // int n = 10829;
    // int sum = 0;
    // cout << "Digit = " << n << endl;
    // while (n != 0) {
    //     int lastDigit = n % 10;
    //     sum += lastDigit;
    //     n /= 10;
    // }

    // cout << "Digit Sum = " << sum << endl;


    //! Print the Sum of odd digits of a number using a while loop.
    // n = 10829;
    // sum = 0;
    // while (n != 0) {
    //     int lastDigit = n % 10;
    //     if(lastDigit % 2 != 0) {
    //         sum += lastDigit;
    //     }
    //     n /= 10;
    // }

    // cout << "Odd Digit Sum = " << sum << endl;


    //! print the digit of a given number in reverse using while loop

    // n = 10829;

    // while (n != 0) {
    //     int lastDigit = n % 10;
    //     cout << lastDigit;
    //     n /= 10;
    // }

    // cout << endl;

    //! Reverse a given number and print the result
    // n = 10829;
    // int reverse = 0;

    // while (n != 0) {
    //     int lastDigit = n % 10;
    //     reverse = (reverse * 10) + lastDigit;
    //     n /= 10;
    // }

    // cout << "Reverse = " << reverse << endl;


    //! Check if a number is Prime or not

    // int n = 5;
    // bool isPrime = true;

    // for(int i = 2; i <= sqrt(n); i++) {
    //     if(n % i == 0) {
    //         isPrime = false;
    //         break;
    //     }
    // }

    // if(isPrime) {
    //     cout << "Number is prime" << endl;
    // } else {
    //     cout << "Number is not prime" << endl;
    // }

    //! WAP to find the factorial of a number entered by the user.

    // int number;
    // cout << "Enter number: ";
    // cin >> number;
    // int factorial = 1;
    // for(int i = 1; i <= number; i++) {
    //     factorial *= i;
    // }

    // cout << "factorial of " << number << " is: " << factorial;

    //! Write a Program to print the multiplication table of a number entered by the user.

    // int n;
    // cout << "Enter n: ";
    // cin >> n;

    // for(int i = 1; i <= 10; i++) {
    //     cout << n << " X " << i << " = " << (n * i) << endl;
    // }

    //! for a positive n WAP to print all the prime numbers from 2 to n

    // int n;
    // cout << "Enter n: ";
    // cin >> n;
    
    // for(int i = 2; i <= n; i++) {
    //     int currentNumber = i;
    //     bool isPrime = true;
    //     for(int j = 2; j <= sqrt(currentNumber); j++) {
    //         if(currentNumber % j == 0) {
    //             isPrime = false;
    //             break;
    //         }
    //     }
    //     if(isPrime) {
    //         cout << currentNumber << " ";
    //     }
    // }

    // cout << endl;


    //! print n fibonacci numbers

    int n;
    cout << "Enter n: ";
    cin >> n;
    int first = 0;
    int second = 1;
    cout << first << " " << second << " ";

    for(int i = 2; i < n; i++) {
        int third = first + second;
        cout << third << " ";
        first = second;
        second = third;
    }

    return 0;
}