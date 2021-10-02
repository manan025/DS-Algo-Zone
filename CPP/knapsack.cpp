#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int value[] ,int arr_size, int weight) 
{
    //function which returns the maximum cost of the knapsack
    int dp[arr_size+1][weight+1];
    
    //initialising dp array
    for(int i=0; i<arr_size+1; i++){
        for(int j=0; j<weight+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    //filling the dp array
    for(int i=1; i<arr_size+1; i++){
        for(int j=1; j<weight+1; j++){
            if(wt[i-1]<=weight){
                dp[i][j]=max(dp[i-1][j], value[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[arr_size][weight];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr_size; //array size
    cin>>arr_size;
    int wt[arr_size]; //weight array 
    int value[arr_size]; //value array of each weight
    for(int i=0; i<arr_size; i++){
        cin>>wt[i];
    }
    for(int i=0; i<arr_size; i++){
        cin>>value[i];
    }
    int weight; //total weight of knapsack
    cin>>weight;
    cout<<knapsack(wt, value, arr_size, weight)<<endl;
    return 0;
}

/*
0/1 knapsack implementation in C++
Input: Size of array , Array of weight, Array of value for each weight, total weight of knapsack
Output: Maximum Value/Price of knapsack

----------------------------------------
Sample Input1:
3
[10, 20, 30]
[60, 100, 120]
50
Output:
220

----------------------------------------

Time Complexity:
Worst and Average case = O(arr_size * weight)

Space Complexity: O(arr_size * weight)

*/