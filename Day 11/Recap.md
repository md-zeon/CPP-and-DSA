# Day 11: Arrays Part 2

## Topics Covered

- **Subarray Problems**: Finding subarrays and their properties
- **Maximum Subarray Sum**: Three different approaches with varying complexities
- **Kadane's Algorithm**: Dynamic programming approach for maximum subarray sum
- **Stock Buy/Sell Problem**: Finding maximum profit from stock prices
- **Trapping Rainwater**: Calculating trapped water between buildings
- **Array Duplicates**: Checking for duplicate elements

## Key Concepts

1. **Subarray Definition**: Contiguous part of array
2. **Dynamic Programming**: Kadane's algorithm for optimal subarray problems
3. **Prefix Computations**: Precomputing values for efficient calculations
4. **Two Pointer Technique**: For various array optimizations
5. **Greedy Approach**: For stock profit maximization

## Code Examples

### 1. Maximum Subarray Sum - Brute Force O(n³)

```cpp
void maxSubArraySum1(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int start = 0; start < n; start++) {
        for(int end = start; end < n; end++) {
            int currSum = 0;
            for(int i = start; i <= end; i++) {
                currSum += arr[i];
            }
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Max Sub Array Sum = " << maxSum << endl;
}
```

### 2. Maximum Subarray Sum - Optimized O(n²)

```cpp
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
```

### 3. Kadane's Algorithm - Dynamic Programming O(n)

```cpp
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
```

### 4. Stock Buy and Sell Problem

```cpp
void maxProfit(int prices[], int n) {
    int bestBuy[10];
    bestBuy[0] = INT_MAX;

    for(int i = 1; i < n; i++) {
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }

    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    cout << "Max Profit = " << maxProfit << endl;
}
```

### 5. Trapping Rainwater Problem

```cpp
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
```

### 6. Check for Duplicates

```cpp
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
```

## Algorithm Complexities

### Maximum Subarray Sum

- **Brute Force**: O(n³) time, O(1) space
- **Optimized**: O(n²) time, O(1) space
- **Kadane's**: O(n) time, O(1) space

### Stock Buy/Sell

- **Time Complexity**: O(n)
- **Space Complexity**: O(n) for bestBuy array

### Trapping Rainwater

- **Time Complexity**: O(n)
- **Space Complexity**: O(n) for leftMax and rightMax arrays

## Key Takeaways

- **Kadane's Algorithm**: Most efficient for maximum subarray sum problems
- **Prefix Arrays**: Useful for precomputing values to avoid repeated calculations
- **Greedy Strategy**: Works well for stock profit problems
- **Two Pointers**: Can optimize many array problems
- **Dynamic Programming**: Breaking down problems into overlapping subproblems

## Common Mistakes to Avoid

- Not resetting current sum to 0 in Kadane's algorithm when it becomes negative
- Incorrect calculation of water trapped (forgetting to check if currentWater > 0)
- Not handling edge cases (empty arrays, single element arrays)
- Using nested loops when O(n) solution exists
- Forgetting to initialize variables with appropriate values (INT_MIN, INT_MAX)

## Problem Solving Tips

- **Identify Pattern**: Look for subarray problems that can use Kadane's algorithm
- **Precomputation**: Use prefix arrays when multiple queries are expected
- **Edge Cases**: Always consider arrays with negative numbers, zeros, single elements
- **Optimization**: Look for O(n) solutions instead of O(n²) or O(n³)
