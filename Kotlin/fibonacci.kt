import java.util.*

/*
    Please enter the Length of the Fibonacci Series: 10
    0 1 1 2 3 5 8 13 21 34

    Please enter the Length of the Fibonacci Series: 15
    0 1 1 2 3 5 8 13 21 34 55 89 144 233 377

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

fun main(args: Array<String>) {

    print("Enter the length of the Fibonacci Series: ")

    val sc = Scanner(System.`in`)
    val number = sc.nextInt()

    fibonacci(0, 1, 1, number)

    sc.close()
}

/*
    Receives a integer and print the fibonacci series
 */
fun fibonacci(firstNumber: Int, secondNumber: Int, counter: Int, number: Int) {

    print(firstNumber)
    print(" ")

    if (counter < number) {
        fibonacci(secondNumber, firstNumber + secondNumber, counter + 1, number)
    }
}
