import java.util.*

/**
 * Stack Implementation which supports fixed-size or dynamic
 * Operations && Time Complexities:
 *    Push - O(1) -- adds new element to the stack
 *    Pop - O(1)  -- removes the top element from the stack and returns the removed element,
 *    isEmpty - O(1) -- returns true if stack is empty
 *    peek - O(1) -- returns top element of the stack
 *    print - O(size) -- prints elements present in the stack
 */
class Stack(private val size: Int = 0) {
    private var maxStackSize = if (size > 0) size else 65536 // 2 ^ 16 = 65536 is chosen to save memory.
    private var array = IntArray(maxStackSize)
    private var stackPointer = -1;
    fun push(value: Int) {
        if (++stackPointer == maxStackSize) {
            stackPointer -= 1
            println("Max $size Limit Reached ..OVERFLOW");
            return;
        }
        array[stackPointer] = value
    }

    fun peek(): Int {
        if (stackPointer < 0) {
            println("No Element present in stack")
            return -1;
        }
        return array[stackPointer]
    }

    fun pop(): Int {
        if (stackPointer < 0) {
            println("No Element present in stack..UNDERFLOW")
            return -1;
        }
        println("${array[stackPointer]} is popped.")
        return array[stackPointer--];
    }

    fun print() {
        for (index in stackPointer downTo 0) {
            print("${array[index]} ")
        }
        println()
    }

    fun isEmpty(): Boolean {
        return stackPointer == -1;
    }
}

/**
Example:
Enter size for fixed size stack or click enter for dynamic stack
5
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
1
Enter element to be pushed
1
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
1
Enter element to be pushed
2
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
1
Enter element to be pushed
3
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
1
Enter element to be pushed
4
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
1
Enter element to be pushed
5
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
1
Enter element to be pushed
6
Max 5 Limit Reached ..OVERFLOW
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
3
Element at the top of the stack is 5
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
4
5 4 3 2 1
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
5
false
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
2
5 is popped.
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
2
4 is popped.
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
3
Element at the top of the stack is 3
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
5
false
Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6
Enter your choice =
6
 **/
fun main() {
    val scanner = Scanner(System.`in`);
    println("Enter size for fixed size stack or click enter for dynamic stack");
    val size: Int = readLine()?.toIntOrNull() ?: 0;
    val stack = Stack(size)
    while (true) {
        println("Stack Operations : Push = 1  Pop = 2  Peek = 3  Print = 4  isEmpty = 5 End = 6");
        println("Enter your choice = ");
        when (scanner.nextInt()) {
            1 -> {
                println("Enter element to be pushed")
                stack.push(scanner.nextInt())
            }
            2 -> {
                stack.pop()
            }
            3 -> {
                println(stack.peek())
            }
            4 -> {
                stack.print()
            }
            5 -> {
                println(stack.isEmpty())
            }
            6 -> {
                break;
            }
        }
    }
}
