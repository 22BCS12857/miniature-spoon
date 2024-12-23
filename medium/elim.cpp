#include <iostream>
using namespace std;

int lastRemaining(int n, bool left = true) {
    // Base case: If only one number is left, return it
    if (n == 1) return 1;

    // If removing from left or the size of the array is odd, the first number is removed
    return left || n % 2 == 1 ? 2 * lastRemaining(n / 2, !left) :2 * lastRemaining(n / 2, !left) - 1;
}

int main(){
    int t;
    cout<<"Enter a Number: ";
    cin>>t;
    cout<<lastRemaining(t);
    return 0;
}
