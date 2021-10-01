import java.util.Scanner;

public class TowerOfHanoi {
    public static void towerOfHanoi(int disks, char originRod, char destinyRod, char auxRod) {
        if (disks == 1) {
            // Base condition, when only one disk is left, we can freely move it to the destiny rod
            System.out.println("Move disk #1 from "
                    + originRod + " to " + destinyRod);
        } else {
            // If more than one disk remains, we divide the tower into smaller numbers of disks until one disk is left
            // First, we want to move all the disks from our origin to our aux rod
            towerOfHanoi(disks - 1, originRod, auxRod, destinyRod);
            // Then, we move the top disk of our origin rod to our destiny rod
            System.out.println("Move disk #" + disks + " from "
                    + originRod + " to " + destinyRod);
            // Finally we want tp move all disks from the aux rod to our destiny rod
            towerOfHanoi(disks - 1, auxRod, destinyRod, originRod);
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        int n = s.nextInt();
        towerOfHanoi(n, 'A', 'C', 'B');
    }
}

/*
Example with 3 disks:

Input n = 3

Output:
Move disk #1 from A to C
Move disk #2 from A to B
Move disk #1 from C to B
Move disk #3 from A to C
Move disk #1 from B to A
Move disk #2 from B to C
Move disk #1 from A to C

TIME COMPLEXITY: O(a^n)
SPACE COMPLEXITY: O(n)

*/
