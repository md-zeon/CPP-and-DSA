#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> findErrorNums(vector<int>& nums) { 
    vector<int> ans;
    int n = nums.size();
    vector<bool> isPresent(n+1, false);
    for(int i=0; i<n; i++) { 
        if(isPresent[nums[i]]) {
            ans.push_back(nums[i]);
        }
        isPresent[nums[i]] = true;
    }
    for(int i=1; i<isPresent.size(); i++) { 
        if(!isPresent[i]) {
            ans.push_back(i); 
            break;
        }
    }
    return ans;
    //& Note - This solution is brute force & more optimized approaches for the same Qs exist that use Bit Manipulation.
}

int maxArea(vector<int>& height) { 
    int left = 0;
    int right = height.size() - 1; 
    int maxArea = 0;
    while (left < right) {
        int currentArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currentArea);
        if (height[left] < height[right]) { 
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}


vector<vector<int>> threeSum(vector<int>& nums) { 
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin() , nums.end());
    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) { 
            continue;
        }
        int j = i+1; 
        int k= n-1;

        while(j < k){
            int sum = nums[i] + nums[j] + nums[k]; 
            if(sum < 0){
                j++;
            }
            else if(sum > 0){ 
                k--;
            }
            else{
                vector<int> temp = {nums[i] , nums[j] , nums[k]}; 
                ans.push_back(temp);
                j++; 
                k--;
                while(j<k && nums[j] == nums[j-1]) { 
                    j++;
                }
                while(j<k && nums[k] == nums[k+1]) { 
                    k--;
                }
            }
        }
    }
    
    return ans;
}



int main() {
    /*
    
    *  Question 1 : You have a set of integers, which originally contains all the numbers
    *  from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated
    *  to another number in the set, which results in repetition of one number and loss of
    *  another number.
    *  You are given an integer array nums representing the data status of this set after the
    *  error.
    *  Find the number that occurs twice and the number that is missing and return them in
    *  the form of an array. [ Go to Qs ]
    *  Example :
    *  Input: nums = [1,2,2,4]. Output:[2,3]

    */ 
    

    /*
    
    * Question 2 : You are given an integer array height of length n. There are n vertical
    * lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    * Find two lines that together with the x-axis form a container, such that the container
    * contains the most water. Return the maximum amount of water a container can
    * store.
    * Notice that you may not slant the container. [ Go to Qs ]
    * Input: height = [1,8,6,2,5,4,8,3,7]
    * Output: 49
    * Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this
    * case, the max area of water (blue section) the container can contain is 49.

    */

   /*
   
    * Question 3 : Given an integer array nums, return all the triplets [nums[i], nums[j],
    * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    * Notice that the solution set must not contain duplicate triplets. [ Go to Qs ]
    * Input: nums = [-1,0,1,2,-1,-4]
    * Output: [[-1,-1,2],[-1,0,1]]
    * Explanation:
    * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.The
    * distinct triplets are [-1,0,1] and [-1,-1,2].
    * Notice that the order of the output and the order of the triplets does not matter.
    * Input: nums = [0,1,1]Output:
    * [ ]
    * Explanation: The only possible triplet does not sum up to 0.
    * Note - Read up about the in-built sorting of vectors.
   
   */

    return 0;
}