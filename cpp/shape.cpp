#include <iostream>
#include <cmath> // For circle calculations
using namespace std;

// Abstract base class
class Shape {
protected:
    int sides;

public:
    // Constructor
    Shape(int sides) : sides(sides) {}

    // Pure virtual functions
    virtual void display() const = 0;
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base, height;

public:
    // Constructor
    Triangle(double base, double height) : Shape(3), base(base), height(height) {}

    // Implementing the pure virtual functions
    void display() const override {
        cout << "I am a triangle with " << sides << " sides." << endl;
    }

    double area() const override {
        return 0.5 * base * height;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, breadth;

public:
    // Constructor
    Rectangle(double length, double breadth) : Shape(4), length(length), breadth(breadth) {}

    // Implementing the pure virtual functions
    void display() const override {
        cout << "I am a rectangle with " << sides << " sides." << endl;
    }

    double area() const override {
        return length * breadth;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double radius) : Shape(1), radius(radius) {}

    // Implementing the pure virtual functions
    void display() const override {
        cout << "I am a circle with " << sides << " sides." << endl;
    }

    double area() const override {
        return M_PI * radius * radius; // Use M_PI from <cmath> for π
    }
};

int main() {
    // Using the derived classes
    Shape* triangle = new Triangle(5, 2);
    triangle->display();
    cout << "Area: " << triangle->area() << endl;

    Shape* rectangle = new Rectangle(10, 5);
    rectangle->display();
    cout << "Area: " << rectangle->area() << endl;

    Shape* circle = new Circle(7);
    circle->display();
    cout << "Area: " << circle->area() << endl;

    // Clean up
    delete triangle;
    delete rectangle;
    delete circle;

    return 0;
}
