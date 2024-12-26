package easy;

// Java Code to find common elements in three sorted arrays
import java.util.*;

public class CommonElements {

    // Function to find common elements in three arrays
    public static ArrayList<Integer>
    commonElements(ArrayList<Integer> A,
                   ArrayList<Integer> B,
                   ArrayList<Integer> C)
    {
        // TreeMap to mark the common elements
        TreeMap<Integer, Integer> map = new TreeMap<>();

        // Mark all the elements in the first array with
        // value=1
        for (int ele : A) {
            map.put(ele, 1);
        }

        // Mark all the elements which are common in first
        // and second array with value = 2
        for (int ele : B) {
            if (map.containsKey(ele) && map.get(ele) == 1)
                map.put(ele, 2);
        }

        // Mark all the elements which are common in first,
        // second, and third array with value = 3
        for (int ele : C) {
            if (map.containsKey(ele) && map.get(ele) == 2)
                map.put(ele, 3);
        }

        // Store all the common elements
        ArrayList<Integer> commonElements
            = new ArrayList<>();
        for (int ele : map.keySet()) {
            if (map.get(ele) == 3)
                commonElements.add(ele);
        }

        // Return the common elements which are common in
        // all the three arrays
        return commonElements;
    }

    public static void main(String[] args)
    {
        // Sample Input
        ArrayList<Integer> A
            = new ArrayList<>(List.of(1, 5, 10, 20, 30));
        ArrayList<Integer> B
            = new ArrayList<>(List.of(5, 13, 15, 20));
        ArrayList<Integer> C
            = new ArrayList<>(List.of(5, 20));

        // Function call and storing result
        ArrayList<Integer> ans = commonElements(A, B, C);

        // Printing common elements
        System.out.print("Common elements are: ");
        for (int i = 0; i < ans.size(); i++)
            System.out.print(ans.get(i) + " ");
    }
}