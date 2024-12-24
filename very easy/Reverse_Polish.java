import java.util.ArrayDeque;
import java.util.Deque;

class polisher {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (String token : tokens) {
            if ("+-*/".contains(token)) { // Check if token is an operator
                int num2 = stack.pop(); // Retrieve the top two numbers
                int num1 = stack.pop();
                stack.push(applyOperation(token, num1, num2));
            } else {
                stack.push(Integer.parseInt(token)); // Parse and push numbers
            }
        }
        
        return stack.pop(); // Final result
    }
    
    private int applyOperation(String operator, int num1, int num2) {
        switch (operator) {
            case "+":
                return num1 + num2;
            case "-":
                return num1 - num2;
            case "*":
                return num1 * num2;
            case "/":
                return num1 / num2; // Integer division
            default:
                throw new IllegalArgumentException("Invalid operator: " + operator);
        }
    }
}

public class Reverse_Polish {
    public static void main(String[] args) {
        polisher p = new polisher();
        
        // Example 1: ["2", "1", "+", "3", "*"]
        String[] tokens1 = {"2", "1", "+", "3", "*"};
        System.out.println(p.evalRPN(tokens1)); // Output: 9
        
        // Example 2: ["4", "13", "5", "/", "+"]
        String[] tokens2 = {"4", "13", "5", "/", "+"};
        System.out.println(p.evalRPN(tokens2)); // Output: 6
        
        // Example 3: ["10", "6", "9", "3", "/", "-", "*"]
        String[] tokens3 = {"10", "6", "9", "3", "/", "-", "*"};
        System.out.println(p.evalRPN(tokens3)); // Output: 30
    }
}