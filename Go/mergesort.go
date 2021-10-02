package main

import (
  "fmt"
)

func mergeSort(leftList []int, rightList []int) ([]int) {
	var finalList []int
  
	for len(leftList) > 0 && len(rightList) > 0 {
	  if leftList[0] <= rightList[0] {
		finalList = append(finalList, leftList[0])
		leftList = leftList[1:]
	  } else {
		  finalList = append(finalList, rightList[0])
		  rightList = rightList[1:]
	  }
	}
	//For elements left in right or left list.
	for len(leftList) > 0 {
	  finalList = append(finalList, leftList[0])
	  leftList = leftList[1:]
	}
	for len(rightList) > 0 {
	  finalList = append(finalList, rightList[0])
	  rightList = rightList[1:]
	}
  
	return finalList
  }

func merge(listOfNumbers []int) ([]int) {
 // If list size is less than 1 or 0 then return the same array.
  if len(listOfNumbers) <= 1 {
    return listOfNumbers
  }
  // Dividing the List to two equal halves.
  midTerm := len(listOfNumbers) / 2

  //Sorting the splitted lists of the original list.
  leftList := merge(listOfNumbers[:midTerm])
  rightList := merge(listOfNumbers[midTerm:])
  // Merging  the sorted sublists.
  return mergeSort(leftList, rightList)
}

func main() {
	array := []int{10,28,2,3,78,90,65,32,9,5,7,2}
  
	array = merge(array)
	fmt.Println("Sorted Array : ")
	fmt.Println(array)
  }


//Time complexity : O(nLogn)
//Space complexity: O(n) 