import java.util.Scanner

fun linearSearch(arr: Array<Int>, key: Int): Int {
    for (i in arr.indices)
    {
        if (arr[i] == key) {
            return i
        }
    }
    return -1
}
 
fun main() {
    val input = Scanner(System.`in`)
    
    val arr = arrayOf(1, 2, 3, 4, 5)
    val key = input.nextInt();
     
    val index = linearSearch(arr, key)
    
    if(index == -1 ){
        print("The Number Not Found")
    }
    else {
        print("The Number found at position : ${index}")
    }
}

/*

Sample Array : 1 2 3 4 5 

case : 1

stdin:5
The Number found at position : 4

case : 2

stdin:1
The Number found at position : 0

case : 3

stdin:9
The Number Not Found

Space Complexity : O(1)

Best Case Complexity : O(1)
Worst Case Complexity : O(n)
*/
