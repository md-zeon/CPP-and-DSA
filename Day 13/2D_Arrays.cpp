#include <iostream>

using namespace std;

void spiralMatrix(int matrix[][4], int n, int m) {
    int sCol, sRow, eCol, eRow;
    sCol = sRow = 0;
    eCol = m - 1, eRow = n - 1;
    while(sRow <= eRow && sCol <= eCol) { //odd matrix
        // top
        for(int j = sCol; j <= eCol; j++) {
            cout << matrix[sRow][j] << " ";
        }

        //right
        for(int i = sRow+1; i <= eRow; i++) {
            cout << matrix[i][eCol] << " ";
        }

        // bottom
        for(int j = eCol-1; j >= sCol; j--) {
            if(sRow == eRow) {
                break;
            }
            cout << matrix[eRow][j] << " ";
        }

        // left
        for(int i = eRow-1; i >= sRow+1; i--)  {
            if(sCol == eCol) {
                break;
            }
            cout << matrix[i][sCol] << " ";
        }
        sRow++; sCol++;
        eRow--; eCol--;
    }
}

void diagonalSum(int mat[][4], int n) {
    int sum = 0;
    // O(n^2)
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(i == j) {
    //             sum+= mat[i][j];
    //         } else if(j == n-i-1) {
    //             sum+= mat[i][j];
    //         }
    //     }
    // }

    //O(n)
    for(int i = 0; i < n;  i++) {
        sum += mat[i][i]; // pd
        if(i != n - 1 - i) {
            sum += mat[i][n-i-1]; // sd
        }
    }

    cout << endl << "Diagonal Sum is = " << sum << endl;
}

void searchWithBruteForce(int mat[][4], int m, int n, int key) {
    //O(n^2)
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == key) {
                cout << "Element found at (" << i << ", " << j << ")" << endl;
                return;
            }
        }
    }
    cout << "Element not found" << endl;
}

void searchWithBinarySearch(int mat[][4], int m, int n, int key) {
    //O(nlogn)
    for(int i = 0; i < m; i++) {
        int si = 0, ei = n-1;
        while(si <= ei) {
            int mid = (si + ei) / 2;

            if(mat[i][mid] == key) {
                cout << "Element found at (" << i << ", " << mid << ")" << endl;
                return;
            } else if(mid > key) {
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }
    }
    cout << "Element not found" << endl;
}

void searchWithStaircaseSearch(int mat[][4], int m, int n, int key) {
    int i = 0, j = m-1;
    //O(n+m)
    while(i < n && j >= 0) {
        if(mat[i][j] == key) {
            cout << "Element found at (" << i << ", " << j << ")" << endl;
            return;
        } else if(mat[i][j] > key) {
            j--;
        } else {
            i++;
        }
    }
    cout << "Element not found" << endl;
}


int main() {
    int matrix[4][4] = {{1, 2, 3, 4},
                 {5, 6, 7, 8},
                 {9, 10, 11, 12},
                 {13, 14, 15, 16} };
    
    // spiralMatrix(matrix, 4, 4);
    // diagonalSum(matrix, 4);

    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    // searchWithBruteForce(mat, 4, 4, 33);
    // searchWithBinarySearch(mat, 4, 4, 33);
    searchWithStaircaseSearch(mat, 4, 4, 33);
    

    return 0;
}