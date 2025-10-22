#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {
    vector <int> temp;
    int i = si;
    int j = mid+1;
    while(i <= mid && j <= ei){
        if(arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= ei) {
        temp.push_back(arr[j++]);
    }
    for(int i = si, k = 0; k < temp.size(); i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, mid, ei);
}

int partition(int arr[], int si, int ei) {
    int i = si - 1;
    int pivot = arr[ei];
    for(int j = si; j < ei; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);

    //pivot index i
    return i;
}

void quickSort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }
    int pivotIdx = partition(arr, si, ei);
    quickSort(arr, si, pivotIdx-1);
    quickSort(arr, pivotIdx+1, ei);
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search(int arr[], int si, int ei, int target) {
    if(si > ei) {
        return -1;
    }
    int mid = si + (ei - si) / 2;
    if(arr[mid] == target) {
        return mid;
    }

    if(arr[si] <= arr[mid]) {
        //L1
        if(arr[si] <= target && target <= arr[mid]) {
            //left
            return search(arr, si, mid-1, target);
        } else {
            //right
            return search(arr, mid+1, ei, target);
        }
    } else {
        //L2
        if(arr[mid] <= target && target <= arr[ei]) {
            //right
            return search(arr, mid+1, ei, target);
        } else {
            //left
            return search(arr, si, mid-1, target);
        }
    }
}

int main() {
    int arr[6] = {6, 3, 7, 5, 2, 4};
    int n = 6;
    // printArray(arr, n);
    // mergeSort(arr, 0, n-1);
    // quickSort(arr, 0, n-1);
    // printArray(arr, n);

    //! Search in Rotated Sorted Array
    int target = 0;
    int rotatedArr[7] = {4, 5, 6, 7, 0, 1, 2};
    n = 7;
    cout << "Idx = " << search(rotatedArr, 0, n-1, 0); // log(n)
    return 0;
}