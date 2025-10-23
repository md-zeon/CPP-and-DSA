# Day 20: Recursion Part 2 - Diagrams

## 1. Tiling Problem Flowchart

This diagram shows the recursive flow for the tiling problem.

```mermaid
graph TD
    A[Start tilingProblem(n)] --> B{n == 0 or n == 1?}
    B -->|Yes| C[Return 1]
    B -->|No| D[vertical = tilingProblem(n-1)]
    D --> E[horizontal = tilingProblem(n-2)]
    E --> F[ways = vertical + horizontal]
    F --> G[Return ways]
```

## 2. Remove Duplicates Flowchart

This diagram illustrates the recursive process for removing duplicates from a string.

```mermaid
graph TD
    A[Start removeDuplicates(str, ans, i, map)] --> B{i == str.size()?}
    B -->|Yes| C[Print ans]
    B -->|No| D{map[str[i] - 'a']?}
    D -->|Yes| E[Call removeDuplicates(str, ans, i+1, map)]
    D -->|No| F[map[str[i] - 'a'] = true]
    F --> G[Call removeDuplicates(str, ans + str[i], i+1, map)]
```

## 3. Friends Pairing Flowchart

This diagram shows the recursion for the friends pairing problem.

```mermaid
graph TD
    A[Start friendsPairing(n)] --> B{n == 1 or n == 2?}
    B -->|Yes| C[Return n]
    B -->|No| D[single = friendsPairing(n-1)]
    D --> E[pair = friendsPairing(n-2) * (n-1)]
    E --> F[Return single + pair]
```

## 4. Binary String Generation Flowchart

This diagram depicts the process for generating binary strings without consecutive 1s.

```mermaid
graph TD
    A[Start binaryString(n, lastPlace, ans)] --> B{n == 0?}
    B -->|Yes| C[Print ans]
    B -->|No| D{lastPlace != 1?}
    D -->|Yes| E[Call binaryString(n-1, 0, ans + '0')]
    E --> F[Call binaryString(n-1, 1, ans + '1')]
    D -->|No| G[Call binaryString(n-1, 0, ans + '0')]
```

## 5. Recursion Tree Example for Tiling Problem (n=3)

This tree shows the recursive calls for tilingProblem(3).

```mermaid
graph TD
    A[tilingProblem(3)] --> B[tilingProblem(2)]
    A --> C[tilingProblem(1)]
    B --> D[tilingProblem(1)]
    B --> E[tilingProblem(0)]
    C --> F[Return 1]
    D --> G[Return 1]
    E --> H[Return 1]
    F --> I[Return 1]
    G --> J[Return 1]
    H --> K[Return 1]
```

## Notes

- These diagrams use Mermaid syntax for GitHub compatibility.
- Flowcharts help visualize the decision points in recursion.
- Recursion trees illustrate the call stack and overlapping subproblems.
- Use these to understand base cases and recursive cases better.
