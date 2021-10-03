import java.util.Scanner;

public class climbstaris {

	public static void main(String[] args) {
		
		// Taking input from user 
		
		Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        
        int[] arr = new int[n];
        for(int i = 0;i<n;i++){
            arr[i] = scn.nextInt();
        }
        
        // creating an array for DP
        
        Integer[] dp = new Integer[n+1];
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]>0){
                int m = Integer.MAX_VALUE;
            for(int j = 1;j<=arr[i] && i+j<n+1;j++){
                if(dp[i+j]!=null)
                   m= Math.min(m,dp[i+j]);        //calc. best possible way
                
            }
            if(m != Integer.MAX_VALUE)
                dp[i]=m+1;
            
            }
        }
        
        // Displaying result
        
        System.out.println(dp[0]);
	}
}

/*
------------------------------------------------------------------
JAVA program for climb stairs with minimum moves.
Input: Size of stairs and the maximum value to which user can jump
Output: minimum number of moves, in which we can reach to the top of staircase.
-------------------------------------------------------------------
Sample input 1:
10
3 3 0 2 1 2 4 2 0 0 

Output:
4
-------------------------------------------------------------------
Time Complexity : O(n^2)
Space Complexity : O(n)
-------------------------------------------------------------------
*/