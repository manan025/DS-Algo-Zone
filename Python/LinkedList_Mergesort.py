class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class Linkedlists:
    def __init__(self):
        self.head = None

    def printlist(self):
        arr = [] # temporary arr to return
        temp = self.head
        while temp:
            arr.append(temp.data)
            temp = temp.next

        return arr

    def append(self, new_data):
        if self.head
            temp = self.head
            while temp:
                temp = temp.next
            temp.next = Node(new_data)
        else:
            self.head = Node(new_data)


def mergeLists(head1, head2):
    # if both the headers are NULL

    if head1 == None and head2 == None:
        return None

    if head1 == None: # if either of headers are NULL, return other header
        return head2
    if head2 == None:  # if either of headers are NULL, return other header
        return head1

    # comparison between the two headers

    if head1.data < head2.data:
        temp = head1
        temp.next = mergeLists(head1.next, head2)
    else:
        temp = head2
        temp.next = mergeLists(head1, head2.next)

    return temp