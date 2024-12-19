#include<iostream>
#include<cmath>
using namespace std;
class funky{
public:
int area(int length,int breadth){
    return length*breadth;
}
int area(int radius){
    return 3.14*radius*radius;
}
int area(int l,int b,bool istri){
    return l*b/2;
}
};
int main(){
    funky f;
    cout<<f.area(1,10)<<endl;
    cout<<f.area(7)<<endl;
    cout<<f.area(10,10,true)<<endl;
    return 0;
}