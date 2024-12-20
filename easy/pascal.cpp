#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalTriangle;

    // Base case: if numRows is 0, return an empty triangle
    if (numRows == 0) return pascalTriangle;

    // First row is always [1]
    pascalTriangle.push_back({1});

    for (int i = 1; i < numRows; i++) {
        vector<int> row(i + 1, 1); // Start each row with '1's
        for (int j = 1; j < i; j++) {
            row[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]; // Sum the two numbers above
        }
        pascalTriangle.push_back(row); // Add the new row to the triangle
    }

    return pascalTriangle;
}

void printPascalTriangle(const vector<vector<int>>& pascalTriangle) {
    for (const auto& row : pascalTriangle) {
        cout<<"[";
        for (int num : row) {
            cout << num << " ,";
        }
        cout<<"]";
    }
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    vector<vector<int>> pascalTriangle = generate(numRows);
    cout<<"[";
    printPascalTriangle(pascalTriangle);
    cout<<"]";
    return 0;
}
