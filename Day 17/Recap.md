# Day 17: Object Oriented Programming Part 1

## Topics Covered

- **Classes and Objects**: Basic OOP structure
- **Access Modifiers**: Private and public members
- **Getter/Setter Methods**: Encapsulation implementation
- **Constructors**: Default, parameterized, and copy constructors
- **Destructors**: Memory cleanup
- **Inheritance**: Single and multiple inheritance
- **This Pointer**: Referencing current object

## Key Concepts

1. **Encapsulation**: Hiding data and exposing methods
2. **Abstraction**: Showing only necessary information
3. **Inheritance**: Code reuse through parent-child relationships
4. **Polymorphism**: Different behaviors for same interface (to be covered later)
5. **Memory Management**: Dynamic allocation and cleanup

## Code Examples

### 1. Basic Class and Object

```cpp
class Student {
private:
    string name;
    float cgpa;

public:
    // Setter methods
    void setName(string n) {
        name = n;
    }
    void setCgpa(float cg) {
        cgpa = cg;
    }

    // Getter methods
    string getName() {
        return name;
    }
    float getCgpa() {
        return cgpa;
    }

    // Member function
    void getPercentage() {
        cout << (cgpa * 10) << "% \n";
    }
};

// Usage
Student s1;
s1.setName("Zeon");
s1.setCgpa(9.1);
cout << "Name: " << s1.getName() << endl;
s1.getPercentage();
```

### 2. Constructors

```cpp
class Car {
    string name;
    string color;

public:
    int *mileage;

    // Non-parameterized constructor
    Car() {
        cout << "Constructor without parameter is called" << endl;
    }

    // Parameterized constructor
    Car(string name, string color) {
        cout << "Constructor with parameter is called" << endl;
        this->name = name;    // 'this' pointer refers to current object
        this->color = color;
        mileage = new int;    // Dynamic allocation
        *mileage = 12;
    }
};

// Usage
Car c1("Maruti 800", "Blue");
cout << "Mileage: " << *c1.mileage << endl;
```

### 3. Copy Constructor (Deep Copy)

```cpp
class Car {
public:
    // Custom copy constructor for deep copy
    Car(Car &original) {
        cout << "Copy Constructor is called" << endl;
        name = original.name;
        color = original.color;
        mileage = new int;           // Deep copy - new memory allocation
        *mileage = *original.mileage;
    }

    // Destructor
    ~Car() {
        cout << "Deleting object..." << endl;
        if(mileage != NULL) {
            delete mileage;          // Clean up dynamic memory
            mileage = NULL;
        }
    }
};

// Usage
Car c1("Toyota", "Red");
Car c2(c1);  // Copy constructor called
*c2.mileage = 10;  // Changes only c2's mileage (deep copy)
```

### 4. Inheritance

```cpp
class Animal {
public:
    void eat() {
        cout << "Eats" << endl;
    }
    void breath() {
        cout << "Breathes" << endl;
    }
};

class Fish : public Animal {
public:
    int fins;
    void swim() {
        cout << "Swims" << endl;
    }
};

class Mammal : public Animal {
public:
    string bloodType;
    Mammal() {
        bloodType = "Warm";
    }
};

class Dog : public Mammal {
public:
    void tailWag() {
        cout << "Wags Tail" << endl;
    }
};

// Usage
Dog d1;
d1.eat();        // Inherited from Animal
d1.breath();     // Inherited from Animal
d1.tailWag();    // Own method
cout << d1.bloodType << endl;  // Inherited from Mammal
```

### 5. Multiple Inheritance

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

// Usage
TA ta1;
ta1.name = "Zeanur Rahaman Zeon";
ta1.subject = "C++";
ta1.cgpa = 9.1;

cout << ta1.name << endl;
cout << ta1.subject << endl;
cout << ta1.cgpa << endl;
```

### 6. Practice Question - User Class

```cpp
class User {
private:
    int id;
    string password;

public:
    string username;

    // Parameterized constructor
    User(int id) {
        this->id = id;
    }

    // Setter for password
    void setPassword(string password) {
        this->password = password;
    }

    // Getter for password
    string getPassword() {
        return password;
    }
};
```

## Access Modifiers

### Private Members

- **Declaration**: `private:`
- **Access**: Only within the same class
- **Purpose**: Hide implementation details
- **Example**: Data members, helper functions

### Public Members

- **Declaration**: `public:`
- **Access**: From anywhere in the program
- **Purpose**: Interface for class interaction
- **Example**: Public methods, constructors, destructors

## Constructor Types

### 1. Non-parameterized Constructor

```cpp
Car() {
    // Default initialization
}
```

### 2. Parameterized Constructor

```cpp
Car(string name, string color) {
    this->name = name;
    this->color = color;
}
```

### 3. Copy Constructor

```cpp
Car(Car &original) {
    // Copy all members
}
```

## This Pointer

- **Purpose**: Reference to current object
- **Usage**: `this->member` to access current object's member
- **Necessity**: Distinguish between parameter and member names
- **Type**: `ClassName *const this` (constant pointer)

## Inheritance Types

### Single Inheritance

```cpp
class Derived : public Base {
    // Inherits from one base class
};
```

### Multiple Inheritance

```cpp
class Derived : public Base1, public Base2 {
    // Inherits from multiple base classes
};
```

## Key Takeaways

- **Encapsulation**: Private data, public methods
- **Constructor Initialization**: Use member initializer list when possible
- **Deep Copy**: Create new memory for pointer members in copy constructor
- **Destructor**: Always clean up dynamic memory
- **Inheritance**: Public inheritance preserves access levels
- **This Pointer**: Implicit parameter in member functions

## Common Mistakes to Avoid

- Forgetting to define copy constructor for classes with pointers
- Not cleaning up dynamic memory in destructor
- Accessing private members from outside class
- Forgetting to use `this->` when parameter names match member names
- Incorrect inheritance syntax

## Memory Layout

- **Object Size**: Sum of all non-static members
- **Padding**: Compiler adds padding for alignment
- **VTable**: Virtual functions add pointer to vtable (for polymorphism)
- **Inheritance**: Derived class contains base class as subobject

## Best Practices

- **RAII**: Resource Acquisition Is Initialization
- **Rule of Three**: If you define destructor, copy constructor, or copy assignment, define all three
- **Const Correctness**: Use const for methods that don't modify object
- **Access Levels**: Keep data private, provide public interface
- **Initialization**: Initialize all members in constructor
