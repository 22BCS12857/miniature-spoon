package very_easy;
public class Inserted_at{
    
    public int searchInsert(int[] nums, int target) {
        return _search(nums, target, 0, nums.length - 1);
    }

    private int _search(int[] nums, int target, int begin, int end) {
        // Base case: If begin > end, return the insertion point at `begin`
        if (begin > end) {
            return begin;
        }

        // Calculate the middle index
        int pivot = (begin + end) / 2;

        // If the target is found at the pivot, return the pivot index
        if (nums[pivot] == target) {
            return pivot;
        }
        // If the target is less than the value at pivot, search the left half
        else if (target < nums[pivot]) {
            return _search(nums, target, begin, pivot - 1);
        }
        // If the target is greater than the value at pivot, search the right half
        else {
            return _search(nums, target, pivot + 1, end);
        }
    }

    public static void main(String[] args) {
        Inserted_at helper = new Inserted_at();
        
        // Test cases
        int[] nums = {1, 3, 5, 6};
        int target = 5;
        int result = helper.searchInsert(nums, target);
        System.out.println("Insert at index: " + result); // Expected output: 2 (target 5 is at index 2)
        
        target = 2;
        result = helper.searchInsert(nums, target);
        System.out.println("Insert at index: " + result); // Expected output: 1 (target 2 should be inserted at index 1)
        
        target = 7;
        result = helper.searchInsert(nums, target);
        System.out.println("Insert at index: " + result); // Expected output: 4 (target 7 should be inserted at the end)
    }
}
