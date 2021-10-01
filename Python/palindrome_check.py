def isPalindrome(s):
     
    
    rev = ''.join(reversed(s))
 
    if (s == rev):
        return True
    return False
 
# main function
s = "malayalam"
ans = isPalindrome(s)
 
if (ans):
    print("Yes")
else:
    print("No")

"""
Palindrome Check using Python

----------------------------------------
Input : malayalam
Output : Yes

Input : geeks
Output : No

In this method user take a character of string one by one and store in an empty variable. After storing all the character user will compare both the string and check whether it is palindrome or not. 

"""
