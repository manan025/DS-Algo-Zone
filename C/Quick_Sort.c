#include <stdio.h>

int main() {
  int size;
   printf("Enter Array Size\n");
    scanf("%d",&size);
     int array[size];
    

    printf("Enter Array Elements\n");
    for(int i=0;i<size;i++)
        scanf("%d",&array[i]);

  int n = sizeof(array) / sizeof(array[0]);
  
  printf("Unsorted Array\n");
  printArray(array, n);        // call for array function 
  
  
  quickSort(array, 0, n - 1);  //call for quicksort function 
  
  printf("Sorted array in ascending order: \n");
  printArray(array, n);         // call for array function 
}



void swap(int *a, int *b) {    // function to swap elements
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {  // function to find the partition position
  int pivot = array[high];                       // select the rightmost element as pivot
  int i = (low - 1);                             // pointer for greater element

  
 for (int j = low; j < high; j++) {    // traverse each element of the array
    if (array[j] <= pivot) {          // compare them with the pivot
        i++;                          // if element smaller than pivot is found then swap it with the greater element pointed by i
      swap(&array[i], &array[j]);     // swap element at i with element at j
    }
  }

    
  swap(&array[i + 1], &array[high]);  // swap the pivot element with the greater element at i
  return (i + 1);                     // return the partition point
}

 
int quickSort(int array[], int low, int high) {   // find the pivot element such that
    if (low < high) {                              // elements smaller than pivot are on left of pivot
    int pi = partition(array, low, high);         // elements greater than pivot are on right of pivot
    quickSort(array, low, pi - 1);                // recursive call on the left of pivot
    
    quickSort(array, pi + 1, high);               // recursive call on the right of pivot
  }
}



int printArray(int array[], int size) {        // function to print array elements
  for (int i = 0; i < size; ++i) {              //better to make array function insted of writing again and again
    printf("%d  ", array[i]);
  }
  printf("\n");
}

/*output
Enter Array Size
6
Enter Array Elements
7
5
8
9
5
7
Unsorted Array
7  5  8  9  5  7
Sorted array in ascending order:
5  5  7  7  8  9


The best-case time complexity of the quick sort algorithm is O(n logn)
The worst case time complexity of Quick Sort algorithm would be O(n^2)



*/ 
