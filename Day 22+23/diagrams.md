# Day 22+23: Time and Space Complexity - Diagrams

## 1. Time Complexity Analysis Flowchart

This diagram shows the steps to analyze time complexity.

```mermaid
graph TD
    A[Start Analysis] --> B[Identify Loops and Recursions]
    B --> C[Count Number of Iterations]
    C --> D[Determine Growth Rate]
    D --> E[Apply Big O Rules: Drop Constants, Lower Terms]
    E --> F[State Final Complexity: O(f(n))]
```

## 2. Space Complexity Analysis Flowchart

This diagram illustrates space complexity analysis.

```mermaid
graph TD
    A[Start Space Analysis] --> B[Count Input Space]
    B --> C[Count Auxiliary Space]
    C --> D[Count Recursion Stack Space]
    D --> E[Sum All Components]
    E --> F[State Final Space Complexity: O(g(n))]
```

## 3. Recurrence Relation for Merge Sort

This shows the recurrence for merge sort: T(n) = 2T(n/2) + O(n)

```mermaid
graph TD
    A[T(n)] --> B[2T(n/2)]
    B --> C[O(n)]
    C --> D[Solution: O(n log n)]
```

## 4. Recurrence Relation for Fibonacci

This shows the recurrence for naive Fibonacci: T(n) = T(n-1) + T(n-2) + O(1)

```mermaid
graph TD
    A[T(n)] --> B[T(n-1)]
    A --> C[T(n-2)]
    B --> D[O(1)]
    C --> D
    D --> E[Solution: O(2^n)]
```

## 5. Complexity Comparison

This diagram compares different complexity classes.

```mermaid
graph LR
    A[O(1): Constant] --> B[O(log n): Logarithmic]
    B --> C[O(n): Linear]
    C --> D[O(n log n): Linearithmic]
    D --> E[O(n^2): Quadratic]
    E --> F[O(2^n): Exponential]
```

## 6. Best, Worst, Average Case Analysis

This flowchart helps distinguish between cases.

```mermaid
graph TD
    A[Analyze Algorithm] --> B{Consider Input Scenarios}
    B --> C[Best Case: Optimal Input]
    B --> D[Worst Case: Adversarial Input]
    B --> E[Average Case: Random Input]
    C --> F[Ω(f(n))]
    D --> G[O(g(n))]
    E --> H[Θ(h(n))]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts help in systematically analyzing complexities.
- Recurrence diagrams visualize how recursive algorithms grow.
- Comparison graphs show relative growth rates of different complexities.
- Use these to quickly identify the complexity class of an algorithm.
