#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int n, int i) {
    if(i == n) {
        printArr(arr, n);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;
}

void printSubsets(string str, string subset) {
    if(str.size() == 0) {
        cout << subset << endl;
        return;
    }
    char ch = str[0];

    // yes
    printSubsets(str.substr(1, str.size()-1), subset+ch);
    // no
    printSubsets(str.substr(1, str.size()-1), subset);
}

void permutations(string str, string ans) {
    int n = str.size();
    if(n == 0) {
        cout << ans << "\n";
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i+1, n - i - 1);
        permutations(nextStr, ans + ch); // ith char choice to add in perm
    }
}

void printBoard(vector <vector<char>> board) {
    int n = board.size();
    cout << "------------------\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector <vector<char>> board, int row, int col) {
    int n = board.size();
    // horizontal
    for(int j = 0; j < n; j++) {
        if(board[row][j] == 'Q') {
            return false;
        }
    }

    // vertical

    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    // diagonal left

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    // diagonal right

    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

int nQueens(vector <vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        printBoard(board);
        return 1;
    }
    int count = 0;

    for(int j = 0; j < n; j++) { // cols
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';
        }
    }
    return count; // no of possible solutions at each level
}

int gridWays(int r, int c, int n, int m, string ans) {
    if(r == n-1 && c == m-1) {
        cout << ans << endl;
        return 1;
    }

    if(r >= n || c >= m) {
    
        return 0;
    }


    //right
    int val1 = gridWays(r, c+1, n, m, ans+'R');

    //down
    int val2 = gridWays(r+1, c, n, m, ans+'D');

    return val1 + val2;
}

void printSudoku(int sudoku[][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool isItSafe(int sudoku[9][9], int row, int col, int digit) {
    //vertical
    for(int i = 0; i <= 8; i++) {
        if(sudoku[i][col] == digit) {
            return false;
        }
    }

    //horizontal
    for(int j = 0; j <= 8; j++) {
        if(sudoku[row][j] == digit) {
            return false;
        }
    }

    // 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for(int i = startRow; i <= startRow+2; i++) {
        for(int j = startCol; j <= startCol+2; j++) {
            if(sudoku[i][j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    if(row == 9) {
        //sudoku solve
        printSudoku(sudoku);
        return true;
    }
    int nextRow = row;
    int nextCol = col+1;
    if(col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }
    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for(int digit = 1; digit <= 9; digit++) {
        if(isItSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}


int main() {
    // int arr[5] = {0};
    // changeArr(arr, 5, 0);
    // printArr(arr, 5);

    //! Find & print all Subsets of a given string
    // string str = "abc";
    // string subset = "";
    // printSubsets(str, subset);

    //! Find & print all permutations (arrangements) of a given string.
    // str = "abc";
    // string ans = "";
    // permutations(str, ans);

    //! N Queens: Place N queens on NxN chess board such that no 2 queens can attack each other.
    // vector <vector<char>> board;
    // int n = 2;
    // for(int i = 0; i < n; i++) {
    //     vector<char> newRow;
    //     for(int j = 0; j < n; j++) {
    //         newRow.push_back('.');
    //     }
    //     board.push_back(newRow);
    // }

    // int count = nQueens(board, 0);
    // cout << "Count : " << count << endl;

    //! Grid Ways: Find number of ways to reach from (0,0) to (N-1, M-1) in a NxM Grid.
    //! Allowed moves -> right & down
    // int n = 3;
    // int  m = 3;
    // string ans = "";
    // cout << "Ways = " << gridWays(0, 0, n, m, ans) << endl;

    //! Sudoku Solver

    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};
     cout << "isSolved: " << sudokuSolver(sudoku, 0, 0);

    return 0;
}

