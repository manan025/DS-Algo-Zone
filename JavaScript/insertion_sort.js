// insertion sort function
function insertionSort(a) {
	for (let i = 1; i < a.length; i++) {
		let j = i - 1;
		let ele = a[i];
		while (j >= 0 && a[j] > ele) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = ele;
	}
}

// function to display the array
function displayArr(a) {
	for (let i = 0; i < a.length; i++) {
		console.log(a[i], ' ');
	}
	console.log('\n');
}

function main() {
	var a = [6, 4, 2, 1, 78, 23];
	var n = a.length;

	var flag = 0;
	for (let i = 0; i < n - 1; ++i) {
		if (a[i + 1] < a[i]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		console.log('\nSorted Array: ');
		insertionSort(a);
	} else {
		console.log('\nData is already sorted: ');
	}

	// Display the Final Array
	displayArr(a);
}

main();

// Insertion Sort implementation in Javascript
// Input: Array of integers
// Output: Sorted array in ascending order
// ----------------------------------------
// Sample Input 1:
// 6
// [6, 4, 2, 1, 78, 23]
// Output:
//  Sorted Array:
//  1
//  2
//  4
//  6
//  23
//  78

// Sample Input 2:
// 5
// [34, 56, 78, 98, 99]
// Output:
//  Data is already sorted:
//  34
//  56
//  78
//  98
//  99

// ----------------------------------------
// Time Complexity:
// Worst and Average case = O(n^2)
// Best case (when array is already sorted) = O(n)
// Space Complexity: O(1)
