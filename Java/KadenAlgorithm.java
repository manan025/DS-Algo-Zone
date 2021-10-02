
import java.util.Scanner;

public class KadenAlgorithm {

    public static void main(String[] args) {
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

        System.out.println(maxSubarraySum(arr,n));

    }

    static long maxSubarraySum(int arr[], int n){

        long currSum =0;
        long maxSum =Long.MIN_VALUE;

        for (int i =0; i<n ;i++){
            currSum += arr[i];

        maxSum = Math.max(maxSum,currSum);
        if(currSum < 0){
            currSum= 0;
        }
    }
    return maxSum;
    }

/*
* Java program for Kadane's Algorithm
* Input: Size of array,array of integers
* Output: maximum sum of contagious array
* ----------------------------------------
* Sample Input1:
* 5
* {1,2,3,-2,5}
* Output:
* 9
*
* Sample Input2:
* 4
* {-1,-2,-3,-4}
* Output:
* -1
*/
}
