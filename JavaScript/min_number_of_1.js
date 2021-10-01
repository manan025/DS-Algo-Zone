/*
JS PROGRAM TO FIND THE ROWS WITH MINIMUMM NUMBER OF 1s

INPUT FORMAT :
number of rows and number of column
||THE ARRAY ||


OUTPUT FORMAT:
ith row which has least number of 1s
the elements of row which has least number of 1s


INPUT:
5 4
1 1 1 2
1 1 5 2
0 0 1 1
1 1 2 2
1 0 1 1

OUTPUT:
2 row:
1 1 5 2
------------
3 row:
0 0 1 1
------------
4 row:
1 1 2 2
------------


Time complexity : O(N^2);
Space complexity : O(N^2);



*/

findMinNumberOfOnes = (numOfRows, numOfCols, array) => {

  let row = new Array(numOfRows).fill(0); // an array for number of 1s in each row

  for (let i = 0; i < numOfRows; i++) {
    for (let j = 0; j < numOfCols; j++) {
      if (array[i][j] == 1) {
        row[i]++;
      }
    }
  }

  let min_1s_in_row = row[0];

  for (let i = 0; i < numOfRows; i++) {
    min_1s_in_row = Math.min(min_1s_in_row, row[i]);
  } // variable min_is_in_row contains the least number of 1s present in a row

  for (let i = 0; i < numOfRows; i++) {

    if (min_1s_in_row == row[i]) { // print the number and elements of row which has least number of 1s
      console.log(i + 1 + " row:");
      for (let j = 0; j < numOfCols; j++) {
        console.log(array[i][j] + " ");
      }
      console.log("------");
    }
  }

};

// SAMPLE INPUTS

const rows = 5;
const cols = 4;
const array = [[1, 1, 1, 2], [1, 1, 5, 2], [0, 0, 1, 1], [1, 1, 2, 2], [1, 0, 1, 1]];

findMinNumberOfOnes(rows, cols, array);


