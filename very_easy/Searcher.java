package very_easy;
import java.util.Arrays;

public class Searcher {
    public static int returner(int arr[],int k){
        if(Arrays.binarySearch(arr, k)>0){
            return Arrays.binarySearch(arr, k);
        }
        else{
            return -1;
        }
    }
    public static void main(String[] args) {
        int[] arr = {9,7,16,16,4};
        Arrays.sort(arr);
        // Perform binary search for the specified values
        System.out.println("Searching for 20 in arr: " + returner(arr, 16));
        // System.out.println("Searching for 50 in arr: " + returner(arr, 50));
    }
}