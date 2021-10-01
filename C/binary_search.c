// Including the required header files
#include<stdio.h>

void binary_search(int *arr, int n, int x) {
    // Initializing the variables
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        // Calculating the mid
        mid = (low + high) / 2;

        if (arr[mid] == x) {
            // If the element is found
            printf("%d found at %d\n", x, mid);
            return;
        }
        // If the element is greater than the mid, it is present in the greater side of mid, therefore we increment mid by 1
        else if (arr[mid] < x) low = mid + 1;
        // If the element is lesser than the mid, it is present in the lesser side of mid, therefore we decrement mid by 1
        else high = mid - 1;
    }

    // If the element is not found
    printf("%d not found\n", x);
}

int main() {
    // Getting the size of the array from the user
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Getting the elements of the array from the user
    int arr[n];
    printf("Enter the elements of the array in sorted order: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Getting the value to be found from the user
    int val;
    printf("Enter the value to be searched: ");
    scanf("%d", &val);

    // Calling the binary search function
    binary_search(arr, n, val);
}

/*
Binary Search implementation in C

Input: Size of the array (n), integer elements of the array (arr), value to be searched (val)
Output: The index of the value if found, "not found" otherwise

----------------------------------------------------------------------------------------------------------------------
Test Cases

Sample Input - 1:
Enter the number of elements in the array: 5
Enter the elements of the array in sorted order: 1 2 3 4 5
Enter the value to be searched: 3

Sample Output - 1:
3 found at 2


Sample Input - 2:
Enter the number of elements in the array: 10
Enter the elements of the array in sorted order: 1 2 3 4 5 6 7 8 9 10
Enter the value to be searched: 11

Sample Output - 2:
11 not found

----------------------------------------------------------------------------------------------------------------------
Time Complexity Analysis

Worst Case Time Complexity: O(log n)
Average Case Time Complexity: O(log n)
Best Case Time Complexity: O(1)

Worst case occurs when the element is present at either extremes of the array or is not present in the array
Best case occurs when the element is present at the middle of the array

Space Complexity: O(1)
*/