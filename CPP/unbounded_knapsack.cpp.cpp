/*
  A brief description of the problem ----
  Given a knapsack weight W and a set of n items with certain value val[i] and weight wt[i], we need to calculate the maximum amount that could make up this quantity exactly. Here we are allowed to use unlimited number of instances of an item.
*/

#include <bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int wt[], int val[], int arr_size, int weight)
{
    //function which returns the maximum cost of the knapsack

    int dp[arr_size + 1][weight + 1];

    //initislising the do array
    for (int i = 0; i < arr_size + 1; i++)
    {
        for (int j = 0; j < weight + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    //filling the dp array using previously calculated values
    for (int i = 1; i < arr_size + 1; i++)
    {
        for (int j = 1; j < weight + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[arr_size][weight];
}

int main()
{
    int weight; // total weight
    cin >> weight;
    int arr_size; //array size
    cin >> arr_size;
    int wt[arr_size];  //weight array
    int val[arr_size]; //value array of each weight

    for (int i = 0; i < arr_size; i++) 
        cin >> wt[i];

    for (int i = 0; i < arr_size; i++)
        cin >> val[i];

    cout << unbounded_knapsack(wt, val, arr_size, weight);
    return 0;
}
/*Unbounded knapsack implementation in C++
Input: Total weight, size of the array, weight array and vallue array
Output: Returns the maximum cost of the knapsack

----------------------------------------
Sample Input1:
100
3
5 10 15
10 30 20
Output:
300
----------------------------------------

Time Complexity: O((weight+1) * arr_size)

Space Complexity: O((weiight+1)*(arr_size+1))

*/