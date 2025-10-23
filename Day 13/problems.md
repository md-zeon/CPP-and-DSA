# Day 13: 2D Arrays - Practice Problems

## Problem 1: Matrix Creation and Input

**Difficulty:** Easy

### Description

Create a 2D array (matrix) and take input from user.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print the matrix

### Sample Input

```
3 3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```
1 2 3
4 5 6
7 8 9
```

### Code Example

```cpp
int rows, cols;
cin >> rows >> cols;
int matrix[rows][cols];

for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
    }
}
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 2: Spiral Matrix Traversal

**Difficulty:** Medium

### Description

Print matrix elements in spiral order (clockwise).

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print elements in spiral order

### Sample Input

```
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
```

### Sample Output

```
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
```

### Algorithm

1. Initialize boundaries: top, bottom, left, right
2. While top <= bottom and left <= right:
   - Print top row (left to right)
   - Print right column (top to bottom)
   - Print bottom row (right to left)
   - Print left column (bottom to top)
3. Update boundaries

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 3: Diagonal Sum

**Difficulty:** Easy

### Description

Calculate sum of both main diagonals in a square matrix.

### Input Format

- Integer `n` (size of square matrix)
- Next `n` lines: `n` integers each

### Output Format

- Print sum of primary and secondary diagonals

### Sample Input

```
3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```
Primary diagonal sum: 15
Secondary diagonal sum: 15
Total: 30
```

### Explanation

- Primary diagonal: 1 + 5 + 9 = 15
- Secondary diagonal: 3 + 5 + 7 = 15

### Algorithm (O(n))

```cpp
int primary = 0, secondary = 0;
for(int i = 0; i < n; i++) {
    primary += matrix[i][i];
    if(i != n-1-i) {
        secondary += matrix[i][n-1-i];
    }
}
```

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 4: Matrix Search (Brute Force)

**Difficulty:** Easy

### Description

Search for an element in a 2D matrix using brute force.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each
- Integer `key` to search

### Output Format

- Print position if found, "Not found" otherwise

### Sample Input

```
3 3
1 2 3
4 5 6
7 8 9
5
```

### Sample Output

```
Found at (1, 1)
```

### Algorithm (O(rows × cols))

```cpp
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        if(matrix[i][j] == key) {
            return true;
        }
    }
}
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 5: Matrix Search (Binary Search)

**Difficulty:** Medium

### Description

Search for an element in a row-wise sorted matrix using binary search.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each (sorted)
- Integer `key` to search

### Output Format

- Print position if found, "Not found" otherwise

### Sample Input

```
4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
33
```

### Sample Output

```
Found at (3, 1)
```

### Algorithm (O(rows × log cols))

```cpp
for(int i = 0; i < rows; i++) {
    // Binary search in row i
    int low = 0, high = cols - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(matrix[i][mid] == key) {
            return true;
        } else if(matrix[i][mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}
```

### Constraints

- 1 ≤ rows, cols ≤ 1000

---

## Problem 6: Matrix Search (Staircase Search)

**Difficulty:** Medium

### Description

Search for an element in a row-wise and column-wise sorted matrix.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each (sorted)
- Integer `key` to search

### Output Format

- Print position if found, "Not found" otherwise

### Sample Input

```
4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
33
```

### Sample Output

```
Found at (3, 1)
```

### Algorithm (O(rows + cols))

```cpp
int i = 0, j = cols - 1;
while(i < rows && j >= 0) {
    if(matrix[i][j] == key) {
        return true;
    } else if(matrix[i][j] > key) {
        j--; // Move left
    } else {
        i++; // Move down
    }
}
```

### Constraints

- 1 ≤ rows, cols ≤ 1000

---

## Problem 7: Transpose of Matrix

**Difficulty:** Easy

### Description

Find the transpose of a given matrix.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print the transposed matrix

### Sample Input

```
2 3
1 2 3
4 5 6
```

### Sample Output

```
1 4
2 5
3 6
```

### Algorithm

```cpp
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        transpose[j][i] = matrix[i][j];
    }
}
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 8: Matrix Addition

**Difficulty:** Easy

### Description

Add two matrices of same dimensions.

### Input Format

- Two integers: `rows` and `cols`
- First matrix (rows × cols)
- Second matrix (rows × cols)

### Output Format

- Print the sum matrix

### Sample Input

```
2 2
1 2
3 4
5 6
7 8
```

### Sample Output

```
6 8
10 12
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 9: Matrix Multiplication

**Difficulty:** Medium

### Description

Multiply two matrices (if compatible).

### Input Format

- Dimensions: `m` `n` `p` (A is m×n, B is n×p)
- Matrix A (m × n)
- Matrix B (n × p)

### Output Format

- Print the product matrix (m × p)

### Sample Input

```
2 3 2
1 2 3
4 5 6
1 0
0 1
1 1
```

### Sample Output

```
1*1 + 2*0 + 3*1 = 4
1*1 + 2*1 + 3*1 = 6
4*1 + 5*0 + 6*1 = 10
4*1 + 5*1 + 6*1 = 15
```

### Algorithm (O(m × n × p))

```cpp
for(int i = 0; i < m; i++) {
    for(int j = 0; j < p; j++) {
        for(int k = 0; k < n; k++) {
            result[i][j] += A[i][k] * B[k][j];
        }
    }
}
```

### Constraints

- 1 ≤ m, n, p ≤ 100

---

## Problem 10: Row-wise Sum

**Difficulty:** Easy

### Description

Calculate sum of each row in a matrix.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print sum of each row

### Sample Input

```
3 3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```
Row 0 sum: 6
Row 1 sum: 15
Row 2 sum: 24
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 11: Column-wise Sum

**Difficulty:** Easy

### Description

Calculate sum of each column in a matrix.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print sum of each column

### Sample Input

```
3 3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```
Col 0 sum: 12
Col 1 sum: 15
Col 2 sum: 18
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 12: Boundary Traversal

**Difficulty:** Medium

### Description

Print only the boundary elements of a matrix.

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print boundary elements

### Sample Input

```
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
```

### Sample Output

```
1 2 3 4 8 12 16 15 14 13 9 5
```

### Algorithm

1. Print first row
2. Print last column (except first element)
3. Print last row in reverse (except first element)
4. Print first column in reverse (except first and last)

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 13: Rotate Matrix 90 Degrees

**Difficulty:** Medium

### Description

Rotate a square matrix 90 degrees clockwise.

### Input Format

- Integer `n` (size of square matrix)
- Next `n` lines: `n` integers each

### Output Format

- Print the rotated matrix

### Sample Input

```
3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```
7 4 1
8 5 2
9 6 3
```

### Algorithm

1. Transpose the matrix
2. Reverse each row

### Constraints

- 1 ≤ n ≤ 100

---

## Problem 14: Find Saddle Point

**Difficulty:** Medium

### Description

Find saddle point in a matrix (minimum in row, maximum in column).

### Input Format

- Two integers: `rows` and `cols`
- Next `rows` lines: `cols` integers each

### Output Format

- Print position of saddle point or "No saddle point"

### Sample Input

```
3 3
1 2 3
4 5 6
7 8 9
```

### Sample Output

```
No saddle point
```

### Sample Input (with saddle point)

```
3 3
6 3 9
1 8 2
4 5 7
```

### Sample Output

```
Saddle point at (1, 1) with value 8
```

### Constraints

- 1 ≤ rows, cols ≤ 100

---

## Problem 15: Matrix is Identity Matrix

**Difficulty:** Easy

### Description

Check if a square matrix is an identity matrix.

### Input Format

- Integer `n` (size of square matrix)
- Next `n` lines: `n` integers each

### Output Format

- Print "Identity Matrix" or "Not Identity Matrix"

### Sample Input

```
3
1 0 0
0 1 0
0 0 1
```

### Sample Output

```
Identity Matrix
```

### Algorithm

```cpp
bool isIdentity = true;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        if((i == j && matrix[i][j] != 1) ||
           (i != j && matrix[i][j] != 0)) {
            isIdentity = false;
        }
    }
}
```

### Constraints

- 1 ≤ n ≤ 100

---

## Additional Practice Problems

### Problem 16: Matrix is Symmetric

Check if a square matrix is symmetric.

### Problem 17: Matrix is Skew-Symmetric

Check if a square matrix is skew-symmetric.

### Problem 18: Search in Row-wise and Column-wise Sorted Matrix

Implement efficient search in sorted 2D matrix.

### Problem 19: Print Matrix in Wave Form

Print matrix elements in wave pattern.

### Problem 20: Find Maximum Element in Matrix

Find maximum element and its position.

### Problem 21: Sort Matrix Rows

Sort each row of the matrix individually.

### Problem 22: Sort Matrix Columns

Sort each column of the matrix individually.

### Problem 23: Matrix Chain Multiplication

Find minimum cost to multiply matrix chain.

### Problem 24: Boolean Matrix Problem

Set entire row and column to 1 if any element is 1.

### Problem 25: Print Matrix Diagonally

Print matrix elements diagonally.

## 2D Array Concepts

### 1. Memory Layout

- **Row-major order:** Elements stored row by row
- **Column-major order:** Elements stored column by column
- C++ uses row-major order by default

### 2. Matrix Types

- **Square Matrix:** rows == cols
- **Rectangular Matrix:** rows != cols
- **Diagonal Matrix:** Non-diagonal elements are zero
- **Identity Matrix:** Diagonal elements are 1, others zero
- **Symmetric Matrix:** matrix[i][j] == matrix[j][i]

### 3. Matrix Operations

- **Transpose:** Swap rows and columns
- **Addition:** Element-wise addition
- **Multiplication:** Row × Column dot product
- **Rotation:** 90°, 180°, 270° rotations

### 4. Traversal Patterns

- **Row-wise traversal**
- **Column-wise traversal**
- **Spiral traversal**
- **Diagonal traversal**
- **Boundary traversal**

## Key Takeaways

### Common Patterns

```cpp
// Pattern 1: Matrix input
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
    }
}

// Pattern 2: Matrix output
for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}

// Pattern 3: Spiral traversal
int top = 0, bottom = rows-1, left = 0, right = cols-1;
while(top <= bottom && left <= right) {
    // Top row
    for(int j = left; j <= right; j++) {
        cout << matrix[top][j] << " ";
    }
    top++;
    // Right column
    for(int i = top; i <= bottom; i++) {
        cout << matrix[i][right] << " ";
    }
    right--;
    // Bottom row (if needed)
    if(top <= bottom) {
        for(int j = right; j >= left; j--) {
            cout << matrix[bottom][j] << " ";
        }
        bottom--;
    }
    // Left column (if needed)
    if(left <= right) {
        for(int i = bottom; i >= top; i--) {
            cout << matrix[i][left] << " ";
        }
        left++;
    }
}
```

### Best Practices

- **Fixed size arrays:** Use constants for dimensions
- **Dynamic allocation:** Use vectors for variable sizes
- **Boundary checks:** Always check array bounds
- **Memory layout:** Understand row-major vs column-major

### Common Mistakes

- **Array bounds:** Accessing invalid indices
- **Variable size arrays:** Not supported in some compilers
- **Memory waste:** Large fixed-size arrays
- **Transpose logic:** Incorrect swapping logic

### Optimization Tips

- **Cache friendly:** Access elements in row-major order
- **Block processing:** Process matrix in blocks for large matrices
- **Vector of vectors:** Use for dynamic sized matrices
- **Bit manipulation:** For certain matrix operations

### Interview Tips

- **Matrix traversal:** Know different traversal patterns
- **Search algorithms:** Brute force vs optimized approaches
- **Space complexity:** Consider auxiliary space needed
- **Edge cases:** Single element, single row/column matrices
- **Real-world applications:** Image processing, graphs, etc.

### Applications

1. **Image Processing**

   - Pixel manipulation
   - Filters and effects
   - Computer vision

2. **Graph Representation**

   - Adjacency matrix
   - Distance matrix
   - Transition matrix

3. **Mathematical Computing**

   - Linear algebra
   - Numerical analysis
   - Scientific computing

4. **Game Development**

   - Game boards
   - Tile maps
   - Grid-based games

5. **Data Analysis**
   - Spreadsheets
   - Statistical analysis
   - Data visualization
