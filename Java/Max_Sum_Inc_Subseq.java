import java.util.Scanner;

public class Main {

    /* maximumsumIncSubse() returns the
    maximum sum of increasing
    subsequence in arr[] of size n */
    static int maximumsumIncSubse(int arr[], int n)
    {
        int i, j, max = 0;
        int dp[]=new int[n];

	/* Initialize dp values
	for all indexes */
        for ( i = 0; i < n; i++ )
            dp[i] = arr[i];

	/* Compute maximum sum values
	in bottom up manner */
        for ( i = 1; i < n; i++ )
            for ( j = 0; j < i; j++ )
                if (arr[i] > arr[j] &&
                        dp[i] < dp[j] + dp[i])
                    dp[i] = dp[j] + arr[i];


        for ( i = 0; i < n; i++ )
            if ( max < dp[i] )
                max = dp[i];

        return max;
    }

    public static void main(String[] args) {

        Scanner in=new Scanner(System.in);
        System.out.println("Enter the number of elements in the array");

        //Getting the size of the array as input
        int n=in.nextInt();

        //Declaring an array of given input size
        int arr[]=new int[n];

        System.out.println("Enter the elements of the array");

        //Taking array elements as user input
        for(int i=0;i<n;i++)
        {
            arr[i]=in.nextInt();
        }

        System.out.println("Sum of maximum sum increasing subsequence is "+ maximumsumIncSubse( arr, n ));
    }
}



/*
Maximum Sum Increasing Subsequence implementation in Java
Input: Array of integers
Output: Sum of maximum sum increasing subsequence is printed
----------------------------------------
Sample Input:
[1, 101, 2, 3, 100, 4, 5]
Output:
Sum of maximum sum increasing subsequence is 106
----------------------------------------

 Time Complexity: O(n^2)
 Space Complexity O(n)

*/