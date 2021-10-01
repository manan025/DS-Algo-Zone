import java.util.Scanner;

class SelectionSort {
	void sort(int arr[]) {
		int n = arr.length;

		// One by one move boundary of unsorted subarray
		for (int i = 0; i < n - 1; i++) {
			// Find the minimum element in unsorted array
			int min_idx = i;
			for (int j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;

			// Swap the found minimum element with the first
			// element
			int temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
	}

	// Prints the array
	void printArray(int arr[]) {
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	// Driver code to test above
	public static void main(String args[]) {
		SelectionSort ob = new SelectionSort();
		Scanner sc = new Scanner(System.in);

		// Input the size of the array
		System.out.println("Enter the size of array: ");
		int size = sc.nextInt();

		// Initialize the array with given size
		int arr[] = new int[size];

		// Input the array elements
		System.out.println("Enter array elements");
		for (int i = 0; i < size; i++)
			arr[i] = sc.nextInt();
		ob.sort(arr);
		System.out.println("Sorted array");
		ob.printArray(arr);
	}
}
/*
// Java program for Implementation of Selection Sort
Input: Size of array, array of integers
Output: Sorted array in ascending order
----------------------------------------
Sample Input:
4
4 3 2 1
Output:
Sorted array
1 2 3 4
----------------------------------------
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
