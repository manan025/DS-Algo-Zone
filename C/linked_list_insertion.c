#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void display(struct Node *n)
{
  printf("\nPrinting new list...\n");
  while (n != NULL)
  {
    printf("%d ", n->data);
    n = n->next;
  }
};

int main()
{
  struct Node *first = (struct Node *)malloc(sizeof(struct Node));
  first->data = 5;
  first->next = NULL;

  struct Node *second = (struct Node *)malloc(sizeof(struct Node));
  second->data = 10;
  first->next = second;

  struct Node *third = (struct Node *)malloc(sizeof(struct Node));
  third->data = 15;
  second->next = third;

  display(first);

  return 0;
}

/*
Sample Input 5 10 15

Sample Output
 Printing new list...
 5 10 15 

*/ 

// Time Complexity O(1);
// Space Complexity O(n);