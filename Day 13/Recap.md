# Day 13: 2D Arrays

## Topics Covered

- **2D Array Declaration**: Static and dynamic 2D arrays
- **Matrix Traversal**: Row-wise and column-wise traversal
- **Spiral Matrix Traversal**: Clockwise spiral pattern
- **Diagonal Sum**: Primary and secondary diagonal calculations
- **Matrix Search**: Multiple search algorithms for 2D arrays
- **Staircase Search**: Optimized search for sorted 2D arrays

## Key Concepts

1. **2D Array Structure**: Rows and columns organization
2. **Memory Layout**: Row-major order storage
3. **Boundary Conditions**: Handling matrix boundaries in traversals
4. **Search Optimizations**: Different approaches based on matrix properties
5. **Time-Space Tradeoffs**: Choosing algorithms based on constraints

## Code Examples

### 1. Spiral Matrix Traversal

```cpp
void spiralMatrix(int matrix[][4], int n, int m) {
    int sCol, sRow, eCol, eRow;
    sCol = sRow = 0;
    eCol = m - 1, eRow = n - 1;

    while(sRow <= eRow && sCol <= eCol) {
        // top
        for(int j = sCol; j <= eCol; j++) {
            cout << matrix[sRow][j] << " ";
        }

        // right
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
        for(int i = eRow-1; i >= sRow+1; i--) {
            if(sCol == eCol) {
                break;
            }
            cout << matrix[i][sCol] << " ";
        }
        sRow++; sCol++;
        eRow--; eCol--;
    }
}
```

### 2. Diagonal Sum Calculation

```cpp
void diagonalSum(int mat[][4], int n) {
    int sum = 0;

    // O(n) approach
    for(int i = 0; i < n; i++) {
        sum += mat[i][i]; // Primary diagonal
        if(i != n - 1 - i) {
            sum += mat[i][n-i-1]; // Secondary diagonal
        }
    }

    cout << "Diagonal Sum is = " << sum << endl;
}

// Primary diagonal: elements where row == column
// Secondary diagonal: elements where row + column == n-1
```

### 3. Brute Force Search O(n²)

```cpp
void searchWithBruteForce(int mat[][4], int m, int n, int key) {
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
```

### 4. Binary Search in Each Row O(n log n)

```cpp
void searchWithBinarySearch(int mat[][4], int m, int n, int key) {
    for(int i = 0; i < m; i++) {
        int si = 0, ei = n-1;
        while(si <= ei) {
            int mid = (si + ei) / 2;

            if(mat[i][mid] == key) {
                cout << "Element found at (" << i << ", " << mid << ")" << endl;
                return;
            } else if(mat[i][mid] > key) {
                ei = mid - 1;
            } else {
                si = mid + 1;
            }
        }
    }
    cout << "Element not found" << endl;
}
```

### 5. Staircase Search O(n + m)

```cpp
void searchWithStaircaseSearch(int mat[][4], int m, int n, int key) {
    int i = 0, j = m-1;

    while(i < n && j >= 0) {
        if(mat[i][j] == key) {
            cout << "Element found at (" << i << ", " << j << ")" << endl;
            return;
        } else if(mat[i][j] > key) {
            j--;  // Move left
        } else {
            i++;  // Move down
        }
    }
    cout << "Element not found" << endl;
}

// Requirements: Matrix should be sorted row-wise and column-wise
```

## Algorithm Complexities

| Algorithm          | Time Complexity | Space Complexity | Requirements          |
| ------------------ | --------------- | ---------------- | --------------------- |
| Spiral Traversal   | O(n × m)        | O(1)             | None                  |
| Diagonal Sum       | O(n)            | O(1)             | Square matrix         |
| Brute Force Search | O(n × m)        | O(1)             | None                  |
| Binary Search      | O(n log m)      | O(1)             | Sorted rows           |
| Staircase Search   | O(n + m)        | O(1)             | Sorted rows & columns |

## Key Takeaways

- **2D Array Declaration**: `int matrix[rows][cols]` for static arrays
- **Memory Layout**: Elements stored in row-major order
- **Boundary Management**: Careful handling of start and end indices
- **Search Optimization**: Choose algorithm based on matrix properties
- **Spiral Logic**: Four loops for four directions with boundary updates

## Common Mistakes to Avoid

- Incorrect boundary conditions in spiral traversal
- Forgetting to handle square matrix cases in diagonal sum
- Not checking if matrix is sorted before using optimized search
- Array index out of bounds errors
- Incorrect loop termination conditions

## When to Use Which Search

- **Brute Force**: Small matrices, no sorting assumptions
- **Binary Search**: When each row is sorted
- **Staircase Search**: When entire matrix is sorted (both rows and columns)
- **Diagonal Sum**: Only for square matrices

## Matrix Properties

- **Row-Major Order**: Elements of each row are stored contiguously
- **Column Access**: Accessing different rows requires jumping in memory
- **Cache Efficiency**: Row-wise operations are generally faster
- **Transpose**: Swapping rows with columns changes memory access patterns
