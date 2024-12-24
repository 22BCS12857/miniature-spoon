package veryhard;
import java.util.*;

class Result {
    public static int poisonousPlants(List<Integer> p) {
        // A stack to hold pairs of (plant toxicity, days it took to die)
        Stack<int[]> stack = new Stack<>();
        int maxDays = 0;

        for (int plant : p) {
            int day = 0;
            // Check if the current plant can be poisoned by the plant on the left
            while (!stack.isEmpty() && stack.peek()[0] >= plant) {
                // Pop the stack and get the number of days it took for the plant to die
                day = Math.max(day, stack.pop()[1]);
            }

            // If the plant can be poisoned by another plant, increment the day count
            if (!stack.isEmpty()) {
                day++;
            }

            // Update the maximum days
            maxDays = Math.max(maxDays, day);

            // Push the current plant with the days it took to die
            stack.push(new int[] { plant, day });
        }

        return maxDays;
    }
}

public class Poison {
    public static void main(String[] args) {
        // Example usage:
        List<Integer> plants = Arrays.asList(6, 5, 8, 4, 7, 10, 9);
        System.out.println(Result.poisonousPlants(plants));  // Output will be the max days
    }
}
