# Day 27: Stack STL and Applications - Diagrams

## 1. Push at Bottom Flowchart

This shows the recursive process of pushing an element at the bottom of a stack.

```mermaid
graph TD
    A[pushAtBottom(s, val)] --> B{s.empty()?}
    B -->|Yes| C[s.push(val)]
    B -->|No| D[top = s.top()]
    D --> E[s.pop()]
    E --> F[pushAtBottom(s, val)]
    F --> G[s.push(top)]
```

## 2. String Reversal Flowchart

This illustrates reversing a string using a stack.

```mermaid
graph TD
    A[reverseString(str)] --> B[Create stack s]
    B --> C[Loop i=0 to str.size()-1]
    C --> D[s.push(str[i])]
    D --> E[Loop while !s.empty()]
    E --> F[ans += s.top()]
    F --> G[s.pop()]
    G --> H[Return ans]
```

## 3. Stack Reversal Flowchart

This depicts reversing a stack using recursion.

```mermaid
graph TD
    A[reverse(s)] --> B{s.empty()?}
    B -->|Yes| C[Return]
    B -->|No| D[temp = s.top()]
    D --> E[s.pop()]
    E --> F[reverse(s)]
    F --> G[pushAtBottom(s, temp)]
```

## 4. Stock Span Problem Flowchart

This shows the algorithm for calculating stock spans.

```mermaid
graph TD
    A[stockSpanProblem] --> B[s.push(0), span[0]=1]
    B --> C[Loop i=1 to n-1]
    C --> D[While !s.empty() and stock[i] >= stock[s.top()]]
    D --> E[s.pop()]
    E --> F{s.empty()?}
    F -->|Yes| G[span[i] = i+1]
    F -->|No| H[span[i] = i - s.top()]
    G --> I[s.push(i)]
    H --> I
```

## 5. Balanced Parentheses Flowchart

This illustrates checking balanced parentheses using a stack.

```mermaid
graph TD
    A[isBalanced(str)] --> B[Create stack s]
    B --> C[Loop through each char in str]
    C --> D{char is opening?}
    D -->|Yes| E[s.push(char)]
    D -->|No| F{stack empty or not matching?}
    F -->|Yes| G[Return false]
    F -->|No| H[s.pop()]
    G --> I[After loop, return s.empty()]
    H --> I
```

## 6. Stack Operations Comparison

This compares basic stack operations.

```mermaid
graph TD
    A[Stack Operations] --> B[push: O(1)]
    B --> C[pop: O(1)]
    C --> D[top: O(1)]
    D --> E[empty: O(1)]
    E --> F[size: O(1)]
    F --> G[All O(1) in STL]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts visualize the LIFO behavior and recursive operations.
- For push at bottom and reversal, recursion is key.
- Stock span uses a monotonic stack to find nearest greater.
- Balanced parentheses demonstrates stack's use in parsing.
- Use these to understand stack-based problem-solving patterns.
