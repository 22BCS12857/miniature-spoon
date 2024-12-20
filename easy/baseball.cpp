#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> scores;
    
    for (const string& op : operations) {
        if (op == "C") {
            // Invalidate the previous score
            if (!scores.empty()) {
                scores.pop();
            }
        } else if (op == "D") {
            // Double the previous score
            if (!scores.empty()) {
                int lastScore = scores.top();
                scores.push(2 * lastScore);
            }
        } else if (op == "+") {
            // Sum of the last two scores
            if (scores.size() >= 2) {
                int first = scores.top();
                scores.pop();
                int second = scores.top();
                scores.push(first); // Push back the first score
                scores.push(first + second); // Push the sum of the last two scores
            }
        } else {
            // It must be a number, so we convert it to an integer and push it
            scores.push(stoi(op));
        }
    }
    
    int total = 0;
    // Sum all the scores in the stack
    while (!scores.empty()) {
        total += scores.top();
        scores.pop();
    }
    
    return total;
}

int main() {
    vector<string> operations = {"5","-2","4","C","D","9","+","+"};
    
    int result = calPoints(operations);
    
    cout << "Total score: " << result << endl;
    
    return 0;
}
