#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>
#include<iostream>
using namespace std;
class Solution {
public:
    int index = 0;
     string expression;
     unordered_map< string,  vector<int>> scopes;

    int evaluate( string expression) {
        this->expression = expression;
        return evaluateExpression();
    }

    int evaluateExpression() {
        // If current character is not an opening parenthesis, it must be a variable or an integer
        if (expression[index] != '(') {
            return  islower(expression[index]) ? scopes[parseVariable()].back() : parseInteger();
        }
      
        int ans = 0;
        ++index; // Skip the '('

        if (expression[index] == 'l') { // If it starts with 'let'
            index += 4; // Skip the "let"
             vector< string> variables;
            while (true) {
                 string variable = parseVariable();
                if (expression[index] == ')') { // End of let expression
                    ans = scopes[variable].back();
                    break;
                }
                ++index; // Skip the space or '(' before the expression
                variables.push_back(variable);
                scopes[variable].push_back(evaluateExpression());
                ++index; // Skip the space after expression
              
                // If next token is not a variable, it must be an expression 
                if (! islower(expression[index])) {
                    ans = evaluateExpression();
                    break;
                }
            }
            // Pop the variables' values from the scope after finishing the "let" expression
            for ( string var : variables) {
                scopes[var].pop_back();
            }
        } else { // If it's an "add" or "mult" expression
            bool isAdd = expression[index] == 'a'; // Check if the operator is add
            index += isAdd ? 4 : 5; // Skip the "add" or "mult"
            int firstOperand = evaluateExpression();
            ++index; // Skip the space between operands
            int secondOperand = evaluateExpression();
            ans = isAdd ? firstOperand + secondOperand : firstOperand * secondOperand; // Calculate result
        }
        ++index; // Skip the closing parenthesis ')'
        return ans;
    }

    // Parses a variable name from the current index
     string parseVariable() {
        int start = index;
        while (index < expression.size() && expression[index] != ' ' && expression[index] != ')') ++index;
        return expression.substr(start, index - start);
    }

    // Parses an integer (could be negative) from the current index
    int parseInteger() {
        int sign = 1, value = 0;
        if (expression[index] == '-') {
            sign = -1;
            ++index; // Skip the negative sign
        }
        while (index < expression.size() &&  isdigit(expression[index])) {
            value = value * 10 + (expression[index] - '0');
            ++index;
        }
        return sign * value;
    }
};
int main() {
    unordered_map<string, int> vars;
    Solution s;
    cout <<  s.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") << endl;  // Expected: 14
    return 0;
}