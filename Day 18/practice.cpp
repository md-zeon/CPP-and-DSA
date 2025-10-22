#include <iostream>
using namespace std;

class Complex{
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

class BankAccount { 
private:
    int accountNumber; 
    double balance;
public:
    BankAccount(int accNum, double bal) { 
        accountNumber = accNum;
        balance = bal;
    }
    void deposit(double amount) { 
        balance += amount;
    }
    void withdraw(double amount) { 
        if(amount <= balance) {
            balance -= amount;
        } else {
            cout << "No sufficient balance for this withdrawal.\n";
        }
    }
    double getBalance() {
        return balance;
    }
};


class Person { 
protected:
    string name; 
    int age;
public:
    Person(string n, int a) { 
        name = n;
        age = a;
    }
};
class Student : public Person { 
private:
    string studentID;
public:
    Student(string n, int a, string id) : Person(n, a) { 
        studentID = id;
    }
    void displayStudentInfo() {
        cout << "name : " << this->name << endl; 
        cout << "age : " << this->age << endl;
        cout << "studentId : " << this->studentID << endl;
    }
};


int main() {
    /*
    
    * Question 1 : Create a class to store Complex numbers. Using operator overloading, 
    * create the logic to subtract one complex number from another.
    * Note - In Complex numbers, the real part of 1st gets subtracted from the real part of 
    * 2nd number. Same goes for the imaginary part.
    * 
    * 
    * Question 2 : Create a class BankAccount with private attributes accountNumber and 
    * balance. Implement public methods deposit(), withdraw(), and getBalance() to 
    * manage the account.
    * 
    * 
    * Question 3 : Create a base class Person with attributes name and age.
    * Derive a class Student from Person and add an additional attribute studentID.
    * Implement a method displayStudentInfo( ) in the Student class to display all details.
    * In main function Student class object will be created in this format:
    * Student student("Alice", 20, "S12345");
    * 
    * 
    * 
    ? Note - When we initialize an object of a derived class, the base class part has to be 
    ? constructed first.
    ? If we don't initialize it ourselves in the derived class' constructor by calling one of its 
    ? constructors, the compiler will attempt to use the default constructor of the base 
    ? class.
    ? To invoke the parent’s parameterized constructor in Child’s constructor, syntax is :
    ? Child(int x) : Parent(x)
    ? { …… }
    
    */

    Complex c1(1, 2);
    Complex c2(3, 4);
    c1.showNum();
    c2.showNum();
    Complex c3 = c1 + c2;
    c3.showNum();
    Complex c4 = c1 - c2 + c3;
    c4.showNum();


    BankAccount myAccount(123456, 500.0); 
    myAccount.deposit(150.0); 
    myAccount.withdraw(100.0);
    cout << "Current Balance: Rs." << myAccount.getBalance() << endl; 

    Student student("Alice", 20, "S12345"); 
    student.displayStudentInfo();

    return 0;
}