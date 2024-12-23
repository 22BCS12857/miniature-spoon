#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return matchHelper(s, p, 0, 0);
    }

private:
    bool matchHelper(const string& s, const string& p, int i, int j) {
        // Base case: if we've reached the end of the pattern
        if (j == p.size()) {
            return i == s.size(); // True if we've also exhausted the string
        }

        // Check if the first characters match
        bool firstMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' wildcard
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Two cases:
            // 1. Skip '*' and its preceding character
            // 2. Consume one character from s if there's a match
            return matchHelper(s, p, i, j + 2) || 
                   (firstMatch && matchHelper(s, p, i + 1, j));
        }

        // Regular case: move to the next character
        return firstMatch && matchHelper(s, p, i + 1, j + 1);
    }
};

int main() {
    Solution sol;
    string s = "aab";
    string p = "c*a*b";
    cout << (sol.isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}
