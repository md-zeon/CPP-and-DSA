# Day 01+02: C++ Basics Visualization

This file provides visual representations using Mermaid diagrams to help understand the concepts and code flow in `cppBasics.cpp`.

## 1. Basic Program Structure

```mermaid
flowchart TD
    A([Start]) --> B[Preprocessor Directives<br/>#include iostream]
    B --> C[Namespace Declaration<br/>using namespace std]
    C --> D[int main]
    D --> E[Variables Declaration]
    E --> F[Input/Output Operations]
    F --> G[Calculations & Logic]
    G --> H[return 0]
    H --> I([End])
```

## 2. Area of a Square Calculation

```mermaid
flowchart TD
    A([Start]) --> B[/Input: n side length/]
    B --> C[Calculate: area = n × n]
    C --> D[/Output: Area of square = area/]
    D --> E([End])
    
    style A fill:#90EE90
    style E fill:#FFB6C1
    style C fill:#87CEEB
```

**Formula Visualization:**

```mermaid
graph LR
    A[n] -->|multiply| B[n]
    B --> C[area = n²]
    
    style C fill:#FFD700
```

## 3. Total Bill with GST Calculation

```mermaid
flowchart TD
    A([Start]) --> B[/Input: pencil, pen, eraser/]
    B --> C[Calculate: bill = pencil + pen + eraser]
    C --> D[Calculate: gst = bill × 0.18]
    D --> E[Calculate: finalBill = bill + gst]
    E --> F[/Output: Total Bill = finalBill/]
    F --> G([End])
    
    style A fill:#90EE90
    style G fill:#FFB6C1
    style D fill:#FFA500
```

## 4. Simple Interest Calculator

```mermaid
flowchart TD
    A([Start]) --> B[/Input: principal p/]
    B --> C[/Input: rate r/]
    C --> D[/Input: time t/]
    D --> E["Calculate: interest = (p × r × t) / 100"]
    E --> F[/Output: Simple Interest/]
    F --> G([End])
    
    style A fill:#90EE90
    style G fill:#FFB6C1
    style E fill:#87CEEB
```

**Formula Breakdown:**

```mermaid
graph TD
    A[Principal p] --> D[Multiply]
    B[Rate r] --> D
    C[Time t] --> D
    D --> E[Product]
    E --> F[Divide by 100]
    F --> G[Simple Interest]
    
    style G fill:#FFD700
```

## 5. Area of a Circle Calculation

```mermaid
flowchart TD
    A([Start]) --> B[/Input: radius/]
    B --> C["Calculate: area = π × radius²<br/>(π = 3.14)"]
    C --> D[/Output: Area of circle/]
    D --> E([End])
    
    style A fill:#90EE90
    style E fill:#FFB6C1
    style C fill:#87CEEB
```

**Visual Representation:**

```mermaid
graph LR
    A[radius] --> B[Square: radius²]
    B --> C["Multiply by π (3.14)"]
    C --> D[Circle Area]
    
    style D fill:#FFD700
```

## 6. Average Marks Calculator

```mermaid
flowchart TD
    A([Start]) --> B[/Input: English marks/]
    B --> C[/Input: Science marks/]
    C --> D[/Input: Math marks/]
    D --> E["Calculate: average = (eng + sci + math) / 3.0"]
    E --> F[/Output: Average marks/]
    F --> G([End])
    
    style A fill:#90EE90
    style G fill:#FFB6C1
    style E fill:#87CEEB
```
