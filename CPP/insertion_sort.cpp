#include <iostream>
using namespace std;

// Method to print the elements of the array
void displayArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int ele = a[i];
        while (j >= 0 && a[j] > ele)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = ele;
    }
}

int main()
{
    // Input the size and elements of array
    int n;
    cin >> n;
    int a[n];
    int x = 0;
    while (x < n)
    {
        cin >> a[x];
        x++;
    }

    int flag = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i + 1] < a[i])
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        cout << "\nSorted Array: ";
        insertionSort(a, n);
    }
    else
    {
        cout << "\nData is already sorted: ";
    }

    // Display the Final Array
    displayArr(a, n);
}

/*
Insertion Sort implementation in C++
Input: Length of Array followed by Array of integers
Output: Sorted array in ascending order
----------------------------------------
Sample Input 1:
6
[6, 4, 2, 1, 78, 23]
Output:
Sorted Array: 1 2 4 6 23 78

Sample Input 2:
5
[34, 56, 78, 98, 99]
Output:
Data is already sorted: 34 56 78 98 99
----------------------------------------
Time Complexity:
Worst and Average case = O(n^2)
Best case (when array is already sorted) = O(n)
Space Complexity: O(1)
*/
