
class PathSum_Solution {

    public static boolean hasPathSum(L_Node root, int targetSum) {
    
            return hasPathSumDFS(root, targetSum);

    }

    private static boolean hasPathSumDFS(L_Node root, int currentSum) {
    
            // If the node is null, we've hit a dead end and should return false.
    
            if (root == null) {
    
                return false;
    
            }
    
            // Subtract the value of current node from current sum.
    
            currentSum -= root.data;
    
            // Check if the current node is a leaf and the current sum equals zero,
    
            // which means we've found a path with the required sum.
    
            if (root.left == null && root.right == null && currentSum == 0) {
    
                return true;
    
            }
            // Recursively check the left and right subtrees for the remaining sum.
            // If either subtree returns true, a path has been found.
            return hasPathSumDFS(root.left, currentSum) || hasPathSumDFS(root.right, currentSum);

    }
    public static void main(String[] args) {
      
        // Representation of input binary tree
        //        1
        //       / \
        //      2   3
        //     / \
        //    4   5
        L_Node  root = new L_Node(5);
        root.left = new L_Node(2);
        root.left.right = new L_Node(3);
        root.right = new L_Node(4);
        root.right.left = new L_Node(10);
        root.right.right = new L_Node(8);
        root.left.left = new L_Node(7);
        root.left.left.right = new L_Node(12);
        System.out.println(hasPathSum(root,10));
    }
}