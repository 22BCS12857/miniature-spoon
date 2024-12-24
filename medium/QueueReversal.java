package medium;

import java.util.Queue;
import java.util.LinkedList;

public class QueueReversal {
    
    // Recursive function to reverse the queue
    public static void reverseQueue(Queue<Integer> queue) {
        // Base case: if the queue is empty, nothing to do
        if (queue.isEmpty()) {
            return;
        }
        
        // Recursive case: dequeue an element from the front
        int front = queue.poll();
        
        // Recursively reverse the rest of the queue
        reverseQueue(queue);
        
        // After recursion, enqueue the element back to the queue
        queue.offer(front);
    }

    public static void main(String[] args) {
        // Create a queue and add some elements
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);
        queue.offer(4);
        queue.offer(5);
        
        // Print the queue before reversal
        System.out.println("Queue before reversal: " + queue);
        
        // Call the recursive function to reverse the queue
        reverseQueue(queue);
        
        // Print the queue after reversal
        System.out.println("Queue after reversal: " + queue);
    }
}
