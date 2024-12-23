#include<iostream>
using namespace std;
int factorial(int n){
    if (n <= 1){
        return 1;
    }
    return n*factorial(n - 1);
}
int main(){
    int t;
    cout<<"Enter a Number: ";
    cin>>t;
    cout<<factorial(t);
    return 0;
}