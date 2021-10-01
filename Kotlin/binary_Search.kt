package com.company

fun main(args: Array<String>) {
    // please pass sorted array in input always because binary search will always run in sorted array

    val i = readLine()!!.trim().split(" ").map { it -> it.toInt() }.toIntArray()
    val key = readLine()!!.trim().toInt()
    val ans = binarySearch(i, key)
    if(ans >= 0 ) {
        println(ans)
    } else {
        println("Position not found")
    }
}

fun binarySearch(input: IntArray, key: Int) : Int{
    var i = 0
    var j = input.size
    var mid : Int
    while(i < j) {
        mid = (i +j) / 2
        when {
            key == input[mid] -> return mid
            key >input[mid]   -> i = mid+1
            key < input[mid]  -> j = mid-1;
        }
    }
    return -1
}

// sample input 1 :
// 1, 2, 3, 4, 5, 6
// 3
// output : 2

// sample input 2 :
// 4 5 2 3 6
// 3
// output : position not found

// Time Complexity = O(log(n)) for worst case and would be O(1) in best case
// space complexity = O(1)
