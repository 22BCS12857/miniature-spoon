#include <iostream>
using namespace std;

void printTable(int n) { 
  for (int i = 1; i <= 10; ++i) 
        cout << n << " * " << i << " = "  
             << n * i << endl;
}

int main() {
    int n;
    cout<<"Enter Number: "
    cin>>n;
    printTable(n);
    return 0;
}