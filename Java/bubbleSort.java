import java.util.Scanner;
public class Main {

    //Method to swap the elements of an array
    static void swap(int arr[],int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    //method to sort the given array using bubbleSort
    static void bubbleSort(int arr[],int n)
    {
        for (int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j+1]<arr[j])
                    swap(arr,j+1,j);
            }
        }
    }

    //method to print the elements of the array
    static void printArray(int arr[], int n)
    {
        for(int i = 0; i < n; ++i)
        {
            System.out.print(arr[i]+" ");
        }
    }

    public static void main(String[] args) {
        // write your code here
        Scanner in=new Scanner(System.in);
        int flag=0;
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

         /* Check if array is already sorted,
        thus making time complexity = O(n)
         */
        for(int i = 0; i < n-1; ++i)
        {
            if(arr[i+1] < arr[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            System.out.println("\nSorted Array: ");
            bubbleSort(arr, n);
        }
        else
        {
            System.out.println("\nData is already sorted: ");
        }

        printArray(arr, n);
    }
}
/*
Bubble Sort implementation in Java
Input: Array of integers
Output: Sorted array in ascending order
----------------------------------------
Sample Input:
[19, 7, -5, 6, 0, 8]
Output:
Sorted Array: -5 0 6 7 8 19
----------------------------------------

Time Complexity:
Worst and Average case = O(n^2)
Best case (when array is already sorted) = O(n)

Space Complexity: O(1)

*/