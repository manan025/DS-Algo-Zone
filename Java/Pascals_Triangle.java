import java.util.*;
public class Pascals_Triangle
{
    int fact(int f)
    {
        if (f == 0)
            return 1;
        return f * fact(f - 1);
    }

    public static void main(String[] args)
    {
        int i , j;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Pascals_Triangle obj = new Pascals_Triangle();
        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n - i; j++)
            {
                System.out.print(" ");//for spacing in the left
            }
            for (j = 0; j <= i; j++)
            {
                // nCr formula [n ! / ( n – r ) ! r !] 
                System.out.print(" "+ obj.fact(i)/(obj.fact(i - j)*obj.fact(j)));
            }
            System.out.println();//for changing line;
        }
        sc.close();
    }//end of main
}// end of class
/*
Sample Input & Output
The first & only line of input denotes an integer representing the no of lines
INPUT : 
5
OUTPUT :
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1
  1 5 10 10 5 1
--------------------
Time Complexity :
T(n) = O(N^2), two nested loops.
--------------------
Space complexity:
A(n) = O(N^2), for storing each of the rows of the pascal triangle.
*/