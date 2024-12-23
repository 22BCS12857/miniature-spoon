#include <iostream>
#include <string>
using namespace std;
bool isMatch(const string& s, const string& p, int i, int j) {
    // Base case: if both strings are fully matched
    if (i == s.length() && j == p.length()) return true;
    
    // If pattern is exhausted but string is not
    if (j == p.length()) return false;

    // If pattern character is '?', it matches any single character
    if (p[j] == '?' || p[j] == s[i]) {
        return isMatch(s, p, i + 1, j + 1);
    }

    // If pattern character is '*', it matches any sequence of characters (including empty sequence)
    if (p[j] == '*') {
        // Try two options: match no characters (i) or match one or more characters (i+1)
        return isMatch(s, p, i, j + 1) || (i < s.length() && isMatch(s, p, i + 1, j));
    }

    return false;
}

bool isMatch(const  string& s, const  string& p) {
    return isMatch(s, p, 0, 0);
}

int main() {
     cout <<  boolalpha;
     cout << isMatch("aa", "a") <<  endl; // false
     cout << isMatch("aa", "*") <<  endl; // true
     cout << isMatch("cb", "?a") <<  endl; // false
    return 0;
}
