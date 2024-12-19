#include<iostream>
using namespace std;
int odd_sum(int n){
    int sum = 0;
    int curr = 1;
    int i = 0;
    while(i < n){
        sum = sum + curr;
        curr = curr + 2;
        i = i + 1;
        }
    return sum;
}
int main(){
    int num;
    cout<<"Enter number";
    cin>>num;
    int result=odd_sum(num);
    cout<<result;
}