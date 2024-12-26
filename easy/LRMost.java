package easy;
public class LRMost {

	public static void findIndices(int arr[], int n)
	{
		int leftMin = 0, rightMin = 0;
		int leftMax = 0, rightMax = 0;

		int min = arr[0], max = arr[0];
		for (int i = 1; i < n; i++) {

			// If found new minimum
			if (arr[i] < min) {
				leftMin = rightMin = i;
				min = arr[i];
			}

			// If arr[i] = min then rightmost index
			// for min will change
			else if (arr[i] == min)
				rightMin = i;

			// If found new maximum
			if (arr[i] > max) {
				leftMax = rightMax = i;
				max = arr[i];
			}

			// If arr[i] = max then rightmost index
			// for max will change
			else if (arr[i] == max)
				rightMax = i;
		}

		System.out.println("Minimum left : " + leftMin);
		System.out.println("Minimum right : " + rightMin);
		System.out.println("Maximum left : " + leftMax);
		System.out.println("Maximum right : " + rightMax);
	}

	// Driver code
	public static void main(String[] args)
	{
		int arr[] = { 2, 1, 1, 2, 1, 5, 6, 5 };
		int n = arr.length;

		findIndices(arr, n);
	}
}
