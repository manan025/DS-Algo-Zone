/*
Problem statement ---
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is the same. 
*/

#include <bits/stdc++.h>
using namespace std;

bool equal_partition(int arr[],int size)
{
    /*function which returns true if the array can be partitioned into two subsets with equal sum else return false*/

    int sum=0;

    for(int i=0;i<sum;i++)
    sum+=arr[i];

    //if sum is even then only it can be partitioned into two parts
    if(sum%2==1)
    return false;

    else
    {
        int equal_sum=sum/2;
        bool dp[size+1][equal_sum+1];

        //initialising the array
        for(int i=0;i<size+1;i++)
        {
            for(int j=0;j<equal_sum+1;j++)
            {
                if(i==0 && j==0)
                dp[i][j]=true;
                else if(i==0 && j!=0)
                dp[i][j]=false;
                else if(i!=0 && j!=0)
                dp[i][j]=true;
            }
        }

        //filling the dp array using previously calculated values
        for(int i=1;i<size+1;i++)
        {
            for(int j=1;j<equal_sum+1;j++)
            {
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }

        if(dp[size][equal_sum])
        return true;
        else
        return false;
    }
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];

    bool res=equal_partition(arr,size);

    if(res==true)
    cout<<"Can be divided into two equal subsets";
    else
    cout<<"Cannot be divided into two equal subsets";

}

/*
Partition equal subset sum implementation in C++
Input: Size of array , Array of integers 
Output: Returns if the array can be partitioned into two subsets with equal sum or not
----------------------------------------
Sample Input1:
5
1 4 2 2 1
Output:
Can be divided into two equal subsets

Sample Input2:
7
4 3 5 2 7
Output:
Cannot be divided into two equal subsets

----------------------------------------

Time Complexity: O(sum*n) 
Auxiliary Space: O(sum*n) 

Practice problem link : https://leetcode.com/problems/partition-equal-subset-sum/

*/