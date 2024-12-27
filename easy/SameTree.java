class TreeNode {
    int val;        // value of the node
    TreeNode left;  // left child
    TreeNode right; // right child

    // Constructor to create a new node with no children
    TreeNode() {}

    // Constructor to create a new node with a specified value
    TreeNode(int val) {
        this.val = val;
    }

    // Constructor to create a new node with a specified value and specified left and right children
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // If both trees are empty, they are the same.
        if (p == null && q == null) return true;

        // If one of the trees is empty or the values of current nodes don't match,
        // the trees aren't the same.
        if (p == null || q == null || p.val != q.val) return false;

        // Recursively check if the left subtree of both trees are the same 
        // AND the right subtree of both trees are the same.
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
public class SameTree {

    public static void main(String[] args) {
        // Create trees for testing
        TreeNode tree1 = new TreeNode(1);
        tree1.left = new TreeNode(2);
        tree1.right = new TreeNode(3);

        TreeNode tree2 = new TreeNode(1);
        tree2.left = new TreeNode(2);
        tree2.right = new TreeNode(3);

        TreeNode tree3 = new TreeNode(1);
        tree3.left = new TreeNode(2);

        // Create an instance of Solution
        Solution solution = new Solution();

        // Test isSameTree with different cases
        System.out.println(solution.isSameTree(tree1, tree2)); // Should return true
        System.out.println(solution.isSameTree(tree1, tree3)); // Should return false
    }
}

