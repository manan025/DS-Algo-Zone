def tower_of_hanoi(d, src, aux, trgt):
    if(d == 1):
        print('Move disk 1 from rod {} to rod {}.'.format(src, trgt))
        return
    # Recursion
    tower_of_hanoi(d - 1, src, trgt, aux)
    print('Move disk {} from rod {} to rod {}.'.format(d, src, trgt))
    tower_of_hanoi(d - 1, aux, src, trgt)

d = int(input('Enter the number of d: '))  
# src: A, aux: B, trgt: C
tower_of_hanoi(d, 'A', 'B', 'C')

'''
Input: 3
Output: Move disk 1 from rod A to rod C.
	Move disk 2 from rod A to rod B.
	Move disk 1 from rod C to rod B.
	Move disk 3 from rod A to rod C.
	Move disk 1 from rod B to rod A.
	Move disk 2 from rod B to rod C.
	Move disk 1 from rod A to rod C.
	
Time Complexity: O(2^n)
Space Complexity: O(n)
'''
