# Day 18: Object-Oriented Programming Part 2 - Practice Problems

## Problem 1: Complex Number with Operator Overloading

**Difficulty:** Medium

### Description

Create a Complex number class with overloaded arithmetic operators.

### Input Format

- Two complex numbers (real, imag)

### Output Format

- Print sum, difference, and product

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
    int real;
    int imaginary;

public:
    Complex(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    void showNum() {
        if(imaginary >= 0) {
            cout << real << " + " << imaginary << "i" << endl;
        } else {
            cout << real << " - " << (-imaginary) << "i" << endl;
        }
    }

    Complex operator + (Complex &obj) {
        int resReal = this->real + obj.real;
        int resImaginary = this->imaginary + obj.imaginary;
        return Complex(resReal, resImaginary);
    }

    Complex operator - (Complex &obj) {
        int resReal = this->real - obj.real;
        int resImaginary = this->imaginary - obj.imaginary;
        return Complex(resReal, resImaginary);
    }
};
```

### Constraints

- Valid integer values for real and imaginary parts

---

## Problem 2: Function Overriding

**Difficulty:** Easy

### Description

Demonstrate function overriding with base and derived classes.

### Input Format

- No input required

### Output Format

- Show method resolution in inheritance

### Sample Output

```
Parent class show...
Child hello...
```

### Class Design

```cpp
class Parent {
public:
    void show() {
        cout << "Parent class show..." << endl;
    }
    virtual void hello() {
        cout << "Parent hello..." << endl;
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "Child class show..." << endl;
    }
    void hello() {
        cout << "Child hello..." << endl;
    }
};
```

---

## Problem 3: Abstract Shape Class

**Difficulty:** Medium

### Description

Create an abstract Shape class with pure virtual functions.

### Input Format

- Shape type and dimensions

### Output Format

- Print area of different shapes

### Sample Input

```
circle 5
square 4
```

### Sample Output

```
Drawing circle...
Circle area: 78.5
Drawing square...
Square area: 16
```

### Class Design

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual double getArea() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) { radius = r; }
    void draw() {
        cout << "Drawing circle..." << endl;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double s) { side = s; }
    void draw() {
        cout << "Drawing square..." << endl;
    }
    double getArea() {
        return side * side;
    }
};
```

### Constraints

- Valid dimensions

---

## Problem 4: Static Members in Class

**Difficulty:** Medium

### Description

Demonstrate static data members and their behavior.

### Input Format

- No input required

### Output Format

- Show static member sharing across objects

### Sample Output

```
Object 1 x: 0
Object 2 x: 1
Object 3 x: 2
All objects share same x: 2
```

### Class Design

```cpp
class Example {
public:
    static int x;

    Example() {
        cout << "Constructor" << endl;
    }

    ~Example() {
        cout << "Destructor" << endl;
    }
};

// Initialize static member outside class
int Example::x = 0;
```

---

## Problem 5: Friend Class

**Difficulty:** Medium

### Description

Demonstrate friend class functionality for accessing private members.

### Input Format

- No input required

### Output Format

- Show friend class accessing private data

### Sample Output

```
Secret Data
Secret Data
```

### Class Design

```cpp
class A {
private:
    string secret = "Secret Data";
    friend class B; // B is friend of A
    friend void revealSecret(A &obj); // Function is friend of A
};

class B {
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;
}
```

---

## Problem 6: String Class with Operator Overloading

**Difficulty:** Medium

### Description

Create a String class with overloaded operators.

### Input Format

- Two strings

### Output Format

- Demonstrate concatenation and comparison

### Sample Input

```
hello world
```

### Sample Output

```
String 1: hello
String 2: world
Concatenated: helloworld
Are equal: false
Comparison: hello < world
```

### Class Design

```cpp
class MyString {
private:
    char *str;
    int length;

public:
    MyString(const char *s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    MyString operator + (MyString &s) {
        char *newStr = new char[length + s.length + 1];
        strcpy(newStr, str);
        strcat(newStr, s.str);
        MyString result(newStr);
        delete[] newStr;
        return result;
    }

    bool operator == (MyString &s) {
        return strcmp(str, s.str) == 0;
    }

    ~MyString() {
        delete[] str;
    }
};
```

### Constraints

- String length ≤ 100

---

## Problem 7: Virtual Functions and Polymorphism

**Difficulty:** Medium

### Description

Demonstrate runtime polymorphism using virtual functions.

### Input Format

- No input required

### Output Format

- Show dynamic method dispatch

### Sample Output

```
Parent hello...
Child hello...
```

### Code Example

```cpp
class Parent {
public:
    virtual void hello() {
        cout << "Parent hello..." << endl;
    }
};

class Child : public Parent {
public:
    void hello() {
        cout << "Child hello..." << endl;
    }
};

int main() {
    Parent p;
    Child c;
    Parent *ptr = &c; // Base class pointer to derived object
    ptr->hello(); // Calls Child's hello() due to virtual
}
```

---

## Problem 8: Array Class with Operator Overloading

**Difficulty:** Medium

### Description

Create an Array class with subscript operator overloading.

### Input Format

- Array size and elements

### Output Format

- Demonstrate array access and bounds checking

### Sample Input

```
5
1 2 3 4 5
```

### Sample Output

```
Array[0] = 1
Array[2] = 3
All elements: 1 2 3 4 5
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
            // Return reference to temporary variable
            static int temp = 0;
            return temp;
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

## Problem 9: Counter Class with Static Member

**Difficulty:** Easy

### Description

Create a counter that maintains count across all objects.

### Input Format

- Number of objects to create

### Output Format

- Show object count

### Sample Input

```
3
```

### Sample Output

```
Object 1 created
Object 2 created
Object 3 created
Total objects: 3
```

### Class Design

```cpp
class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
        cout << "Object " << count << " created" << endl;
    }

    static int getCount() {
        return count;
    }

    ~Counter() {
        count--;
    }
};

// Initialize static member
int Counter::count = 0;
```

---

## Problem 10: Matrix Class with Operator Overloading

**Difficulty:** Hard

### Description

Create a Matrix class with overloaded operators for addition and multiplication.

### Input Format

- Two matrices

### Output Format

- Print sum and product matrices

### Sample Input

```
2 2
1 2
3 4
2 2
5 6
7 8
```

### Sample Output

```
Matrix A:
1 2
3 4
Matrix B:
5 6
7 8
Sum:
6 8
10 12
Product:
19 22
43 50
```

### Class Design

```cpp
class Matrix {
private:
    int **matrix;
    int rows, cols;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for(int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    Matrix operator + (Matrix &m) {
        Matrix result(rows, cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
            }
        }
        return result;
    }

    // Similar implementation for multiplication
};
```

### Constraints

- Valid matrix dimensions

---

## Problem 11: Function Object (Functor)

**Difficulty:** Medium

### Description

Create a function object for custom sorting criteria.

### Input Format

- Vector of numbers

### Output Format

- Print sorted vector

### Sample Input

```
5
3 1 4 1 5
```

### Sample Output

```
Original: 3 1 4 1 5
Sorted (ascending): 1 1 3 4 5
Sorted (descending): 5 4 3 1 1
```

### Class Design

```cpp
class Descending {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

vector<int> vec = {3, 1, 4, 1, 5};

// Ascending sort
sort(vec.begin(), vec.end());

// Descending sort using functor
sort(vec.begin(), vec.end(), Descending());
```

---

## Problem 12: Smart Pointer with Custom Class

**Difficulty:** Medium

### Description

Use smart pointers with custom classes.

### Input Format

- No input required

### Output Format

- Demonstrate automatic memory management

### Sample Output

```
Object created
Using object
Object destroyed automatically
```

### Code Example

```cpp
class MyClass {
public:
    MyClass() {
        cout << "Object created" << endl;
    }

    ~MyClass() {
        cout << "Object destroyed" << endl;
    }

    void doSomething() {
        cout << "Doing something" << endl;
    }
};

int main() {
    {
        unique_ptr<MyClass> ptr = make_unique<MyClass>();
        ptr->doSomething();
        // Object automatically destroyed when ptr goes out of scope
    }
}
```

---

## Problem 13: Template Function

**Difficulty:** Medium

### Description

Create a generic template function for swapping values.

### Input Format

- Two values of same type

### Output Format

- Print swapped values

### Sample Input

```
10 20
```

### Sample Output

```
Before swap: 10 20
After swap: 20 10
```

### Template Function

```cpp
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: " << x << " " << y << endl;
    swapValues(x, y);
    cout << "After swap: " << x << " " << y << endl;
}
```

---

## Problem 14: Template Class

**Difficulty:** Medium

### Description

Create a generic Stack template class.

### Input Format

- Stack operations

### Output Format

- Print stack operations

### Sample Input

```
push 10
push 20
pop
```

### Sample Output

```
Pushed: 10
Pushed: 20
Popped: 20
```

### Template Class

```cpp
template <typename T>
class Stack {
private:
    T *arr;
    int top;
    int capacity;

public:
    Stack(int cap) {
        capacity = cap;
        arr = new T[capacity];
        top = -1;
    }

    void push(T element) {
        if(top == capacity - 1) {
            cout << "Stack full!" << endl;
            return;
        }
        arr[++top] = element;
    }

    T pop() {
        if(top == -1) {
            cout << "Stack empty!" << endl;
            return T(); // Default value
        }
        return arr[top--];
    }

    ~Stack() {
        delete[] arr;
    }
};
```

---

## Problem 15: Exception Handling in Classes

**Difficulty:** Medium

### Description

Implement exception handling in class methods.

### Input Format

- Division operation

### Output Format

- Handle division by zero

### Sample Input

```
10 0
```

### Sample Output

```
Division by zero error!
```

### Class Design

```cpp
class Calculator {
public:
    double divide(double a, double b) {
        if(b == 0) {
            throw runtime_error("Division by zero!");
        }
        return a / b;
    }
};

try {
    Calculator calc;
    double result = calc.divide(10, 0);
} catch(const exception& e) {
    cout << "Error: " << e.what() << endl;
}
```

---

## Problem 16: Virtual Destructor

**Difficulty:** Medium

### Description

Demonstrate the importance of virtual destructors.

### Input Format

- No input required

### Output Format

- Show proper destructor calling

### Sample Output

```
Base constructor
Derived constructor
Derived destructor
Base destructor
```

### Class Design

```cpp
class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual ~Base() { // Virtual destructor
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived constructor" << endl;
    }
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base *ptr = new Derived();
    delete ptr; // Calls both destructors due to virtual
}
```

---

## Problem 17: Interface-like Abstract Class

**Difficulty:** Medium

### Description

Create an interface-like abstract class for drawable objects.

### Input Format

- Shape operations

### Output Format

- Demonstrate polymorphism

### Sample Output

```
Drawing circle...
Circle area: 78.5
Drawing rectangle...
Rectangle area: 20
```

### Class Design

```cpp
class Drawable {
public:
    virtual void draw() = 0;
    virtual double getArea() = 0;
    virtual ~Drawable() {}
};

class Circle : public Drawable {
public:
    void draw() {
        cout << "Drawing circle..." << endl;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
private:
    double radius;
};
```

---

## Problem 18: Operator Overloading for Comparison

**Difficulty:** Medium

### Description

Overload comparison operators for custom class.

### Input Format

- Two objects to compare

### Output Format

- Print comparison results

### Sample Input

```
Student A 85
Student B 92
```

### Sample Output

```
Student A marks: 85
Student B marks: 92
Student A < Student B: true
Student A == Student B: false
```

### Class Design

```cpp
class Student {
private:
    string name;
    int marks;

public:
    Student(string n, int m) {
        name = n;
        marks = m;
    }

    bool operator < (Student &s) {
        return marks < s.marks;
    }

    bool operator == (Student &s) {
        return marks == s.marks;
    }

    int getMarks() {
        return marks;
    }
};
```

---

## Problem 19: Copy Constructor vs Assignment Operator

**Difficulty:** Medium

### Description

Demonstrate the difference between copy constructor and assignment operator.

### Input Format

- No input required

### Output Format

- Show when each is called

### Sample Output

```
Copy constructor called
Assignment operator called
```

### Code Example

```cpp
class MyClass {
public:
    MyClass() {
        cout << "Default constructor" << endl;
    }

    MyClass(const MyClass &obj) {
        cout << "Copy constructor" << endl;
    }

    MyClass& operator = (const MyClass &obj) {
        cout << "Assignment operator" << endl;
        return *this;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2 = obj1; // Copy constructor
    MyClass obj3;
    obj3 = obj1; // Assignment operator
}
```

---

## Problem 20: Static Function Members

**Difficulty:** Medium

### Description

Create and use static member functions.

### Input Format

- No input required

### Output Format

- Demonstrate static function behavior

### Sample Output

```
Total objects created: 3
```

### Class Design

```cpp
class ObjectCounter {
private:
    static int count;

public:
    ObjectCounter() {
        count++;
    }

    static int getCount() { // Static function
        return count;
    }
};

int ObjectCounter::count = 0;

int main() {
    ObjectCounter obj1, obj2, obj3;
    cout << "Total objects: " << ObjectCounter::getCount() << endl;
}
```

---

## Problem 21: Multiple Inheritance with Virtual Base Class

**Difficulty:** Hard

### Description

Implement multiple inheritance with virtual base class to avoid diamond problem.

### Input Format

- No input required

### Output Format

- Demonstrate proper inheritance

### Sample Output

```
Base constructor
Derived1 constructor
Derived2 constructor
Final constructor
```

### Class Design

```cpp
class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
};

class Derived1 : virtual public Base {
public:
    Derived1() {
        cout << "Derived1 constructor" << endl;
    }
};

class Derived2 : virtual public Base {
public:
    Derived2() {
        cout << "Derived2 constructor" << endl;
    }
};

class Final : public Derived1, public Derived2 {
public:
    Final() {
        cout << "Final constructor" << endl;
    }
};
```

---

## Problem 22: Runtime Type Identification (RTTI)

**Difficulty:** Medium

### Description

Demonstrate runtime type identification using typeid.

### Input Format

- No input required

### Output Format

- Show type information at runtime

### Sample Output

```
Object type: class Derived
Is instance of Base: true
```

### Code Example

```cpp
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

int main() {
    Base *ptr = new Derived();
    cout << "Type: " << typeid(*ptr).name() << endl;

    if(typeid(*ptr) == typeid(Derived)) {
        cout << "Is Derived class" << endl;
    }

    delete ptr;
}
```

---

## Problem 23: Const Member Functions

**Difficulty:** Easy

### Description

Demonstrate const member functions and const objects.

### Input Format

- No input required

### Output Format

- Show const correctness

### Sample Output

```
Name: John
Cannot modify const object
```

### Class Design

```cpp
class Student {
private:
    string name;

public:
    Student(string n) : name(n) {}

    string getName() const { // Const member function
        return name;
    }

    void setName(string n) { // Non-const function
        name = n;
    }
};

int main() {
    const Student s("John");
    cout << s.getName() << endl; // OK

    // s.setName("Jane"); // Error: cannot call non-const function on const object
}
```

---

## Problem 24: Friend Function

**Difficulty:** Medium

### Description

Implement friend functions for operator overloading.

### Input Format

- Two complex numbers

### Output Format

- Print result of friend operator

### Sample Input

```
3 2
1 4
```

### Sample Output

```
Sum: 4 + 6i
```

### Class Design

```cpp
class Complex {
private:
    int real, imag;

public:
    Complex(int r, int i) : real(r), imag(i) {}

    // Friend function declaration
    friend Complex operator + (Complex c1, Complex c2);

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Friend function definition
Complex operator + (Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
```

---

## Problem 25: Polymorphic Container

**Difficulty:** Hard

### Description

Create a container that holds different shape objects polymorphically.

### Input Format

- Shape operations

### Output Format

- Demonstrate polymorphic behavior

### Sample Output

```
Drawing circle...
Area: 78.5
Drawing rectangle...
Area: 20
```

### Class Design

```cpp
class Shape {
public:
    virtual void draw() = 0;
    virtual double getArea() = 0;
    virtual ~Shape() {}
};

class ShapeContainer {
private:
    vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void drawAllShapes() {
        for(Shape* shape : shapes) {
            shape->draw();
            cout << "Area: " << shape->getArea() << endl;
        }
    }

    ~ShapeContainer() {
        for(Shape* shape : shapes) {
            delete shape;
        }
    }
};
```

---

## Additional Practice Problems

### Problem 26: Custom Iterator Class

Create a custom iterator for a container class.

### Problem 27: RAII Implementation

Implement Resource Acquisition Is Initialization.

### Problem 28: PIMPL Idiom

Implement Pointer to Implementation idiom.

### Problem 29: CRTP (Curiously Recurring Template Pattern)

Implement static polymorphism using CRTP.

### Problem 30: Policy-Based Design

Implement policy-based class design.

### Problem 31: Type Erasure

Implement type erasure for heterogeneous containers.

### Problem 32: Expression Templates

Implement expression templates for optimization.

### Problem 33: SFINAE (Substitution Failure is Not An Error)

Use SFINAE for function overloading.

### Problem 34: Variadic Templates

Implement variadic template functions.

### Problem 35: Advanced Template Metaprogramming

Implement compile-time computations using templates.

## Advanced OOP Concepts

### 1. Runtime Polymorphism

- **Virtual Functions:** Dynamic method dispatch
- **Abstract Classes:** Pure virtual functions
- **Virtual Destructors:** Proper cleanup in inheritance

### 2. Operator Overloading

- **Binary Operators:** +, -, \*, /, ==, <, etc.
- **Unary Operators:** ++, --, !, ~
- **Assignment Operators:** =, +=, -=, etc.
- **Friend Functions:** Access to private members

### 3. Templates

- **Function Templates:** Generic functions
- **Class Templates:** Generic classes
- **Template Specialization:** Custom implementations
- **Variadic Templates:** Variable number of arguments

### 4. Memory Management

- **RAII:** Resource management
- **Smart Pointers:** Automatic memory management
- **Custom Allocators:** Specialized memory allocation
- **Move Semantics:** Efficient resource transfer

### 5. Design Patterns

- **Factory Pattern:** Object creation
- **Observer Pattern:** Event handling
- **Strategy Pattern:** Algorithm selection
- **Singleton Pattern:** Single instance

## Key Takeaways

### Virtual Functions

```cpp
// Base class with virtual function
class Shape {
public:
    virtual void draw() {
        cout << "Drawing shape..." << endl;
    }
    virtual ~Shape() {} // Virtual destructor
};

// Derived class overriding virtual function
class Circle : public Shape {
public:
    void draw() override { // Explicit override
        cout << "Drawing circle..." << endl;
    }
};
```

### Operator Overloading

```cpp
// Overloading binary operator
Complex operator + (Complex &obj) {
    int resReal = this->real + obj.real;
    int resImaginary = this->imaginary + obj.imaginary;
    return Complex(resReal, resImaginary);
}

// Overloading as friend function
friend Complex operator + (Complex c1, Complex c2);
```

### Template Programming

```cpp
// Function template
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Class template
template <typename T>
class Container {
private:
    T value;
public:
    void setValue(T val) { value = val; }
    T getValue() { return value; }
};
```

### Best Practices

- **Use virtual destructors:** In base classes with virtual functions
- **Override explicitly:** Use `override` keyword
- **RAII principle:** Manage resources in constructors/destructors
- **Const correctness:** Use const where appropriate
- **Template specialization:** For optimized implementations

### Common Mistakes

- **Missing virtual destructor:** In polymorphic base classes
- **Incorrect operator overloading:** Wrong return types or parameters
- **Template instantiation issues:** For complex template code
- **Friend function misuse:** Over-exposure of private members

### Interview Tips

- **Polymorphism:** Explain virtual functions and dynamic dispatch
- **Operator overloading:** Show practical examples
- **Templates:** Demonstrate generic programming
- **Memory management:** RAII and smart pointers
- **Design patterns:** Common patterns and their use cases

### Real-World Applications

1. **Game Engines**

   - Entity-component system
   - Plugin architecture
   - Resource management

2. **GUI Frameworks**

   - Widget hierarchies
   - Event handling
   - Layout management

3. **Database Systems**

   - Query result objects
   - Connection management
   - Transaction handling

4. **Network Programming**

   - Protocol implementations
   - Socket wrappers
   - Message handling

5. **Financial Systems**
   - Instrument classes
   - Pricing models
   - Risk management

### Modern C++ Features

1. **Smart Pointers**

   - `unique_ptr`: Exclusive ownership
   - `shared_ptr`: Shared ownership
   - `weak_ptr`: Non-owning reference

2. **Move Semantics**

   - Rvalue references (`&&`)
   - Move constructors and assignment
   - Perfect forwarding

3. **Lambda Expressions**

   - Anonymous functions
   - Closures
   - Functional programming

4. **Type Traits**
   - Compile-time type information
   - SFINAE applications
   - Template metaprogramming

### Performance Considerations

- **Virtual function overhead:** Vtable lookup
- **Template code bloat:** Multiple instantiations
- **Object slicing:** In non-polymorphic contexts
- **Memory layout:** Cache performance

### Testing OOP Code

1. **Polymorphism Testing**

   - Test virtual function calls
   - Test abstract class instantiation
   - Test dynamic casting

2. **Template Testing**

   - Test with different types
   - Test template specializations
   - Test compilation errors

3. **Memory Testing**
   - Test smart pointer behavior
   - Test RAII compliance
   - Test copy and move operations

### Advanced Topics

1. **Multiple Inheritance**

   - Diamond problem
   - Virtual base classes
   - Interface design

2. **Template Metaprogramming**

   - Compile-time computation
   - Type manipulation
   - Policy-based design

3. **Reflection**

   - Runtime type information
   - Dynamic casting
   - Type introspection

4. **Memory Models**
   - Object layout
   - Virtual table structure
   - Memory alignment

### Design Principles

1. **SOLID Principles**

   - Single Responsibility
   - Open/Closed
   - Liskov Substitution
   - Interface Segregation
   - Dependency Inversion

2. **GRASP Patterns**

   - Information Expert
   - Creator
   - Controller
   - Low Coupling
   - High Cohesion

3. **Design Patterns**
   - Creational (Factory, Singleton)
   - Structural (Adapter, Decorator)
   - Behavioral (Observer, Strategy)

### Debugging OOP Code

1. **Memory Issues**

   - Use Valgrind for leak detection
   - Check virtual destructor calls
   - Validate copy operations

2. **Polymorphism Issues**

   - Check virtual function resolution
   - Verify object slicing
   - Test dynamic casting

3. **Template Issues**
   - Check compilation errors
   - Verify type deduction
   - Test with different types

### Best Practices Summary

- **Encapsulation:** Hide implementation details
- **Inheritance:** Use for "is-a" relationships
- **Polymorphism:** Use virtual functions for flexibility
- **Composition:** Prefer over inheritance when possible
- **RAII:** Manage resources automatically
- **Const Correctness:** Use const appropriately
- **Template Design:** Make code generic and reusable
- **Exception Safety:** Ensure exception-safe code
