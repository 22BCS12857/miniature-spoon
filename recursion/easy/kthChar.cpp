#include <string>
#include <iostream>
using namespace std;

char findKthCharacter(int k, string word = "a") {
    if (word.length() >= k) return word[k - 1];

    string next_word = "";
    for (char c : word) {
        next_word += (c == 'z' ? 'a' : c + 1);
    }

    return findKthCharacter(k, word + next_word);
}

int main() {

    int k = 10;
    cout << "The " << k << "-th character is: " << findKthCharacter(k) << endl;

    return 0;
}
