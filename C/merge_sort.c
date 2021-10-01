#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];


	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r){
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


void printArray(int A[], int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main(){

	    // Getting the size of the array from the user
        int n;
        printf("Enter the count of elements in the array: ");
        scanf("%d", &n);

        // Getting the elements of the array from the user
        int arr[n];
        printf("Enter the elements of the array (enter one element and press enter key): ");
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	//int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = n;

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}


/*
Merge sort implementation in C
This code is contributed by Yasas Sandeepa
-------------------------------------------
Enter the count of elements in the array: 8
Enter the elements of the array (enter one element and press enter key): 10
4
20
1
7
5
15
12
Given array is 
10 4 20 1 7 5 15 12 

Sorted array is 
1 4 5 7 10 12 15 20 


Complexity Analysis
---------------------
Average Time complexity: O(nlogn)
Space complexity: O(n)
*/
