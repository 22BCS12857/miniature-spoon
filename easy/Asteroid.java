package easy;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class Asteroid {
    public static int[] asteroidCollision(int[] asteroids) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int x : asteroids) {
            if (x > 0) {
                stk.offerLast(x);
            } else {
                while (!stk.isEmpty() && stk.peekLast() > 0 && stk.peekLast() < -x) {
                    stk.pollLast();
                }
                if (!stk.isEmpty() && stk.peekLast() == -x) {
                    stk.pollLast();
                } else if (stk.isEmpty() || stk.peekLast() < 0) {
                    stk.offerLast(x);
                }
            }
        }
        return stk.stream().mapToInt(Integer::valueOf).toArray();
    }

    public static void main(String[] args) {
        int[] arr = {10,-10};
        int[] res = asteroidCollision(arr);
        System.out.println(Arrays.toString(res));  // Correctly prints the array
    }
}
