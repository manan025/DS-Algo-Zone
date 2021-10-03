// C++ program to implement Jump Search

#include <bits/stdc++.h>
using namespace std;

int jump_Search(int arr[], int x, int n)
{
    // step will hold the optimal block size to be jumped, whcih is sqrt(n)
    int jump = sqrt(n);

    // Finding the block where element is present (if it is present)
    int index = 0;
    while (arr[min(jump, n) - 1] < x)
    {
        index = jump;
        jump+= sqrt(n);
        if (index >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[index] < x)
    {
        index++;
        // If we reached next block or end of
        // array, element is not present.
        if (index == min(jump, n))
            return -1;
    }
    // If element is found
    if (arr[index] == x)
        return index;

    return -1;
}

// Driver program to test function
int main()
{
    int n;
    cout << "Enter size of the Array :";
    cin >> n;


    //creating array of size n
    int arr[n];

    cout<<"\n Enter elements of the array in sorted order : ";
    //taking the array as input (***The array must be sorted****)
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }

    int a;
    cout<<"\n Enter element to be searched : ";
    cin>> a;

     //this function will return the index of the searched element if found, else will return -1;
    int index = jump_Search(arr, a, n);

    // Print the index where the element 'a' is located
    cout << "\n the Number " << a << " is present at index " << index;
    return 0;
}

/*
sample test cases:
input:
5 
4 8 12 13 16
12
output:
the Number 12 is present at index 2 (0 based indexing)

input:
4
5 6 7 9
10
output:
the Numeber 10 is present at index -1


Time Complexity : O(√n) 
Auxiliary Space : O(1)

some key points:

What is the optimal block size to be skipped? 
-->In the worst case, we have to do n/m jumps and if the last checked value is greater than the element to be searched for, we perform m-1 comparisons more for linear search.
 Therefore the total number of comparisons in the worst case will be ((n/m) + m-1).
 The value of the function ((n/m) + m-1) will be minimum when m = √n.
 Therefore, the best step size is m = √n.

-->The provided array must be given in sorted manner
*/
