"""
Problem - Check if a linked list is a palidrome or not

Algorithm Explaination:
1. Get the middle of the linked list.
2. Reverse the second half of the linked list.
3. Check if the first half and second half are identical.
4. Construct the original linked list by reversing the second half again and attaching it back to the first half

Time Complexity - O(n)
Auxiliary Space Complexity - O(1)


Example Test Cases - 
1. I/P - ['a', 'b', 'a', 'c', 'a', 'b', 'a']
    O/P - "Is Palindrome"
2. I/P - ['a']
    O/P - "Is Palindrome"
3. I/P - ['a', 'b', 'c']
    O/P - "Not Palindrome"
"""

class Node:
    def __init__(self, data):

        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def isPalindrome(self, head):
        slow_ptr = head
        fast_ptr = head
        prev_of_slow_ptr = head

        midnode = None

        res = True

        if (head != None and head.next != None):
            while (fast_ptr != None and
                   fast_ptr.next != None):

                fast_ptr = fast_ptr.next.next
                prev_of_slow_ptr = slow_ptr
                slow_ptr = slow_ptr.next

            if (fast_ptr != None):
                midnode = slow_ptr
                slow_ptr = slow_ptr.next

            second_half = slow_ptr

            prev_of_slow_ptr.next = None

            second_half = self.reverse(second_half)

            res = self.compareLists(head, second_half)

            second_half = self.reverse(second_half)

            if (midnode != None):
                prev_of_slow_ptr.next = midnode
                midnode.next = second_half
            else:
                prev_of_slow_ptr.next = second_half
        return res

    def reverse(self, second_half):

        prev = None
        current = second_half
        next = None

        while current != None:
            next = current.next
            current.next = prev
            prev = current
            current = next

        second_half = prev
        return second_half

    def compareLists(self, head1, head2):

        temp1 = head1
        temp2 = head2

        while (temp1 and temp2):
            if (temp1.data == temp2.data):
                temp1 = temp1.next
                temp2 = temp2.next
            else:
                return 0

        if (temp1 == None and temp2 == None):
            return 1

        return 0

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):

        temp = self.head

        while(temp):
            print(temp.data, end="->")
            temp = temp.next

        print("NULL")


# Driver code
if __name__ == '__main__':

    ll = LinkedList()
    s = ['a','b','c']

    for i in range(len(s)):
        ll.push(s[i])
    ll.printList()

    if (ll.isPalindrome(ll.head) != False):
        print("Is Palindrome\n")
    else:
        print("Not Palindrome\n")
    print()
