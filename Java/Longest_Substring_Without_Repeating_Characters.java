import java.util.*;

public class Longest_Substring_Without_Repeating_Characters {
  
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine().trim(); //input String
        System.out.println(lengthOfLongestSubstringWithoutRepeatingChars(input));
    }
    
    //We will use sliding window technique to keep track the substring without any repeated characters. Whenever we see repetition,
    //we remove the window till the repeated string.
    public static int lengthOfLongestSubstringWithoutRepeatingChars(String s) {
        int[] arr = new int[300]; //stores the last encountered index of character
        Arrays.fill(arr, -1);
      
        int start = 0; //To keep track of the starting position of the sliding window
        int end = 0;  //To keep track of the ending position of the sliding window
        int max = 0; //For determining the length of the longest substring
        char[] ch = s.toCharArray();
      
        while (end < ch.length) {
            if (arr[ch[end]] != -1) {  //this means character is repeated
                while (ch[start] != ch[end])
                    arr[ch[start++]] = -1; //remove all the characters from the start until you find the repeated character
                start++;  
            } 
                
            arr[ch[end]] = end;  //update the value in arr
            max = Math.max(max, end - start + 1);
            end++;
        }
        return max;
    }

}

//TIME COMPLEXITY - O(n)
//SPACE COMPLEXITY - O(n)


/**

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0

**/
