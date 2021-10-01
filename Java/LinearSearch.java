import java.util.Scanner;
public class LinearSearch {

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
        
        //Input the target element 
        System.out.println("Enter the element to be searched");
        int target = sc.nextInt();
        
        //Close the scanner after input is taken
        sc.close();
        
        int result = linearSearch(arr,n,target);
        if(result == -1)
        	System.out.println("Element not found!");
        else
            System.out.println("Element found at index: "+result);
     
	}
	
	public static int linearSearch(int[] arr,int size,int target) {
		for(int i = 0; i < size; i++) {
			if(arr[i]==target)
				return i;
		}
		return -1;
	}

}
/*
Linear search implementation in Java
Input: Size of array , array of integers and the target element to be searched in the array
Output: Returns index of the element if it's present, else '-1'
----------------------------------------
Sample Input 1:
6
11 10 6 7 8 19
6
Output:
Element found at index: 2
Sample Input 2:
6
10 33 23 22 11 1
5
Output:
Element not found!
----------------------------------------
Time Complexity:
Worst Case = O(n)
Best Case = O(1) (when the first element is the desired element)
Average time Complexity = O(n)
Space Complexity: O(1)
*/
