#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *first_643 = NULL;

void create (int A[], int n)
{
  int i;
  struct Node *t, *last;
  first_643 = (struct Node *) malloc (sizeof (struct Node));
  first_643->data = A[0];
  first_643->next = NULL;
  last = first_643;

  for (i = 1; i < n; i++)
    {
      t = (struct Node *) malloc (sizeof (struct Node));
      t->data = A[i];
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

void Insert_beginning (struct Node *p, int x)
{ 
  struct Node *t;
  t = (struct Node *) malloc (sizeof (struct Node));
  t->data = x;
  t->next = first_643;
  first_643 = t;
}

void Insert (struct Node *p, int index, int x)
{
  struct Node *t;
  int i;
    t = (struct Node *) malloc (sizeof (struct Node));
  t->data = x;
    
      for (i = 0; i < index - 1; i++)
	        p = p->next;
      t->next = p->next;
      p->next = t;
}

void Insert_last (int x)
{
    struct Node *newNode, *t;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
        newNode->data = x; 
        newNode->next = NULL; 
        t = first_643;
         while(t != NULL && t->next != NULL)
            t = t->next;
        t->next = newNode;
}

int main ()
{
  int A[100], n ,ch,i;
  printf ("Enter the size of array:\n");
  scanf ("%d", &n);
  printf ("Insert the elements :\n");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &A[i]);
    }
  create (A, n);
  printf ("The Linked List created is:\n");
  Display (first_643);
  printf("\nDo you want to insert new node?"); 
  printf("Insert 1 for Yes and 0 for No\n");
  scanf("%d",&ch);
  
  if(ch==1)
  {
	   int index, x, ch2;
	   printf("\nWhere do you want to insert node?\n");
	   printf(" 0.for beginning\n 1.for last\n 2.for any other position\n");
	   scanf("%d", &ch2);
	   
	   printf("\nWhich element do you want to insert?\n");
	   scanf("%d", &x);
	   
	   if(ch2==0) Insert_beginning(first_643,x);
	   else if(ch2==1) Insert_last(x);
	   else {
	   	      printf("Enter the index where you want to insert node:\n");
	   	      scanf("%d", &index);
	   	      Insert(first_643,index,x);
	        }
	   Display (first_643);
  }
  else 
  return 0;
}


