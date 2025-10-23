# Day 24: Backtracking

## Topics Covered

- **Backtracking Basics**: Trial and error problem solving
- **Subset Generation**: Finding all subsets of a set
- **String Permutations**: All arrangements of characters
- **N-Queens Problem**: Placing queens without attacks
- **Grid Path Counting**: Finding paths in a grid
- **Sudoku Solver**: Solving 9×9 Sudoku puzzles

## Key Concepts

1. **Decision Making**: Choose, explore, backtrack pattern
2. **State Management**: Track current state and constraints
3. **Base Cases**: Conditions for success or failure
4. **Constraint Checking**: Validate moves before proceeding
5. **Recursive Exploration**: Depth-first search with backtracking

## Code Examples

### 1. Array Manipulation with Backtracking

```cpp
void changeArr(int arr[], int n, int i) {
    if(i == n) {
        printArr(arr, n);
        return;
    }

    arr[i] = i + 1;           // Make choice
    changeArr(arr, n, i + 1); // Explore
    arr[i] -= 2;              // Backtrack
}

// Example: changeArr(arr, 5, 0)
// Makes choices and backtracks to explore all possibilities
```

### 2. Subset Generation

```cpp
void printSubsets(string str, string subset) {
    if(str.size() == 0) {
        cout << subset << endl;  // Base case: print subset
        return;
    }

    char ch = str[0];

    // Include current character
    printSubsets(str.substr(1), subset + ch);

    // Exclude current character
    printSubsets(str.substr(1), subset);
}

// Example: printSubsets("abc", "")
// Generates: "", "a", "b", "c", "ab", "ac", "bc", "abc"
```

### 3. String Permutations

```cpp
void permutations(string str, string ans) {
    if(str.size() == 0) {
        cout << ans << endl;  // Base case: print permutation
        return;
    }

    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1);
        permutations(nextStr, ans + ch);  // Choose each character
    }
}

// Example: permutations("abc", "")
// Generates: abc, acb, bac, bca, cab, cba
```

### 4. N-Queens Problem

```cpp
bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();

    // Check horizontal
    for(int j = 0; j < n; j++) {
        if(board[row][j] == 'Q') return false;
    }

    // Check vertical
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 'Q') return false;
    }

    // Check diagonal (top-left)
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') return false;
    }

    // Check diagonal (top-right)
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') return false;
    }

    return true;
}

int nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        printBoard(board);  // Solution found
        return 1;
    }

    int count = 0;
    for(int j = 0; j < n; j++) {  // Try each column
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';           // Place queen
            count += nQueens(board, row + 1); // Recurse
            board[row][j] = '.';           // Backtrack
        }
    }
    return count;  // Return number of solutions
}
```

### 5. Grid Ways (Path Counting)

```cpp
int gridWays(int r, int c, int n, int m, string ans) {
    if(r == n - 1 && c == m - 1) {
        cout << ans << endl;  // Reached destination
        return 1;
    }

    if(r >= n || c >= m) {
        return 0;  // Out of bounds
    }

    // Move right
    int val1 = gridWays(r, c + 1, n, m, ans + 'R');

    // Move down
    int val2 = gridWays(r + 1, c, n, m, ans + 'D');

    return val1 + val2;  // Total ways
}

// Example: gridWays(0, 0, 3, 3, "")
// Finds all paths from (0,0) to (2,2) using R and D moves
```

### 6. Sudoku Solver

```cpp
bool isItSafe(int sudoku[9][9], int row, int col, int digit) {
    // Check vertical
    for(int i = 0; i <= 8; i++) {
        if(sudoku[i][col] == digit) return false;
    }

    // Check horizontal
    for(int j = 0; j <= 8; j++) {
        if(sudoku[row][j] == digit) return false;
    }

    // Check 3×3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for(int i = startRow; i <= startRow + 2; i++) {
        for(int j = startCol; j <= startCol + 2; j++) {
            if(sudoku[i][j] == digit) return false;
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    if(row == 9) {
        printSudoku(sudoku);  // Solved
        return true;
    }

    // Move to next cell
    int nextRow = row;
    int nextCol = col + 1;
    if(col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // Skip filled cells
    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    // Try digits 1-9
    for(int digit = 1; digit <= 9; digit++) {
        if(isItSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;              // Place digit
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;                       // Solution found
            }
            sudoku[row][col] = 0;                  // Backtrack
        }
    }
    return false;  // No solution found
}
```

## Backtracking Pattern

### 1. Base Case

- **Success**: Problem solved (print result, return true)
- **Failure**: Invalid state (return false, stop exploration)
- **Completion**: All decisions made (process result)

### 2. Choice Making

- **Options**: Generate all possible choices
- **Constraints**: Check if choice is valid
- **State Update**: Apply choice to current state

### 3. Recursive Exploration

- **Depth-First**: Explore one path completely
- **Branching**: Try each valid choice
- **State Passing**: Pass updated state to recursive calls

### 4. Backtracking

- **Undo Changes**: Restore state after exploration
- **Clean Up**: Remove choices that didn't work
- **Continue**: Try next alternative

## Algorithm Analysis

### Time Complexity

- **Subset Generation**: O(2^n) - exponential
- **Permutations**: O(n!) - factorial
- **N-Queens**: O(n!) worst case, but optimized with constraints
- **Grid Ways**: O(2^(n+m)) - exponential paths
- **Sudoku**: O(9^(n²)) in worst case

### Space Complexity

- **Call Stack**: O(n) for recursion depth
- **State Storage**: O(n²) for 2D problems like Sudoku
- **Result Storage**: Varies based on problem requirements

## Key Takeaways

- **Decision Tree**: Each choice creates a new branch
- **Pruning**: Stop exploring invalid branches early
- **State Management**: Track current configuration
- **Base Cases**: Define when to stop recursion
- **Backtracking**: Essential for undoing choices

## Common Mistakes to Avoid

- Forgetting to backtrack (not undoing changes)
- Incorrect base case conditions
- Not checking constraints before making choices
- Stack overflow due to deep recursion
- Not handling edge cases (n=0, n=1)

## Optimization Techniques

### 1. Constraint Checking

- **Early Termination**: Stop when constraints violated
- **Feasibility**: Check if solution possible before exploring
- **Pruning**: Eliminate branches that can't lead to solution

### 2. State Optimization

- **Bit Manipulation**: Use bits for state representation
- **Memoization**: Cache results of subproblems
- **Symmetry**: Avoid exploring symmetric solutions

### 3. Algorithm Selection

- **Dynamic Programming**: For counting problems
- **Greedy**: When optimal choice can be made locally
- **Branch and Bound**: For optimization problems

## Applications

### 1. Puzzle Solving

- **Sudoku**: Constraint satisfaction
- **Crossword**: Word placement
- **Chess**: Game tree exploration

### 2. Combinatorial Problems

- **Permutations**: All arrangements
- **Combinations**: All subsets
- **Paths**: All routes in graph

### 3. Optimization

- **Traveling Salesman**: Finding optimal tour
- **Knapsack**: Optimal item selection
- **Scheduling**: Optimal resource allocation

### 4. Game Theory

- **Tic-Tac-Toe**: Finding winning strategies
- **Chess**: Move evaluation
- **Checkers**: Game state exploration

## Interview Tips

- **Pattern Recognition**: Identify backtracking opportunities
- **State Design**: Think about what state to track
- **Base Cases**: Define clear stopping conditions
- **Constraints**: Implement efficient constraint checking
- **Edge Cases**: Test with small inputs (n=1, n=2)

## Problem Variations

- **Rat in Maze**: Finding path through maze
- **Knight's Tour**: Chess knight visiting all squares
- **Graph Coloring**: Assigning colors to vertices
- **Subset Sum**: Finding subsets with target sum
- **Hamiltonian Path**: Visiting all vertices once

## Performance Considerations

- **Exponential Time**: Only feasible for small n
- **Memory Usage**: Track recursion depth
- **Optimization**: Look for symmetry and constraints
- **Alternative Approaches**: Consider DP or greedy when applicable
