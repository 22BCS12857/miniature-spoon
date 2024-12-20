#include <iostream>
#include <string>
using namespace std;

// Base class: Vehicle
class Vehicle {
protected:
    string brand;
    string model;
    double mileage;

public:
    Vehicle(string b, string m, double mil) : brand(b), model(m), mileage(mil) {}

    void displayDetails() {
        cout << "Vehicle: " << brand << " " << model << endl;
        cout << "Mileage: " << mileage << endl;
    }
};

// Derived class: Car
class Car : public Vehicle {
protected:
    double fuel;  // Gallons
    double distance;  // Miles

public:
    Car(string b, string m, double mil, double f, double d)
        : Vehicle(b, m, mil), fuel(f), distance(d) {}

    double calculateFuelEfficiency() {
        if (fuel > 0)
            return distance / fuel;
        else
            return 0; // Avoid division by zero
    }
};

// Derived class: ElectricCar
class ElectricCar : public Car {
private:
    double batteryCapacity;  // kWh
    double efficiency;  // Miles per kWh

public:
    ElectricCar(string b, string m, double mil, double cap, double eff)
        : Car(b, m, mil, 0, 0), batteryCapacity(cap), efficiency(eff) {}

    double calculateRange() {
        return batteryCapacity * efficiency;
    }
};

int main() {
    int vehicleType;
    cout << "Enter Vehicle Type (1 for Car, 2 for Electric Car): ";
    cin >> vehicleType;

    if (vehicleType == 1) {
        string brand, model;
        double mileage, fuel, distance;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Mileage: ";
        cin >> mileage;
        cout << "Enter Fuel (gallons): ";
        cin >> fuel;
        cout << "Enter Distance Covered (miles): ";
        cin >> distance;

        Car car(brand, model, mileage, fuel, distance);
        car.displayDetails();
        cout << "Fuel Efficiency: " << car.calculateFuelEfficiency() << " miles/gallon" << endl;
    }
    else if (vehicleType == 2) {
        string brand, model;
        double mileage, batteryCapacity, efficiency;
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Mileage: ";
        cin >> mileage;
        cout << "Enter Battery Capacity (kWh): ";
        cin >> batteryCapacity;
        cout << "Enter Efficiency (miles per kWh): ";
        cin >> efficiency;

        ElectricCar eCar(brand, model, mileage, batteryCapacity, efficiency);
        eCar.displayDetails();
        cout << "Range: " << eCar.calculateRange() << " miles" << endl;
    }
    else {
        cout << "Invalid vehicle type." << endl;
    }

    return 0;
}
