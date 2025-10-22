#include <iostream>
#include <vector>
using namespace std;

void clearBitsInRange(int num, int i, int j) { 
    int a = (~0) << (j+1);
    int b = (1 << i) - 1;
    int mask = a | b; 
    num = num & mask;
    cout << num << endl;
}

int singleNumber(vector<int>& nums) { 
    int answer = 0;
    for(int i=0; i<nums.size(); i++) { 
        answer ^= nums[i];
    }
    return answer;
}

int xorBeauty(vector<int>& nums) { 
    int a = 0, b = 0;
    for(int i=0; i<nums.size(); i++){
        a = a | nums[i];
        b = b ^ nums[i];
    }

    return ( a & b );
}

int main() {
    /*
    & Question 1 : //* Write a Function to clear the range of bits from i to j in a given number. (i 
    * & j are counted backwards from the right end of the number)
    * Examples :
    * Input : num = 15, i = 1, j = 3 Output 
    * : 1
    * Explanation :
    * 15 in binary form is => 00001111 [i=1st & j=3rd bit underlined] 
    * After bits are cleared, number will become 00000001
    * Input : num = 31, i = 1, j = 3 Output 
    * : 17
    * Note - Think about what type of bit mask is needed. It can also be a combination of 2 
    * numbers.
    * 
    * 
    * 
    & Question 2 ://* Given a non-empty array of integers nums, every element appears twice 
    * except for one. Find that single one.
    * You must implement a solution with a linear runtime complexity and use only
    * constant extra space. [ Go to Qs ]
    * Hint - Think XOR.
    * 
    * 
    * 
    & Question 3 ://* You are given a 0-indexed integer array nums.
    * The effective value of three indices i, j, and k is defined as ((nums[i] | nums[j]) & 
    * nums[k]).
    * The xor-beauty of the array is the XORing of the effective values of all the possible triplets 
    * of indices (i, j, k) where 0 <= i, j, k < n.
    * Return the xor-beauty of nums. [ Go to Qs ]
    * 
    * 
    & Extra Qs ://* Given two integers dividend and divisor, divide two integers without using 
    * multiplication, division, and mod operator. [ Go to Qs ]

    */

    return 0;
}