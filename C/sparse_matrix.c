# include<stdio.h>
int main(){
    int i,j,k,l,t,m,n;
    int a[7][7];
    int b[7][7];
    printf("please enter the number of rows:\t");
    scanf("%d",&m);
    printf("\nplease enter the number of column\t");
    scanf("%d",&n);
    printf("Please enter the elements\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("\tplease enter element %d , %d :\t",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
printf("the matrix is :\n");
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
     
    t=1;
    b[0][0]=m;
    b[0][1]=n;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (a[i][j]!=0)
            {
                b[t][0]=i+1;
                b[t][1]=j+1;
                b[t][2]=a[i][j];
                t++;
            }
            
        }
        b[0][2]=t-1;
    }
    printf("the sparse matrix is : \n");
    for ( i = 0; i < t; i++)
    { 
          printf("\t| %d | %d | %d |\n",b[i][0],b[i][1],b[i][2]); 
    }
    printf("\nJaskirat Singh CSE2 06313202720");
    return 0;
}