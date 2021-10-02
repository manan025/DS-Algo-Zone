import java.util.*

/*
Sample Input & Output :
---------------------
The first line of the input contains an integer 'n' denoting the size of the array
The second line of the input contains 'n' no integers
SAMPLE INPUT & OUTPUT 1
INPUT :
4
98 76 54 32
OUTPUT :
32 54 76 98
SAMPLE INPUT & OUTPUT 2
INPUT :
5
45 45 23 65 12
OUTPUT:
12 23 45 45 65
------------------------
Time Complexity :
Best Case Complexity - O(n*logn)
Worst Case Complexity - O(n2)
------------------------
Space Complexity :
The space complexity of quicksort is O(n*logn)
*/
class QuickSort(private val array: IntArray) {
    private fun partition(start: Int, end: Int): Int {
        val pivot: Int = array[end] // pivot is the last element
        var i = start - 1;
        /**
         * At start of each iteration, array will satisfy following
         *  elements less than or equal to pivot are between start index and ith index
         *  elements greater than pivot are between (i + 1)th index and (j - 1)th index
         */
        for (j in start until end) {
            if (array[j] <= pivot) {
                i += 1
                swap(i, j)
            }
        }
        swap(i + 1, end); // After this swap pivot will get to its sorted position
        return i + 1;
    }

    private fun swap(index1: Int, index2: Int) {
        array[index1] = array[index2].also { array[index2] = array[index1] }
    }

    fun sort(start: Int, end: Int) {
        if (start < end) {
            val partitionIndex = partition(start, end);
            sort(start, partitionIndex - 1)
            sort(partitionIndex + 1, end)
        }
    }

    fun printElements() {
        println(array.joinToString(" "))
    }
}

fun main() {
    val scanner = Scanner(System.`in`)
    val noOfElements = scanner.nextInt()
    val array = IntArray(noOfElements)
    readInputArray(array, scanner)
    val quickSort = QuickSort(array)
    quickSort.sort(0, array.size - 1)
    quickSort.printElements()
}

fun readInputArray(array: IntArray, scanner: Scanner) {
    for (i in array.indices) {
        array[i] = scanner.nextInt()
    }
}
