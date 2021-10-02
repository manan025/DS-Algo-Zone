fun main(args: Array<String>) {
    //Input the array in the format num1 num2 num3 num4 etc
    print("Enter the elements for the Array: ")
    var inputArray = readLine()!!.trim().split(" ").map { it -> it.toInt() }.toIntArray()

    var sortedArray = insertionSort(inputArray)
    println(sortedArray.contentToString())
}

fun insertionSort(arr: IntArray): IntArray {
    for (i in 0 until arr.lastIndex) {
        for (j in i+1 downTo 1) {
            if(arr[j]<arr[j-1]) {
                var temp = arr[j - 1]
                arr[j - 1] = arr[j]
                arr[j] = temp
            }
            else
                break
        }
    }
    return arr
}


//Sample
//Input:   Enter the elements for the Array: 5 0 -23 -2 15 1 62
//Output:   [-23, -2, 0, 1, 5, 15, 62]

//Time Complexity:  Worst Case: O(n^2)   Best Case: O(n)
//Space Complexity: O(1)
