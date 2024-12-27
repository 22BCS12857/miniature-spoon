public class SumofNodes {
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

    static int addBT(Node root) {
        if (root == null)
            return 0;
        return (root.k + addBT(root.l) +
                addBT(root.r));
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
        int sum = addBT(root);
        System.out.println("Sum: " + sum);
    }

}