import java.util.*;
public class SumAndProductOfNumber {
    public static void main(String args[]) {
    Scanner sc= new Scanner(System.in);  
    System.out.print("Enter a number: ");  
    int n=sc.nextInt(); 
    int sum = 0;
    int prod = 1;
    int digit = 0;
    while(n > 0)
    {
        digit = n % 10;
        sum = sum + digit;
        prod = prod * digit;
        n = n / 10;
    }
    System.out.println("sum of Digits of is: " + sum); 
    System.out.println("Product of Digits of is: " + prod);
   
    }
}