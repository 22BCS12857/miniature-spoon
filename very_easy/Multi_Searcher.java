package very_easy;
import java.util.*;

public class Multi_Searcher {
    public static List<Integer> returner(int arr[], int k) {
        // Perform binary search for the element k
        int index = Arrays.binarySearch(arr, k);
        
        // If the element is not found
        if (index < 0) {
            return new ArrayList<Integer>(Arrays.asList(-1));// Return [-1]
        }

        List<Integer> result = new ArrayList<>();
        
        // Find all occurrences of k, starting from the found index
        // Check to the left of the found index
        int left = index;
        while (left >= 0 && arr[left] == k) {
            result.add(left);
            left--;
        }
        
        // Check to the right of the found index (in case there are more occurrences)
        int right = index + 1;
        while (right < arr.length && arr[right] == k) {
            result.add(right);
            right++;
        }

        // Return the list of indices
        Collections.sort(result); // Ensure the indices are sorted in ascending order
        return result;
    }

    public static void main(String[] args) {
        int[] arr = {9, 7, 16, 16, 4};
        Arrays.sort(arr);  // Sort the array before binary search
        System.out.println(Arrays.toString(arr));
        // Perform binary search for the specified values
        System.out.println("Searching for 16 in arr: " + returner(arr, 16));  // Should return [3, 4]
        System.out.println("Searching for 9 in arr: " + returner(arr, 9));    // Should return [2]
        System.out.println("Searching for 50 in arr: " + returner(arr, 50));  // Should return []
    }
}
