#include<string>
#include<stack>
#include<iostream>
using namespace std;
class Solution {
public:
    // Function to evaluate the boolean expression.
    bool parseBoolExpr(string expression) {
        stack<char> charStack; // Create a stack to manage the characters.

        // Iterating over each character in the input expression.
        for (char c : expression) {
            // If the character is not an operator or a comma, push it onto the stack.
            if (c != '(' && c != ')' && c != ',') {
                charStack.push(c);
            } else if (c == ')') { // When a closing bracket is encountered, evaluate the expression inside it.
                int trueCount = 0, falseCount = 0; // Variables to count the number of true and false values.

                // Process all operands up to the previous operator.
                while (charStack.top() == 't' || charStack.top() == 'f') {
                    // Increment trueCount or falseCount based on the operand.
                    trueCount += charStack.top() == 't';
                    falseCount += charStack.top() == 'f';
                    charStack.pop(); // Remove the processed operand from the stack.
                }

                // Now, pop the operator from the stack.
                char operatorChar = charStack.top();
                charStack.pop();

                // Evaluate the expression based on the operator.
                if (operatorChar == '!') {
                    c = falseCount > 0 ? 't' : 'f'; // Logical NOT: 'true' if any is 'false', else 'false'.
                }
                if (operatorChar == '&') {
                    c = falseCount > 0 ? 'f' : 't'; // Logical AND: 'false' if any is 'false', else 'true'.
                }
                if (operatorChar == '|') {
                    c = trueCount > 0 ? 't' : 'f'; // Logical OR: 'true' if any is 'true', else 'false'.
                }

                // Push the result onto the stack.
                charStack.push(c);
            }
        }

        // The top of the stack now contains the result, return 'true' if 't', 'false' otherwise.
        return charStack.top() == 't';
    }
};
int main() {
    Solution s;
    cout <<  s.parseBoolExpr("&(|(f))") << endl;  // Expected: 14
    return 0;
}