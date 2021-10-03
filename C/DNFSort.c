/*
    Sort an array containing 3 unique values
    In one iteration 
    and no extra space
*/
#include <stdio.h>
void swap( int *a , int *b ){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void DNFSort( int *A, int n ){
    int p0=0;
    int p1=0;
    int p2=n-1;
    while( p1<=p2 ){
        if( A[p1]==1 )
            p1++;
        else if(A[p1]==0){
            swap(&A[p1],&A[p0]);
            p0++; p1++;
        } 
        else{
            swap(&A[p1],&A[p2]);
            p2--;
        }
    }
}
int main(){
    int n = 11;
    int A[] = { 2, 1, 1, 0, 0, 2, 1, 1, 0, 2, 1 };
    DNFSort( A  , n);
    for(int i=0; i<n; i++) printf("%d ", A[i]);
    return 0;
}
