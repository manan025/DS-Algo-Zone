fun main(args: Array<String>) {
    //Input the array in the format num1 num2 num3 num4 etc
    print("Enter the elements for the Array: ")
    var inputArray = readLine()!!.trim().split(" ").map { it -> it.toInt() }.toIntArray()

    var sortedArray = selectionSort(inputArray)
    println(sortedArray.contentToString())
}

fun selectionSort(arr: IntArray): IntArray {
    for (i in arr.lastIndex downTo 0) {
        var max = arr[0]
        var maxIndex = 0
        for (j in 0..i) {
            if (arr[maxIndex]<arr[j])
                maxIndex = j
        }
        val temp = arr[maxIndex]
        arr[maxIndex] = arr[i]
        arr[i] = temp
    }
    return arr
}

//Sample
//Input:   Enter the elements for the Array: 64 23 -12 -5 0 2 89 20 100 32 650 -230 130
//Output:   [-230, -12, -5, 0, 2, 20, 23, 32, 64, 89, 100, 130, 650]

//Time Complexity:  Worst Case: O(n^2)   Best Case: O(n^2)
//Space Complexity: O(1)
