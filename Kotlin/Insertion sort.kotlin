fun insertionSort(arr: IntArray) {

    val lastIndex: Int = arr.size - 1

    // Un-sorted array from position 1 to size -1
    for (i in 1..lastIndex) {

        // Take the left most item in an un-sorted array to temp variable
        val temp: Int = arr[i]

        // Mark the left most position as empty or hole
        var holePosition: Int = i

        // Traverse the sorted array from right to left direction
        // Move the item from the sorted array to the empty position (i.e. holePosition) only if the temp variable is less then
        // Mark the current item's position as empty by decrementing the value by one
        while(holePosition > 0 && arr[holePosition - 1] > temp) {
            arr[holePosition] = arr[holePosition - 1]
            holePosition--
        }
        
        // Once the comparison done, move the value in temp variable to the lastly marked empty position
        arr[holePosition] = temp
    }
}

fun printArray(arr: IntArray) {

    val lastIndex: Int = arr.size - 1;

    // Loop the item and print each item in the console with white space seperated
    for (i in 0..lastIndex) {
        val num = arr[i]
            print("$num ")
    }
    println("")
}

fun main(args: Array<String>) {
    val arr: IntArray = intArrayOf(15, 3, 12, 6, -9, 9, 0);

    print("Before Sorting: ")
    printArray(arr)

    insertionSort(arr)
    print("After Sorting: ")
    printArray(arr)
}