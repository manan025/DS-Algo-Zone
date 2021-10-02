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
import java.util.*;
public class Euclid_algorithm{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first num : ");
        int a = sc.nextInt();
        System.out.print("Enter second num : ");
        int b = sc.nextInt();

        System.out.println("GCD : ");
        System.out.println(gcdNaive(a,b));
        System.out.println(gcdEuclidBasicVersion(a,b));
        System.out.println(gcdEuclidUsingRecursion(a,b));

        sc.close();
    }
    /**
        * Naive Approach
        Time complexity - O(min(a,b));
        Aux Space - O(1)
    */
    static int gcdNaive(int a , int b){
        int res = Math.min(a,b);
        while(res>0){
            if(a%res == 0 && b%res == 0)
                break;
            res--;
        }
        return res;
    }
    /**
        * Efficient Approach (Euclid's Algorithm)
        Time complexity - O(log(min(a,b)));
        Aux Space - O(1)
    */  
    static int gcdEuclidBasicVersion(int a, int b){
        while(a != b){
            if(a>b) a = a-b;
            else b = b-a;
        }
        return a;
    } 
    /**
        * Efficient Approach (Euclid's Algorithm) Using recursion
        Time complexity - O(log(min(a,b)));
        Aux Space - O(1)
    */   
    static int gcdEuclidUsingRecursion(int a, int b){
        if(b==0) return a;
        else return gcdEuclidUsingRecursion(b, a%b);
    }



}

 
  