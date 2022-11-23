/*SLL MENU DRIVEN (RECURSIVE + ITERATIVE)*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *first = NULL;

void
create (int A_643[], int n)
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

void
RDisplay (struct Node *p)
{
  if (p != NULL)
    {
      printf ("%d ", p->data);
      RDisplay (p->next);
    }
}

int
count (struct Node *p)
{
  int l = 0;
  while (p)
    {
      l++;
      p = p->next;
    }
  return l;
}

int
Rcount (struct Node *p)
{
  if (p != NULL)
    return Rcount (p->next) + 1;
  else
    return 0;
}

int
sum (struct Node *p)
{
  int s = 0;

  while (p != NULL)
    {
      s += p->data;
      p = p->next;
    }
  return s;
}

int
Rsum (struct Node *p)
{
  if (p == NULL)
    return 0;
  else
    return Rsum (p->next) + p->data;
}

int
pro (struct Node *p)
{
  int pdt = 1;

  while (p != NULL)
    {
      pdt *= p->data;
      p = p->next;
    }
  return pdt;
}

int
Rpro (struct Node *p)
{
  if (p == NULL)
    return 1;
  else
    return Rpro (p->next) * p->data;
}

int
Max (struct Node *p)
{
  int max = -100000;

  while (p)
    {
      if (p->data > max)
	max = p->data;
      p = p->next;
    }
  return max;

}

int
RMax (struct Node *p)
{
  int x = 0;

  if (p == 0)
    return 100000;
  x = RMax (p->next);
  if (x > p->data)
    return x;
  else
    return p->data;
}

int
Min (struct Node *p)
{
  int min = 100000;

  while (p)
    {
      if (p->data < min)
	min = p->data;
      p = p->next;
    }
  return min;

}

int
RMin (struct Node *p)
{
  int x = 0;

  if (p == 0)
    return -100000;
  x = RMin (p->next);
  if (x > p->data)
    return x;
  else
    return p->data;
}


int
main ()
{
  int A_643[100], n, i , ch;
  printf ("Enter the size of array:\n");
  scanf ("%d", &n);

  printf ("Insert the elements :\n");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &A_643[i]);
    }

  create (A_643, n);

  printf ("The Linked List created is:\n");
  RDisplay (first);
  
  printf ("Which operation do you want to perform?\n");
  printf ("Enter 1 for recursive length\n");
  printf ("Enter 2 for iterative length\n");
  printf ("Enter 3 for recursive sum\n");
  printf ("Enter 4 for iterative sum\n");
  printf ("Enter 5 for recursive product\n");
  printf ("Enter 6 for iterative product\n");
  printf ("Enter 7 for recursive max\n");
  printf ("Enter 8 for iterative max\n");
  printf ("Enter 9 for recursive min\n");
  printf ("Enter 0 for iterative min\n");
  scanf("%d", &ch);

  switch (ch)
  { 
      case 1 : printf("The length of linked list is: %d", Rcount(first));
               break;
      case 2 : printf("The length of linked list is: %d", count(first));
               break;
      case 3 : printf("The sum of linked list is: %d", Rsum(first));
               break;
      case 4 : printf("The sum of linked list is: %d", sum(first));
               break;
      case 5 : printf("The product of linked list is: %d", Rpro(first));
               break;
      case 6 : printf("The product of linked list is: %d", pro(first));
               break;
      case 7 : printf("The max of linked list is: %d", RMax(first));
               break;
      case 8 : printf("The max of linked list is: %d", Max(first));
               break;
      case 9 : printf("The min of linked list is: %d", RMin(first));
               break;
      case 0 : printf("The min of linked list is: %d", Min(first));
               break;
      default: printf("Wrong input\n");               
   }

  return 0;
}
