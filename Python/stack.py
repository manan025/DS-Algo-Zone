stack=[]    
p=True
while p:
    print("Select operation to perform")    # Give user a choice
    print("1. Push into stack")             # Add elements 
    print("2. Pop into stack")              # remove last elements
    print("3. Peek Element of stack")      
    print("4. Show stack")                  # print stack
    print("5. Exit")                        # end program
    n=int(input())
    if n==1:
        print("Enter Element to add: ")
        x=int(input())
        stack.append(x)
        print("Element is added successfully.\n")
    elif n==2:
        if len(stack)==0:               # check if there is element to pop
            print("Stack is empty.\n")
        else:
            k=stack.pop()
            print(f"{k} is poped\n")
    elif n==3:
        if len(stack)==0:              
            print("Stack is empty.\n")
        else:
            k=stack[len(stack)-1]
            print(f"peek of stack is {k}\n")
    elif n==4:
        if len(stack)==0:               # check if there is elements to show
            print("Stack is empty.\n")
        else:
            print(stack,"\n")
    elif n==5:
        print("Program ended successfully.")
        p=False                         # End program
    else:
        print("Enter valid choice.\n")