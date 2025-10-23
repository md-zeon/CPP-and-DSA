# Day 27: Stack STL and Applications

## Topics Covered

- **Stack STL**: Standard Template Library stack implementation
- **Stack Operations**: Push, pop, top, empty, size
- **Push at Bottom**: Inserting element at stack bottom using recursion
- **String Reversal**: Using stack for string manipulation
- **Stack Reversal**: Reversing stack contents recursively
- **Stock Span Problem**: Classic stack-based algorithm

## Key Concepts

1. **LIFO Principle**: Last In, First Out data structure
2. **STL Implementation**: Container adapter using deque by default
3. **Recursive Operations**: Using recursion for complex stack manipulations
4. **Monotonic Stack**: Maintaining increasing/decreasing order
5. **Span Calculation**: Finding nearest greater element

## Code Examples

### 1. Basic Stack Operations

```cpp
stack<int> s;

// Push elements
s.push(3);
s.push(2);
s.push(1);

// Access top element
cout << s.top() << endl;  // Output: 1

// Pop element
s.pop();
cout << s.top() << endl;  // Output: 2

// Check if empty
cout << s.empty() << endl;  // Output: 0 (false)

// Get size
cout << s.size() << endl;   // Output: 2
```

### 2. Push at Bottom (Recursive)

```cpp
void pushAtBottom(stack<int> &s, int val) {
    if(s.empty()) {
        s.push(val);  // Base case: push when stack is empty
        return;
    }

    int top = s.top();  // Store top element
    s.pop();            // Remove top element
    pushAtBottom(s, val);  // Recursive call
    s.push(top);        // Restore top element
}

// Example: pushAtBottom(s, 4) on [1,2,3] -> [4,1,2,3]
```

### 3. String Reversal using Stack

```cpp
string reverseString(string str) {
    string ans;
    stack<char> s;

    // Push all characters to stack
    for(int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    // Pop characters to build reversed string
    while(!s.empty()) {
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
}

// Example: reverseString("abcd") -> "dcba"
// Stack: a,b,c,d -> d,c,b,a (LIFO)
```

### 4. Stack Reversal (Recursive)

```cpp
void reverse(stack<int> &s) {
    if(s.empty()) {
        return;  // Base case
    }

    int temp = s.top();  // Store top element
    s.pop();             // Remove top element
    reverse(s);          // Reverse remaining stack
    pushAtBottom(s, temp);  // Push stored element at bottom
}

// Example: reverse([1,2,3]) -> [3,2,1]
```

### 5. Stock Span Problem

```cpp
void stockSpanProblem(vector<int> stock, vector<int> span) {
    stack<int> s;
    s.push(0);        // Push first index
    span[0] = 1;      // First element span is always 1

    for(int i = 1; i < stock.size(); i++) {
        int currPrice = stock[i];

        // Remove elements smaller than current price
        while(!s.empty() && currPrice >= stock[s.top()]) {
            s.pop();
        }

        if(s.empty()) {
            span[i] = i + 1;  // All previous elements are smaller
        } else {
            int prevHigh = s.top();
            span[i] = i - prevHigh;  // Span to previous higher element
        }

        s.push(i);  // Push current index
    }
}

// Example: stock = [100, 80, 60, 70, 60, 65, 100]
// Span = [1, 1, 1, 2, 1, 5, 7]
```

## Stack STL Details

### Container Adapter

- **Default Container**: `deque<T>` (double-ended queue)
- **Alternative Containers**: `vector<T>`, `list<T>`
- **Declaration**: `stack<T, Container> s;`

### Member Functions

- `s.push(element)`: Add element to top
- `s.pop()`: Remove top element
- `s.top()`: Access top element
- `s.empty()`: Check if stack is empty
- `s.size()`: Get number of elements

### Stack Characteristics

- **LIFO Order**: Last In, First Out
- **No Random Access**: Cannot access middle elements
- **Efficient Operations**: All operations O(1)
- **Memory Management**: Automatic in STL

## Algorithm Analysis

### Time Complexity

- **Push/Pop/Top**: O(1) - constant time
- **Push at Bottom**: O(n) - recursive calls
- **String Reversal**: O(n) - linear traversal
- **Stack Reversal**: O(n²) - due to push at bottom
- **Stock Span**: O(n) - each element pushed/popped once

### Space Complexity

- **Stack Storage**: O(n) for n elements
- **Recursion Stack**: O(n) for recursive operations
- **Auxiliary Space**: O(1) for most operations

## Key Takeaways

- **LIFO Principle**: Stack follows Last In, First Out
- **STL Efficiency**: All basic operations are O(1)
- **Recursive Manipulation**: Complex operations using recursion
- **Monotonic Stack**: Useful for nearest greater/smaller problems
- **Span Problems**: Finding influence range of elements

## Common Mistakes to Avoid

- Modifying stack while iterating (pass by value for printing)
- Forgetting to handle empty stack cases
- Incorrect recursive base cases
- Not understanding LIFO behavior
- Memory issues with deep recursion

## Stack vs Other Data Structures

### Stack vs Queue

- **Stack**: LIFO (Last In, First Out)
- **Queue**: FIFO (First In, First Out)
- **Use Case**: Stack for depth-first, queue for breadth-first

### Stack vs Vector

- **Stack**: Restricted access (top only)
- **Vector**: Random access (any index)
- **Performance**: Stack operations are simpler

### Stack vs Linked List

- **Stack**: Only top access
- **Linked List**: Any node access
- **Implementation**: Stack can be implemented using linked list

## Applications

### 1. Expression Evaluation

- **Infix to Postfix**: Converting mathematical expressions
- **Postfix Evaluation**: Evaluating expressions using stack
- **Parentheses Matching**: Checking balanced brackets

### 2. Navigation Systems

- **Browser History**: Back/forward navigation
- **Undo/Redo**: Text editors, design software
- **Function Calls**: Call stack in programming languages

### 3. Algorithm Implementation

- **Depth-First Search**: Graph traversal
- **Backtracking**: Constraint satisfaction problems
- **Tree Traversal**: Inorder, preorder, postorder

### 4. Problem Solving

- **Stock Span**: Finding price influence periods
- **Nearest Greater**: Finding next greater element
- **Histogram Problems**: Largest rectangle calculations

## Interview Tips

- **Understand LIFO**: Explain stack behavior clearly
- **STL Usage**: Know stack member functions
- **Recursive Thinking**: Practice recursive stack operations
- **Problem Patterns**: Recognize stack-based problems
- **Edge Cases**: Handle empty stack scenarios

## Problem Variations

### 1. Expression Problems

- **Balanced Parentheses**: Check if brackets are balanced
- **Infix to Postfix**: Convert mathematical expressions
- **Postfix Evaluation**: Evaluate postfix expressions

### 2. Navigation Problems

- **Browser History**: Implement back/forward functionality
- **File Directory**: Navigate through folder structure
- **Game Moves**: Undo/redo game actions

### 3. Algorithm Problems

- **Next Greater Element**: Find next greater for each element
- **Largest Rectangle**: Histogram rectangle area calculation
- **Min Stack**: Stack with O(1) minimum retrieval

### 4. String Problems

- **Reverse Words**: Reverse words in a sentence
- **Remove Adjacent**: Remove adjacent duplicate characters
- **Valid Parentheses**: Check valid parentheses sequence

## Performance Considerations

- **STL Stack**: Very efficient, use when possible
- **Custom Stack**: Only when specific requirements
- **Recursion Depth**: Be careful with deep recursive calls
- **Memory Usage**: Stack uses contiguous memory in STL

## Advanced Stack Concepts

- **Monotonic Stack**: Maintains increasing or decreasing order
- **Min/Max Stack**: Track minimum/maximum with O(1) access
- **Stack with Middle**: Operations at middle of stack
- **Multiple Stacks**: Managing multiple stack instances
