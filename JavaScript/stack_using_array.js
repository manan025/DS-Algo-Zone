/**
 * @description stack implementation using array 
 * @author prasanna kale 
 * @language Javascript 
 */


/**
 * @class Stack
 */
class Stack{

    constructor() {
        this.stack = []
        this.top = -1
    }

    // push data onto the stack
    push(data){
        this.stack.push(data)
        this.top++
    }

    // pop data from the top of stack
    pop(){

        // Underflow condition
        if (this.top == -1) {
            return -1
        }
        let data = this.stack.pop()
        this.top--
        return data
    }
    
    // check value on the top of stack
    peek(){
        if (this.top == -1) {
            return -1
        }
        let data = this.stack[this.top]
        return data
    }
}


/**
 * @example
 */

let myStack = new Stack()
myStack.push(1)
myStack.push(2)
myStack.push(3)

console.log(myStack.pop())
console.log(myStack.pop())
console.log(myStack.pop())
console.log(myStack.pop())

/**
 * @Output
 * 3
 * 2
 * 1
 * -1  // underflow condition
 */


/**
 * @Complexity analysis
 * Time-complexity = O(1)
 * Space-complexity = O(n)
 */