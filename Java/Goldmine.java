import java.util.Scanner;
/* Java Program for Gold mine Problem using DP */ 
public class goldmine {

	public static void main(String[] args) {
		        Scanner scn = new Scanner(System.in);
		        
		        /* Accepting data from user */
		        
		        System.out.println("Please enter the number of rows columns, followed by elements of goldmine :");
		        int n = scn.nextInt();
		        int m = scn.nextInt();
		        int[][] a = new int[n][m];
		        for(int i=0;i<n;i++){
		            for(int j=0;j<m;j++){
		                a[i][j] = scn.nextInt();
		            }
		        }
		        
		        /* Creating another matrix for DP */
		        
		        int[][] dp = new int[n][m];
		        
		        /* Traversing in given matrix and adding values in DP matrix */
		        
		        for(int j=m-1;j>=0;j--){
		            for(int i = n-1;i>=0;i--){
		                if(j == m-1){
		                    dp[i][j] = a[i][j];
		                }else if(i == 0){
		                    dp[i][j] = a[i][j] + Math.max(dp[i][j+1],dp[i+1][j+1]);
		                }else if(i == n-1){
		                    dp[i][j] = a[i][j] + Math.max(dp[i][j+1],dp[i-1][j+1]);
		                }else{
		          dp[i][j] = a[i][j] + Math.max(dp[i-1][j+1],Math.max(dp[i][j+1],dp[i+1][j+1]));  //deciding maximum value
		                }
		            }
		        }
		        		        
		        int ma = dp[0][0];
		        for(int i = 1;i<n;i++){
		            if(dp[i][0]>ma)
		            ma = dp[i][0];
		        }
		        
		        /* Result output */
		        
		        System.out.println(ma);
		    }
}


/*
---------------------------------------------------------------------------
Java program for Gold mine problem using DP
Input: number of rows, number of columns, element of matrix
Output: maximum amount of gold that can be mined.
---------------------------------------------------------------------------
Sample input 1:
Please enter the number of rows columns, followed by elements of goldmine :
6
6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1

Output:
33
--------------------------------------------------------------------------
Time Complexity : O(n^2)
Space Complexity : O(n^2)
--------------------------------------------------------------------------
*/