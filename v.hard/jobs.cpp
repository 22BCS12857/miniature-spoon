#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumJobTime; // Renamed from 'ans' to 'minimumJobTime' for clarity

    // Method to find the minimum time required to complete all jobs given 'k' workers
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workerTimes(k); // Holds the current total time for each worker
        minimumJobTime = INT_MAX; // Initialize with the maximum possible value
        // Sort jobs in descending order to try the largest jobs first for optimization
        sort(jobs.begin(), jobs.end(), greater<int>());
        // Start the Depth-First Search (DFS) to assign jobs
        dfs(0, k, jobs, workerTimes);
        return minimumJobTime;
    }

    // Helper method to perform DFS
    void dfs(int currentIndex, int k, vector<int>& jobs, vector<int>& workerTimes) {
        if (currentIndex == jobs.size()) { // Base case: all jobs have been assigned
            // Update the minimum job time if necessary
            minimumJobTime = min(minimumJobTime, *max_element(workerTimes.begin(), workerTimes.end()));
            return;
        }
        // Iterate through each worker to assign the job
        for (int j = 0; j < k; ++j) {
            // Skip if adding this job exceeds the current minimum time
            if (workerTimes[j] + jobs[currentIndex] >= minimumJobTime) continue;
            // Assign the job to the worker
            workerTimes[j] += jobs[currentIndex];
            // Recur for the next job
            dfs(currentIndex + 1, k, jobs, workerTimes);
            // Backtrack: remove the job from the worker for the next iteration
            workerTimes[j] -= jobs[currentIndex];
            // Optimization: If the worker time is zero, no need to try assigning this job to other workers
            if (workerTimes[j] == 0) break;
        }
    }
};

int main() {
    Solution s;
    vector<int> inp = {1,2,4,7,8}; // Example job times
    int k = 2; // Number of workers
    int result = s.minimumTimeRequired(inp, k);
    cout << "Answer: " << result << endl;
    return 0;
}
