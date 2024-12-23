#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;
 string makeLargestSpecial(const  string& s) {
    if (s.empty()) return "";
    
     vector< string> parts;
    int balance = 0, start = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        balance += (s[i] == '1') ? 1 : -1;
        
        if (balance == 0) {
             string part = s.substr(start + 1, i - start - 1);
            parts.push_back("1" + makeLargestSpecial(part) + "0");
            start = i + 1;
        }
    }
    
     sort(parts.rbegin(), parts.rend());  // Sort in reverse order
    return  string(parts.begin(), parts.end());
}

int main() {
     cout << makeLargestSpecial("11011000") <<  endl;  // Output: "11100100"
     cout << makeLargestSpecial("10") <<  endl;  // Output: "10"
    return 0;
}
