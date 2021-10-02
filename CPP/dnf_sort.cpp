// DNF Sort in CPP

#include<iostream>
using namespace std;

// dnfsort() function to sort the 3 numbers(0,1,2)
void dnfsort(int arr[], int n) {
    int low = 0, high = n-1, mid = 0;

    // while() until we reach the end of the function
    while(mid<=high) {

        // if the number is the smallest(0), we swap it to the start(low point)
        if(arr[mid]==0) {
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }

        // if the number is the largest(2), we swap it to the end(high point)
        else if(arr[mid]==2) {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }

        // if the number is the middle one(1), we leave it and move on to next number
        else {
            mid++;
        }
    }
}

int main() {
    // Only 3 numbers can be taken in array to sort using DNF Sort
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    // Sending the array to the dnfsort() function
    dnfsort(arr, n);

    // printing the sorted array
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

/*
DNF SORT implementation in C++
Input: Size of array , Array Integers
Output: Returns the sorted array

----------------------------------------
Sample Input1:
6
0 2 2 1 1 0

Output:
0 0 1 1 2 2 

Sample Input2:
8
1 2 0 2 1 1 0 1

Output:
0 0 1 1 1 1 2 2

----------------------------------------

Time Complexity: O(n)

Space Complexity: O(1)

*/