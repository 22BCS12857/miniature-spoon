#include <iostream>
#include <string>
using namespace std;
// Function to calculate salary for Interns
double calculateSalary(double stipend) {
    return stipend;
}

// Function to calculate salary for Regular Employees
double calculateSalary(double baseSalary, double bonuses) {
    return baseSalary + bonuses;
}

// Function to calculate salary for Managers
double calculateSalary(double baseSalary, double bonuses, double performanceIncentives) {
    return baseSalary + bonuses + performanceIncentives;
}

int main() {
    // Intern salary calculation
    double internStipend = 15000; // Monthly stipend for intern
     cout << "Intern Salary: " << calculateSalary(internStipend) << "\n";

    // Regular employee salary calculation
    double regularBaseSalary = 50000; // Base salary for a regular employee
    double regularBonuses = 10000;    // Bonuses for a regular employee
     cout << "Regular Employee Salary: " << calculateSalary(regularBaseSalary, regularBonuses) << "\n";

    // Manager salary calculation
    double managerBaseSalary = 80000;         // Base salary for a manager
    double managerBonuses = 20000;            // Bonuses for a manager
    double managerPerformanceIncentives = 15000; // Performance incentives for a manager
     cout << "Manager Salary: " << calculateSalary(managerBaseSalary, managerBonuses, managerPerformanceIncentives) << "\n";

    return 0;
}
