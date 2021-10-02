package main
import (
    "fmt"
     "os"
    "strconv"
)

func towerOfHanoi(n int, a, b, c string){
    if n == 1{
        fmt.Printf("move from %s to %s\n", a, c)
        return
    }

    towerOfHanoi(n-1, a, c, b)
    fmt.Printf("move from %s to %s\n", a,c)
    towerOfHanoi(n-1, b, a, c)
}

func main(){
    var n int = 3
    var err error
    if len(os.Args) == 2{
        n, err = strconv.Atoi(os.Args[1])
        if err != nil {
            fmt.Printf("%s\n", err.Error())
            os.Exit(-1)
        }
    }

    towerOfHanoi(n, "A", "B", "C")
}

// Sample Input 
// 	3, A, B, C
// Sample Output
// move from A to C
// move from A to B
// move from C to B
// move from A to C
// move from B to A
// move from B to C
// move from A to C

// Time Complexity - O(2^n)
// Space Complexity - O(n)

