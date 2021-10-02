#include<stdio.h>

int max(int a,int b)  // function to find the maximum value
{
    if(b>a)
    return b;
    return a;
}

int main()
{
    printf("Enter the size of array:\n");
    int n; 
    scanf("%d",&n);
    
    int w[n+1];  //weight array
    printf("Enter the weights of elements\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&w[i]);
    }
    int val[n+1]; // value array
    printf("Enter the value of elements\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&val[i]);
    }
    
    int weight; // weight of knapsack
    printf("Enter the weight of knapsack\n");
    scanf("%d",&weight);
    
    int dp[n+1][weight+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=weight;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;   // initializing dp array
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=weight;j++)
        {
            if(j>=w[i])
            dp[i][j]=max(val[i]+dp[i-1][j-w[i]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d",dp[n][weight]);  // printing max value
    
    return 0;
}
/*
 Input: size of array, weight of elements, value of elements, weight of knapsack
 
 Output: Maximum value of knapsack
 
 time complexity: O(n*wg), 
    where n is number of elements and wg is weight of knapsack
    
    
 Sample input:
   4
   [3, 2, 4, 1]
   [100, 20, 60, 40]
   5
   
 Output: 140
 
*/