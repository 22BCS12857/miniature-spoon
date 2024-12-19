#include <iostream>
#include <cmath> // For sqrt function
using namespace std;

bool primeornot(int num) {
    if (num <= 1) return false; // Numbers <= 1 are not prime
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false; // Composite
        }
    }
    return true; // Prime
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    bool result = primeornot(n);
    if (result) {
        cout << "Prime";
    } else {
        cout << "Composite";
    }
    return 0;
}
