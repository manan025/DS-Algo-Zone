//Program for Array Rotation

// Write a program which will take an array as input and a value k, which will rotate the array in right by k units

#include <bits/stdc++.h>
using namespace std;

void rotate(int nums[], int n, int k)
{
    for (; k = k % n; n -= k, nums += k)
    {
        // Swap the last k elements with the first k elements.
        // The last k elements will be in the correct positions
        // but we need to rotate the remaining (n - k) elements
        // to the right by k steps.
        for (int i = 0; i < k; i++)
        {
            swap(nums[i], nums[n - k + i]);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter Size of Array :";
    cin>> n;

    int k;
    cout<<"\n Enter number of units you want to rotate the array: ";
    cin>>k;


    cout<<" \n Enter Array elements :";

    int arr[n]; // vector array to store array elements

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rotate(arr,n,k); //calling the function

    //Output
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    

}

/* 

Sample Input Output:

Input:
5
2
1 2 3 4 5

Output:
4 5 1 2 3


Time Complexity : O(n)
Space Complexity : O(1)


*/