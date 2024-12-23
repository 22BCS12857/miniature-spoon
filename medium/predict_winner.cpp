#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    // Memoization table to store results of subproblems
    vector<vector<int>> memo;

    // Recursive helper function
    int helper(vector<int>& nums, int left, int right) {
        // Base case: if there's only one number left
        if (left == right) {
            return nums[left];
        }

        // If already computed, return the memoized value
        if (memo[left][right] != INT_MIN) {
            return memo[left][right];
        }

        // Player 1's turn: maximize the score difference
        int pickLeft = nums[left] - helper(nums, left + 1, right);
        int pickRight = nums[right] - helper(nums, left, right - 1);

        // Store the result and return the maximum
        memo[left][right] = max(pickLeft, pickRight);
        return memo[left][right];
    }

public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // Initialize memoization table with INT_MIN (uncomputed state)
        memo.assign(n, vector<int>(n, INT_MIN));

        // If the score difference is >= 0, Player 1 can win
        return helper(nums, 0, n - 1) >= 0;
    }
};

int main() {
    Solution solution;
    vector<int> case1={1,5,2};
    vector<int> case2 = {1,5,233,7};
    cout<<"Case 1: "<< (solution.PredictTheWinner(case1) ? "true" : "false") << endl;
    cout<<"Case 2: " << (solution.PredictTheWinner(case2) ? "true" : "false") << endl;
    return 0;
}
