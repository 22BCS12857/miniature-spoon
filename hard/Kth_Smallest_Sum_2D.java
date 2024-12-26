package hard;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Kth_Smallest_Sum_2D {
    // Method to find the kth smallest sum in a 2D matrix.
    public int kthSmallest(int[][] matrix, int k) {
        int cols = matrix[0].length;
        
        // Initialize a list to store the previous row's computations.
        List<Integer> previousRowSums = new ArrayList<>(k);
        
        // Initialize a list to store the current row's computations.
        List<Integer> currentRowSums = new ArrayList<>(cols * k);
        
        // Start with 0 as the only element for an empty prefix sum.
        previousRowSums.add(0);
        
        // Iterate through each row of the matrix.
        for (int[] row : matrix) {
            // Clear the current sums list for new calculations.
            currentRowSums.clear();
            
            // Combine each element from the previous list with each element of the current row.
            for (int prevSum : previousRowSums) {
                for (int value : row) {
                    // Add the sum to the current list.
                    currentRowSums.add(prevSum + value);
                }
            }
            
            // Sort the current list to prepare for selecting the smallest k elements.
            Collections.sort(currentRowSums);
            
            // Clear the previous sums list to reuse it for the next iteration.
            previousRowSums.clear();
            
            // Take the first k elements from the current list, or the entire list if it's smaller than k.
            for (int i = 0; i < Math.min(k, currentRowSums.size()); ++i) {
                // Add each of the smallest elements to the previous sums list.
                previousRowSums.add(currentRowSums.get(i));
            }
        }
        
        // Return the k-th smallest sum.
        return previousRowSums.get(k - 1);
    }

    // Main method to test the kthSmallest method.
    public static void main(String[] args) {
        // Example 2D matrix.
        int[][] matrix = {
            {1, 3, 11},
            {2, 4, 6},
        };
        // Specify the value of k.
        int k = 5;
        // Create an object of the class to call the kthSmallest method.
        Kth_Smallest_Sum_2D solution = new Kth_Smallest_Sum_2D();
        // Call the method and print the result.
        int result = solution.kthSmallest(matrix,k);
        System.out.println("The " + k + "-th smallest sum is: " + result);
    }
}
