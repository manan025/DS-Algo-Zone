let items = [ 56, 19, 47, 28, 30 ]

function swap(items, leftIndex, rightIndex) {
	// Swaps elements to their correct positions
	let temp = items[leftIndex]
	items[leftIndex] = items[rightIndex]
	items[rightIndex] = temp
}

function partition(items, left, right) {
	// partition input array with pivot as middle element and return final index of pivot
	let pivot = items[Math.floor((right + left) / 2)]			// middle element chosen as pivot
	while (left <= right) {
		while (items[left] < pivot) {
			++left
		}
		while (items[right] > pivot) {
			--right
		}
		if (left <= right) {
			swap(items, left, right)							// swapping two elements w.r.t pivot value
			++left
			--right
		}
	}
	return left
}

function quickSort(items, left, right) {
	// quicksort main function [Time complexity: O(n*log(n))]
	// Parameters: <input array>, <starting index>, <ending index>
	// Implementation:
	// let array = [ 4,1,5,3,2 ]
	// console.log(quickSort(array, 0, array.index-1))
	if (items.length > 1) {
		let index = partition(items, left, right)				// index returned from partition
		if (left < index - 1) {									// recursive call to quicksort on left partition
			quickSort(items, left, index - 1)
		}
		if (index < right) {									// recursive call to quicksort on right partition
			quickSort(items, index, right)
		}
	}
	return items
}
console.log(quickSort(items, 0, items.length - 1))				//prints [ 19, 28, 30, 47, 56 ]
