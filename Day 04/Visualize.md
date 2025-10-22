# Day 04: Conditional Statements Visualization

This file provides visual representations using Mermaid diagrams for understanding conditional statements in `Conditional_Statements.cpp`.

## 1. Positive/Negative/Zero Check

```mermaid
flowchart TD
    A([Start]) --> B[/Input: n/]
    B --> C{n > 0?}
    C -->|Yes| D[Output: Positive]
    C -->|No| E{n < 0?}
    E -->|Yes| F[Output: Negative]
    E -->|No| G[Output: Zero]
    D --> H([End])
    F --> H
    G --> H
    
    style A fill:#90EE90
    style H fill:#FFB6C1
    style C fill:#FFD700
    style E fill:#FFD700
```

**Decision Tree:**

```mermaid
graph TD
    A[Input n] --> B{Check Value}
    B -->|n > 0| C[Positive]
    B -->|n < 0| D[Negative]
    B -->|n = 0| E[Zero]
    
    style A fill:#87CEEB
    style B fill:#FFD700
    style C fill:#90EE90
    style D fill:#FFA07A
    style E fill:#DDA0DD
```

## 2. Leap Year Logic

```mermaid
flowchart TD
    A([Start]) --> B[/Input: year/]
    B --> C{year % 4 == 0?}
    C -->|Yes| D[Output: Leap Year]
    C -->|No| E{year % 100 == 0?}
    E -->|Yes| F[Output: Leap Year]
    E -->|No| G{year % 400 == 0?}
    G -->|Yes| H[Output: Leap Year]
    G -->|No| I[Output: Not a Leap Year]
    D --> J([End])
    F --> J
    H --> J
    I --> J
    
    style A fill:#90EE90
    style J fill:#FFB6C1
    style C fill:#FFD700
    style E fill:#FFD700
    style G fill:#FFD700
```

**Leap Year Conditions:**

```mermaid
graph LR
    A[Year] --> B{Divisible by 4?}
    B -->|Yes| C{Divisible by 100?}
    B -->|No| D[Not Leap Year]
    C -->|No| E[Leap Year]
    C -->|Yes| F{Divisible by 400?}
    F -->|Yes| G[Leap Year]
    F -->|No| H[Not Leap Year]
    
    style E fill:#90EE90
    style G fill:#90EE90
    style D fill:#FFA07A
    style H fill:#FFA07A
```

## 3. Armstrong Number Check

An Armstrong number is a number that equals the sum of its digits raised to the power of the number of digits.

```mermaid
flowchart TD
    A([Start]) --> B["Initialize: n = 371, sum = 0"]
    B --> C["Store original: NUM = n"]
    C --> D{n != 0?}
    D -->|Yes| E["lastDigit = n % 10"]
    E --> F["sum += lastDigit³"]
    F --> G["n = n / 10"]
    G --> D
    D -->|No| H{sum == NUM?}
    H -->|Yes| I["Output: Armstrong Number"]
    H -->|No| J["Output: Not Armstrong Number"]
    I --> K([End])
    J --> K
    
    style A fill:#90EE90
    style K fill:#FFB6C1
    style D fill:#FFD700
    style H fill:#FFD700
    style F fill:#87CEEB
```

**Armstrong Number Example (371):**

```mermaid
graph TD
    A[371] --> B[Extract Digits]
    B --> C[3]
    B --> D[7]
    B --> E[1]
    C --> F["3³ = 27"]
    D --> G["7³ = 343"]
    E --> H["1³ = 1"]
    F --> I[Sum]
    G --> I
    H --> I
    I --> J["27 + 343 + 1 = 371"]
    J --> K{371 == 371?}
    K -->|Yes| L[Armstrong Number ✓]
    
    style A fill:#FFD700
    style I fill:#87CEEB
    style L fill:#90EE90
```

**Step-by-Step Breakdown:**

```mermaid
sequenceDiagram
    participant N as Number (371)
    participant LD as Last Digit
    participant S as Sum
    participant Loop as While Loop
    
    Note over N,S: Initialize: n=371, sum=0
    
    Loop->>N: Check n != 0?
    N-->>Loop: Yes (371)
    Loop->>LD: Extract: 371 % 10 = 1
    LD->>S: Add: sum + 1³ = 1
    Loop->>N: Update: 371 / 10 = 37
    
    Loop->>N: Check n != 0?
    N-->>Loop: Yes (37)
    Loop->>LD: Extract: 37 % 10 = 7
    LD->>S: Add: sum + 7³ = 344
    Loop->>N: Update: 37 / 10 = 3
    
    Loop->>N: Check n != 0?
    N-->>Loop: Yes (3)
    Loop->>LD: Extract: 3 % 10 = 3
    LD->>S: Add: sum + 3³ = 371
    Loop->>N: Update: 3 / 10 = 0
    
    Loop->>N: Check n != 0?
    N-->>Loop: No (0)
    Note over S: Final sum = 371
    Note over S: 371 == 371 ✓ Armstrong!
```

## 4. If-Else Statement Structure

```mermaid
graph TD
    A[Program Flow] --> B[if Condition]
    B -->|True| C[Execute if Block]
    B -->|False| D[else if Condition]
    D -->|True| E[Execute else if Block]
    D -->|False| F[else Block]
    F --> G[Execute else Block]
    C --> H[Continue Program]
    E --> H
    G --> H
    
    style B fill:#FFD700
    style D fill:#FFD700
    style H fill:#90EE90
```

## 5. Switch vs If-Else Comparison

```mermaid
graph TD
    A[Control Flow Decision] --> B{Multiple<br/>Discrete Values?}
    B -->|Yes| C[Use Switch]
    B -->|No| D{Range or<br/>Complex Conditions?}
    D -->|Yes| E[Use If-Else]
    D -->|No| F{Simple<br/>True/False?}
    F -->|Yes| G[Use If]
    
    style A fill:#FFD700
    style C fill:#90EE90
    style E fill:#87CEEB
    style G fill:#DDA0DD
```

## Key Concepts Summary

```mermaid
mindmap
  root((Conditional<br/>Statements))
    If Statement
      Single Condition
      True Block
    If-Else
      Two Paths
      True/False Blocks
    Else-If Ladder
      Multiple Conditions
      Sequential Check
    Nested If
      If inside If
      Complex Logic
    Logical Operators
      AND operator
      OR operator
      NOT operator
```
