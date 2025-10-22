#include <iostream> // preprossessor directives

#define PI 3.14; // macro definitions

using namespace std;

int main() {
    // cout << "Apna Collage" << " " << PI;
    // cout << endl << "Print pattern: " << endl;
    // cout << "****\n***\n**\n*\n";
    // int a = 10;
    // int b = 5;
    // cout << "a + b = " << a+b << endl;
    // int c; // c has garbage value
    // cout << "c = " << c << endl;

    // cout << "Data Types :\n";
    // cout << "1. Primitive: int(4 bytes), char(1 bytes), bool(1 bytes), float(4 bytes), double(8 bytes)\n";
    // cout << "2. Non-Primitive: strings, Arrays etc.\n";

    // int age;
    // cout << "Enter age: ";
    // cin >> age;

    // cout << "Your age is " << age << endl;

    // int A, B, sum;
    // cout << "Enter A & B: ";
    // cin >> A >> B;
    // sum = A + B;
    // int prod = A * B;
    // cout << "Sum = " << sum << endl;
    // cout << "Product = " << prod << endl;

    // // average marks

    // int eng, science, math;
    // cout << "Enter English Marks: ";
    // cin >> eng;
    // cout << "Enter Science Marks: ";
    // cin >> science;
    // cout << "Enter Math Marks: ";
    // cin >> math;
    // float avg = (eng + science + math) / 3.0;
    // cout << "Average is = " << avg << endl;

    // Practice Task

    // Question 1: Area of a square (inpput from user)

    int n;
    cin >> n;
    cout << "Area of a square is = " << n*n << endl;

    // Question 2: calculate total bill
    float pencil, pen, eraser;
    cin >> pencil >> pen >> eraser;
    float bill = pencil + pen + eraser;
    float gst = bill * (18 / (float)100);
    bill -= gst;
    cout << "Total Bill = " << bill << endl;

    // Question 03: simple interest calculator

    int p, t;
    float r;
    float interest = (p * r * t) / (float)100;
    cout << "Interest is = " << interest << endl;

    // Question 04: area of a circle 
    int radius;
    cin >> radius;
    float area = 3.14 * radius * radius;

    cout << "Area of circle is = " << area << endl;

    return 0;
}