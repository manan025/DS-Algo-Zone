#include <bits/stdc++.h>
using namespace std;

int linear_search(int key, int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == key)
            return (i + 1);
    }

    return -1;
}

int main()
{

    //fast input-output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input Size and Array Elements
    int arr_size;
    cin >> arr_size;
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
        cin >> arr[i];

    // Input the element to be searched
    int key;
    cin >> key;

    int pos = linear_search(key, arr, arr_size);
    if (pos > 0)
        cout << "ELEMENT FOUND AT POSITION " << pos;
    else
        cout << "ELEMENT NOT FOUND !";

    return 0;
}
/*
Linear search implementation in C++
Input: Size of array , Array of integers and the value to be searched in the array
Output: Returns position of the element if it's present else '-1'
----------------------------------------
Sample Input 1:
6
[11, 10, 6, 7, 8, 19]
6
Output:
ELEMENT FOUND AT POSITION 3


Sample Input 2:
6
[10,33,23,22,11,1]
5
Output:
ELEMENT NOT FOUND !
----------------------------------------
Time Complexity:
Worst Case = O(n)
Best Case(when the first element is the desired element) = O(1)
Space Complexity: O(1)
*/
