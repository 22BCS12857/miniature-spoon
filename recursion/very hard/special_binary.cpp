#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        // Base case: If the string is empty, return as is.
        if (s.empty()) return s;

        // Define a vector to hold special substrings.
        vector<string> specials;
      
        int counter = 0; // Initialized to count the balance of 1s and 0s.
        int startIdx = 0; // Index to keep track of the start of a special substring.

        // Iterate over the string to find and process special substrings.
        for (int currentIdx = 0; currentIdx < s.size(); ++currentIdx) {
            // Increment counter if '1', decrement if '0'.
            counter += s[currentIdx] == '1' ? 1 : -1;
          
            // When counter is 0, we found a special string.
            if (counter == 0) {
                // Make a special string by recursively calling makeLargestSpecial on the inner part.
                // We concatenate '1' at the beginning and '0' at the end.
                specials.push_back("1" + makeLargestSpecial(s.substr(startIdx + 1, currentIdx - startIdx - 1)) + "0");
              
                // Set the start index for the next special substring.
                startIdx = currentIdx + 1;
            }
        }

        // Sort the special substrings in descending order to make the string largest.
        sort(specials.begin(), specials.end(), greater<string>());

        // Concatenate all special strings together using accumulate.
        return accumulate(specials.begin(), specials.end(), string{});
    }
};
int main() {
    Solution s;
     cout << s.makeLargestSpecial("11011000") <<  endl;  // Output: "11100100"
     cout << s.makeLargestSpecial("10") <<  endl;  // Output: "10"
    return 0;
}
