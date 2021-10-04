import java.util.*;

public class HF {

    static void Fib(int N)
    {
        int num1 = 1, num2 = 1;
        System.out.print(num1 + " ");
        System.out.print(num2 + " ");

        while (count < N-2){
            int num3 = num2 + num1;
            num1 = num2;
            num2 = num3;            
            System.out.print(num3 + " ");
        }
    }

    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        Fib(n);
    }
}
