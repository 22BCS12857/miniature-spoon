#include<iostream>
using namespace std;
int nSum(int n){
    if (n <= 1){
        return 1;
    }
    return n+nSum(n - 1);
}
int main(){
    int a;
    cout<<"Enter a number: ";
    cin>>a;
    cout<<nSum(a);
    return 0;
}