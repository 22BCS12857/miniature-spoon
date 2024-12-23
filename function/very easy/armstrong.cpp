#include<iostream>
using namespace std;
int armstrong(int num){
    int originalNum, remainder, result = 0;
    originalNum = num;

    while (originalNum != 0) {
        // remainder contains the last digit
        remainder = originalNum % 10;
        
        result += remainder * remainder * remainder;
        
        // removing last digit from the original number
        originalNum /= 10;
    }

    if (result == num)
        cout << num << " is an Armstrong number.";
    else
        cout << num << " is not an Armstrong number.";

    return 0;
}
int main() {
    int num;
    cout << "Enter a three-digit integer: ";
    cin >> num;
    armstrong(num);
    return 0;
}