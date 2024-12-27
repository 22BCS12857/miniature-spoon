public class InorderT {
    static class Node {
        int k;
        Node l, r;
    }

    static Node newNode(int key) {
        Node node = new Node();
        node.k = key;
        node.l = node.r = null;
        return (node);
    }
    static void inorder(Node root) {
        if (root == null) {
            return;  // Base case: If the node is null, do nothing
        }
        inorder(root.l);  // Traverse the left subtree
        System.out.print(root.k + " ");  // Print the current node's value
        inorder(root.r);  // Traverse the right subtree
    }
    public static void main(String[] args) {
        Node root = newNode(5);
        root.l = newNode(2);
        root.l.r = newNode(3);
        root.r = newNode(4);
        root.r.l = newNode(10);
        root.r.r = newNode(8);
        root.l.l = newNode(7);
        root.l.l.r = newNode(12);
        inorder(root);
    }

}