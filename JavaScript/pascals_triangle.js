// Helper function to format and print the matrix in a friendly way
function printMatrix(matrix) {
  for (let i = 0; i < matrix.length; i++) {
    console.log(`[ ${matrix[i].join(' | ')} ]`);
  }
}

// Function to calculate and return pascal's triangle with given rows
function pascalsTriangle(rows) {
  let pascal = [];
  for (let i = 0; i < rows; i++) {
    let currentRow = [];
    for (let j = 0; j <= i; j++) {
      if (j === 0 || j === i) {
        // The first and last column of each row is always 1
        currentRow.push(1);
      } else {
        // The middle columns are the sum of elements of the previous row
        // The elements of the previous row (i-1) that are added are the current column (j) and the previous column (j-1)
        let temp = pascal[i - 1][j - 1] + pascal[i - 1][j];
        currentRow.push(temp);
      }
    }
    pascal.push(currentRow);
  }
  return pascal;
}

let pascal = pascalsTriangle(4);
printMatrix(pascal);

/*
Example 1:

Input
rows = 4

Output
[ 1 ]
[ 1 | 1 ]
[ 1 | 2 | 1 ]
[ 1 | 3 | 3 | 1 ]

Example 2:

Input
rows = 6

Output
[ 1 ]
[ 1 | 1 ]
[ 1 | 2 | 1 ]
[ 1 | 3 | 3 | 1 ]
[ 1 | 4 | 6 | 4 | 1 ]
[ 1 | 5 | 10 | 10 | 5 | 1 ]

TIME COMPLEXITY: O(n^2)
SPACE COMPLEXITY: O(n^2)

*/