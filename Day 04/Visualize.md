# Day 04: Conditional Statements Visualization

This file provides visual representations for understanding conditional statements in `Conditional_Statements.cpp`.

## 1. If-Else Structure
**Flowchart for Positive/Negative/Zero:**

```
Start
  |
  v
Input: n
  |
  v
if (n > 0)
  |
  v
"Positive"
  |
  v
End
  |
else if (n < 0)
  |
  v
"Negative"
  |
  v
End
  |
else
  |
  v
"Zero"
  |
  v
End
```

**ASCII Diagram:**
```
   n
    |
   / \
  /   \
 >0   <0
  |    |
Positive Negative
  |    |
  \   /
   \ /
   Zero
```

## 2. Leap Year Logic
**Flowchart:**

```
Start
  |
  v
Input: year
  |
  v
if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
  |
  v
"Leap year"
  |
  v
End
  |
else
  |
  v
"Not a leap year"
  |
  v
End
```

**ASCII Diagram:**
```
   year
    |
   / \
  /   \
 %4==0  %100==0  %400==0
  |     |        |
  \     |        /
   \    |       /
    \   |      /
     \  |     /
      \ |    /
       \|   /
        "Leap"
         |
        else
         |
      "Not Leap"
```

## 3. Armstrong Number Process
**Flowchart:**

```
Start
  |
  v
n = 371, sum = 0
  |
  v
while (n != 0)
  |
  v
lastDigit = n % 10
  |
  v
sum += lastDigit^3
  |
  v
n = n / 10
  |
  v
if (sum == original)
  |
  v
"Armstrong"
  |
  v
End
  |
else
  |
  v
"Not Armstrong"
  |
  v
End
```

**ASCII Diagram:**
```
   n=371
    |
   / \
  /   \
 !=0  ==0
  |    |
  |   End
  |    |
  |   / \
  |  /   \
  | /     \
  |/       \
  |         \
  |          \
  |           \
  |            \
  |             \
  |              \
  |               \
  |                \
  |                 \
  |                  \
  |                   \
  |                    \
  |                     \
  |                      \
  |                       \
  |                        \
  |                         \
  |                          \
  |                           \
  |                            \
  |                             \
  |                              \
  |                               \
  |                                \
  |                                 \
  |                                  \
  |                                   \
  |                                    \
  |                                     \
  |                                      \
  |                                       \
  |                                        \
  |                                         \
  |                                          \
  |                                           \
  |                                            \
  |                                             \
  |                                              \
  |                                               \
  |                                                \
  |                                                 \
  |                                                  \
  |                                                   \
  |                                                    \
  |                                                     \
  |                                                      \
  |                                                       \
  |                                                        \
  |                                                         \
  |                                                          \
  |                                                           \
  |                                                            \
  |                                                             \
  |                                                              \
  |                                                               \
  |                                                                \
  |                                                                 \
  |                                                                  \
  |                                                                   \
  |                                                                    \
  |                                                                     \
  |                                                                      \
  |                                                                       \
  |                                                                        \
  |                                                                         \
  |                                                                          \
  |                                                                           \
  |                                                                            \
  |                                                                             \
  |                                                                              \
  |                                                                               \
  |                                                                                \
  |                                                                                 \
  |                                                                                  \
  |                                                                                   \
  |                                                                                    \
  |                                                                                     \
  |                                                                                      \
  |                                                                                       \
  |                                                                                        \
  |                                                                                         \
  |                                                                                          \
  |                                                                                           \
  |                                                                                            \
  |                                                                                             \
  |                                                                                              \
  |                                                                                               \
  |                                                                                                \
  |                                                                                                 \
  |                                                                                                  \
  |                                                                                                   \
  |                                                                                                    \
  |                                                                                                     \
  |                                                                                                      \
  |                                                                                                       \
  |                                                                                                        \
  |                                                                                                         \
  |                                                                                                          \
  |                                                                                                           \
  |                                                                                                            \
  |                                                                                                             \
  |                                                                                                              \
  |                                                                                                               \
  |                                                                                                                \
  |                                                                                                                 \
  |                                                                                                                  \
  |                                                                                                                   \
  |                                                                                                                    \
  |                                                                                                                     \
  |                                                                                                                      \
  |                                                                                                                       \
  |                                                                                                                        \
  |                                                                                                                         \
  |                                                                                                                          \
  |                                                                                                                           \
  |                                                                                                                            \
  |                                                                                                                             \
  |                                                                                                                              \
  |                                                                                                                               \
  |                                                                                                                                \
  |                                                                                                                                 \
  |                                                                                                                                  \
  |                                                                                                                                   \
  |                                                                                                                                    \
  |                                                                                                                                     \
  |                                                                                                                                      \
  |                                                                                                                                       \
  |                                                                                                                                        \
  |                                                                                                                                         \
  |                                                                                                                                          \
  |                                                                                                                                           \
  |                                                                                                                                            \
  |                                                                                                                                             \
  |                                                                                                                                              \
  |                                                                                                                                               \
  |                                                                                                                                                \
  |                                                                                                                                                 \
  |                                                                                                                                                  \
  |                                                                                                                                                   \
  |                                                                                                                                                    \
  |                                                                                                                                                     \
  |                                                                                                                                                      \
  |                                                                                                                                                       \
  |                                                                                                                                                        \
  |                                                                                                                                                         \
  |                                                                                                                                                          \
  |                                                                                                                                                           \
  |                                                                                                                                                            \
  |                                                                                                                                                             \
  |                                                                                                                                                              \
  |                                                                                                                                                               \
  |                                                                                                                                                                \
  |                                                                                                                                                                 \
  |                                                                                                                                                                  \
  |                                                                                                                                                                   \
  |                                                                                                                                                                    \
  |                                                                                                                                                                     \
  |                                                                                                                                                                      \
  |                                                                                                                                                                       \
  |                                                                                                                                                                        \
  |                                                                                                                                                                         \
  |                                                                                                                                                                          \
  |                                                                                                                                                                           \
  |                                                                                                                                                                            \
  |                                                                                                                                                                             \
  |                                                                                                                                                                              \
  |                                                                                                                                                                               \
  |                                                                                                                                                                                \
  |                                                                                                                                                                                 \
  |                                                                                                                                                                                  \
  |                                                                                                                                                                                   \
  |                                                                                                                                                                                    \
  |                                                                                                                                                                                     \
  |                                                                                                                                                                                      \
  |                                                                                                                                                                                       \
  |                                                                                                                                                                                        \
  |                                                                                                                                                                                         \
  |                                                                                                                                                                                          \
  |                                                                                                                                                                                           \
  |                                                                                                                                                                                            \
  |                                                                                                                                                                                             \
  |                                                                                                                                                                                              \
  |                                                                                                                                                                                               \
  |                                                                                                                                                                                                \
  |                                                                                                                                                                                                 \
  |                                                                                                                                                                                                  \
  |                                                                                                                                                                                                   \
  |                                                                                                                                                                                                    \
  |                                                                                                                                                                                                     \
  |                                                                                                                                                                                                      \
  |                                                                                                                                                                                                       \
  |                                                                                                                                                                                                        \
  |                                                                                                                                                                                                         \
  |                                                                                                                                                                                                          \
  |                                                                                                                                                                                                           \
  |                                                                                                                                                                                                            \
  |                                                                                                                                                                                                             \
  |                                                                                                                                                                                                              \
  |                                                                                                                                                                                                               \
  |                                                                                                                                                                                                                \
  |                                                                                                                                                                                                                 \
  |                                                                                                                                                                                                                  \
  |                                                                                                                                                                                                                   \
  |                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                     \
  |                                                                                                                                                                                                                      \
  |                                                                                                                                                                                                                       \
  |                                                                                                                                                                                                                        \
  |                                                                                                                                                                                                                         \
  |                                                                                                                                                                                                                          \
  |                                                                                                                                                                                                                           \
  |                                                                                                                                                                                                                            \
  |                                                                                                                                                                                                                             \
  |                                                                                                                                                                                                                              \
  |                                                                                                                                                                                                                               \
  |                                                                                                                                                                                                                                \
  |                                                                                                                                                                                                                                 \
  |                                                                                                                                                                                                                                  \
  |                                                                                                                                                                                                                                   \
  |                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                     \
  |                                                                                                                                                                                                                                      \
  |                                                                                                                                                                                                                                       \
  |                                                                                                                                                                                                                                        \
  |                                                                                                                                                                                                                                         \
  |                                                                                                                                                                                                                                          \
  |                                                                                                                                                                                                                                           \
  |                                                                                                                                                                                                                                            \
  |                                                                                                                                                                                                                                             \
  |                                                                                                                                                                                                                                              \
  |                                                                                                                                                                                                                                               \
  |                                                                                                                                                                                                                                                \
  |                                                                                                                                                                                                                                                 \
  |                                                                                                                                                                                                                                                  \
  |                                                                                                                                                                                                                                                   \
  |                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                     \
  |                                                                                                                                                                                                                                                      \
  |                                                                                                                                                                                                                                                       \
  |                                                                                                                                                                                                                                                        \
  |                                                                                                                                                                                                                                                         \
  |                                                                                                                                                                                                                                                          \
  |                                                                                                                                                                                                                                                           \
  |                                                                                                                                                                                                                                                            \
  |                                                                                                                                                                                                                                                             \
  |                                                                                                                                                                                                                                                              \
  |                                                                                                                                                                                                                                                               \
  |                                                                                                                                                                                                                                                                \
  |                                                                                                                                                                                                                                                                 \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
  |                                                                                                                                                                                                                                                                    \
