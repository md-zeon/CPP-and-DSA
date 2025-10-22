#include <iostream>
#include <string>
using namespace std;

class Student {
//access modifier
private:
    //properties
    string name;
    float cgpa;
//access modifier
public:
    //methods
    void getPercentage() {
        cout << (cgpa * 10) << "% \n";
    }
    //setter functions
    void setName(string n) {
        name = n;
    }
    void setCgpa(float cg) {
        cgpa = cg;
    }
    //getter functions
    string getName() {
        return name;
    }
    float getCgpa() {
        return cgpa;
    }
};

class Car {
    string name;
    string color;
public:
    int *mileage;
    //constructor overloading

    //non-parameterized constructor
    Car() {
        cout << "Constructor without parameter is called. object being created..." << endl;
    }

    //parameterized constructor
    Car(string name, string color) {
        cout << "Constructor with parameter is called. object being created..." << endl;
        // name = nameVal;
        // color = colorVal;
        this->name = name;
        this->color = color; // *(this).color = color;
        mileage = new int; // Dynamic allocation (heap)
        *mileage = 12;
    }

    //custom copy constructor (deep copy)
    Car(Car &original) {
        cout << "Copy Constructor is called. object being created..." << endl;
        cout << "Copying original ->> new..." << endl;
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }

    void start() {
        cout << "Car has started" << endl;
    }

    void stop() {
        cout << "Car has stoped" << endl;
    }
    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }

    //Destructor
    ~Car() {
        cout << "Deleting object..." << endl;
        if(mileage != NULL) {
            delete mileage;
            mileage = NULL;
        }
    }
};

//! Practice Question:
/**
 * Create a User class with properties: id(private), username(public), & password(private).
 * It's id should be initialized in a parameterized constructor.
 * It should have a getter and setter for password.
 */

class User{
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
};


// inheritance:

class Animal{
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

class Mammal : public Animal{
public:
    string bloodType;
    Mammal() {
        bloodType = "Warm";
    }
};

class Dog : public Mammal{
public:
    void tailWag() {
        cout << "Wags Tail" << endl;
    }
};

class Teacher {
public:
    int salary;
    string subject;
};

class student {
public:
    int rollNo;
    float cgpa;
};

class TA : public Teacher, public student {
public:
    string name;
};

int main() {
    // Student s1; //object
    // cout << sizeof(s1) << endl;
    // s1.setName("Zeon");
    // s1.setCgpa(9.1);

    // cout << "Name: " << s1.getName() << endl;
    // cout << "Cgpa: " << s1.getCgpa() << endl;
    // s1.getPercentage();
    // Car c0;
    // Car c1("Maruti 800", "Blue");
    // cout << "Car Name: " << c1.getName() << endl;
    // cout << "Car Color: " << c1.getColor() << endl;
    // cout << "Mileage: " << *c1.mileage << endl;
    // Car c2(c1); // calling custom copy constructor
    // *c2.mileage = 10;
    // cout << "Car Name: " << c2.getName() << endl;
    // cout << "Car Color: " << c2.getColor() << endl;
    // cout << "Mileage address: " << c1.mileage << endl;
    // cout << "Mileage address: " << c2.mileage << endl; 
    // cout << "Mileage: " << *c1.mileage << endl;
    // cout << "Mileage: " << *c2.mileage << endl;

    // Fish f1;
    // f1.fins = 3;
    // cout << "Fins = " << f1.fins << endl;
    // f1.swim();
    // f1.eat();
    // f1.breath();

    // Dog d1;
    // d1.eat();
    // d1.breath();
    // d1.tailWag();
    // cout << d1.bloodType << endl;

    TA ta1;
    ta1.name = "Zeanur Rahaman Zeon";
    ta1.subject = "C++";
    ta1.cgpa = 9.1;

    cout << ta1.name << endl;
    cout << ta1.subject << endl;
    cout << ta1.cgpa << endl;
    return 0;
}