# Day 01+02: C++ Basics Visualization

This file provides visual representations and diagrams to help understand the concepts and code flow in `cppBasics.cpp`. Since this is text-based, we'll use ASCII art, flowcharts described in text, and simple diagrams.

## 1. Basic Program Structure

A typical C++ program structure:

```
[Start]
   |
   v
[Preprocessor Directives]
   e.g., #include <iostream>
   |
   v
[Namespace Declaration]
   e.g., using namespace std;
   |
   v
[int main()]
   |
   v
[Code Body]
   - Variables
   - Input/Output
   - Calculations
   |
   v
[return 0;]
   |
   v
[End]
```

## 2. Area of a Square Visualization

**Flowchart:**

```
Start
  |
  v
Input: n (side length)
  |
  v
Calculate: area = n * n
  |
  v
Output: "Area of a square is = " + area
  |
  v
End
```

**ASCII Diagram:**

```
   +-----+
   |     |
   |  n  |
   |     |
   +-----+
     |
     | * n
     v
   +-----+
   |     |
   |area |
   |     |
   +-----+
```

## 3. Total Bill with GST Visualization

**Flowchart:**

```
Start
  |
  v
Input: pencil, pen, eraser
  |
  v
Calculate: bill = pencil + pen + eraser
  |
  v
Calculate: gst = bill * 0.18
  |
  v
Calculate: bill = bill - gst  (Note: Typically add GST)
  |
  v
Output: "Total Bill = " + bill
  |
  v
End
```

**ASCII Diagram:**

```
pencil + pen + eraser
     |
     v
   bill
     |
     | * 0.18
     v
    gst
     |
     | bill - gst
     v
  Final Bill
```

## 4. Simple Interest Calculator Visualization

**Flowchart:**

```
Start
  |
  v
Input: p (principal), r (rate), t (time)
  |
  v
Calculate: interest = (p * r * t) / 100
  |
  v
Output: "Interest is = " + interest
  |
  v
End
```

**ASCII Diagram:**

```
   p    r    t
    \   /   /
     \ /   /
      *   /
       \ /
        |
       /100
        |
     interest
```

## 5. Area of a Circle Visualization

**Flowchart:**

```
Start
  |
  v
Input: radius
  |
  v
Calculate: area = 3.14 * radius * radius
  |
  v
Output: "Area of circle is = " + area
  |
  v
End
```

**ASCII Diagram:**

```
   radius
     |
     | * radius
     v
  radius^2
     |
     | * 3.14
     v
    area
```

## Visual Tips

- Use tools like Draw.io or Lucidchart for graphical flowcharts.
- For code visualization, tools like Code2Flow can generate diagrams from code.
- Practice drawing these on paper to reinforce understanding.
