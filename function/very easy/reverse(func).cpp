#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pointless(vector<int> arr) {
    reverse(arr.begin(), arr.end()); // Reverse in place
    return arr; // Return the modified vector
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> reversedArr = pointless(arr);
    for (int num : reversedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
