import java.util.Scanner;

class Main
{
    static long binpow(long base, long power, long MOD)
    {
        long result = 1;
        
        /* Algorithm to calculate (base ^ power), Time Complexity : O(log (power)), Space Complexity : O(1)*/
        while(power != 0)
        {
            if(power % 2 == 0) // means power is even
            {
                base = base * base;
                base %= MOD; // to avoid overflow in case of large base, power
                power /= 2; 
             }
                
            else // if the power is odd, 2 ^ 3 = 2 * (2 ^ 2)
            {
                result = result * base; // storing the result of (base ^ power)
                result %= MOD; // to avoid overflow in case of large base, power
                power--; // as we have given one to result, to make power even (in above example 2 given to result)
            }
        }
            
        return result % MOD;
    }
    
    public static void main (String[] args) 
    {
        long base, power, MOD = 1000000007, t;
        Scanner sc = new Scanner(System.in);
        
        // System.out.println("Enter number of testcases : ");
        t = sc.nextInt();
        
        while(t != 0)
        {
            // System.out.println("Enter base and power : ");
            
            base = sc.nextInt(); 
            power = sc.nextInt();
            
            System.out.println(binpow(base, power, MOD));
            t--;
        }
        
        sc.close();
    }
}

/* Testcases : 

Input : 
3
3 4
2 8
123 123

Output : 
81
256
921450052 

Time Complexity : O(log (power))
Space COmplexity : O(1) */