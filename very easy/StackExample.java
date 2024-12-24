import java.util.*;

class MinStack {
    private Stack<Integer> mainStack;
    private Stack<Integer> minStack;

    public MinStack() {
        mainStack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int val) {
        mainStack.push(val);
        System.out.println("Pushed: "+minStack.push(val));
    }

    public void pop() {
        if (!mainStack.isEmpty() && mainStack.peek().equals(minStack.peek())) {
            System.out.println("Popped: "+minStack.pop());
        }
        System.out.println("Popped: "+minStack.pop());
    }

    public int top() {
        return mainStack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}

public class StackExample {
    public static void main(String args[]) {
        MinStack stack = new MinStack();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println("Minimum: " + stack.getMin());
        stack.pop();
        System.out.println("Top: " + stack.top());
        System.out.println("Minimum: " + stack.getMin());
    }
}
