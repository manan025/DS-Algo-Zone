import java.util.Scanner;

public class NQueen {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of queens.");

        int n = sc.nextInt();
        int ans[][] = new int[n][n];
        boolean found = findPositionOfQueen(n,0,ans);
        if(found){
            for(int i = 0 ; i < n ;i++){
                for(int j = 0 ; j < n ; j++){
                    System.out.print(ans[i][j]+"");
                }
                System.out.println();
            }
        }else{
            System.out.println("Queens cannot be placed");
        }
    }

    private static boolean findPositionOfQueen(int n, int row, int[][] ans) {
        if(row >= n)
        return true;

        int col;
        for(col = 0; col < n;col++){
            if(isSafe(ans,row,col,n)){
                ans[row][col] = 1;
                if(findPositionOfQueen(n, row+1, ans))
                    return true;
                ans[row][col] = 0;
            }
        }
        return false;
    }

    private static boolean isSafe(int[][] arr, int row, int col, int n) {
        if(row < 0 || row >= n || col < 0 || col >= n)
        return false;

        int i,j;
        for(i = 0; i < row;i++)
            if(arr[i][col] == 1)
                return false;
        
        i = row;
        j = col;

        while(i >= 0 && j >= 0){
            if(arr[i][j] == 1)
                return false;
            i--;
            j--;
        }

        i= row;j=col;
        while(i >= 0 && j < n){
            if(arr[i][j] == 1)
            return false;

            i--;
            j++;
        }

        return true;
    }
    
}
/**
 * Input: 4 
 * Output: 0100
           0001
           1000
           0010
 * Time-Complexity: O(n!)
Space-Complexity: O(1)

 */