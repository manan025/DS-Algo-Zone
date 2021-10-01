package main
import "fmt"

func isPalindrome(str string) bool {
    for i := 0; i < len(str); i++ {
        j := len(str)-1-i
        if str[i] != str[j] {
            return false   
        }
    }
    return true
}

func main() {
	str:=""
	fmt.Print("Enter the string : ")
	fmt.Scan(&str)
	fmt.Print(isPalindrome(str))
}