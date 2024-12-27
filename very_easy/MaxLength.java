
class Max_Solution {
    // Calculates the maximum depth of a binary tree.
    public int maxDepth(TreeNode root) {
        // If the root is null, the depth is 0.
        if (root == null) {
            return 0;
        }
        // Recursively compute the depth of the left subtree.
        int leftDepth = maxDepth(root.left);
        // Recursively compute the depth of the right subtree.
        int rightDepth = maxDepth(root.right);
        // The depth of the current node is the greater of its two children's depths plus one.
        return 1 + Math.max(leftDepth, rightDepth);
    }
}
public class MaxLength{
    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);

        // Creating an instance of Solution class
        Max_Solution s = new Max_Solution();
        
        // Counting the number of nodes in the binary tree
        int depth = s.maxDepth(root);
        
        // Printing the result
        System.out.println("Depth of the binary tree: " + depth);
    }

}