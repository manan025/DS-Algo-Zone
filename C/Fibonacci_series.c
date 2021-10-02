#include<stdio.h>
int main()
{
    int value, first_term = 0, second_term = 1, next_term;
 
   
    printf("Enter the number of terms for fibonacci series :\n");  //Ask user to input number of terms
    scanf("%d",&value);
 
    printf("Fibonacci series upto %d term:\n",value);
    for (int i = 2 ; i < value ; i++ )
    {
      
           printf("%d\n",first_term);
          next_term = first_term + second_term;  //here always next value will be sum of previous two value that is first term and second term
          first_term = second_term;         // then second value will assign to first term 
          second_term = next_term;          // here next value  assigned to second term 
       
       
    }
 
    return 0;
}
/*
In case of fibonacci series, next number is the sum of previous two numbers 
for example 0, 1, 1, 2, 3, 5, 8, 13, 21 etc. The first two numbers of fibonacci series
 are 0 and 1.
a    b     c    output
0    1     1       0
1    1     2       1
1    2     3       1
2    3     5       2
3    5     8       3
5    8     13      5 
..   ..     ..     ..

and so on

output:-

Enter the number of terms for fibonacci series :
10
Fibonacci series upto 10 term:
0
1
1
2
3
5
8
13
21
34
*/