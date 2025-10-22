#include <iostream>
#include <vector>

using namespace std;

void funcInt() {
    int *ptr = new int;
    *ptr = 10;
    cout << *ptr << endl;
    delete ptr;
}

void funcArr() {
    int size;
    cin >> size;
    int *ptr = new int[size];
    for(int i = 0; i < size; i++) {
        ptr[i] = i+1;
        cout << ptr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < size; i++) {
        delete &ptr[i]; // delete individual elements
    }
    delete[] ptr; // delete the array
}

void func2D() {
    int rows, cols;
    cout << "Enter Rows: ";
    cin >> rows;
    cout << "Enter Cols: ";
    cin >> cols;

    int **matrix = new int *[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    int x = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // delete 2D array
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i]; // delete individual rows
    }
    delete[] matrix; // delete the entire array
}

vector<int> pairSum(vector<int> arr, int target) {
    int st = 0, end = arr.size()-1;
    int currSum = 0;
    vector<int> ans;
    while(st < end) {
        currSum = arr[st] + arr[end];
        if(currSum == target) {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        } else if(currSum > target) {
            end--;
        } else {
            st++;
        }
    }

    return ans;
}

int main() {
    // funcArr();
    // func2D();


    //& STL: Standard Template Library in C++
    //? It is a library collection of container classes, algorithm and iterators.
    //? It contains the implementation of common data structures like vector, maps, stack etc.

    //& Vectors
    //? It is a dynamic array that can grow and shrink in size. it can resize dynamically in run time.
    // They are stored contiguously in memory.

    // vector<int> vec1;
    // cout << vec1.size() << endl;
    // vector<int> vec2 = {1, 2, 3, 4};
    // cout << vec2.size() << endl;
    // vector<int> vec3(10, -1);
    // cout << vec3.size() << endl;
    // for(int i = 0; i < vec3.size(); i++) {
    //     cout << vec3[i] << " ";
    // }
    // cout << endl;

    // vector<int> vec = {1, 2, 3, 4};
    // cout << "Size : " << vec.size() << endl;
    // cout << "Capacity : " << vec.capacity() << endl;
    // vec.push_back(5);
    // cout << "Size : " << vec.size() << endl;
    // cout << "Capacity : " << vec.capacity() << endl;
    // vec.pop_back();
    // cout << "Size : " << vec.size() << endl;
    // cout << "Capacity : " << vec.capacity() << endl;

    //! Pair Sum

    vector<int> vec = {2, 7, 11, 15};
    int target = 9;
    // vector<int> ans = pairSum(vec, target);
    // cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    //& 2D vector

    vector <vector<int>> matrix = {{1,2,3}, {4,5}, {6,7,8,9}};

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}