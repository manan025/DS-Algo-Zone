#include <iostream>
using namespace std;

void swap(int* a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

//this function rearrange the array
int partition(int arr[], int l , int h){
    int pivot = arr[h];
    int i = (l-1);
    
    for(int j= l;j<=h-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[j],&arr[i]);
        }
       
    }
    swap(&arr[i+1],&arr[h]);
    return (i+1);
    
}

void quicksort(int arr[],int l, int h){

    if(l<h){
        //partition index
        int pi = partition(arr,l,h);

        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}

void printArray(int arr[],int size){
    for(int i = 0;i<size;i++){
        printf("%d " , arr[i]);
    }
}

int main(){
    int arr[] = {10,3,6,2,6,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    printf("Sorted array: ");
    printArray(arr,n);
    return 0;
}

/*
Quick Sort implementation in C++
Input: Array of integers
Output: Sorted array in ascending order
----------------------------------------
Sample Input:
[10,3,6,2,6,0,1]
Output:
Sorted Array: 0 1 2 3 6 6 10 
----------------------------------------

Time Complexity:
Worst case = O(n^2)
Average and Best case = O(n log n)

Space Complexity: O(log n)

*/
