#include <math.h>
#include <stdio.h>
void print(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int n){
    /*
        * This function is used for Insertion sort.

        * We generally fix a key and we try to move elements in the array which are greater than key to one position ahead.

        * We update the key every iteration and we also print sort result for every iteration.

        * The print function is used to print the entire array on the same line with each element having one char space between them.

    */
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        print(arr,n);
        arr[j+1]=key;
    }
    print(arr,n);
}
int main(){
    //Getting the size of the array from user
    int i,n;
    scanf("%d",&n);
    int arr[n];
    //Getting array elements as input from user
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before Sorting\n");
    print(arr,n);
    printf("\nInsertion Sort\n");
    insertionSort(arr, n);
    printf("\nArray after Sorting\n");
    print(arr,n);
    return 0;
}

/*
    Insertion Sort in C

    Input : A valid input size (n) of an array and n array elements to implement insertion sort
    Output : Returns a sorted array using insertion sort

    ----------------------------------------------------------------------

    Sample Input 1 :
    5

    4
    3
    8
    1
    0
    
    Sample Output 1 :
    Array before Sorting
    4 3 8 1 0 

    Insertion Sort
    4 4 8 1 0 
    3 4 8 1 0 
    3 3 4 8 0 
    1 1 3 4 8 
    0 1 3 4 8 

    Array after Sorting
    0 1 3 4 8 

    Sample Input 2 :
    7

    63
    3
    5
    7
    2
    0
    1

    Sample Output 2 :
    Array before Sorting
    63 3 5 7 2 0 1 

    Insertion Sort
    63 63 5 7 2 0 1 
    3 63 63 7 2 0 1 
    3 5 63 63 2 0 1 
    3 3 5 7 63 0 1 
    2 2 3 5 7 63 1 
    0 2 2 3 5 7 63 
    0 1 2 3 5 7 63 

    Array after Sorting
    0 1 2 3 5 7 63 

    -----------------------------------------------------------------------

    Time Complexity : O(n^2)
    Space Complexity : O(1)
*/