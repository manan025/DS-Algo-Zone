""" perform mergesort on a list of numbers 

    >>> verticalOrder([1,2,3,4,5,N,6]) n-> None
    [4 2 1 5 3 6]

    >>> verticalOrder([1,2,3,4,5,6,7,N,N,N,N,N,8,N,9])
    [4 2 1 5 6 3 8 7 9]


    >>> as we are traversing the whole tree its time complexity is O(N)
    where N is no.of  nodes
    >>> we using extra space of O(N).
    """

class Solution:
    
    #Function to find the vertical order traversal of Binary Tree.
    def verticalOrder(self, root): 
        #Your code here
        d = {}
        q = deque()
        level = 0
        # create a deque and store the root as well as level in it for dictionary
        q.append([root,level])
        while(q):
            ele = q.popleft()
            #After popping store the element according to its level in the dictionary
            # there can be multiple values to a particular key in a dictionary
            if ele[1] not in d:
                d[ele[1]] = [ele[0].data]
            else:
                d[ele[1]].append(ele[0].data)
            # if left present add it to the deque by decreasing the level 
            if ele[0].left != None:
                q.append([ele[0].left,ele[1]-1])
            # if left present add it to the deque by increasing the level     
            if ele[0].right != None:
                q.append([ele[0].right,ele[1]+1])
        #adding the values to answer array        
        ans = []
        for i in sorted(d.keys()):
            ans.extend(d[i])
        return ans
            
 
#{ 
#  Driver Code Starts
#Initial Template for Python 3

#Contributed by Sudarshan Sharma
from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None



# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    
    
if __name__=="__main__":
    t=int(input()) 
    import sys
    sys.setrecursionlimit(10000)
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        res = Solution().verticalOrder(root)
        for i in res:
            print (i, end=" ")
        print()



# } Driver Code Ends