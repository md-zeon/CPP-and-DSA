#include <iostream>
using namespace std;
int factorial(int n);
void sayHello() {
    cout << "Hello :) \n";
}

bool isPrime(int n);
void printPrime(int n);
bool isPalindrome(int n);
int digitSum(int n);
void largest(int a, int b, int c);
char nextChar(char ch);

int abSquare(int a, int b);


int main() {
    // sayHello();
    // cout << factorial(5) << endl;

    //! print all  the prime number from 2 to n
    // printPrime(100);

    //! WAF to check if a number is a palindrome
    // cout << isPalindrome(123) << endl;

    //! WAF to calculate the sum of digits of a number
    // cout << digitSum(29374) << endl;

    //! WAF that outputs a^2 + b^2 + 2ab
    cout << abSquare(5, 3) << endl;

    //! WAF that prints largest of 3 numbers
    // largest(12,9,7);

    //! WAF that prints the next char of a alphabet
    // cout << nextChar('z') << endl;
    // cout << nextChar('Z') << endl;


    return 0;
}

int factorial(int n) {
    int fact = 1;

    for(int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}


bool isPrime(int n) {
    if(n == 1) {
        return false;
    }

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

void printPrime(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

bool isPalindrome(int n) {
    int num = n;
    int reverse = 0;
    while(num != 0) {
        int lastDigit = num % 10;
        reverse = (reverse * 10) + lastDigit;
        num /= 10;
    }
    if(reverse == n) {
        return true;
    }

    return false;
}

int digitSum(int n) {
    int digit = n;
    int sum = 0;
    while (digit != 0) {
        int lastDigit = digit % 10;
        sum += lastDigit;
        digit /= 10;
    }
    return sum;
}


void largest(int a, int b, int c) {
    if(a > b && a > c) {
        cout << a << " is the largest number between (" << a << ", " << b << ", " << c << ")" << endl;
    } else if(b > c) {
        cout << b << " is the largest number between (" << a << ", " << b << ", " << c << ")" << endl;
    } else {
        cout << c << " is the largest number between (" << a << ", " << b << ", " << c << ")" << endl;
    }
}

char nextChar(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        if(ch == 'z') {
            return 'a';
        } else {
            return ch+1;
        }
    } else if(ch >= 'A' && ch <= 'Z') {
        if(ch == 'Z') {
            return 'A';
        } else {
            return ch++;
        }
    }
} 

int abSquare(int a, int b) {
    return a*a + b*b + 2*a*b;
}