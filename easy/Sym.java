

class Sym_Solution {

    /**
     * Determines if a binary tree is symmetric around its center (mirrored).
     * 
     * @param root The root of the tree.
     * @return true if the tree is symmetric, false otherwise.
     */
    public boolean isSymmetric(TreeNode root) {
        // Start DFS from the root for both subtrees for comparison.
        return isMirror(root, root);
    }

    /**
     * Helper method to perform a DFS to check for symmetry by comparing nodes.
     *
     * @param node1 The current node from the first subtree.
     * @param node2 The current node from the second subtree.
     * @return true if the two subtrees are mirrors of each other, false otherwise.
     */
    private boolean isMirror(TreeNode node1, TreeNode node2) {
        // Both nodes are null, meaning this branch is symmetric.
        if (node1 == null && node2 == null) {
            return true;
        }

        // If only one of the nodes is null, or their values differ,
        // the tree cannot be symmetric.
        if (node1 == null || node2 == null || node1.val != node2.val) {
            return false;
        }

        // Continue to compare the left subtree of node1 with the right subtree of node2
        // and the right subtree of node1 with the left subtree of node2. Both comparisons
        // must be true for the subtree to be symmetric.
        return isMirror(node1.left, node2.right) && isMirror(node1.right, node2.left);
    }
}

public class Sym {
    public static void main(String[] args) {
        // Create the tree manually using TreeNode
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(2);
        root.left.right = new TreeNode(3);
        root.right = new TreeNode(4);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(8);
        root.left.left = new TreeNode(7);
        root.left.left.right = new TreeNode(12);

        // Create an instance of the solution class
        Sym_Solution solution = new Sym_Solution();
        
        // Check if the tree is symmetric
        boolean result = solution.isSymmetric(root);
        
        // Output the result
        System.out.println(result); // Expected output: false (since the tree is not symmetric)
    }
}
