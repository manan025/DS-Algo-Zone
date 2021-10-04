#include <stdio.h>

// Problem based on it : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

int kadane_algorithm(int arr[], int n)
{
    int max_sum = 0, ans = -1e9, i; 
    // we want to choose a subarray with the maximum sum (kadane_algorithm), so its intutitive that we should try to avoid negative number
    // in case where there are all negative numbers, then we choose the maximum element
    // so maximum_sum starts from 0, ans starting from -1e9 as there is possibility that all elements of array are negative, not any negative value;
    
    // Now its very intutitive that we have to take positive numbers to maximise the sum 
    // But wait can we take negative numbers ???
    // We can take negative numbers till then we current_sum + negative_number_current >= 0
    // But why this condition only ? 
    
    // Suppose array is like 5 -2 3 
    // 5 ---> 3 (negative taken) or 0 (negative not taken, break subarray, so maximum_sum starts from 0) ----> 6 or 3
    
    // Suppose array is like 5 -6 3
    // 5 ---> -1 (negative taken) or 0 (negative not taken, break subarray, so maximum_sum starts from 0) -----> 2 or 3
    
    // I hope it clears your doubt why and when we take negative numbers in kadane_algorithm
    
    // Once again, we take negative numbers when (current_sum + negative_number_current >= 0)
    
    for(i=0; i<n; i++)
    {
        max_sum += arr[i];
            
        if(max_sum >= ans)
            ans = max_sum;
            
        if(max_sum <= 0)
            max_sum = 0;
    }
    
    return ans;
}

int main()
{
    int i, n;
    printf("Enter the number of element : \n");
    scanf("%d ", &n);
    
    int arr[n];
    
    printf("Enter the elements of the array : \n");
    
    for(i=0; i<n; i++)
    scanf("%d ", &arr[i]);
    
    printf("Elements of the array : \n");
    
    for(i=0; i<n; i++)
    printf("%d ", arr[i]);
    
    printf("\nMax subarrary sum : %d\n", kadane_algorithm(arr, n));
}

/* Testcase :

Input : 
8
-2 -3 4 -1 -2 1 5 -3

Output : 
7 

Time Complexity : 
O(N) ---> As we are traversing the whole array one time 

Space Complexity : 
O(N) ---> As we are storing the data in the array */