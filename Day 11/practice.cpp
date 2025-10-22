#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int> nums) { 
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++) { 
        if(nums[i-1] == nums[i]) {
            return true;
        }
    }
    return false;
}

int search(vector<int> nums, int target) {
    int si = 0;
    int ei = nums.size()-1;

    while(si <= ei) {
        int mid = si + (ei - si) / 2;
        
        if(nums[mid] == target) {
            return mid;
        }

        if(nums[si] <= nums[mid]) {
            if(nums[si] <= target && target < nums[mid]) {
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        } else {
            if(nums[mid] < target && target <= nums[ei]) {
                si = mid + 1;
            } else {
                ei = mid - 1;
            }
        }
    }

    return -1;
}


int maxProduct(vector<int> nums) { 
    int maxTillNow = nums[0]; 
    int minTillNow = nums[0]; 
    int ans = maxTillNow;
    for (int i=1; i<nums.size(); i++) { 
        int curr = nums[i];
        int tempMaxTillNow = max(curr, max(maxTillNow * curr, minTillNow * curr));
        minTillNow = min(curr, min(maxTillNow * curr, minTillNow * curr)); 
        maxTillNow = tempMaxTillNow;
        ans = max(maxTillNow, ans);
    }
    return ans;
}



int main() {
    /*
    
    * Question 1 : Given an integer array nums, return true if any value appears at least
    * twice in the array, and return false if every element is distinct. [link]
    * Examples :
    * Input: nums = [1,2,3,4]
    * Output: false
    * Input: nums = [1,1,1,3,3,4,3,2,4,2]
    * Output: true
    
    */
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    cout << containsDuplicate(nums) << endl;

    /*
    
    * Question 2 : There is an integer array nums sorted in ascending order (with distinct values).
    * Prior to being passed to your function, nums is possibly rotated at an unknown pivot
    * index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ...,
    * nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7]
    * might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
    * Given the array nums after the possible rotation and an integer target, return the
    * index of target if it is in nums, or -1 if it is not in nums.
    * You must write an algorithm with O(log n) runtime complexity. [link]
    * 
    * Examples :
    * Input: nums = [4,5,6,7,0,1,2], target = 0 Output: 4
    * Input: nums = [4,5,6,7,0,1,2], target = 3 Output: -1
    
    */

    nums.clear();
    nums = {4,5,6,7,0,1,2};
    cout << search(nums, 0) << endl;
    cout << search(nums, 3) << endl;


    /*
    
    * Question 3 : Given an integer array nums, find a sub-array that has the largest
    * product, and return the product. The test cases are generated so that the answer will
    * fit in a 32-bit integer. [link]
    * Note - This Qs might feel difficult as a beginner because it uses DP approach.
    * Examples :
    * Input: nums = [2,3,-2,4]
    * Output: 6
    * Explanation: [2,3] has the largest product 6.
    * Input: intervals =nums = [-2,0,-1]
    * Output: 0
    * Explanation: The result cannot be 2, because [-2,-1] is not a sub-array

    */

    nums.clear();
    nums = {2,3,-2,4};
    cout << maxProduct(nums) << endl;
    nums.clear();
    nums = {-2, 0, -1};
    cout << maxProduct(nums) << endl;

    return 0;
}