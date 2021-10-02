fun main(args: Array<String>) {
    //Input the array in the format num1 num2 num3 num4 etc
    print("Enter the elements for the Array: ")
    var inputArray = readLine()!!.trim().split(" ").map { it -> it.toInt() }.toIntArray()

    var sortedArray = bubbleSort(inputArray)
    println(sortedArray.contentToString())
}

fun bubbleSort(arr: IntArray): IntArray {
    var swapped = false
    for (i in arr.lastIndex - 1 downTo 1) {
        for (j in 0..i) {
            if (arr[j] > arr[j + 1]) {
                val temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                swapped = true
            }
        }
        if (!swapped)
            break;
    }
    return arr
}

//Sample
//Input: Enter the elements for the Array: 2 6 10 54 21 62 3
//Output: [2, 3, 6, 10, 21, 54, 62]

//Time Complexity:  Worst Case: O(n^2)   Best Case: O(n)
//Space Complexity: O(1)
