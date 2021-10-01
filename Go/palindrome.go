//Palindrome Check
/*
Example 1:
input: madam
output:true

Example 2:
input: abbkcba
output:false

Example 3:
input: fchgatr
output:false
*/

package main

import "fmt"

func isPalindrome(str string) bool {
	for i := 0; i < len(str); i++ {
		j := len(str) - 1 - i
		if str[i] != str[j] {
			return false
		}
	}
	return true
}

func main() {
	str := ""
	fmt.Print("Enter the string : ")
	fmt.Scan(&str)
	fmt.Print(isPalindrome(str))
}

//Time complexity : O(N)
//Space complexity: O(1) 