import java.util.Scanner;

public class KadaneAlgorithm
{
	static int maxSubArraySum(int a[])
	{
		int size = a.length;
		int max_so_far = Integer.MIN_VALUE, max_ending_here = 0;

		for (int i = 0; i < size; i++)
		{
			max_ending_here = max_ending_here + a[i];
			if (max_so_far < max_ending_here)
				max_so_far = max_ending_here;
			if (max_ending_here < 0)
				max_ending_here = 0;
		}
		return max_so_far;
	}
	
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		//Input the size of the array
        System.out.println("Enter the size of array: ");
        int n = sc.nextInt();
        
        //Initialize the array with given size
        int arr[] = new int[n];
        
        //Input the array elements
        System.out.println("Enter array elements");
        for(int i = 0; i< n; i++)
            arr[i] = sc.nextInt();
        
        sc.close();
        
		System.out.println("Maximum contiguous sum is " +
									maxSubArraySum(arr));
	}
}
/*
 * Java program for Implementation of Kadane's Algorithm 
 * Input: Size of array,array of integers 
 * Output: Sorted array in ascending order
 * ---------------------------------------- 
 * Sample Input1: 
 * 4
 * 25 9 -49 16
 * Output:
 * Maximum contiguous sum is 34
 *
 * Sample Input2:
 * 5
 * 5 4 -1 7 8
 * Output:
 * Maximum contiguous sum is 23
 *
 * Sample Input3:
 * 9
 * -2 1 -3 4 -1 2 1 -5 4
 * Output:
 * Maximum contiguous sum is 6
 * 
 * ---------------------------------------- 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
