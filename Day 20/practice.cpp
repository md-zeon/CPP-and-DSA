#include <iostream>
#include <string>
using namespace std;

int binSearch(int arr[], int si, int ei, int key) {
    if(si > ei) {
        return -1;
    }
    int mid = si + (ei - si)/2;
    if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] > key) { //left half call
        return binSearch(arr, si, mid-1, key);
    } else { //right half call
        return binSearch(arr, mid+1, ei, key);
    }
}

void allOccurrences(int arr[], int key, int i, int n) {
    if(i == n) {
        return;
    }
    if(arr[i] == key) {
        cout << i << " ";
    }

    allOccurrences(arr, key, i+1, n);
}

int countSubstrs(string str, int i, int j, int n) {
    if (n == 1) {
        return 1;
    }
    if (n <= 0) {
        return 0;
    }

    int res = countSubstrs(str, i + 1, j, n - 1) + countSubstrs(str, i, j - 1, n - 1) - countSubstrs(str, i + 1, j - 1, n - 2);

    if (str[i] == str[j]) {
        res++;
    }

    return res;
}


void towerOfHanoi(int n, string src, string helper, string dest) {
if(n == 1) {
cout << "transfer disk " << n << " from " << src << " to " << dest << endl;
return;
}
//transfer top n-1 from src to helper using dest as 'helper'
towerOfHanoi(n-1, src, dest, helper);
//transfer nth from src to dest
cout << "transfer disk " << n << " from " << src << " to " << helper << endl;
//transfer n-1 from helper to dest using src as 'helper'
towerOfHanoi(n-1, helper, src, dest);
}


int MOD = 109 + 7;

long long power(long long a,long long b){
    if(b==0) {
        return 1;
    }
    long long half_power= power(a,b/2);
    if(b%2 ==0){
        return half_power*half_power % MOD;
    } else {
        return half_power*half_power % MOD * (a % MOD) % MOD ;
    }
}


int countGoodNumbers(long long n) {
    long long ed;
    long long od;
    if(n&1) {
        od=n/2;
        ed=(n+1)/2;
    }
    else {
        od=n/2;
        ed=n/2;
    }

    return ((power(5,ed)%MOD)*(power(4,od)%MOD))%MOD;
}



int main() {
    /*

        * Question 1 : Write a recursive function to perform Binary Search.
        * Input : arr[ ] = {1, 2, 3, 4, 5, 6, 7}, n = 7, key = 5
        * Output : 4 (index of key)
        * *Use the starting index & ending index logic used in rotated, sorted array Qs.

    */


    /*
        * Question 2 : For a given integer array of size N. You have to find all the occurrences
        * (indices) of a given element (Key) and print them.
        * Use a recursive function to solve this problem.
        * Sample Input : arr[ ] = {3, 2, 4, 5, 6, 2, 7, 2, 2}, key = 2
        * Sample Output : 1 5 7 8
        
    */


    /*
        
        * Question 3 : We are given a string S, we need to find the count of all contiguous
        * substrings starting and ending with the same character. [Leetcode Premium Qs]
        * Sample Input 1 : S = "abcab"
        * Sample Output 1 : 7
        * There are 15 substrings of "abcab" : a, ab, abc, abca, abcab, b, bc, bca, bcab, c, ca, cab, a,
        * ab, b
        * Out of the above substrings, there are 7 substrings : a, abca, b, bcab, c, a and b. So, only
        * 7 contiguous substrings start and end with the same character.
        * Sample Input 2 : S = "aba"Sample
        * Output 2 : 4
        * The substrings are a, b, a and aba
        
    */

    string str = "abcab";
    int n = str.size();
    cout << countSubstrs(str, 0, n-1, n) <<endl;


    /*
        
        * Question 4 : TOWER OF HANOI (Important!)
        * You have 3 towers and N disks of different sizes which can slide onto any tower. The
        * puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each
        * disk sits on top of an even larger one).
        * You have the following constraints:
        * (1) Only one disk can be moved at a time.
        * (2) A disk is slid off the top of one tower onto another tower.
        * (3) A disk cannot be placed on top of a smaller disk. Write a program to move the disks
        * from the first tower to the
        * last using Stacks.
        * Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.
        * An example with 2 disks i.e. N=2:
        * Step 1 : Shift the first disk from 'A' to 'B'.
        * Step 2 : Shift the second disk from 'A' to 'C'.
        * Step 3 : Shift the first disk from 'B' to 'C'.
        * An example with 3 disks i.e. N=3 :
        * Step 1 : Shift the first disk from 'A' to 'C'.
        * Step 2 : Shift second disk from 'A' to 'B'.
        * Step 3 : Shift the first disk from 'C' to 'B'.
        * Step 4 : Shift the third disk from 'A' to 'C'.
        * Step 5 : Shift the first disk from 'B' to 'A'.
        * Step 6 : Shift second disk from 'B' to 'C'.
        * Step 7 : Shift the first disk from 'A' to 'C'.
        * 
        * 
        * The Approach here is :
        * - Shift 'n-1' disks from 'A' to 'B', using C.
        * - Shift the last disk from 'A' to 'C'.
        * - Shift 'n-1' disks from 'B' to 'C', using A.
        
    */

    int n = 4;
    towerOfHanoi(4, "A", "B", "C");


    /*
        * Question 5 : A digit string is good if the digits (0-indexed) at even indices are even and
        * the digits at odd indices are prime (2, 3, 5, or 7).
        * For example, "2582" is good because the digits (2 and 8) at even positions are even and
        * the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is
        * at an even index but is not even.
        * Given an integer n, return the total number of good digit strings of length n. Since the
        * answer may be large, return it modulo 109 + 7.
        * A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
        * [Go to Question]
        * Input: n = 1
        * Output: 5
        * Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
        * Hint : This Qs uses the binary exponentiation technique we learnt in the Bit Manipulation
        * chapter.
        
    */


    return 0;
}