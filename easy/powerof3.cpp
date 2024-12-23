#include<iostream>
using namespace std;
bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    return n % 3 == 0 && isPowerOfThree(n / 3);
}
int main(){
    int t;
    cout<<"Enter a Number: ";
    cin>>t;
    cout<<isPowerOfThree(t);
    return 0;
}
