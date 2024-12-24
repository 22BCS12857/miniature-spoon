import java.util.Stack;
class my_queue {

    Stack<Integer> input = new Stack();
    Stack<Integer> output = new Stack();
    
    public void push(int x) {
        input.push(x);
    }

    public void pop() {
        peek();
        output.pop();
    }

    public int peek() {
        if (output.empty())
            while (!input.empty())
                output.push(input.pop());
        return output.peek();
    }

    public boolean empty() {
        return input.empty() && output.empty();
    }
}

public class MyQueue{
    public static void main(String[] a){
        my_queue q=new my_queue();
        q.push(1);
        q.push(2);
        System.out.println(q.peek());
        q.pop();
        System.out.println(q.empty());
    }
}