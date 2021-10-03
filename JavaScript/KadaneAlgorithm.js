let array = [ -2, -3, 4, -1, -2, 1, 5, -3 ]

function kadane(array) {
	// Kadane's Algorithm is used to find the Largest Sum of a continuous sub-array in an array.
	// It works by storing 2 values: a Final Maximum & Current Maximum.
	// Final Maximum stores the overall "maximum sum" i.e. the answer.
	// Current Maximum stores the currently iterated maximum value.
	// Current Maximum starts storing the sum from each element, as long as the sum doesn't become negative; in which case it resets to 0.
	// This Current Maximum is compared with Final Maximum, and set as the new Final Maximum if Final is less than Current.
	// Time Complexity: O(n).    Space Complexity: O(1)
	// Sample I/P: [ 3, -1, 2, -4, 1].    Sample O/P: 4
	let finalMax = Number.NEGATIVE_INFINITY, currentMax = 0
	array.forEach(element => {
		currentMax += element
		finalMax = (finalMax < currentMax ? currentMax : finalMax)
		currentMax = (currentMax < 0 ? 0 : currentMax)
	})
	return finalMax
}

console.log("Given Array :", array)
console.log("Largest Sum of Contiguous Subarray :", kadane(array))
