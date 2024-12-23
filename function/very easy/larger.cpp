#include<iostream>
using namespace std;
int comp(int a ,int b){
    if(a>b){
        cout<<a<<"Larger than "<<b; 
    }
    if(a<b){
        cout<<b<<"Larger than "<<a; 
    }
    return 0;
}
int main(){
    int a=10;
    int b=12;
    comp(a,b);
    return 0;
}