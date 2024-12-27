
class L_Node {
    int data;
    L_Node left, right;

    L_Node(int val) {
        data = val;
        left = right = null;
    }
}

public class LNodeCount {

    // Function to count the leaf nodes in a binary tree
    static int countLeaves(L_Node root) {
      
        // If root is NULL, return 0
        if (root == null) {
            return 0;
        }

        // If the L_Node has no left or right child, 
        // it is a leaf
        if (root.left == null && root.right == null) {
            return 1;
        }

        // Recursively count the leaves in the 
        // left and right subtrees
        return countLeaves(root.left) 
                         + countLeaves(root.right);
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
        System.out.println(countLeaves(root));
    }
}