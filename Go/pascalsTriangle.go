package main

import "fmt"

func pascalsTriangle(numRows int) {
	// Iterate over lines.
	for i := 1; i < numRows+1; i++ {
		c := 1
		// Iterate over columns.
		for j := 1; j < i+1; j++ {
			fmt.Printf("%d ", c)
			// Every single element of every row is calculated by a formula of
			// Combinations which is commonly known as "n choose k".
			c = (c * (i - j) / j)
		}
		fmt.Println()
	}
}

func main() {
	numRows := 5
	pascalsTriangle(numRows)
}

/* EXAMPLE
Input: 5
Output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

/* COMPLEXITY
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
