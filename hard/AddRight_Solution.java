package hard;

import java.util.ArrayDeque;
import java.util.Deque;

class Node {

    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }

    // Helper function to print the tree level by level
    public void printLevelOrder() {
        Node current = this;
        while (current != null) {
            System.out.print(current.val + " -> ");
            if (current.next == null) {
                System.out.print("NULL");
                break;
            }
            current = current.next;
        }
        System.out.println();
    }
}

class AR_Solution {

    // Method connects each node to its next right node in the same level.
    // If there is no next right node, the next pointer should be set to NULL.
    public Node connect(Node root) {

        // Handle the base case when the tree is empty.
        if (root == null) {
            return root;
        }

        // Queue to hold the nodes to be processed.
        Deque<Node> queue = new ArrayDeque<>();

        // Start with the root node.
        queue.offer(root);

        // Traverse the binary tree level by level.
        while (!queue.isEmpty()) {

            // Previous node on the current level.
            Node previousNode = null;

            // Process all nodes in the current level.
            for (int i = queue.size(); i > 0; --i) {

                // Get the next node from the queue.
                Node currentNode = queue.poll();

                // Link the previous node (if any) to the current one.
                if (previousNode != null) {
                    previousNode.next = currentNode;
                }

                // Current node becomes the previous node for the next iteration.
                previousNode = currentNode;

                // Add the children of current node to the queue for next level processing.
                if (currentNode.left != null) {
                    queue.offer(currentNode.left);
                }

                if (currentNode.right != null) {
                    queue.offer(currentNode.right);
                }
            }
        }

        // Return the root of the modified tree.
        return root;
    }
}

public class AddRight_Solution{

    public static void main(String[] args) {

        // Create the tree nodes
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        // Connect the nodes at the same level
        AR_Solution solution = new AR_Solution();
        solution.connect(root);

        // Print the tree levels and the next pointers
        System.out.println("Level 1: ");
        root.printLevelOrder();
        System.out.println("Level 2: ");
        root.left.printLevelOrder();
        System.out.println("Level 3: ");
        root.left.left.printLevelOrder();
    }
}
