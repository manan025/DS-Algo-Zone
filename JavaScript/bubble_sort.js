//function which returns the sorted array using bubble sort
const bubbleSort = (array) => {
  const n = array.length;
  // Traverse upto n-1 because the last element will be either the max or it will eventually get swapped.
  for (let i = 0; i < n; ++i) {
    // Traverse the array till n-1-i as all the elements after n-1-i are in the correct positions as they would have got swapped in the previous iterations
    for (let j = 0; j < n - i; ++j) {
      // Swap array[j] and array[j+1]
      if (array[j] > array[j + 1]) {
        let temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  return array;
};

const main = () => {
  // Bubble Sort can be applied to any array
  const arr = [45, 456, 12, 34, 76, 78, 89, 100];

  const sortedArr = bubbleSort(arr);

  console.log("The sorted array:", sortedArr);
};

main();

/*
Input: An array of numbers that are to be sorted
Output: Returns the sorted array

----------------------------------------
Sample Input:
[45, 12, 456, 34, 76, 78, 89, 100]
Output: 
[12, 34, 45, 76, 78, 89, 100, 456]


----------------------------------------

Time Complexity:
Worst and Average case = O(n*n) = O(n²)
Best case = O(n*n) = O(n²)

Space Complexity: O(1)
*/
