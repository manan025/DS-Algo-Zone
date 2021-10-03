package main

import "fmt"

func insertioSort(arr []int) []int {
	for i := 1; i < len(arr); i++ {
		j := i
		for j > 0 {
			if arr[j-1] > arr[j] {
				arr[j-1], arr[j] = arr[j], arr[j-1]
			}
			j = j - 1
		}
	}
	return arr
}
func main() {
	items := []int{45, 100, 1, 20, 31, 63, 70, 2, 9}
	fmt.Println(insertioSort(items))
}
