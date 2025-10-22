# Day 03: Operators Visualization

This file provides visual representations for understanding operator precedence and expressions in `operators.cpp`.

## 1. Operator Precedence Hierarchy

Visual representation of operator precedence (higher to lower):

```
1. Parentheses ()
2. Multiplication * and Division /
3. Addition + and Subtraction -
```

## 2. Expression 1: exp1 = (x \* y / x)

**Flowchart:**

```
Start
  |
  v
x=10, y=5
  |
  v
x * y = 50
  |
  v
50 / x = 5
  |
  v
exp1 = 5
  |
  v
End
```

**ASCII Diagram:**

```
   x    y
    \   /
     *
      \
       50
        |
        / x
       /
      5
```

## 3. Expression 2: exp2 = (x \* (y / x))

**Flowchart:**

```
Start
  |
  v
x=10, y=5
  |
  v
y / x = 0 (integer division)
  |
  v
x * 0 = 0
  |
  v
exp2 = 0
  |
  v
End
```

**ASCII Diagram:**

```
   x    y
    \   /
     / x
    /
   0
    |
    * x
    |
   0
```

## 4. Expression 3: exp3 = (y \* (x / y + x / y))

**Flowchart:**

```
Start
  |
  v
x=10, y=5
  |
  v
x / y = 2
  |
  v
x / y = 2
  |
  v
2 + 2 = 4
  |
  v
y * 4 = 20
  |
  v
exp3 = 20
  |
  v
End
```

**ASCII Diagram:**

```
   x    y
    \   /
     / y
    /
   2
    |
   2
    |
   2 + 2 = 4
    |
    * y
    |
   20
```

## 5. Expression 4: exp4 = (y _ x / y + y _ x / y)

**Flowchart:**

```
Start
  |
  v
x=10, y=5
  |
  v
y * x = 50
  |
  v
50 / y = 10
  |
  v
y * x = 50
  |
  v
50 / y = 10
  |
  v
10 + 10 = 20
  |
  v
exp4 = 20
  |
  v
End
```

**ASCII Diagram:**

```
   y    x
    \   /
     *
      \
       50
        |
        / y
       /
      10
       |
      10
       |
      10 + 10 = 20
```

## Visual Tips

- Use colors: Red for multiplication/division, Blue for addition/subtraction.
- Draw trees for expression evaluation.
- Tools: Lucidchart for professional diagrams.
