import java.util.*;
public class Knapsack
{
    int solveKnapsack(int[] value, int[] weights, int capacity)
    {
        // basic checks
      if (capacity <= 0 || value.length == 0 || weights.length != value.length)
        return 0;
  
      int n = value.length;
      int[][] dp = new int[n][capacity + 1];
  
      // populate the capacity=0 columns, with '0' capacity we have '0' value
      for(int i=0; i < n; i++)
        dp[i][0] = 0;
  
      // if we have only one weight, we will take it if it is not more than the capacity
      for(int c=0; c <= capacity; c++) {
        if(weights[0] <= c)
          dp[0][c] = value[0];
      }
  
      // process all sub-arrays for all the capacities
      for(int i=1; i < n; i++)
      {
        for(int c=1; c <= capacity; c++)
        {
          int value1= 0, value2 = 0;
          // include the item, if it is not more than the capacity
          if(weights[i] <= c)
            value1 = value[i] + dp[i-1][c-weights[i]];
          // exclude the item
          value2 = dp[i-1][c];
          // take maximum
          dp[i][c] = Math.max(value1, value2);
        }
      }
      // maximum profit will be at the bottom-right corner.
      return dp[n-1][capacity];
    }
  
    public static void main(String[] args)
    {
      Scanner sc = new Scanner( System.in);
      Knapsack obj = new Knapsack();
      System.out.println("Enter the no of values");
      int n = sc.nextInt();
      int[] value = new int[n];
      int[] weights = new int[n];
      System.out.println("Enter the values");
      for(int i = 0; i<n; i++)
      value[i] = sc.nextInt();
      System.out.println("Enter the weights");
      for(int i = 0; i<n; i++)
      weights[i] = sc.nextInt();
      System.out.println("Enter the knapsack capacity");
      int w = sc.nextInt();
      int maxvalue = obj.solveKnapsack(value, weights, w);
      System.out.println("Total knapsack value ---> " + maxvalue);
    }//end of main
  }//end of class
/*
Sample Input & Output -
INPUT:
Enter the no of values
3
Enter the values
50 100 120
Enter the weights
10 20 30

OUTPUT:
Total knapsack value ---> 220
-----------------------------
TIME COMPLEXITY:
O(N*C)
[(where ‘N’ is the number of items and ‘C’ is the knapsack capacity)]
---------------------------------------------------------------------
SPACE COMPLEXITY:
O(N∗C)
*/