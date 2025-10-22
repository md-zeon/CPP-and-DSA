#include <iostream>
#include <string>
using namespace std;

class Complex {
    int real;
    int imaginary;
public:
    Complex(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
    void showNum() {
        (imaginary > 0) ? cout << real << " + " << imaginary << "i" << endl : cout << real << " - " << ((-1) * imaginary) << "i" << endl;
    }

    // Operator Overloading
    Complex operator + (Complex &obj) {
        int resReal = this->real + obj.real;
        int resImaginary = this->imaginary + obj.imaginary;
        Complex result(resReal, resImaginary);
        return result;
    }

    Complex operator - (Complex &obj) {
        int resReal = this->real - obj.real;
        int resImaginary = this->imaginary - obj.imaginary;
        Complex result(resReal, resImaginary);
        return result;
    }
};

class Parent{
public:
    void show() {
        cout << "Parent class show..." << endl;
    }
    virtual void hello() {
        cout << "Parent hello..." << endl;
    }
};

class Child : public Parent{
public:
    // function overriding
    void show() {
        cout << "Child class show..." << endl;
    }
    void hello() {
        cout << "Child hello..." << endl;
    }
};

class Shape{
public:
    virtual void draw() = 0; // abstract function / pure virtual function
};

class Circle : public Shape{
public:
    void draw() {
        cout << "Drawing circle..." << endl;
    }
};

class Square : public Shape{
public:
    void draw() {
        cout << "Drawing Square..." << endl;
    }
};

void counter() {
    static int count = 0; // static uses in function
    count++;
    cout << "Count = " << count << endl;
}

class Example {
public:
    static int x;
    // static const int x;
    Example() {
        cout << "Constructor" << endl;
    }
    ~Example() {
        cout << "Destructor" << endl;
    }
};

int Example::x = 0;

class A{
    string secret = "Secret Data";
    friend class B;
    friend void revealSecret(A &obj);
};
class B{ // becomes a friend class of A
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;;
    }
};

void revealSecret(A &obj) {
    cout << obj.secret << endl;
}

int main() {
    // Complex c1(1, 2);
    // Complex c2(3, 4);
    // c1.showNum();
    // c2.showNum();
    // Complex c3 = c1 + c2;
    // c3.showNum();
    // Complex c4 = c1 - c2 + c3;
    // c4.showNum();

    Child child1;
    child1.show();
    Parent *ptr;
    ptr = &child1;
    ptr->hello();

    // Circle circle1;
    // circle1.draw();
    // Square square1;
    // square1.draw();

    // counter(); // 1
    // counter(); // 2
    // counter(); // 3
    // if(true) {
    //     static Example es0;
    // }
 
    // Example eg1;
    // Example eg2;
    // Example eg3;
    // cout << eg1.x++ << endl;
    // cout << eg2.x++ << endl;
    // cout << eg3.x++ << endl;
    // cout << "code ending..." << endl;

    A a1;
    B b1;
    b1.showSecret(a1);
    revealSecret(a1);



    return 0;
}