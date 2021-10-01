

//function which returns the position of the element from an array
function binary_search(sortedArray, key) {
  //if the value is not present it simply returns -1
  let start = 0;
  let end = sortedArray.length - 1;

  while (start <= end) {
    let middle = Math.floor((start + end) / 2);

    if (sortedArray[middle] === key) {
      // found the key
      return middle;
    } else if (sortedArray[middle] < key) {
      // continue searching to the right
      start = middle + 1;
    } else {
      // search searching to the left
      end = middle - 1;
    }
  }
  // At each run of this while loop we reduce the size of the array to be searched by 2.

  return -1;
}

function main() {
  // We can only apply binary search if array is sorted so the input array must be sorted
  const arr = [2, 3, 14, 54, 63, 78];

  // Element to be searched in the array
  const key = 14;

  const pos = binary_search(arr, key);
  if (pos !== -1) {
    console.log("Element found in position", pos);
  } else {
    console.log("Element not found in array");
  }
  return 0;
}

main();

/*
Input: Sorted array of numbers and the number we are searching
Output: Returns position of the element if it's present if not -1

----------------------------------------
Sample Input:
[-5, 0, 6, 7, 8, 19]
6
Output:
Element found in position 3

Sample Input:
[-5, 0, 6, 7, 8, 19]
4
Output:
Element not found in array

----------------------------------------

Time Complexity:
Worst and Average case = O(logn)
Best case = O(1)

Space Complexity: O(1)
*/