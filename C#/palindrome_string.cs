using System;

public class PalindromeString
{
    public static void Main()
    {
        string s=Console.ReadLine();
        char[] rev=s.ToCharArray();
        Array.Reverse(rev);
        string revs=new string(rev);
        if (s.Equals(revs))
            Console.WriteLine("Palindrome");
        else
            Console.WriteLine("Not Palindrome");
    }

}

/* SAMPLE INPUT

 RIVER
 Not Palindrome

 MADAM
 Palindrome

*/