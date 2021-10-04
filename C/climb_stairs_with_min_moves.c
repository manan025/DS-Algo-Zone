#include <stdio.h>

// Problem Link : https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/climb-stairs-with-minimum-moves-official/ojquestion

// stairs[i] ---> How many stairs from ith stair we can travel atmost

// We want to minimise the steps to reach the nth stair, in otherwords if we have many ways to come to nth stair
// then in those ways we will choose the one which we have to take the minimum steps 

// dp[n] --> Minimum moves to reach the nth stairs

// How can we reach nth stair ? 
// if current_stair + stairs[current_stair] >= n, then we can easily reach nth stair

// Now in all those possible stairs we have to choose the minimum one, so can we say 
// dp[n] = min(dp[possible1], dp[possible2], .... dp[possiblem]) 

// Where dp[i] ---> Minimum moves to reach the ith stair

int main()
{
    int n, i, j, inf = 1e9 + 9;
    printf("Enter the total stairs : ");
    scanf("%d ", &n);
    printf("%d\n", n);
    
    int stairs[n];
    
    for(i=0; i<n; i++)
        scanf("%d ", &stairs[i]); 
        
    int dp[n + 1];
    dp[0] = 0;
    
    for(i=1; i<=n; i++)
        dp[i] = inf; // infinite moves to reach every stair except 0th as we are starting from that only 
    
    for(i=0; i<n; i++)
    {
        for(j=1; j<=stairs[i]; j++)
        {
            if(i + j > n)
            {
                if(dp[n] >= (dp[i] + 1))
                    dp[n] = dp[i] + 1; 
            }
            
            else
            {
                if(dp[i + j] >= (dp[i] + 1))
                    dp[i + j] = dp[i] + 1;
            }
        }
    }
    
    if(dp[n] == inf)
        printf("null\n"); // No possible move to reach nth stair 
    else
        printf("%d\n", dp[n]);
}

/* Testcases :

Input : 
10 
3 3 0 2 1 2 4 2 0 0

Output : 
4

Time Complexity : 
O(N * max(stairs[i])) ----> Because in worst we have move max(stairs[i]) for every N 

Space Complexity :
O(N) ---> Because we are storing the min moves in dp array */