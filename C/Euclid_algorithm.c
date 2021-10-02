/*
    *Problem ->
        To find Greatest Common Divisor (GCD) of two numbers.
    * Input ->
        a = 4, b= 6;
    *Output ->
            2
    * Input ->
        a = 100, b= 200;
    *Output ->
            100
*/

/* Solution Idea :
        The basic idea is if we have 2 numbers we can with the min one
        because the gcd is not greater than min one.
 */
    // Euclidean Algorithm
    #include <stdio.h>
    // C function for extended Euclidean Algorithm
      /**
        * Efficient Approach (Euclid's Algorithm)
        Time complexity - O(log(min(a,b)));
        Aux Space - O(1)
    */  
    int gcdExtended(int a, int b, int *x, int *y){
        // Base Case
        if (a == 0){
            *x = 0;
            *y = 1;
            return b;
        }
        int x1, y1; // To store results of recursive call
        int gcd = gcdExtended(b%a, a, &x1, &y1);
        // Update x and y using results of recursive
        // call
        *x = y1 - (b/a) * x1;
        *y = x1;
        return gcd;
    }
    /**
        * Efficient Approach (Euclid's Algorithm) Using recursion
        Time complexity - O(log(min(a,b)));
        Aux Space - O(1)
    */   
    // Function to return gcd of a and b
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b%a, a);
    }
    int main(){
         int x, y;
        int c = 35, d = 15;
        int g = gcdExtended(c, d, &x, &y);
        printf("gcd(%d, %d) = %d\n", c, d, g);
        int a = 10, b = 15;
        printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
        a = 35, b = 10;
        printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
        a = 31, b = 2;
        printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
        return 0;
    }


   





 
  