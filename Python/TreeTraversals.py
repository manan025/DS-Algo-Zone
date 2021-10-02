""" --> Tree traversals recursive solutions"""

# class to create a tree Node
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key
 
 
# A function to do inorder tree traversal
def printInorder(root):
 
    if root:
 
        # First recur on left child
        printInorder(root.left)
 
        # then print the data of node
        print(root.val),
 
        # now recur on right child
        printInorder(root.right)
 
 
# A function to do postorder tree traversal
def printPostorder(root):
 
    if root:
 
        # First recur on left child
        printPostorder(root.left)
 
        # the recur on right child
        printPostorder(root.right)
 
        # now print the data of node
        print(root.val),
 
 
# A function to do preorder tree traversal
def printPreorder(root):
 
    if root:
 
        # First print the data of node
        print(root.val),
 
        # Then recur on left child
        printPreorder(root.left)
 
        # Finally recur on right child
        printPreorder(root.right)
 
 
# Driver code
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
#print the preorder of the tree
printPreorder(root)
#print the inorder of the tree
printInorder(root)
#print the postorder of the tree
printPostorder(root)

# Input : [1,2,3,4,5]
# preorder : 1 2 4 5 3 
# inorder : 4 2 5 1 3
# postorder : 4 5 2 3 1

#Time complexity : O(N) 
# Space Complexity :O(H) where H is height if we consider stack for function call

