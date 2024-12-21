#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        // We use the helper function starting from row 0 and the two robots at column 0 and column cols-1
        return helper(grid, 0, 0, cols - 1);
    }

    int helper(vector<vector<int>>& grid, int currRow, int robotACol, int robotBCol) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Check bounds
        if (robotACol < 0 || robotBCol < 0 || robotACol >= cols || robotBCol >= cols) {
            return 0;
        }

        // Base case: if we've reached beyond the last row
        if (currRow == rows) {
            return 0;
        }

        // Add the cherries collected by both robots at the current position
        int result = grid[currRow][robotACol];
        if (robotACol != robotBCol) {
            result += grid[currRow][robotBCol];
        }

        int maxCherries = 0; // Variable to store the maximum cherries collected from the next row

        // Explore all possible moves for both robots in the next row
        for (int x = robotACol - 1; x <= robotACol + 1; ++x) {
            for (int y = robotBCol - 1; y <= robotBCol + 1; ++y) {
                maxCherries = max(maxCherries, helper(grid, currRow + 1, x, y));
            }
        }

        result += maxCherries; // Add the best possible result from the next row
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    int result = s.cherryPickup(grid);
    cout << "Maximum cherries collected: " << result << endl;
    return 0;
}
