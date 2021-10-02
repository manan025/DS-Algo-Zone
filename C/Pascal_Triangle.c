#include<stdio.h>
int main()
{   int no;
    printf("enter number of rows for pascal triangle ");
    scanf("%d",&no);
    int space=no;
      int number=1;
    for(int i=0;i<no;i++){
        
        for(int s = 1; s<=space; s++){
            printf(" ");
        }
        number=1;
        for(int j=0;j<=i;j++){
         
         printf("%d ",number);
         number = number * (i-j)/(j+1);
           
        }
        space--;
        
        printf("\n");   
        

    }   
    
}
/* 
output:-
enter number of rows for pascal triangle 5
     1 
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1 
 
*/