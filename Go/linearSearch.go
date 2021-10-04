//Linear Search
/*
Example 1:
Input:9
Output:2

Example 2:
Input:1100
Output:-1

Example 3:
Input:1100
Output:7

*/

/*
Time Complexity of Linear Search is O(n) where n is length of array.
Space Complexity of Linear Search is O(1).

*/
package main

import "fmt"

// function linearSearch return posstion of the element if present otherwise returns -1.
func linearSearch(array []int, num int) int {
	for i := 0; i < len(array); i++ {
		if array[i] == num {

			return i
		}
	}
	return -1
}

func main() {
	items := []int{45, 100, 9, 1, 2, 20, 31, 63, 70}
	ans := linearSearch(items, 9)
	//ans := linearSearch(items, 1110)
	if ans == -1 {
		fmt.Println("Number is not present in array")
	} else {
		fmt.Printf("Number is present at the location :%d", ans)
	}
}
