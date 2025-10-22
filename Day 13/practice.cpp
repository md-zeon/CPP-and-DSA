#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<vector<int>> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void numberOf7s(vector<vector<int>> arr) {
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            if(arr[i][j] == 7) {
                count++;
            }
        }
    }
    cout << "Number of 7's : " << count << endl;
}

void secondRowSum(vector<vector<int>> arr) {
    int sum = 0;
    for(int i = 1; i < 2; i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            sum += arr[i][j];
        }
    }

    cout << "Sum of Second Row is: " << sum << endl;
}

int main() {
    /*
    
    * Question 1 : Print the number of all 7’s that are in the 2d array.
    * Example :
    * Input - int arr[ ][ ] = { {4,7,8}, {8,8,7} }; n = 2, m = 3
    * Output - 2

    */

    vector<vector<int>> arr = { {4,7,8}, {8,8,7} };
    numberOf7s(arr);

    /*
    
    * Question 2 : Print out the sum of the numbers in the second row of the “nums” array.
    * Example :
    * Input - int nums[ ][ ] = { {1,4,9}, {11,4,3}, {2,2,3} };
    * Output - 18
    
    */
    
    arr.clear();
    arr = { {1,4,9}, {11,4,3}, {2,2,3} };
    secondRowSum(arr);

    /*
    
    * Question 3 : Write a program to Find Transpose of a Matrix. 
    * What is Transpose?
    * Transpose of a matrix is the process of swapping the rows to columns. For a 2x3 
    * matrix,
    * Matrix
    * a11 a12 a13 
    * a21 a22 a23
    * Transposed Matrix 
    * a11 a21
    * a12 a22
    * a13 a23
    
    */


    return 0;
}