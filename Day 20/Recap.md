# Day 20: Recursion Part 2

## Topics Covered

- **Tiling Problem**: Dynamic programming with recursion
- **String Manipulation**: Removing duplicates recursively
- **Friends Pairing**: Combinatorial problem solving
- **Binary String Generation**: Constrained string generation
- **Multiple Parameters**: Passing additional state in recursion
- **Boolean Arrays**: Using maps for tracking state

## Key Concepts

1. **State Management**: Tracking additional information in recursive calls
2. **Combinatorial Problems**: Counting ways using recursion
3. **String Processing**: Recursive string manipulation
4. **Constraint Handling**: Managing constraints in recursive solutions
5. **Memoization Ready**: Problems that benefit from caching

## Code Examples

### 1. Tiling Problem (2×n Floor with 2×1 Tiles)

```cpp
int tilingProblem(int n) {
    if(n == 0 || n == 1) {
        return 1;  // Base cases
    }

    int vertical = tilingProblem(n-1);   // Place tile vertically
    int horizontal = tilingProblem(n-2); // Place two tiles horizontally
    int ways = vertical + horizontal;

    return ways;
}

// Example: tilingProblem(3)
// Ways: 3 (VVV, HH, VH)
// V = Vertical tile, H = Horizontal tiles
```

### 2. Remove Duplicates from String (Two Approaches)

#### Approach 1: Left to Right

```cpp
void removeDuplicates(string str, string ans, int i, bool map[]) {
    if(i == str.size()) {
        cout << "Ans : " << ans << endl;
        return;
    }

    int mapIdx = (int)(str[i] - 'a');
    if(map[mapIdx]) { // Duplicate found
        removeDuplicates(str, ans, i+1, map);
    } else { // Not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ans + str[i], i+1, map);
    }
}
```

#### Approach 2: Right to Left

```cpp
void removeDuplicates(string str, string ans, bool map[]) {
    if(str.size() == 0) {
        cout << "Ans : " << ans << endl;
        return;
    }

    int n = str.size();
    char ch = str[n-1];
    str = str.substr(0, n-1);

    int mapIdx = (int)(ch - 'a');
    if(map[mapIdx]) { // Duplicate
        removeDuplicates(str, ans, map);
    } else { // Not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ch + ans, map);
    }
}
```

### 3. Friends Pairing Problem

```cpp
int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;  // Base cases
    }

    int single = friendsPairing(n-1);        // nth person stays single
    int pair = friendsPairing(n-2) * (n-1);  // nth person pairs with someone
    return single + pair;
}

// Example: friendsPairing(3)
// Ways: 4
// 1. All single: A, B, C
// 2. A pairs with B, C single: (AB), C
// 3. A pairs with C, B single: (AC), B
// 4. B pairs with C, A single: A, (BC)
```

### 4. Binary String Generation (No Consecutive 1s)

```cpp
void binaryString(int n, int lastPlace, string ans) {
    if(n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != 1) {
        binaryString(n-1, 0, ans + '0');  // Place 0
        binaryString(n-1, 1, ans + '1');  // Place 1
    } else {
        binaryString(n-1, 0, ans + '0');  // Only place 0 after 1
    }
}

// Example: binaryString(3, 0, "")
// Valid strings: 000, 001, 010, 100, 101
// Invalid: 011, 110, 111 (consecutive 1s)
```

## Problem Analysis

### 1. Tiling Problem

- **Pattern**: Fibonacci-like recurrence
- **Base Cases**: n=0, n=1
- **Recursive Cases**: Last tile vertical or horizontal
- **Time Complexity**: O(2^n) - exponential
- **Space Complexity**: O(n) - call stack

### 2. Remove Duplicates

- **State Tracking**: Boolean array for character occurrence
- **Two Approaches**: Process from left or right
- **Character Mapping**: Convert char to index (0-25)
- **String Building**: Accumulate result in ans parameter

### 3. Friends Pairing

- **Combinatorial**: Counting ways to pair people
- **Single Choice**: Person can remain single
- **Pair Choice**: Person can pair with any of remaining (n-1) people
- **Overlapping**: Same as Fibonacci but with multiplication

### 4. Binary String

- **Constraints**: No two consecutive 1s
- **State Parameter**: Track last placed character
- **Decision Making**: Place 0 always, place 1 only if last was 0
- **Generation**: All valid binary strings of length n

## Recursion Patterns

### 1. State-Based Recursion

- **Additional Parameters**: Track state (lastPlace, map, etc.)
- **Decision Making**: Use state to determine valid moves
- **Examples**: Binary strings, tiling with constraints

### 2. String Processing Recursion

- **String Reduction**: Process one character at a time
- **Result Building**: Accumulate result in parameter
- **Index Tracking**: Use indices or substring operations

### 3. Combinatorial Recursion

- **Counting Ways**: Return sum of different choices
- **Choice Multiplication**: Ways multiply when choices are independent
- **Base Cases**: Simple cases (n=0, n=1, n=2)

## Key Takeaways

- **State Management**: Use additional parameters to track state
- **Boolean Arrays**: Efficient way to track used items
- **String Building**: Pass result as parameter to avoid global variables
- **Constraint Handling**: Use conditions to enforce problem constraints
- **Multiple Choices**: Sum or multiply choices based on problem type

## Common Mistakes to Avoid

- Not properly managing state parameters
- Incorrect base case conditions
- Forgetting to reset state for new recursive calls
- String index confusion (0-based vs length-based)
- Not handling edge cases (empty strings, n=0)

## Optimization Opportunities

### Memoization

- **Tiling Problem**: Cache results for each n
- **Friends Pairing**: Store computed values
- **Pattern**: Use array or map to store computed results

### Dynamic Programming

- **Bottom-Up**: Solve smaller problems first
- **Space Optimization**: Use variables instead of arrays
- **Time Improvement**: O(n) instead of exponential

## Problem Variations

### 1. Tiling Variations

- **Different Tiles**: 2×1 and 2×2 tiles
- **Grid Tiling**: 2D grid instead of 1D floor
- **Colored Tiles**: Tiles with different colors

### 2. String Problems

- **Permutations**: Generate all unique permutations
- **Subsequences**: Find all subsequences
- **Edit Distance**: Minimum operations to transform strings

### 3. Combinatorial Problems

- **Staircase**: Ways to climb stairs (1 or 2 steps)
- **Coin Change**: Ways to make change with coins
- **Subset Sum**: Find subsets with given sum

## Time Complexities

| Problem           | Time Complexity | Space Complexity | Optimization |
| ----------------- | --------------- | ---------------- | ------------ |
| Tiling            | O(2^n)          | O(n)             | O(n) with DP |
| Remove Duplicates | O(n)            | O(n)             | O(n)         |
| Friends Pairing   | O(2^n)          | O(n)             | O(n) with DP |
| Binary String     | O(2^n)          | O(n)             | O(n) with DP |

## Applications

- **Dynamic Programming**: Many problems have recursive solutions
- **Backtracking**: State-based recursion for constraint satisfaction
- **Combinatorics**: Counting problems in mathematics
- **String Algorithms**: Text processing and pattern matching
- **Game Theory**: Optimal strategies in games

## Interview Tips

- **Recognize Patterns**: Fibonacci-like problems
- **State Parameters**: Think about what state to track
- **Base Cases**: Always define clear stopping conditions
- **Memoization**: Look for overlapping subproblems
- **Edge Cases**: Test with n=0, n=1, n=2
