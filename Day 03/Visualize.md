# Day 03: Operators Visualization

This file provides visual representations using Mermaid diagrams for understanding operator precedence and expressions in `operators.cpp`.

## 1. Operator Precedence Hierarchy

```mermaid
graph TD
    A[Operator Precedence<br/>Highest to Lowest] --> B["1. Parentheses ( )"]
    A --> C["2. Multiplication * and Division /"]
    A --> D["3. Addition + and Subtraction -"]
    
    style A fill:#FFD700
    style B fill:#90EE90
    style C fill:#87CEEB
    style D fill:#FFA07A
```

## 2. Expression 1: exp1 = (x * y / x)

```mermaid
flowchart TD
    A([Start<br/>x=10, y=5]) --> B["Step 1: x * y"]
    B --> C["Result: 50"]
    C --> D["Step 2: 50 / x"]
    D --> E["Result: 5"]
    E --> F([exp1 = 5])
    
    style A fill:#90EE90
    style F fill:#FFB6C1
    style C fill:#FFFF99
    style E fill:#FFFF99
```

**Expression Tree:**

```mermaid
graph TD
    A[/] --> B[*]
    A --> C[x=10]
    B --> D[x=10]
    B --> E[y=5]
    
    F[Evaluation] --> G["x * y = 50"]
    G --> H["50 / x = 5"]
    
    style A fill:#87CEEB
    style B fill:#87CEEB
```

## 3. Expression 2: exp2 = (x * (y / x))

```mermaid
flowchart TD
    A([Start<br/>x=10, y=5]) --> B["Step 1: y / x"]
    B --> C["Result: 0<br/>(integer division)"]
    C --> D["Step 2: x * 0"]
    D --> E["Result: 0"]
    E --> F([exp2 = 0])
    
    style A fill:#90EE90
    style F fill:#FFB6C1
    style C fill:#FFFF99
    style E fill:#FFFF99
```

**Expression Tree:**

```mermaid
graph TD
    A[*] --> B[x=10]
    A --> C[/]
    C --> D[y=5]
    C --> E[x=10]
    
    F[Evaluation] --> G["y / x = 0"]
    G --> H["x * 0 = 0"]
    
    style A fill:#87CEEB
    style C fill:#87CEEB
```

## 4. Expression 3: exp3 = (y * (x / y + x / y))

```mermaid
flowchart TD
    A([Start<br/>x=10, y=5]) --> B["Step 1: x / y"]
    B --> C["Result: 2"]
    C --> D["Step 2: x / y"]
    D --> E["Result: 2"]
    E --> F["Step 3: 2 + 2"]
    F --> G["Result: 4"]
    G --> H["Step 4: y * 4"]
    H --> I["Result: 20"]
    I --> J([exp3 = 20])
    
    style A fill:#90EE90
    style J fill:#FFB6C1
    style C fill:#FFFF99
    style E fill:#FFFF99
    style G fill:#FFFF99
    style I fill:#FFFF99
```

**Expression Tree:**

```mermaid
graph TD
    A[*] --> B[y=5]
    A --> C[+]
    C --> D[/]
    C --> E[/]
    D --> F[x=10]
    D --> G[y=5]
    E --> H[x=10]
    E --> I[y=5]
    
    style A fill:#87CEEB
    style C fill:#FFA07A
    style D fill:#87CEEB
    style E fill:#87CEEB
```

## 5. Expression 4: exp4 = (y * x / y + y * x / y)

```mermaid
flowchart TD
    A([Start<br/>x=10, y=5]) --> B["Left Side: y * x"]
    B --> C["Result: 50"]
    C --> D["50 / y"]
    D --> E["Result: 10"]
    E --> F["Right Side: y * x"]
    F --> G["Result: 50"]
    G --> H["50 / y"]
    H --> I["Result: 10"]
    I --> J["Final: 10 + 10"]
    J --> K["Result: 20"]
    K --> L([exp4 = 20])
    
    style A fill:#90EE90
    style L fill:#FFB6C1
    style E fill:#FFFF99
    style I fill:#FFFF99
    style K fill:#FFFF99
```

**Expression Tree:**

```mermaid
graph TD
    A[+] --> B[/]
    A --> C[/]
    B --> D[*]
    B --> E[y=5]
    C --> F[*]
    C --> G[y=5]
    D --> H[y=5]
    D --> I[x=10]
    F --> J[y=5]
    F --> K[x=10]
    
    style A fill:#FFA07A
    style B fill:#87CEEB
    style C fill:#87CEEB
    style D fill:#87CEEB
    style F fill:#87CEEB
```

## Operator Precedence Summary

```mermaid
graph LR
    A[Expression] --> B{Has Parentheses?}
    B -->|Yes| C[Evaluate Innermost ( )]
    B -->|No| D{Has * or /?}
    C --> D
    D -->|Yes| E[Evaluate * or / left to right]
    D -->|No| F{Has + or -?}
    E --> F
    F -->|Yes| G[Evaluate + or - left to right]
    F -->|No| H[Done]
    G --> H
    
    style A fill:#FFD700
    style H fill:#90EE90
```
