#include<stdio.h>
#include<string.h>
#include<limits.h>
#define MAX 1000000
int checkPalindromeString(char *str){
    /*
        * This function is used to determine whether the string is palindrome or not

        * The main idea is to use two pointer approach where one points to the first element(left pointer) of the string
        and one points to the last(right pointer)

        * If the value at both the pointer is same, Move the left pointer one step forward and move the right pointer one step back
        and repeat the above step till you reach the middle index.

        * If the value is not equal, simply break the loop and conclude that it is not palindrome.
    */
    int i,j,len=strlen(str);
    for(i=0,j=len-1;i<j;i++,j--){
        if(str[i]!=str[j]){
            return 0;
        }
    }
    return 1;
}
int main(){
    // Getting a string input from the user.
    char str[MAX];
    scanf("%s",str);
    // Applying checkPalindromeString function for the input string
    int answer = checkPalindromeString(str);

    /*
        If the function returns 1 ----> Palindrome String
        else                      ----> Not a Palindrome String
    */

    if(answer){
        printf("%s is a palindrome string",str);
        return 0;
    }
   printf("%s is not a palindrome string",str);
}

/*
    Check Palindrome in C

    Input : A valid string to check whether it is palindrome or not
    Output : Returns a statement whether the string is palindrome or not

    ----------------------------------------------------------------------

    Sample Input 1 :
    programming
    Sample Output 1 :
    programming is not a palindrome string

    Sample Input 2 :
    malayalam
    Sample Output 2 :
    malayalam is a palindrome string

    Sample Input 3 :
    a
    Sample Output 3 :
    a is a palindrome string

    Sample Input 4 :
    abcba
    Sample Output 4 :
    abcba is a palindrome string

    -----------------------------------------------------------------------

    Time Complexity : O(length of string)
    Space Complexity : O(1)
    

*/
