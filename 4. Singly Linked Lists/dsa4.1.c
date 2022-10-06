#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *first = NULL;

void create (int A_643[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *) malloc (sizeof (struct Node));
  first->data = A_643[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
    {
      t = (struct Node *) malloc (sizeof (struct Node));
      t->data = A_643[i];
      t->next = NULL;
      last->next = t;
      last = t;
    }
}

void Display (struct Node *p)
{
  while (p != NULL)
    {
      printf ("%d ", p->data);
      p = p->next;
    }
}

int main ()
{
  int A_643[100],n,i;
  printf("Enter the size of array:\n");
  scanf("%d", &n);
  
  printf("Insert the elements :\n");
  for ( i=0; i<n;i++)
  {scanf("%d", &A_643[i]);}
  
  create (A_643, n);
  
  printf("The Linked List created is:\n");
  Display (first);

  return 0;
}
