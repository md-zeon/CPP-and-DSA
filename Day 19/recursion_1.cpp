#include <iostream>
#include <string>
#include <vector>
using namespace std;
int factorial(int n);
void decreasingOrder(int n);
void increasingOrder(int n);
int naturalSum(int n);
int nthFibonacci(int n);
bool isSorted(int arr[], int n, int i);
int firstOccur(vector<int> arr, int target);
int lastOccur(vector<int> arr, int target, int i);
int power(int x, int n);

int main() {
    //! Calculate factorial of a number using recursion
    // cout << factorial(5) << endl;
    //! Print numbers in decreasing order using recursion from n to 1
    // decreasingOrder(5);
    // cout << endl;
    //! Print numbers in increasing order using recursion from 1 to n
    // increasingOrder(5);
    // cout << endl;
    //! Calculate the sum of n natural numbers
    // cout << "Sum = " << naturalSum(5) << endl;
    //! Print the nth fibonacci number
    // cout << "Fibonacci = " << nthFibonacci(7) << endl;
    //! Check if an array is sorted or not
    // int arr1[5] = {1,2,3,4,5};
    // int arr2[5] = {1,2,4,3,5};
    // cout << "isSorted : " << isSorted(arr1, 5, 0) << endl;
    // cout << "isSorted : " << isSorted(arr2, 5, 0) << endl;
    //! WAF to find first Occurrence in an element in a vector
    // vector<int> arr = {1,2,3,3,3,4};
    // cout << "Index : " << firstOccur(arr, 3) << endl;
    //! WAF to find last Occurrence in an element in a vector
    // cout << "Index : " << lastOccur(arr, 3, 0) << endl;
    //! Print X to the power N
    cout << power(5,3);

    return 0;
}

int power(int x, int n) { //O(log n)
    if(n == 0) {
        return 1;
    }
    int halfPower = power(x, n/2);
    int halfPowerSquare = halfPower * halfPower;
    if(x % 2 == 0) {
        return halfPowerSquare;
    }
    return x * halfPowerSquare;
}

int lastOccur(vector <int> arr, int target, int i) {
    if(i == arr.size()) {
        return -1;
    }
    int idx = lastOccur(arr, target, i+1);
    if(idx == -1 && arr[i] == target) {
        return i;
    }
    return idx;
}

int firstOccur(vector<int> arr, int target) {
    static int i = 0;
    if(i == arr.size()) {
        return -1;
    }
    if(arr[i] == target) {
        return i;
    }
    i++;
    return firstOccur(arr, target);
}

bool isSorted(int arr[], int n, int i) {
    if(i == n-1) {
        return true;
    }
    if(arr[i] > arr[i+1]) {
        return false;
    }
    isSorted(arr, n, i+1);
}

int nthFibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    return nthFibonacci(n-1) + nthFibonacci(n-2);
}

int factorial(int n) {
    //base case
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

void decreasingOrder(int n) {
    if(n < 1) {
        return;
    }
    cout << n << " ";
    decreasingOrder(n-1);
}

void increasingOrder(int n) {
    if(n < 1) {
        return;
    }
    increasingOrder(n-1);
    cout << n << " ";
}

int naturalSum(int n) {
    if(n == 1) {
        return 1;
    }
    return (n + naturalSum(n-1));
}