'''
Given a 2D binary matrix A of dimensions NxM, determine the row that contains a minimum number of 1's.
The matrix contains only 1s and 0s.
'''
'''
Example:
    input:
    N=5,M=5
	A=[[1,1,1,1,0],[1,0,0,0,0],[0,1,0,1,1],[1,0,1,1,1],[1,1,1,1,1]]
	
	Output:
	2

    Explanation:
    Your Matrix:
        1 1 1 1 0
        1 0 0 0 0
        0 1 0 1 1
        1 0 1 1 1
        1 1 1 1 1

        As you can see 2nd row contains 1 only one time which is minimum in this matrix. So Output is 2.
'''
matrix=[]   
print("Enter number of rows: ")

r=int(input())
print("Enter number of columns: ")

c=int(input())
print(f"matrix size is {r}x{c}")    #print size of matrix

print("Enter elemnts:")         # take value of matrix 
for i in range(r):
    temp=[]
    for j in range(c):
        x=int(input())
        temp.append(x)
    matrix.append(temp)

print("Your Matrix is: ")   #print matrix
for i in range(r):
    for j in range(c):
        print(matrix[i][j],end=" ")
    print()

count=float('inf')    # intialize count of 1 to infinte
ans=-1                # intialize answer to -1      
for i in range(len(matrix)):
    try:
        if count > matrix[i].count(1):  # checking minium number of 1
            ans=i                       # save row number
            count=matrix[i].count(1)    # change the count 
    except Exception as e:
        continue
ans+=1
print(f"Row that has Minimum number of 1 is {ans}")          # print answer