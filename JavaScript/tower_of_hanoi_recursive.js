// Tower of Hanoi - Recursive Solution

// Problem Statement :
// The Towers of Hanoi has 3 pegs with multiple disks of different sizes.
// The goal of the puzzle is to move all the disks from the first peg to the third peg according to the following rules :
// Only one disk can be moved at a time.
// You can only move the top disc in a stack.
// No disk may be placed on top of a smaller disk.

// Javascript Code :

function towerOfHanoi(disksnumber, startpeg, endpeg, middlepeg) {
  if (disksnumber >= 1) {

    // Move a tower of disksnumber-1 to the middle peg, using the end peg.
    towerOfHanoi(disksnumber - 1, startpeg, middlepeg, endpeg);

    // Move the remaining disks to the end peg.
    console.log('Move disk from Tower ', startpeg, ' to Tower ', endpeg);

    // Move the tower of `disksnumber-1` from the `middle peg` to the `end peg` using the `start peg`.        
    towerOfHanoi(disksnumber - 1, middlepeg, endpeg, startpeg);
  }
  
  return;
}

towerOfHanoi(3, "A", "C", "B");


/*
---Details---

---Sample Inputs and Outputs---

No input required.
Output:
Move disk from Tower  A  to Tower  C
Move disk from Tower  A  to Tower  B
Move disk from Tower  C  to Tower  B
Move disk from Tower  A  to Tower  C
Move disk from Tower  B  to Tower  A
Move disk from Tower  B  to Tower  C
Move disk from Tower  A  to Tower  C

---Time Complexity---
Time Complexity is O(n^2)

---Space Complexity---
Space Complexity is O(n)
*/