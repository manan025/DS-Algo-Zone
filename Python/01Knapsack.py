from sys import stdin

def knapsack_helper(weights,values,n,maxWeight,i):
    if i==n or maxWeight==0:
        return 0
    if weights[i]>maxWeight:
        ans = knapsack_helper(weights,values,n,maxWeight,i+1)
    else:
        ans1 = values[i]+knapsack_helper(weights,values,n,maxWeight-weights[i],i+1)
        
        ans2 = knapsack_helper(weights,values,n,maxWeight,i+1)
        
        ans = max(ans1,ans2)
    return ans


def knapsack(weights, values, n, maxWeight) :
    return knapsack_helper(weights,values,n,maxWeight,0)

def takeInput() :
    n = int(stdin.readline().rstrip())

    if n == 0 :
        return list(), list(), n, 0

    weights = list(map(int, stdin.readline().rstrip().split(" ")))
    values = list(map(int, stdin.readline().rstrip().split(" ")))
    maxWeight = int(stdin.readline().rstrip())

    return weights, values, n, maxWeight

#input n,weights,values and maxWeight
weights, values, n, maxWeight = takeInput()

print(knapsack(weights, values, n, maxWeight))