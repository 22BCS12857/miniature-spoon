package easy;
import java.util.*;

public class Squared_Array {
    public static int[] square_helper(int arr[]) {
        // Initialize the result array with the same length as input array
        
        double[] d = new double[arr.length];
        // Iterate through each element in the input array
        for (int i = 0; i < arr.length; i++) {
            d[i] = Math.pow(arr[i], 2);
        }
        int res[]=new int[d.length];
        for(int i=0;i<d.length;i++){
            res[i]=(int)d[i];
        }
        return res;
    }

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5};
        int[] result = square_helper(arr);        
        // Print the squared values
        System.out.println("Squared values: " + Arrays.toString(result));
    }
}
