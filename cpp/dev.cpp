#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    // Constructor
    Employee(string empName, int empId, double empSalary)
        : name(empName), id(empId), salary(empSalary) {}

    // Virtual function to calculate total earnings
    virtual double calculateTotalEarnings() const = 0;

    // Virtual function to display details
    virtual void displayDetails() const {
        cout << "ID: " << id << "\nName: " << name << "\nBase Salary: " << salary << endl;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Derived class: Manager
class Manager : public Employee {
private:
    double performanceRating; // Rating between 0 and 5

public:
    // Constructor
    Manager(string empName, int empId, double empSalary, double rating)
        : Employee(empName, empId, empSalary), performanceRating(rating) {}

    // Function to calculate bonuses based on performance
    double calculateBonus() const {
        return salary * (performanceRating / 5) * 0.2; // 20% bonus based on rating
    }

    // Overriding calculateTotalEarnings
    double calculateTotalEarnings() const override {
        return salary + calculateBonus();
    }

    // Overriding displayDetails
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Performance Rating: " << performanceRating << "\nTotal Earnings: " << calculateTotalEarnings() << endl;
    }
};

// Derived class: Developer
class Developer : public Employee {
private:
    int extraHours;
    double hourlyRate;

public:
    // Constructor
    Developer(string empName, int empId, double empSalary, int hours, double rate)
        : Employee(empName, empId, empSalary), extraHours(hours), hourlyRate(rate) {}

    // Function to calculate overtime compensation
    double calculateOvertime() const {
        return extraHours * hourlyRate;
    }

    // Overriding calculateTotalEarnings
    double calculateTotalEarnings() const override {
        return salary + calculateOvertime();
    }

    // Overriding displayDetails
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Extra Hours Worked: " << extraHours << "\nHourly Rate: " << hourlyRate
             << "\nTotal Earnings: " << calculateTotalEarnings() << endl;
    }
};

int main() {
    // Input for Manager
    Manager manager("Alice", 101, 80000, 4.5);

    // Input for Developer
    Developer developer("Bob", 102, 60000, 20, 50);

    // Display details
    cout << "Manager Details:\n";
    manager.displayDetails();
    cout << "\nDeveloper Details:\n";
    developer.displayDetails();

    return 0;
}
