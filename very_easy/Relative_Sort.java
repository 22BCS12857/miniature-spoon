package very_easy;
import java.util.Arrays;
import java.util.HashMap;

public class Relative_Sort {
    public static int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        for (int j : arr1) {
            if (hm.containsKey(j)) {
                hm.put(j, hm.get(j) + 1);
            } else {
                hm.put(j, 1);
            }
        }
        int[] ans = new int[arr1.length];
        int cnt=0;
        for (int j : arr2) {
            while (hm.get(j) > 0) {
                ans[cnt] = j;
                cnt++;
                hm.put(j, hm.get(j) - 1);
            }
            hm.remove(j);
        }
        int[] remaining = new int[arr1.length-cnt];
        int index = 0;
        for (int j : arr1) {
            if (hm.containsKey(j)) {
                while (hm.get(j) > 0) {
                    remaining[index] = j;
                    index++;
                    hm.put(j, hm.get(j) - 1);
                }
                hm.remove(j);
            }
        }
        Arrays.sort(remaining);
        for (int j : remaining) {
            ans[cnt] = j;
            cnt++;
        }
        return ans;
    }
    public static void main(String[] args){
        //Case 1: 
        int arr1[]={2,3,1,3,2,4,6,7,9,2,19};
        int arr2[]={2,1,4,3,9,6};
        int res1[]=relativeSortArray(arr1, arr2);
        System.out.println("Case 1:"+Arrays.toString(res1));//Expected: [2,2,2,1,4,3,3,9,6,7,19]
        //Case 2:
        int arr_1[]={28,6,22,8,44,17};
        int arr_2[]={22,28,8,6};
        int res2[]=relativeSortArray(arr_1, arr_2);
        System.out.println("Case 2:"+Arrays.toString(res2)); //Expected: [22,28,8,6,17,44]

    }
}