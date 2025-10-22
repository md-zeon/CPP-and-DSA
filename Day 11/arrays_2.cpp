#include <iostream>
#include <climits>
using namespace std;

void printSubArrays(int arr[], int n);
void maxSubArraySum1(int arr[], int n);
void maxSubArraySum2(int arr[], int n);
void maxSubArraySum3(int arr[], int n);
void maxProfit(int arr[], int n);

void trap(int heights[], int n) {
    int leftMax[20000], rightMax[20000];
    leftMax[0] = heights[0];
    rightMax[n-1] = heights[n-1];
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
    }
    for(int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], heights[i+1]);
    }

    int waterTrapped = 0;
    for(int i = 0; i < n; i++) {
        int currentWater = min(leftMax[i], rightMax[i]) - heights[i];
        if(currentWater > 0) {
            waterTrapped += currentWater;
        }
    }
    cout << "Water Trapped = " << waterTrapped << endl;
}

bool twice(int nums[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    int arr[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    //! Print SubArrays of an array: (O(n^3))
    // printSubArrays(arr, n);

    //! Max SubArrays Sum: (O(n^3))
    // maxSubArraySum1(arr, n);

    //! Max SubArrays Sum2 (Optimized): (O(n^3))
    // maxSubArraySum2(arr, n);

    //! Max SubArrays Sum3 (Kadane's algorithm [DP]): (O(n))
    // maxSubArraySum3(arr, n);

    //! Buy & Sell Stocks
    int prices[6] = {7, 1, 5, 3, 6, 4};
    n = sizeof(prices) / sizeof(int);
    // maxProfit(prices, n);

    //! Trapping RainWater

    int heights[7] = {4, 2, 0, 6, 3, 2, 5};
    n = sizeof(heights) / sizeof(int);
    // trap(heights, n);

    //! check whether any number appears twice in the array
    int nums[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    n = sizeof(nums) / sizeof(int);
    cout << twice(nums, n);

    return 0;
}

void printSubArrays(int arr[], int n) {
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            for(int i = start; i <= end; i++) {
                cout << arr[i];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

void maxSubArraySum1(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            int currSum = 0;
            for(int i = start; i <= end; i++) {
                currSum += arr[i];
                // cout << currSum << " ";
            }
            // cout << ", ";
            maxSum = max(maxSum, currSum);
        }
        // cout << endl;
    }
    cout << "Max Sub Array Sum = " << maxSum << endl;
}

void maxSubArraySum2(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int start = 0; start < n; start++) {
        int currSum = 0;
        for(int end = start; end < n; end++) {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Max Sub Array Sum = " << maxSum << endl;
}

void maxSubArraySum3(int arr[], int n) {
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }

    cout << "Max Sub Array Sum = " << maxSum << endl;
}

void maxProfit(int prices[], int n) {
    int bestBuy[10];
    bestBuy[0] = INT_MAX;
    for(int i = 1; i < n; i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
        cout << bestBuy[i] << ", ";
    }

    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    cout << "Max Profit = " << maxProfit << endl;
}