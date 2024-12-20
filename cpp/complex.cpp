#include <iostream>
#include <cmath>
using namespace std;

// Complex class definition
class Complex {
private:
    double real, imaginary;

public:
    // Constructor to initialize complex number
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Function to overload addition operator for complex numbers
    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Function to overload multiplication operator for complex numbers
    Complex operator * (const Complex& other) {
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    // Function to calculate the magnitude of a complex number
    double magnitude() {
        return sqrt(real * real + imaginary * imaginary);
    }

    // Function to display complex number in the form a + bi
    void display() {
        if (imaginary < 0) {
            cout << real << " - " << -imaginary << "i" << endl;
        } else {
            cout << real << " + " << imaginary << "i" << endl;
        }
    }
};

int main() {
    int operation;
    cout << "Enter Operation Type (1 for Addition, 2 for Multiplication, 3 for Magnitude): ";
    cin >> operation;

    if (operation == 1) {
        double real1, imaginary1, real2, imaginary2;
        cout << "Enter first complex number (real1 imaginary1): ";
        cin >> real1 >> imaginary1;
        cout << "Enter second complex number (real2 imaginary2): ";
        cin >> real2 >> imaginary2;

        Complex num1(real1, imaginary1), num2(real2, imaginary2);
        Complex result = num1 + num2;

        cout << "Result: ";
        result.display();
    }
    else if (operation == 2) {
        double real1, imaginary1, real2, imaginary2;
        cout << "Enter first complex number (real1 imaginary1): ";
        cin >> real1 >> imaginary1;
        cout << "Enter second complex number (real2 imaginary2): ";
        cin >> real2 >> imaginary2;

        Complex num1(real1, imaginary1), num2(real2, imaginary2);
        Complex result = num1 * num2;

        cout << "Result: ";
        result.display();
    }
    else if (operation == 3) {
        double real, imaginary;
        cout << "Enter complex number (real imaginary): ";
        cin >> real >> imaginary;

        Complex num(real, imaginary);
        cout << "Result: Magnitude = " << num.magnitude() << endl;
    }
    else {
        cout << "Invalid operation type." << endl;
    }

    return 0;
}
