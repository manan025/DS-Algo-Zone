//function which returns the position of the element from an array
function linearSearch(array, key) {
  const n = array.length;

  // Create a variable found which says whether the key is found or not.
  let found = false;
  let keyIndex = 0;

  // Traverse the array
  for (let i = 0; i < n; ++i) {
    // Check if the i'th element of the array is equal to key(both the value and the type).
    if (array[i] === key) {
      // If yes, make found = True and update the key index and break
      found = true;
      keyIndex = i;
      break;
    }
  }
  // Check whether the key is found or not and return accordingly
  if (found) return keyIndex;
  else return -1;
}

function main() {
  // Linear Search can be applied to any array(both sorted and unsorted)
  const arr = [12, 45, 78, 12, 456, 34, 76, 78, 89, 100];

  // Element to be searched in the array
  const key = 76;

  const pos = linearSearch(arr, key);

  // Check whether the element is present in the array or not with the help of pos variable
  if (pos !== -1) console.log("Element found at position", pos);
  else console.log("Element not found in array.");
}

main();

/*
Input: An array of numbers and the number we are searching
Output: Returns position of the element if it's present if not -1

----------------------------------------
Sample Input:
[12, 45, 78, 12, 456, 34, 76, 78, 89, 100]
key = 76
Output: 
Element found in position 6

Sample Input:
[12, 45, 78, 12, 456, 34, 76, 78, 89, 100]
key = 32
Output:
Element not found in array

----------------------------------------

Time Complexity:
Worst and Average case = O(n)
Best case = O(1)

Space Complexity: O(1)
*/
