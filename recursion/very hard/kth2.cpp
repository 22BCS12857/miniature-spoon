#include <iostream>
#include <vector>
using namespace std;
char findKthCharacter(int k, const  vector<int>& operations) {
    // Start with the initial string "a" and k is 1-based index
    k--; // Convert to 0-based index for easier calculations

    // Calculate the length of the string after all operations
    long long length = 1; // initial length of "a"
    for (int op : operations) {
        if (op == 0) {
            length *= 2; // Doubles the string length
        } else if (op == 1) {
            length *= 2; // Doubles the string length
        }
    }

    // Traverse the operations in reverse order to find the k-th character
    for (int i = operations.size() - 1; i >= 0; i--) {
        if (operations[i] == 0) {
            // In operation 0, the string was doubled
            // If k is in the second half of the string, adjust k
            if (k >= length / 2) {
                k -= length / 2; // Move to the first half
            }
        } else if (operations[i] == 1) {
            // In operation 1, the string was transformed by shifting characters
            if (k >= length / 2) {
                k -= length / 2; // Move to the first half
            } else {
                // In the first half, we are looking at the original string, so do nothing
                // In the second half, we need to reverse the shift by subtracting 1 from the character
                // This transformation was a shift of every character
                // We don't need to modify the value of k itself, only the character.
            }
        }

        length /= 2; // The length of the string halved each time we move backwards
    }

    // After reversing the operations, the original string at the start was "a".
    // We need to determine the character after all transformations.
    return 'a' + k; // The 0-th position corresponds to 'a', 1-th corresponds to 'b', etc.
}

int main() {
    int k = 3;
     vector<int> operations = {0, 1, 1};
     cout << findKthCharacter(k, operations) <<  endl; // Output should be 'c'
    return 0;
}
