# Day 18: Object Oriented Programming Part 2

## Topics Covered

- **Operator Overloading**: Redefining operators for custom classes
- **Function Overriding**: Runtime polymorphism with virtual functions
- **Abstract Classes**: Pure virtual functions and interfaces
- **Static Members**: Class-level data and functions
- **Friend Functions**: Accessing private members from outside class
- **Friend Classes**: Granting full access to another class

## Key Concepts

1. **Polymorphism**: Compile-time (overloading) vs Runtime (overriding)
2. **Virtual Functions**: Dynamic binding and late binding
3. **Abstract Classes**: Cannot be instantiated, used as base classes
4. **Static Members**: Shared across all objects of a class
5. **Friend Mechanism**: Breaking encapsulation for specific needs

## Code Examples

### 1. Operator Overloading

```cpp
class Complex {
    int real;
    int imaginary;

public:
    Complex(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }

    void showNum() {
        (imaginary > 0) ?
            cout << real << " + " << imaginary << "i" << endl :
            cout << real << " - " << ((-1) * imaginary) << "i" << endl;
    }

    // Operator Overloading for Addition
    Complex operator + (Complex &obj) {
        int resReal = this->real + obj.real;
        int resImaginary = this->imaginary + obj.imaginary;
        Complex result(resReal, resImaginary);
        return result;
    }

    // Operator Overloading for Subtraction
    Complex operator - (Complex &obj) {
        int resReal = this->real - obj.real;
        int resImaginary = this->imaginary - obj.imaginary;
        Complex result(resReal, resImaginary);
        return result;
    }
};

// Usage
Complex c1(1, 2);
Complex c2(3, 4);
Complex c3 = c1 + c2;  // Operator overloading
c3.showNum();          // Output: 4 + 6i
```

### 2. Function Overriding and Virtual Functions

```cpp
class Parent {
public:
    void show() {
        cout << "Parent class show..." << endl;
    }

    virtual void hello() {  // Virtual function enables runtime polymorphism
        cout << "Parent hello..." << endl;
    }
};

class Child : public Parent {
public:
    void show() {  // Function overriding (compile-time binding)
        cout << "Child class show..." << endl;
    }

    void hello() {  // Function overriding (runtime binding due to virtual)
        cout << "Child hello..." << endl;
    }
};

// Usage
Child child1;
child1.show();  // Output: Child class show...

Parent *ptr = &child1;  // Base class pointer to derived class object
ptr->hello();   // Output: Child hello... (runtime polymorphism)
```

### 3. Abstract Classes and Pure Virtual Functions

```cpp
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function
    // Abstract class cannot be instantiated
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing circle..." << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "Drawing Square..." << endl;
    }
};

// Usage
Circle circle1;
circle1.draw();  // Output: Drawing circle...

Square square1;
square1.draw();  // Output: Drawing Square...

// Shape shape1;  // Error: Cannot instantiate abstract class
```

### 4. Static Members

```cpp
class Example {
public:
    static int x;  // Static data member

    Example() {
        cout << "Constructor" << endl;
    }

    ~Example() {
        cout << "Destructor" << endl;
    }
};

// Static member definition outside class
int Example::x = 0;

// Usage
Example eg1;
Example eg2;
Example eg3;

cout << eg1.x++ << endl;  // 0, then x becomes 1
cout << eg2.x++ << endl;  // 1, then x becomes 2
cout << eg3.x++ << endl;  // 2, then x becomes 3

// Static members are shared across all objects
```

### 5. Static Local Variables

```cpp
void counter() {
    static int count = 0;  // Static local variable
    count++;
    cout << "Count = " << count << endl;
}

// Usage
counter();  // Output: Count = 1
counter();  // Output: Count = 2
counter();  // Output: Count = 3

// Static local variables retain their value between function calls
```

### 6. Friend Functions

```cpp
class A {
    string secret = "Secret Data";

    friend class B;           // Friend class
    friend void revealSecret(A &obj);  // Friend function
};

class B {
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;  // Can access private members
    }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;  // Can access private members
}

// Usage
A a1;
B b1;
b1.showSecret(a1);     // Output: Secret Data
revealSecret(a1);      // Output: Secret Data
```

## Polymorphism Types

### Compile-Time Polymorphism (Static Binding)

- **Function Overloading**: Same function name, different parameters
- **Operator Overloading**: Redefining operators for custom types
- **Binding**: Resolved at compile time

### Runtime Polymorphism (Dynamic Binding)

- **Function Overriding**: Virtual functions in inheritance
- **Virtual Functions**: Enable late binding
- **Binding**: Resolved at runtime using vtable

## Virtual Function Table (VTable)

- **Mechanism**: Compiler creates vtable for classes with virtual functions
- **Pointer**: Each object has vptr pointing to vtable
- **Late Binding**: Runtime lookup of correct function implementation
- **Performance**: Small overhead due to indirection

## Abstract Classes

- **Pure Virtual Functions**: `virtual void func() = 0;`
- **Instantiation**: Cannot create objects of abstract class
- **Purpose**: Define interface for derived classes
- **Implementation**: Derived classes must implement all pure virtual functions

## Static Members

### Static Data Members

- **Declaration**: `static int count;`
- **Definition**: `int ClassName::count = 0;` (outside class)
- **Sharing**: Single copy shared by all objects
- **Access**: `object.member` or `ClassName::member`

### Static Member Functions

- **Declaration**: `static void func();`
- **Access**: No `this` pointer, cannot access non-static members
- **Usage**: Utility functions, factory methods

## Friend Mechanism

### Friend Functions

- **Declaration**: `friend returnType functionName(params);`
- **Access**: Can access private and protected members
- **Scope**: Global functions with class access privileges

### Friend Classes

- **Declaration**: `friend class ClassName;`
- **Access**: All member functions of friend class can access private members
- **Usage**: When two classes need tight coupling

## Key Takeaways

- **Operator Overloading**: Enhances readability and usability
- **Virtual Functions**: Enable runtime polymorphism
- **Abstract Classes**: Define contracts for derived classes
- **Static Members**: Shared resources across objects
- **Friend Functions**: Controlled access to private members
- **Memory Layout**: VTable adds small overhead for virtual functions

## Common Mistakes to Avoid

- Forgetting to declare functions as virtual in base class
- Not implementing pure virtual functions in derived classes
- Incorrect operator overloading syntax
- Forgetting to define static members outside class
- Overusing friend functions (breaks encapsulation)

## Best Practices

- **Virtual Destructors**: Always make base class destructor virtual
- **Override Keyword**: Use `override` keyword in derived classes (C++11)
- **Const Correctness**: Overload const and non-const operators appropriately
- **Minimal Friends**: Use friend mechanism sparingly
- **Static Usage**: Use static for class-level data and utility functions

## Performance Considerations

- **Virtual Functions**: Small overhead due to vtable lookup
- **Static Members**: No per-object overhead
- **Inline Functions**: Can optimize small frequently called functions
- **Abstract Classes**: No runtime overhead, compile-time contract
