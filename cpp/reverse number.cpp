#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    string str=to_string(n);
    reverse(str.begin(),str.end());
    cout<<"Number of digits: "<<str;
    
}