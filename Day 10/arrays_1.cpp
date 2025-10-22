#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int key);
void arrayReverse(int arr[], int size);
void printArray(int arr[], int size);
int binarySearch(int arr[], int size, int key);

int main() {
    //! find largest and smallest in array
    // int marks[] = {1, 2, 3, 5, 7};
    // int n = sizeof(marks) / sizeof(int);

    // int max = marks[0];
    // int min = marks[0];
    // for(int i = 0; i < n; i++) {
    //     if(marks[i] > max) max = marks[i];
    //     if(marks[i] < min) min = marks[i];
    // }

    // cout << "Largest = " << max << endl;
    // cout << "Smallest = " << min << endl;


    //! Linear Search: O(n)

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int key = 112;
    int size = sizeof(arr)/sizeof(int);
    // cout << linearSearch(arr, size, key);

    //! Reverse an array (with extra space)
    // arrayReverse(arr, size);

    //! Reverse an array (without extra space) (2 pointer approach)
    // int si = 0, ei = size-1;
    // while(si < ei) {
    //     swap(arr[si], arr[ei]);
    //     si++, ei--;
    // }
    // printArray(arr, size);

    //! Binary search
    cout << binarySearch(arr, size, 14);

    return 0;
}


int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}


// void arrayReverse(int arr[], int size) {
//     int reversedArray[size];
//     for(int i = size-1, j = 0; i >= 0; i--,j++) {
//         reversedArray[j] = arr[i];
//     }
//     for(int i = 0; i < size; i++) {
//         arr[i] = reversedArray[i];
//     }
//     printArray(arr, size);
// }

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        (i == size-1) ? cout << arr[i] : cout << arr[i] << ", ";
    }
    cout << "\n";
}

int binarySearch(int arr[], int size, int key) {
    int si = 0, ei = size-1;
    int counter = 1;
    while(si <= ei) {
        int mid = (si + ei) / 2;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            ei = mid-1;
        } else {
            si = mid+1;
        }
        cout << counter << " loop" << endl;
        counter++;
    }
    return -1;
}