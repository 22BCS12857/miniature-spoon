#include <iostream>
#include <string>
using namespace std;

// Base class: Student
class Student {
protected:
    int rollNumber;
    string name;

public:
    void setStudentDetails(int r, string n) {
        rollNumber = r;
        name = n;
    }

    void displayStudentDetails() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
    }
};

// Derived class: Result
class Result : public Student {
private:
    float marks[3]; // Marks for three subjects

public:
    void setMarks(float m1, float m2, float m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float calculateTotal() {
        return marks[0] + marks[1] + marks[2];
    }

    float calculatePercentage() {
        return calculateTotal() / 3;
    }

    void displayResult() {
        displayStudentDetails();
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Total Marks: " << calculateTotal() << endl;
        cout << "Percentage: " << calculatePercentage() << "%" << endl;
    }
};

int main() {
    Result student;

    // Setting student details
    student.setStudentDetails(101, "John Doe");

    // Setting marks
    student.setMarks(85.5, 92.0, 78.0);

    // Displaying result
    student.displayResult();

    return 0;
}
