#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to construct the BST
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* helper(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        // Find the middle element
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        // Recursively build the left and right subtrees
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        
        return root;
    }
};

// Pre-order traversal function (root -> left -> right)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // Visit the root
    cout << root->val << " ";
    
    // Traverse the left subtree
    preorderTraversal(root->left);
    
    // Traverse the right subtree
    preorderTraversal(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);
    preorderTraversal(root);
    cout << endl;
    
    return 0;
}
