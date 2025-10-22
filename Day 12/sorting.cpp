#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        (i == n-1) ? cout << arr[i] : cout << arr[i] << ", ";
    }
    cout << "]\n";
}

void printArray(char arr[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        (i == n-1) ? cout << arr[i] : cout << arr[i] << ", ";
    }
    cout << "]\n";
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        bool isSwap = false;
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return;
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minimumIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
            }
        }
        swap(arr[i], arr[minimumIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

void countingSort(int arr[], int n) {
    int freq[100] = {0}; // range
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for(int i = minVal, j = 0; i < maxVal; i++) {
        while(freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }
}

void insertionSort(char arr[], int n) {
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] < curr) {
            swap(arr[prev], arr[prev+1]);
            prev--;
        }
        arr[prev+1] = curr;
    }
}

int main() {
    // int arr[] = {5, 4, 1, 3, 2, 6};
    // int n = sizeof(arr)/sizeof(int);
    // // bubbleSort(arr, n);
    // // selectionSort(arr, n);
    // // printArray(arr, n);
    // // insertionSort(arr, n);
    // printArray(arr, n);
    // // countingSort(arr, n);
    // //inbuilt Sort
    // sort(arr, arr+n);
    // printArray(arr, n);
    // //descending order
    // sort(arr+2, arr+n, greater<int>());
    // printArray(arr, n);

    //! Question: Sort this array of character using insertion sort in descending order.

    char ch[] = {'f', 'b', 'a', 'e', 'c', 'd'};
    int size = sizeof(ch);
    printArray(ch, size);
    insertionSort(ch, size);
    printArray(ch, size);


    return 0;
}