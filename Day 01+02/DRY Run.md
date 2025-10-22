# Day 01+02: C++ Basics DRY Run

This file provides step-by-step dry runs (manual simulations) of the practice tasks in `cppBasics.cpp`. A dry run means executing the code mentally or on paper to understand the flow without running it.

## 1. Area of a Square

**Code Snippet:**

```cpp
int n;
cin >> n;
cout << "Area of a square is = " << n*n << endl;
```

**Dry Run Example:**

- Input: `n = 5`
- Step 1: `cin >> n;` → n = 5
- Step 2: Compute `n*n` = 5\*5 = 25
- Step 3: `cout << "Area of a square is = " << 25 << endl;` → Output: "Area of a square is = 25"
- Expected Output: "Area of a square is = 25"

**Another Example:**

- Input: `n = 10`
- n = 10
- Area = 10\*10 = 100
- Output: "Area of a square is = 100"

## 2. Total Bill with GST

**Code Snippet:**

```cpp
float pencil, pen, eraser;
cin >> pencil >> pen >> eraser;
float bill = pencil + pen + eraser;
float gst = bill * (18 / (float)100);
bill -= gst;
cout << "Total Bill = " << bill << endl;
```

**Dry Run Example:**

- Input: pencil=10, pen=20, eraser=5
- Step 1: `cin >> pencil >> pen >> eraser;` → pencil=10, pen=20, eraser=5
- Step 2: `bill = 10 + 20 + 5 = 35`
- Step 3: `gst = 35 * (18 / 100) = 35 * 0.18 = 6.3`
- Step 4: `bill -= 6.3;` → bill = 35 - 6.3 = 28.7
- Step 5: `cout << "Total Bill = " << 28.7 << endl;` → Output: "Total Bill = 28.7"
- Note: The code subtracts GST, but typically GST is added. Corrected bill should be 35 + 6.3 = 41.3.

**Another Example:**

- Input: pencil=5, pen=10, eraser=2
- bill = 5+10+2=17
- gst=17\*0.18=3.06
- bill=17-3.06=13.94
- Output: "Total Bill = 13.94"

## 3. Simple Interest Calculator

**Code Snippet:**

```cpp
int p, t;
float r;
float interest = (p * r * t) / (float)100;
cout << "Interest is = " << interest << endl;
```

**Dry Run Example:**

- Input: p=1000, r=5.0, t=2
- Step 1: `cin >> p >> r >> t;` → p=1000, r=5.0, t=2
- Step 2: `interest = (1000 * 5.0 * 2) / 100 = (10000) / 100 = 100`
- Step 3: `cout << "Interest is = " << 100 << endl;` → Output: "Interest is = 100"

**Another Example:**

- Input: p=2000, r=10.0, t=3
- interest = (2000*10.0*3)/100 = 60000/100 = 600
- Output: "Interest is = 600"

## 4. Area of a Circle

**Code Snippet:**

```cpp
int radius;
cin >> radius;
float area = 3.14 * radius * radius;
cout << "Area of circle is = " << area << endl;
```

**Dry Run Example:**

- Input: radius=7
- Step 1: `cin >> radius;` → radius=7
- Step 2: `area = 3.14 * 7 * 7 = 3.14 * 49 = 153.86`
- Step 3: `cout << "Area of circle is = " << 153.86 << endl;` → Output: "Area of circle is = 153.86"

**Another Example:**

- Input: radius=10
- area = 3.14 _ 10 _ 10 = 3.14 \* 100 = 314
- Output: "Area of circle is = 314"

## Tips for Dry Runs

- Always simulate input first.
- Compute expressions step by step.
- Check for data type conversions (e.g., int to float).
- Verify output format.
