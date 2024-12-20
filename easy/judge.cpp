#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    
    int k = 1; // Initialize the index for the unique elements
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) { // Found a unique element
            nums[k] = nums[i]; // Move it to the correct position
            ++k; // Increment the count of unique elements
        }
    }
    
    return k;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    
    int k = removeDuplicates(nums);
    
    // Print the first k unique elements
    cout << "Number of unique elements: " << k << endl;
    cout << "Unique elements: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
