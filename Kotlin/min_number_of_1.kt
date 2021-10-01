import java.lang.Integer.min
import java.util.*

/*
KOTLIN PROGRAM TO FIND THE ROWS WITH MINIMUM NUMBER OF 1s
INPUT FORMAT :
number of rows and number of column
||THE ARRAY ||
OUTPUT FORMAT:
ith row which has the least number of 1s
the elements of row which has the least number of 1s
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
3 row:
0 0 1 1
4 row:
1 1 2 2
Time complexity : O(N^2);
Space complexity : O(N^2);
*/
fun main() {
    val scanner = Scanner(System.`in`)
    val noOfRows: Int = scanner.nextInt()
    val noOfColumns: Int = scanner.nextInt()
    val array = Array(noOfRows) { IntArray(noOfColumns) }
    val noOf1sPerRow = IntArray(noOfRows) { 0 }
    readInputArray(array, noOfRows, noOfColumns)
    val minNoOf1s = findMin1s(array, noOfRows, noOf1sPerRow)
    printRowsWithMin1s(array, minNoOf1s, noOf1sPerRow)
}

fun readInputArray(array: Array<IntArray>, noOfRows: Int, noOfColumns: Int) {
    val scanner = Scanner(System.`in`)
    for (rowIndex in 0 until noOfRows) {
        for (columnIndex in 0 until noOfColumns) {
            array[rowIndex][columnIndex] = scanner.nextInt()
        }
    }
}

fun findMin1s(array: Array<IntArray>, noOfRows: Int, noOf1sPerRow: IntArray): Int {
    var minNoOf1s = Int.MAX_VALUE;
    for (i in 0 until noOfRows) {
        noOf1sPerRow[i] = array[i].fold(0) { prev, curr -> prev + (if (curr == 1) 1 else 0) }
        minNoOf1s = min(minNoOf1s, noOf1sPerRow[i])
    }
    return minNoOf1s;
}

fun printRowsWithMin1s(array: Array<IntArray>, minNoOf1s: Int, noOf1sPerRow: IntArray) {
    for (i in array.indices) {
        if (minNoOf1s == noOf1sPerRow[i]) {
            println("${i + 1} row:")
            println(array[i].joinToString(" "))
        }
    }
}