// Assuming TreeNode class is defined as follows:


public class IBTree_Solution {
    // Inverts a binary tree and returns the root of the inverted tree.
    public static TreeNode invertTree(TreeNode root) {
        // Start the depth-first search inversion from the root node
        depthFirstSearchInvert(root);
        // Return the new root after inversion
        return root;
    }

    // A helper method that uses Depth-First Search to invert the given binary tree recursively.
    private static void depthFirstSearchInvert(TreeNode node) {
        // Base case: If the current node is null, there's nothing to invert; return immediately
        if (node == null) {
            return;
        }

        // Swap the left and right children of the current node
        TreeNode tempNode = node.left;
        node.left = node.right;
        node.right = tempNode;

        // Recursively invert the left subtree
        depthFirstSearchInvert(node.left);
        // Recursively invert the right subtree
        depthFirstSearchInvert(node.right);
    }

    // Method to print the tree in a pre-order fashion (root, left, right)
    public static void printTree(TreeNode root) {
        if (root == null) {
            return;
        }
        printTree(root.left);
        System.out.print(root.val + " ");
        printTree(root.right);
    }

    public static void main(String[] args) {
        // Construct the tree
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(2);
        root.left.right = new TreeNode(3);
        root.right = new TreeNode(4);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(8);
        root.left.left = new TreeNode(7);
        root.left.left.right = new TreeNode(12);

        // Print the original tree (pre-order traversal)
        System.out.println("Original Tree (in-order):");
        printTree(root);
        System.out.println();

        // Invert the tree
        TreeNode invertedRoot = invertTree(root);

        // Print the inverted tree (pre-order traversal)
        System.out.println("Inverted Tree (in-order):");
        printTree(invertedRoot);
    }
}
