#include <bits/stdc++.h>
using namespace std;
int binary_search(int key, int arr[], int arr_size, int left, int right)
{
    //function which returns the position of the element from an array
    //if the value is not present it simply returns -1

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid + 1;
        else if (arr[mid] > key)
        {
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    //at each run of this while loop we reduce the size of the array to be searched by 2 .

    return -1;
}
int main()
{

    //fast input-output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //taking size of the array and its elements from the user
    int arr_size;
    cin >> arr_size;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
        cin >> arr[i];

    //for applying binary search the array must be sorted so the input array arr must be sorted

    //element to be searched in the array
    int key;
    cin >> key;

    int pos=binary_search(key, arr, arr_size, 0, arr_size);
    if(pos>0)
    cout <<"ELEMENT FOUND AT POSITION "<< pos;
    else
    cout<<"ELEMENT NOT FOUND.!";

    return 0;
}
/*
Binary search implementation in C++
Input: Size of array , Array of integers and the value to be searched in the array
Output: Returns position of the element if it's present else '-1'

----------------------------------------
Sample Input1:
6
[-5, 0, 6, 7, 8, 19]
6
Output:
ELEMENT FOUND AT POSITION 3

Sample Input2:
6
[-5, 0, 6, 7, 8, 19]
4
Output:
ELEMENT NOT FOUND.!

----------------------------------------

Time Complexity:
Worst and Average case = O(logn)
Best case(when the exact middle element is the one searched) = O(1)

Space Complexity: O(1)

*/