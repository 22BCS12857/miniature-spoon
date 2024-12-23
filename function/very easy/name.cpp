#include<string>
#include<iostream>
using namespace std;
void printFullName(string first, string last) {
    cout << "Hello " << first << " " << last << "! You just delved into C++." << endl;
}

int main() {
    string first, last;
    getline(cin, first);
    getline(cin, last);
    printFullName(first, last);
    return 0;
}