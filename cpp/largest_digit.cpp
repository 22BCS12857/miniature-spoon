#include<iostream>
using namespace std;
int Digits(int n){ 
    int largest = 0;
    int smallest = 9;
    int i=0;
    while(i<n){ 
        int r = n % 10;
        //Find the largest digit 
        largest = max(r, largest);  
        n = n/10;
    }
    return largest;
    }
int main(){
int n = 2346;
cout<<"Largest Digit of "<<n<<" is "<<Digits(n);
} 