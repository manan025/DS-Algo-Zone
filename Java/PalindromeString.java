import java.util.*;
public class PalindromeString {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a String to check if it is palindrome: ");
        String str = in.nextLine();
        if (checkIfPalindrome(str)) {
            System.out.println(str + " is a Palindrome String");
        } else {
            System.out.println(str + " is not a Palindrome String");
        }
    }

    // Function which returns true if String is palindrome, false otherwise
    static boolean checkIfPalindrome(String str) { // Uses 2 pointer technique
        str = str.toLowerCase();
        int start = 0;  // Starting index of the String
        int end = str.length() - 1;  // Last index of the String
        while (start <= end) {
            if (str.charAt(start) != str.charAt(end)) {
                return false; // If char at nth position from start is not equal to char at nth position from end
                              // then string is not a palindrome string
            } else {  // Move to the next element in the string
                start++;
                end--;
            }
        }
        return true;
    }
}

/*
---Sample inputs & outputs---

Example - 1
Enter a String to check if it is palindrome: abcdefgh
abcdefgh is not a Palindrome String

Example - 2
Enter a String to check if it is palindrome: abcd dcba
abcd dcba is a Palindrome String

Example - 3
Enter a String to check if it is palindrome: aabaabaa
aabaabaa is a Palindrome String

Example - 4
Enter a String to check if it is palindrome: neveroddoreven
neveroddoreven is a Palindrome String

Example - 5
Enter a String to check if it is palindrome: This is clearly not palindrome
This is clearly not palindrome is not a Palindrome String

---Time Complexity---
The average, best case and worst case time complexity are O(n)

---Space Complexity---
The space complexity is O(1)
 */