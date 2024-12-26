package easy;

import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

public class EvenOddSort {
    public static int[] sort_helper(int arr[]) {
        // Initialize the lists to store even and odd elements
        ArrayList<Integer> oddList = new ArrayList<>();
        ArrayList<Integer> evenList = new ArrayList<>();

        // Separate even and odd numbers
        for (int num : arr) {
            if (num % 2 == 0) {
                evenList.add(num);
            } else {
                oddList.add(num);
            }
        }

        // Sort even and odd arrays in ascending order
        Collections.sort(evenList); // Ascending order for even numbers
        Collections.sort(oddList);  // Ascending order for odd numbers

        // Convert the lists back to arrays
        int[] evenArr = evenList.stream().mapToInt(Integer::intValue).toArray();
        int[] oddArr = oddList.stream().mapToInt(Integer::intValue).toArray();

        // Merge the sorted arrays (even numbers first, then odd numbers)
        int len = evenArr.length + oddArr.length;
        int[] res = new int[len];
        System.arraycopy(evenArr, 0, res, 0, evenArr.length);
        System.arraycopy(oddArr, 0, res, evenArr.length, oddArr.length);

        return res;
    }

    public static void main(String[] args) {
        //Case 1
        int arr[] = {4, 1, 2, 3};
        int[] res = sort_helper(arr);
        System.out.println(Arrays.toString(res)); // Expected: [2, 4, 1, 3]
        //Case 2
        int arr_0[] = {2,1};
        int[] res_0 = sort_helper(arr_0);
        System.out.println(Arrays.toString(res_0));// Expected: [2, 1]
    }
}
