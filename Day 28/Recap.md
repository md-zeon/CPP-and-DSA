# Day 28: Advanced Stack Problems

## Topics Covered

- **Next Greater Element**: Finding next larger element for each array element
- **Valid Parentheses**: Checking balanced brackets using stack
- **Duplicate Parentheses**: Detecting redundant parentheses in expressions
- **Largest Rectangle in Histogram**: Maximum area calculation using stack
- **Monotonic Stack**: Maintaining stack in increasing/decreasing order
- **Nearest Smaller Elements**: Finding boundaries for area calculations

## Key Concepts

1. **Monotonic Stack**: Stack that maintains elements in sorted order
2. **Bracket Matching**: Using stack for parentheses validation
3. **Area Calculation**: Using nearest smaller elements for width calculation
4. **Stack Optimization**: O(n) solutions for O(n²) problems
5. **Boundary Detection**: Finding left and right boundaries efficiently

## Code Examples

### 1. Next Greater Element

```cpp
void nextGreater(vector<int> arr, vector<int> ans) {
    stack<int> s;
    int idx = arr.size() - 1;

    ans[idx] = -1;  // Last element has no greater element
    s.push(arr[idx]);

    for(idx = idx - 1; idx >= 0; idx--) {
        int curr = arr[idx];

        // Remove elements smaller than current
        while(!s.empty() && s.top() <= curr) {
            s.pop();
        }

        if(s.empty()) {
            ans[idx] = -1;  // No greater element found
        } else {
            ans[idx] = s.top();  // Next greater element
        }

        s.push(curr);  // Push current element
    }
}

// Example: arr = [6, 8, 0, 1, 3]
// Result: [8, -1, 1, 3, -1]
// Time Complexity: O(n)
// Space Complexity: O(n)
```

### 2. Valid Parentheses

```cpp
bool isValidParenthesis(string str) {
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // Push opening brackets
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            // Check closing brackets
            if(s.empty()) {
                return false;  // No matching opening bracket
            }

            char top = s.top();
            // Check if brackets match
            if((top == '(' && ch == ')') ||
               (top == '{' && ch == '}') ||
               (top == '[' && ch == ']')) {
                s.pop();  // Matching pair found
            } else {
                return false;  // Mismatch found
            }
        }
    }

    return s.empty();  // All brackets matched
}

// Example: "([{}])" -> true, "([}])" -> false
```

### 3. Duplicate Parentheses Detection

```cpp
bool isDuplicateParenthesis(string str) {
    stack<char> s;

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if(ch != ')') {
            s.push(ch);  // Push non-closing brackets
        } else {
            // Found closing parenthesis
            if(s.top() == '(') {
                return true;  // Duplicate found: () with nothing inside
            }

            // Pop until opening parenthesis
            while(s.top() != '(') {
                s.pop();
            }
            s.pop();  // Remove the opening parenthesis
        }
    }

    return false;  // No duplicates found
}

// Example: "((x+y)) + z" -> true (duplicate parentheses)
// Example: "((a + b) + (c + d))" -> false (no duplicates)
```

### 4. Largest Rectangle in Histogram

```cpp
void maxAreaHistogram(vector<int> height) {
    int n = height.size();
    vector<int> nsl(n);  // Next Smaller Left
    vector<int> nsr(n);  // Next Smaller Right
    stack<int> s;

    // Calculate Next Smaller Left
    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i < n; i++) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(i);
    }

    // Clear stack for next calculation
    while(!s.empty()) s.pop();

    // Calculate Next Smaller Right
    s.push(n - 1);
    nsr[n - 1] = n;
    for(int i = n - 2; i >= 0; i--) {
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    // Calculate maximum area
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht * width;
        maxArea = max(area, maxArea);
    }

    cout << "Max Area Of Histogram : " << maxArea << endl;
}

// Example: heights = [2, 1, 5, 6, 2, 3]
// Max Area = 10 (rectangle with height 5 and width 2)
```

## Algorithm Analysis

### Next Greater Element

- **Approach**: Use stack to keep track of elements
- **Time Complexity**: O(n) - each element pushed/popped once
- **Space Complexity**: O(n) - stack and result array
- **Pattern**: Monotonic stack (decreasing order)

### Valid Parentheses

- **Approach**: Stack for matching opening and closing brackets
- **Time Complexity**: O(n) - single pass through string
- **Space Complexity**: O(n) - stack for nested brackets
- **Pattern**: LIFO matching

### Largest Rectangle in Histogram

- **Approach**: Find nearest smaller elements for width calculation
- **Time Complexity**: O(n) - each element processed constant times
- **Space Complexity**: O(n) - stack and boundary arrays
- **Pattern**: Nearest smaller element

## Stack Patterns

### 1. Monotonic Stack

- **Increasing Stack**: Elements in increasing order
- **Decreasing Stack**: Elements in decreasing order
- **Usage**: Next greater/smaller element problems
- **Maintenance**: Pop elements that violate monotonicity

### 2. Bracket Matching

- **Opening Brackets**: Push to stack
- **Closing Brackets**: Match with stack top
- **Validation**: Stack should be empty at end
- **Error Detection**: Mismatch or empty stack

### 3. Boundary Calculation

- **Left Boundary**: Nearest smaller to left
- **Right Boundary**: Nearest smaller to right
- **Width Calculation**: Right - Left - 1
- **Area Calculation**: Height × Width

## Key Takeaways

- **Monotonic Stacks**: Essential for nearest element problems
- **Bracket Validation**: Stack perfectly matches LIFO requirement
- **Area Problems**: Use nearest smaller elements for boundaries
- **Single Pass**: Most problems solved in O(n) time
- **Stack Direction**: Choose increasing or decreasing based on problem

## Common Mistakes to Avoid

- Forgetting to handle empty stack cases
- Incorrect boundary calculations (off-by-one errors)
- Not clearing stack between different calculations
- Wrong comparison operators in monotonic stacks
- Not handling edge cases (single element, all same elements)

## Problem Solving Approach

### 1. Next Greater Element

- **Stack Type**: Decreasing monotonic stack
- **Comparison**: Pop while current >= stack top
- **Result**: Stack top is next greater, else -1

### 2. Valid Parentheses

- **Stack Type**: General stack for matching
- **Push Condition**: Opening brackets
- **Pop Condition**: Matching closing brackets
- **Validation**: Stack empty at end

### 3. Histogram Area

- **Two Passes**: Left and right boundaries
- **Stack Usage**: Find nearest smaller elements
- **Area Formula**: height[i] × (right[i] - left[i] - 1)

## Applications

### 1. Stock Market Problems

- **Stock Span**: Days until higher price
- **Next Greater Price**: Next day with higher stock price
- **Price Movement**: Analyzing price trends

### 2. Text Processing

- **Code Validation**: Checking syntax in programming languages
- **XML/HTML Parsing**: Validating nested tags
- **Expression Evaluation**: Mathematical expression parsing

### 3. Computer Graphics

- **Histogram Analysis**: Image processing
- **Shape Detection**: Finding boundaries in images
- **Area Calculation**: Computing regions in graphics

### 4. System Design

- **Load Balancing**: Distributing work across servers
- **Task Scheduling**: Managing task dependencies
- **Resource Allocation**: Finding optimal resource distribution

## Interview Tips

- **Pattern Recognition**: Identify when to use monotonic stacks
- **Boundary Conditions**: Handle first and last elements carefully
- **Stack Direction**: Choose increasing or decreasing based on problem
- **Edge Cases**: Test with increasing, decreasing, and same elements
- **Time Complexity**: Explain why solution is O(n)

## Problem Variations

### 1. Next Smaller Element

- **Pattern**: Similar to next greater but find smaller
- **Stack Type**: Increasing monotonic stack
- **Comparison**: Pop while current <= stack top

### 2. Previous Greater Element

- **Direction**: Look backward instead of forward
- **Approach**: Traverse from left to right
- **Stack**: Decreasing monotonic stack

### 3. Trapping Rain Water

- **Pattern**: Similar to histogram but for water trapping
- **Boundaries**: Left max and right max heights
- **Calculation**: Water trapped between boundaries

### 4. Remove Adjacent Duplicates

- **Pattern**: Remove consecutive same characters
- **Approach**: Use stack to track non-duplicate characters
- **Result**: Build string from remaining stack elements

## Performance Considerations

- **Stack Operations**: O(1) for push/pop/top
- **Single Pass**: Most problems solved in O(n) time
- **Space Efficiency**: O(n) extra space for stack
- **Cache Friendly**: Sequential access patterns

## Advanced Concepts

- **Two Stacks**: Using two stacks for different purposes
- **Stack with Constraints**: Limited size or special operations
- **Dynamic Stack**: Stack that can grow and shrink
- **Concurrent Stacks**: Thread-safe stack implementations
