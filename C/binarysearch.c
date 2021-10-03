#include<stdio.h>
void main(){
    int n,elem;
    printf("please enter the number of array elements\t");
    scanf("%d",&n);
    int a[10];
    for(int i=0;i<n;i++){
        printf("please enter %d th element\t",i+1);
        scanf("%d",&a[i]);
    }
    printf("please enter the element which you need to find\n");
    scanf("%d",&elem);
    int lb, ub, middle;
    lb = 0;
    ub = n - 1;
    middle = (lb+ub)/2;
  while (lb <= ub) {
    if (a[middle] <elem)
      lb = middle + 1;
    else if (a[middle] ==elem) {
      printf("%d found at location %d.\n",elem, middle+1);
      printf("\nmade by Jaskirat Singh CSE-2 063");
      break;
    }
    else
      ub = middle - 1;

    middle = (lb + ub)/2;
  }
  if (lb > ub){
    printf("Not found! %d is not a valid element.\n",elem);
    printf("\nmade by Jaskirat Singh CSE-2 063");}
}