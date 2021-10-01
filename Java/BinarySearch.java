import java.util.*;
public class BinarySearch{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array");

        //Getting the size of the array as input.
        int n = sc.nextInt();

        //Declaring an array of the given size
        int[] a = new int[n];

        System.out.println("Enter "+n+" numbers for the array");
        for(int i = 0; i < n; i++){
            //Getting the array elements as input
            a[i] = sc.nextInt();
        }

        System.out.println("Enter the number to be found");
        //Getting the target number as the input
        int target = sc.nextInt();

        //Binary Search Logic

        //The start and end variables are used to specify the portion of the array
        //under consideration.
        int start = 0,end = n-1;

        //The flag variable is used to specify if the target element was found in
        //the given array
        boolean flag = false;


        while(start <= end){
            //Getting the index of the middle element of the array in consideration
            int mid = start + (end-start)/2;

            //If the number at middle index of the array is equal to to the target number,
            //we break from this loop after printing the position in which the target number
            //was found and set the flag variable to true.
            if(a[mid] == target){
                System.out.println("The number "+target+" is found at this position of the array: "+(mid+1));
                flag = true;
                break;
            }

            //If the middle index number is greater than the target, we shrink the array
            //under consideration by decrementing the end index by 1
            if(a[mid] > target){
                end = mid - 1;

            }

            //If the middle index number is less than the target, we shrink the array
            //under consideration by incrementing the start index by 1
            if(a[mid] < target){
                start = mid + 1;
            }
        }
        if(!flag){
            System.out.println("The element is not found in the given array");
        }
    }
}

//Sample Input and Output
//Example 1
/*
Enter the number of elements in the array

5

Enter 5 numbers for the array

23 45 67 89 92

Enter the number to be found

89

The number 89 is found at this position of the array: 4
 */

//Example 2
/*
Enter the number of elements in the array

6

Enter 6 numbers for the array

10 29 49 58 61 72

Enter the number to be found

69

The element is not found in the given array
 */

//Time Complexity
/*
The average time complexity of binary search is O(log n). The worst case time
complexity is also the same.

The best time complexity of binary search is O(1) when the middle index number
directly matches the target number
 */

//Space Complexity
/*
The space complexity of binary search is O(1)
 */