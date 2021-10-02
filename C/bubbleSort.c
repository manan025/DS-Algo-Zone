// Bubble Sort
/*
Example 1:
Input:-
How many numbers: 5
Enter the numbers: 4
3
2
5
1
Output:-
After sorting :
1 2 3 4 5

Example 2:
Input:-
How many numbers: 5
Enter the numbers: 5
4
3
2
1
Output:-
After sorting :
1 2 3 4 5
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *arr,n,i,j,f=0;
	printf("How many numbers: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the numbers: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(*(arr+j)>*(arr+j+1))
			{
				f=*(arr+j);
				arr[j]=*(arr+j+1);
				arr[j+1]=f;
				f=1;
			}
		}
		if(f==0)
		{
			break;
		}
	}
	printf("After sorting :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(arr+i));
	}
	return(0);
}

// Space complexity: 1
// Time complexity: O(N^2)

