package main

import "fmt"

func Fibbonaci(num int) []int {
	var series []int
	if num < 0 {
		return series
	}
	n2 := 0
	n1 := 0
	total := 1

	for i := 1; i < num; i++ {
		n2 = n1
		n1 = total
		total = n2 + n1
		series = append(series, total)

	}
	return series
}

func main() {
	//ans := Fibbonaci(0)
	//ans := Fibbonaci(50)
	ans := Fibbonaci(10)
	if ans == nil {
		fmt.Println("Fibbonaci series is empty")
	} else {
		fmt.Println("Fibbonaci series is :")
		fmt.Println(ans)
	}

}
