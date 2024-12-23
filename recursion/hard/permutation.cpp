#include <iostream>
#include <vector>
#include <string>
using namespace std;
 string getPermutationHelper(int n, int k,  vector<int>& nums) {
    if (n == 0) return "";

    int factorial = 1;
    for (int i = 1; i < n; ++i) factorial *= i;
    
    int index = k / factorial;
    char ch = '0' + nums[index];
    nums.erase(nums.begin() + index);
    
    return ch + getPermutationHelper(n - 1, k % factorial, nums);
}

 string getPermutation(int n, int k) {
     vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);
    return getPermutationHelper(n, k - 1, nums); // k - 1 for zero-indexed k
}

int main() {
     cout << getPermutation(3, 3) <<  endl; // "213"
     cout << getPermutation(4, 9) <<  endl; // "2314"
     cout << getPermutation(3, 1) <<  endl; // "123"
    return 0;
}
