let array = [ -2, -3, 4, -1, -2, 1, 5, -3 ]

function kadane(array) {
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
