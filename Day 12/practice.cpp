#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void bubbleSort(vector<int> &nums) {
    for(int i = 0; i < nums.size()-1; i++) {
        bool isSwap = false;
        for(int j = 0; j < nums.size()- 1 - i; j++) {
            if(nums[j] < nums[j+1]) {
                swap(nums[j], nums[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap) {
            return;
        }
    }
}

void selectionSort(vector<int> &nums) {
    int n = nums.size();
    for(int i = 0; i < n-1; i++) {
        int minimumIndex = i;
        for(int j = i+1; j < n; j++) {
            if(nums[j] > nums[minimumIndex]) {
                minimumIndex = j;
            }
        }
        swap(nums[i], nums[minimumIndex]);
    }
}

void insertionSort(vector<int> &arr) {
    int n = arr.size();
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

void countingSort(vector<int> &arr) {
    int n = arr.size();
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



void printArray(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {

    /*

    * Question 1 : Use the following sorting algorithms to sort an array in DESCENDING
    * order :
    * a. Bubble Sort
    * b. Selection Sort
    * c. Insertion Sort
    * d. Counting Sort

    */

    vector<int> nums = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    // bubbleSort(nums);
    // selectionSort(nums);
    // insertionSort(nums);
    countingSort(nums);
    printArray(nums);



    return 0;
}