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

 Time Complexity: O(n) where n is the length of the string.
 Space Complexity: O(1) since we are using constant space

*/