import java.util.*;
public class QuickSort 
{
    int partition (int abc[], int start, int end)  
{  
    int pivot = abc[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (abc[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            int t = abc[i];  
            abc[i] = abc[j];  
            abc[j] = t;  
        }  
    }  
    int temp = abc[i+1];  
    abc[i+1] = abc[end];  
    abc[end] = temp;  
    return (i + 1);  
}  

/* function to implement quick sort */  
void quick(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end);  //p is partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
/* function to print an array */  
void printArray(int abc[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        System.out.print(abc[i] + " ");  
} 
public static void main(String[] args)
{ 
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int arr[] = new int[n];
    for(int i = 0; i<n; i++)
    arr[i] = sc.nextInt();    
    QuickSort q1 = new QuickSort();  
    q1.quick(arr, 0, n - 1); 
    q1.printArray(arr, n);
    } // end of main
}// end of class
/*
Sample Input & Output :
---------------------
The first line of the input contains an integer 'n' denoting the size of the array
The second line of the input contains 'n' no integers
SAMPLE INPUT & OUTPUT 1
INPUT :
4
98 76 54 32
OUTPUT :
32 54 76 98
SAMPLE INPUT & OUTPUT 2
INPUT :
5
45 45 23 65 12
OUTPUT:
12 23 45 45 65
------------------------
Time Complexity :
Best Case Complexity - O(n*logn)
Worst Case Complexity - O(n2)
------------------------
Space Complexity :
The space complexity of quicksort is O(n*logn)
*/