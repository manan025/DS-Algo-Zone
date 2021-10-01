import java.util.*;

public class min_number_of_1 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int  n = sc.nextInt(); // n is the number of rows of the array
        int  m = sc.nextInt(); // m is the number of column
        int array[][] = new int[n][m]; //declared an Array with name Array
        int row[] = new int[n]; // an array for number of 1s in each row
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < m; j++) {
                array[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(array[i][j]==1) {
                    row[i]++;
                }
            }
        }
        System.out.println(); // row[] contains the number of 1s for each row
        int min_1s_in_row = row[0];
        for(int i = 0; i < n; i++) {
            min_1s_in_row = Math.min(min_1s_in_row,row[i]);
        } // variable min_is_in_row contains the least number of 1s present in a row
        for(int i = 0; i < n;i++) {
            if(min_1s_in_row == row[i]) { // print the number and elements of row which has least number of 1s
                System.out.println(i+1+" row:");
                for(int j = 0; j < m; j++) {
                    System.out.print(array[i][j]+" ");
                }
                System.out.println();
            }
        }
    }   

}

/*
JAVA PROGRAM TO FIND THE ROWS WITH MINIMUMM NUMBER OF 1s

INPUT FORMAT :
number of rows and number of column
||THE ARRAY ||


OUTPUT FORMAT:
ith row which has least number of 1s
the elements of row which has least number of 1s


INPUT: 
5 4
1 1 1 2 
1 1 5 2 
0 0 1 1 
1 1 2 2 
1 0 1 1 

OUTPUT:
2 row:
1 1 5 2 
3 row:
0 0 1 1
4 row:
1 1 2 2


Time complexity : O(N^2);
Space complexity : O(N^2);



*/
