#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int calculateHelper(const  string& s, int& index) {
    int result = 0, sign = 1;
    
    while (index < s.length()) {
        char c = s[index];
        if (isdigit(c)) {
            int num = 0;
            while (index < s.length() && isdigit(s[index])) {
                num = num * 10 + (s[index] - '0');
                index++;
            }
            result += sign * num;
        } 
        else if (c == '+') {
            sign = 1;
            index++;
        } 
        else if (c == '-') {
            sign = -1;
            index++;
        } 
        else if (c == '(') {
            index++;
            result += sign * calculateHelper(s, index);
        } 
        else if (c == ')') {
            index++;
            return result;
        } 
        else if (c == ' ') {
            index++;
        }
    }
    
    return result;
}

int calculate(const  string& s) {
    int index = 0;
    return calculateHelper(s, index);
}

int main() {
     cout << calculate("1 + 1") <<  endl; // 2
     cout << calculate(" 2-1 + 2 ") <<  endl; // 3
     cout << calculate("(1+(4+5+2)-3)+(6+8)") <<  endl; // 23
    return 0;
}
