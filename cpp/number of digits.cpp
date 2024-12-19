#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    string str=to_string(n);
    cout<<"Number of digits: "<<str.size();
    
}