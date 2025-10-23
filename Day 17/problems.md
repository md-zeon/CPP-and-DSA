# Day 17: Object-Oriented Programming Part 1 - Practice Problems

## Problem 1: Student Class with Getters and Setters

**Difficulty:** Easy

### Description

Create a Student class with private properties and public getter/setter methods.

### Input Format

- Student name and CGPA

### Output Format

- Print student details and percentage

### Sample Input

```
John Doe 8.5
```

### Sample Output

```
Name: John Doe
CGPA: 8.5
Percentage: 85%
```

### Class Design

```cpp
class Student {
private:
    string name;
    float cgpa;

public:
    void setName(string n) {
        name = n;
    }
    void setCgpa(float cg) {
        cgpa = cg;
    }
    string getName() {
        return name;
    }
    float getCgpa() {
        return cgpa;
    }
    void getPercentage() {
        cout << (cgpa * 10) << "%" << endl;
    }
};
```

### Constraints

- Valid name and CGPA (0-10)

---

## Problem 2: Car Class with Constructors

**Difficulty:** Easy

### Description

Create a Car class with different types of constructors.

### Input Format

- Car name and color

### Output Format

- Print car details

### Sample Input

```
Maruti 800 Blue
```

### Sample Output

```
Constructor with parameter is called. object being created...
Car Name: Maruti 800
Car Color: Blue
Mileage: 12
```

### Class Design

```cpp
class Car {
private:
    string name;
    string color;

public:
    int *mileage;

    // Default constructor
    Car() {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Car(string name, string color) {
        this->name = name;
        this->color = color;
        mileage = new int;
        *mileage = 12;
    }

    string getName() { return name; }
    string getColor() { return color; }

    ~Car() {
        if(mileage != NULL) {
            delete mileage;
            mileage = NULL;
        }
    }
};
```

### Constraints

- Valid name and color strings

---

## Problem 3: Copy Constructor (Deep Copy)

**Difficulty:** Medium

### Description

Implement a custom copy constructor for deep copying.

### Input Format

- Original car details

### Output Format

- Print both original and copied car details

### Sample Input

```
Toyota Red
```

### Sample Output

```
Constructor with parameter is called. object being created...
Copy Constructor is called. object being created...
Copying original ->> new...
Original Car: Toyota Red, Mileage: 12
Copied Car: Toyota Red, Mileage: 12
Mileage addresses are different (deep copy)
```

### Implementation

```cpp
class Car {
public:
    Car(Car &original) {
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }
};
```

### Constraints

- Proper deep copy implementation

---

## Problem 4: User Class with Encapsulation

**Difficulty:** Easy

### Description

Create a User class with proper encapsulation (id private, username public, password private).

### Input Format

- User ID, username, password

### Output Format

- Print user details (without password)

### Sample Input

```
101 john_doe secret123
```

### Sample Output

```
User ID: 101
Username: john_doe
Password: [hidden]
```

### Class Design

```cpp
class User {
private:
    int id;
    string password;

public:
    string username;

    User(int id) {
        this->id = id;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getPassword() {
        return password;
    }

    int getId() {
        return id;
    }
};
```

### Constraints

- Valid ID, username, password

---

## Problem 5: Animal Inheritance Hierarchy

**Difficulty:** Easy

### Description

Create an inheritance hierarchy with Animal base class and Fish, Mammal derived classes.

### Input Format

- No input required

### Output Format

- Demonstrate inheritance by calling methods

### Sample Output

```
Fish eats
Fish breathes
Fish swims
Fins: 3

Dog eats
Dog breathes
Dog wags tail
Blood type: Warm
```

### Class Design

```cpp
class Animal {
public:
    void eat() { cout << "Eats" << endl; }
    void breath() { cout << "Breathes" << endl; }
};

class Fish : public Animal {
public:
    int fins;
    void swim() { cout << "Swims" << endl; }
};

class Mammal : public Animal {
public:
    string bloodType = "Warm";
};

class Dog : public Mammal {
public:
    void tailWag() { cout << "Wags Tail" << endl; }
};
```

---

## Problem 6: Multiple Inheritance (TA Class)

**Difficulty:** Medium

### Description

Create a TA (Teaching Assistant) class using multiple inheritance.

### Input Format

- TA details

### Output Format

- Print TA information

### Sample Input

```
Zeanur Rahaman Zeon C++ 9.1
```

### Sample Output

```
Name: Zeanur Rahaman Zeon
Subject: C++
CGPA: 9.1
```

### Class Design

```cpp
class Teacher {
public:
    int salary;
    string subject;
};

class Student {
public:
    int rollNo;
    float cgpa;
};

class TA : public Teacher, public Student {
public:
    string name;
};
```

### Constraints

- Valid input values

---

## Problem 7: Bank Account Class

**Difficulty:** Easy

### Description

Create a Bank Account class with deposit and withdrawal functionality.

### Input Format

- Account number, initial balance
- Operations (deposit/withdraw amount)

### Output Format

- Print account details after each operation

### Sample Input

```
12345 1000
deposit 500
withdraw 200
```

### Sample Output

```
Account: 12345, Balance: 1000
After deposit: Balance: 1500
After withdrawal: Balance: 1300
```

### Class Design

```cpp
class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        return balance;
    }

    int getAccountNumber() {
        return accountNumber;
    }
};
```

### Constraints

- Valid amounts and operations

---

## Problem 8: Rectangle Class with Area and Perimeter

**Difficulty:** Easy

### Description

Create a Rectangle class to calculate area and perimeter.

### Input Format

- Length and width

### Output Format

- Print area and perimeter

### Sample Input

```
10 5
```

### Sample Output

```
Length: 10, Width: 5
Area: 50
Perimeter: 30
```

### Class Design

```cpp
class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }

    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }
};
```

### Constraints

- Positive length and width

---

## Problem 9: Complex Number Class

**Difficulty:** Medium

### Description

Create a Complex number class with arithmetic operations.

### Input Format

- Two complex numbers (real, imag)

### Output Format

- Print sum, difference, product

### Sample Input

```
3 2
1 4
```

### Sample Output

```
Complex 1: 3 + 2i
Complex 2: 1 + 4i
Sum: 4 + 6i
Difference: 2 - 2i
Product: -5 + 14i
```

### Class Design

```cpp
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex subtract(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex multiply(Complex c) {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};
```

### Constraints

- Valid real and imaginary parts

---

## Problem 10: Employee Class with Salary Calculation

**Difficulty:** Easy

### Description

Create an Employee class with salary calculation.

### Input Format

- Employee name, basic salary, bonus

### Output Format

- Print employee details and total salary

### Sample Input

```
John Doe 50000 5000
```

### Sample Output

```
Employee: John Doe
Basic Salary: 50000
Bonus: 5000
Total Salary: 55000
```

### Class Design

```cpp
class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n, double basic, double bon) {
        name = n;
        basicSalary = basic;
        bonus = bon;
    }

    double getTotalSalary() {
        return basicSalary + bonus;
    }

    string getName() {
        return name;
    }

    double getBasicSalary() {
        return basicSalary;
    }

    double getBonus() {
        return bonus;
    }
};
```

### Constraints

- Valid salary amounts

---

## Problem 11: Circle Class with Radius Validation

**Difficulty:** Easy

### Description

Create a Circle class with radius validation.

### Input Format

- Radius value

### Output Format

- Print circle properties

### Sample Input

```
5
```

### Sample Output

```
Radius: 5
Area: 78.5
Circumference: 31.4
```

### Class Design

```cpp
class Circle {
private:
    double radius;

public:
    Circle(double r) {
        if(r > 0) {
            radius = r;
        } else {
            radius = 0;
        }
    }

    double getArea() {
        return 3.14 * radius * radius;
    }

    double getCircumference() {
        return 2 * 3.14 * radius;
    }

    double getRadius() {
        return radius;
    }

    void setRadius(double r) {
        if(r > 0) {
            radius = r;
        }
    }
};
```

### Constraints

- Radius > 0

---

## Problem 12: Book Class with Member Functions

**Difficulty:** Easy

### Description

Create a Book class with title, author, and price.

### Input Format

- Book details

### Output Format

- Print book information

### Sample Input

```
C++ Programming Bjarne Stroustrup 999
```

### Sample Output

```
Title: C++ Programming
Author: Bjarne Stroustrup
Price: ₹999
```

### Class Design

```cpp
class Book {
private:
    string title;
    string author;
    double price;

public:
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    void applyDiscount(double percentage) {
        price = price * (1 - percentage / 100);
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    double getPrice() { return price; }
};
```

### Constraints

- Valid book details

---

## Problem 13: Point Class with Distance Calculation

**Difficulty:** Medium

### Description

Create a Point class to represent 2D coordinates and calculate distance.

### Input Format

- Two points (x1, y1) and (x2, y2)

### Output Format

- Print distance between points

### Sample Input

```
0 0
3 4
```

### Sample Output

```
Distance: 5
```

### Class Design

```cpp
class Point {
private:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    double getDistance(Point other) {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    double getX() { return x; }
    double getY() { return y; }
};
```

### Constraints

- Valid coordinate values

---

## Problem 14: Fraction Class with Simplification

**Difficulty:** Medium

### Description

Create a Fraction class with arithmetic operations and simplification.

### Input Format

- Two fractions (numerator/denominator)

### Output Format

- Print sum, difference, product, quotient

### Sample Input

```
1 2
1 3
```

### Sample Output

```
Fraction 1: 1/2
Fraction 2: 1/3
Sum: 5/6
Difference: 1/6
Product: 1/6
Quotient: 3/2
```

### Class Design

```cpp
class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int den) {
        numerator = num;
        denominator = den;
        simplify();
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

    Fraction add(Fraction f) {
        int num = numerator * f.denominator + f.numerator * denominator;
        int den = denominator * f.denominator;
        return Fraction(num, den);
    }

    // Similar methods for subtract, multiply, divide
};
```

### Constraints

- Non-zero denominator

---

## Problem 15: Date Class with Validation

**Difficulty:** Medium

### Description

Create a Date class with proper validation.

### Input Format

- Date (day, month, year)

### Output Format

- Print formatted date and validation result

### Sample Input

```
29 2 2024
```

### Sample Output

```
Date: 29/02/2024
Leap year: Yes
Valid date: Yes
```

### Class Design

```cpp
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    bool isLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValidDate() {
        if(month < 1 || month > 12) return false;
        if(day < 1 || day > 31) return false;

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(month == 2 && isLeapYear()) {
            daysInMonth[1] = 29;
        }

        return day <= daysInMonth[month - 1];
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};
```

### Constraints

- Valid date range

---

## Problem 16: Person Class with Address

**Difficulty:** Easy

### Description

Create a Person class with name and address.

### Input Format

- Person name and address

### Output Format

- Print person details

### Sample Input

```
John Doe 123 Main St
```

### Sample Output

```
Name: John Doe
Address: 123 Main St
```

### Class Design

```cpp
class Person {
private:
    string name;
    string address;

public:
    Person(string n, string addr) {
        name = n;
        address = addr;
    }

    string getName() { return name; }
    string getAddress() { return address; }

    void setAddress(string addr) {
        address = addr;
    }
};
```

---

## Problem 17: Calculator Class

**Difficulty:** Easy

### Description

Create a Calculator class with basic arithmetic operations.

### Input Format

- Two numbers and operation choice

### Output Format

- Print result of operation

### Sample Input

```
10 5 1
```

### Sample Output

```
Addition: 15
```

### Class Design

```cpp
class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if(b != 0) return a / b;
        return 0;
    }
};
```

---

## Problem 18: Student Grading System

**Difficulty:** Medium

### Description

Create a student grading system with multiple subjects.

### Input Format

- Student name
- Marks in 3 subjects

### Output Format

- Print grade for each subject and overall grade

### Sample Input

```
Alice 85 92 78
```

### Sample Output

```
Student: Alice
Math: A
Science: A
English: B
Overall Grade: A
```

### Class Design

```cpp
class Student {
private:
    string name;
    int marks[3];

public:
    Student(string n, int m1, int m2, int m3) {
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    char getGrade(int mark) {
        if(mark >= 90) return 'A';
        if(mark >= 80) return 'B';
        if(mark >= 70) return 'C';
        if(mark >= 60) return 'D';
        return 'F';
    }

    double getAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
};
```

### Constraints

- Valid marks (0-100)

---

## Problem 19: Shape Class with Polymorphism

**Difficulty:** Medium

### Description

Create a Shape base class and derived classes for area calculation.

### Input Format

- Shape type and dimensions

### Output Format

- Print area of the shape

### Sample Input

```
circle 5
```

### Sample Output

```
Circle Area: 78.5
```

### Class Design

```cpp
class Shape {
public:
    virtual double getArea() = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) { radius = r; }
    double getArea() {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double getArea() {
        return length * width;
    }
};
```

### Constraints

- Valid dimensions

---

## Problem 20: Library Management System

**Difficulty:** Medium

### Description

Create a simple library management system.

### Input Format

- Book details and operations

### Output Format

- Print book information and availability

### Sample Input

```
C++ Programming 100 5
borrow 2
return 1
```

### Sample Output

```
Book: C++ Programming
Available: 5
After borrowing 2: Available: 3
After returning 1: Available: 4
```

### Class Design

```cpp
class Book {
private:
    string title;
    int totalCopies;
    int availableCopies;

public:
    Book(string t, int total) {
        title = t;
        totalCopies = total;
        availableCopies = total;
    }

    bool borrowBook(int copies) {
        if(copies <= availableCopies) {
            availableCopies -= copies;
            return true;
        }
        return false;
    }

    void returnBook(int copies) {
        availableCopies += copies;
        if(availableCopies > totalCopies) {
            availableCopies = totalCopies;
        }
    }

    string getTitle() { return title; }
    int getAvailableCopies() { return availableCopies; }
};
```

### Constraints

- Valid copy numbers

---

## Problem 21: Time Class with Operations

**Difficulty:** Medium

### Description

Create a Time class with addition and subtraction operations.

### Input Format

- Two time values (hours, minutes)

### Output Format

- Print time after operations

### Sample Input

```
10 30
2 45
add
```

### Sample Output

```
Time 1: 10:30
Time 2: 2:45
Sum: 13:15
```

### Class Design

```cpp
class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h, int m) {
        hours = h;
        minutes = m;
        normalize();
    }

    void normalize() {
        hours += minutes / 60;
        minutes = minutes % 60;
        hours = hours % 24;
    }

    Time add(Time t) {
        Time result(hours + t.hours, minutes + t.minutes);
        return result;
    }

    void display() {
        cout << hours << ":" << minutes << endl;
    }
};
```

### Constraints

- Valid time values

---

## Problem 22: Array Class with Bounds Checking

**Difficulty:** Medium

### Description

Create a safe Array class with bounds checking.

### Input Format

- Array size and elements

### Output Format

- Print array elements with safe access

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Array elements: 1 2 3 4 5
Element at index 2: 3
```

### Class Design

```cpp
class SafeArray {
private:
    int *arr;
    int size;

public:
    SafeArray(int s) {
        size = s;
        arr = new int[size];
    }

    int& operator[](int index) {
        if(index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            exit(1);
        }
        return arr[index];
    }

    ~SafeArray() {
        delete[] arr;
    }
};
```

### Constraints

- Valid array size and indices

---

## Problem 23: Stack Class Implementation

**Difficulty:** Medium

### Description

Implement a Stack class using arrays.

### Input Format

- Stack operations

### Output Format

- Print stack state after each operation

### Sample Input

```
push 10
push 20
push 30
pop
peek
```

### Sample Output

```
Pushed: 10
Pushed: 20
Pushed: 30
Popped: 30
Top element: 20
```

### Class Design

```cpp
class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int element) {
        if(top == capacity - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = element;
    }

    int pop() {
        if(top == -1) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if(top == -1) {
            cout << "Stack empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    ~Stack() {
        delete[] arr;
    }
};
```

### Constraints

- Valid stack operations

---

## Problem 24: Queue Class Implementation

**Difficulty:** Medium

### Description

Implement a Queue class using arrays.

### Input Format

- Queue operations

### Output Format

- Print queue state after each operation

### Sample Input

```
enqueue 10
enqueue 20
enqueue 30
dequeue
front
```

### Sample Output

```
Enqueued: 10
Enqueued: 20
Enqueued: 30
Dequeued: 10
Front element: 20
```

### Class Design

```cpp
class Queue {
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    void enqueue(int element) {
        if(rear == capacity - 1) {
            cout << "Queue full!" << endl;
            return;
        }
        arr[++rear] = element;
    }

    int dequeue() {
        if(front > rear) {
            cout << "Queue empty!" << endl;
            return -1;
        }
        return arr[front++];
    }

    int getFront() {
        if(front > rear) {
            cout << "Queue empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    ~Queue() {
        delete[] arr;
    }
};
```

### Constraints

- Valid queue operations

---

## Problem 25: Singleton Design Pattern

**Difficulty:** Hard

### Description

Implement Singleton design pattern for a Logger class.

### Input Format

- No input required

### Output Format

- Demonstrate singleton behavior

### Sample Output

```
Logger instance 1: 0x123
Logger instance 2: 0x123
Same instance: Yes
```

### Class Design

```cpp
class Logger {
private:
    static Logger* instance;
    Logger() {}

public:
    static Logger* getInstance() {
        if(instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void log(string message) {
        cout << "Log: " << message << endl;
    }
};

// Initialize static member
Logger* Logger::instance = nullptr;
```

### Constraints

- Proper singleton implementation

---

## Additional Practice Problems

### Problem 26: Abstract Shape Class

Create abstract Shape class with pure virtual functions.

### Problem 27: Interface Segregation

Implement interface segregation principle.

### Problem 28: Composition over Inheritance

Demonstrate composition vs inheritance.

### Problem 29: Smart Pointers with Classes

Use smart pointers with custom classes.

### Problem 30: Template Classes

Create generic container classes.

### Problem 31: Operator Overloading

Overload operators for custom classes.

### Problem 32: Friend Functions

Implement friend functions for classes.

### Problem 33: Static Members

Use static members in classes.

### Problem 34: Virtual Functions

Implement runtime polymorphism.

### Problem 35: Exception Handling in Classes

Handle exceptions in class methods.

## OOP Concepts Covered

### 1. Encapsulation

- **Data Hiding:** Private members
- **Access Control:** Public, private, protected
- **Getters/Setters:** Controlled access to data

### 2. Constructors

- **Default Constructor:** No parameters
- **Parameterized Constructor:** With parameters
- **Copy Constructor:** Deep vs shallow copy
- **Destructor:** Cleanup operations

### 3. Inheritance

- **Single Inheritance:** One base class
- **Multiple Inheritance:** Multiple base classes
- **Access Specifiers:** Public, protected, private inheritance

### 4. Polymorphism

- **Function Overriding:** Virtual functions
- **Abstract Classes:** Pure virtual functions
- **Interface Design:** Abstract base classes

### 5. Memory Management

- **Dynamic Allocation:** new, delete
- **Deep Copy:** Proper copy constructors
- **RAII:** Resource Acquisition Is Initialization

## Key Takeaways

### Class Design Principles

```cpp
// Well-designed class
class WellDesignedClass {
private:
    // Private data members
    string name;
    int id;

public:
    // Public interface
    WellDesignedClass(string n, int i); // Constructor
    ~WellDesignedClass(); // Destructor

    // Getters
    string getName() const;
    int getId() const;

    // Setters
    void setName(string n);
    void setId(int i);

    // Business methods
    void display() const;
};
```

### Constructor Rules

1. **Same name as class**
2. **No return type**
3. **Called automatically**
4. **Can be overloaded**
5. **Default constructor needed for arrays**

### Inheritance Syntax

```cpp
class Base {
public:
    void baseMethod() {}
};

class Derived : public Base { // Public inheritance
public:
    void derivedMethod() {}
};
```

### Best Practices

- **Encapsulation:** Keep data private, methods public
- **Single Responsibility:** Each class has one purpose
- **Dependency Injection:** Avoid tight coupling
- **RAII:** Manage resources in constructors/destructors
- **Const Correctness:** Use const where appropriate

### Common Mistakes

- **Missing copy constructor:** For classes with pointers
- **Memory leaks:** Forgetting to delete dynamic memory
- **Shallow copy issues:** Incorrect copy constructor
- **Missing virtual destructor:** In base classes

### Interview Tips

- **Class design:** Explain encapsulation and abstraction
- **Constructor/destructor:** Memory management
- **Inheritance:** Access specifiers and polymorphism
- **Real-world examples:** Practical class design
- **Error handling:** Exception safety

### Real-World Applications

1. **Game Development**

   - Player, Enemy, Item classes
   - Game state management
   - Component-based design

2. **Banking Systems**

   - Account, Customer, Transaction classes
   - Security and validation
   - Audit trails

3. **E-commerce**

   - Product, Cart, Order classes
   - Payment processing
   - Inventory management

4. **Social Media**

   - User, Post, Comment classes
   - Relationship management
   - Content moderation

5. **Database Systems**
   - Connection, Query, Result classes
   - Transaction management
   - Connection pooling

### Advanced OOP Topics

1. **Design Patterns**

   - Singleton, Factory, Observer
   - Strategy, Decorator, Adapter

2. **SOLID Principles**

   - Single Responsibility
   - Open/Closed
   - Liskov Substitution
   - Interface Segregation
   - Dependency Inversion

3. **Modern C++ Features**

   - Smart pointers
   - Move semantics
   - Lambda expressions
   - Template metaprogramming

4. **Memory Management**
   - RAII principle
   - Smart pointers
   - Custom allocators
   - Memory pools

### Performance Considerations

- **Object size:** Minimize padding and size
- **Virtual functions:** Vtable overhead
- **Inheritance depth:** Method resolution cost
- **Memory layout:** Cache-friendly design

### Testing OOP Code

1. **Unit Testing**

   - Test each class independently
   - Mock dependencies
   - Test edge cases

2. **Integration Testing**

   - Test class interactions
   - Test inheritance hierarchies
   - Test polymorphism

3. **Memory Testing**
   - Check for leaks
   - Validate copy operations
   - Test destructor calls
