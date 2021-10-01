// Function which sorts the given array (Selection sort)
function selectionSort(arr) {
    let lastIndex, maxIndex, temp;
    for (let i = 0; i < arr.length; i++) {
        lastIndex = arr.length - i - 1;  // Stores the last index element for a particular iteration
        maxIndex = 0;  // Stores the index of the largest element
        for (let j = 1; j < arr.length - i; j++) {  
            if (arr[j] > arr[maxIndex]) {  // If current element is greater than element at maxIndex position,
                maxIndex = j;              // then maxIndex = current index (j)
            }
        }
        // Swap largest element (of the particular iteration) 
        // with element at last index (of the particular iteration)
        temp = arr[maxIndex];  
        arr[maxIndex] = arr[lastIndex];
        arr[lastIndex] = temp;
    }
}

function main() {
    // Creating an unsorted array
    let arr = [10, -12, 57, 13, 41, -98];
    console.log("Entered array (unsorted) is:-");
    console.log("[" + arr.join(", ") + "]\n");
    selectionSort(arr);
    console.log("Displaying sorted array:-");
    // Displaying sorted array with proper formatting
    console.log("[" + arr.join(", ") + "]");
}

main();

/*
---Details---
Selection Sort Algorithm in JavaScript
Input: Unsorted array of integers
Output: Sorted array in ascending order

---Sample Inputs and Outputs---

---Sample Input - 1
Input array: [10, -12, 57, 13, 41, -98]
Output:- 
Entered array (unsorted) is:-
[10, -12, 57, 13, 41, -98]

Displaying sorted array:-
[-98, -12, 10, 13, 41, 57]

---Sample Input - 2
Input array: [19, -19, 0, 13, 51, 2, 76, 134, 12]
Output:- 
Entered array (unsorted) is:-
[19, -19, 0, 13, 51, 2, 76, 134, 12]

Displaying sorted array:-
[-19, 0, 2, 12, 13, 19, 51, 76, 134]

---Time Complexity---
Average Case, Best Case and Worst Case all are O(n^2)

---Space Complexity---
Space Complexity is O(1)
*/
