#include <stdio.h>
#include <stdlib.h>
 
int main() {
    
      int n, tot;
      printf("Enter the number of coins and money sum to make :\n");
      scanf("%d %d",&n, &tot);  // number of coins and money sum 
      
      int a[n];
      printf("Enter the coins:\n");
      for (int i=0;i<n;i++)
            scanf("%d",&a[i]);                   // all the coins
     
      int dp[tot+1];
      
      for(int i=0;i<=tot;i++) dp[i]=0;
      dp[0] = 1;  // initializing
      
      for (int i = 1; i <= tot; i++)
      {
            for (int j = 0; j < n; j++)
            {
              if (i-a[j] >= 0)
              {
        	    dp[i] += dp[i-a[j]];
              }
            }
      }
      printf("%d",dp[tot]); // number of distinct ways to produce the given money sum.
}

/*  
 Input : number of coins, total money sum to make, coins.
 
 output : number of distinct ways to produce a money sum.
 
  Sample input : 
           3 9
           2 3 5
  
   Output : 8 
   
   Explanation: 
     2+2+5
     2+5+2
     5+2+2
     3+3+3
     2+2+2+3
     2+2+3+2
     2+3+2+2
     3+2+2+2
*/ 