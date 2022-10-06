//STACK implementation using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *top = NULL;

void
push (int x)
{
  struct Node *t;
  t = (struct Node *) malloc (sizeof (struct Node));

  if (t == NULL)
    printf ("stack is full\n");
  else
    {
      t->data = x;
      t->next = top;
      top = t;
    }

}

int
pop ()
{
  struct Node *t;
  int x = -1;

  if (top == NULL)
    printf ("Stack is Empty\n");
  else
    {
      t = top;
      top = top->next;
      x = t->data;
      free (t);
    }
  return x;
}

void isEmpty()
{
    if(top == NULL) printf("\nStack is empty") ;
    else printf("\nStack is not empty!");
}

void
Display ()
{
  struct Node *p;
  p = top;
  while (p != NULL)
    {
      printf ("%d ", p->data);
      p = p->next;
    }
  printf ("\n");
}

int
main ()
{
    int ch,i,n,a;
    printf("How many elements in the stack?");
    scanf("%d",&n);
    printf("Insert those elements :");
    for(i=0;i<n;i++)
    {
      scanf("%d",&a);
	  push(a);
	  a=0;	
	}
   
  A:
  printf("\nWhat operation do you want to perform in the stack?");
  printf("\n1.isEmpty?");
  printf("\n2.Display?");
  printf("\n3.Push?");
  printf("\n4.Pop?");
  printf("\n5.Exit?");
  scanf("%d",&ch);
   
   switch (ch)
   {
      case 1 : isEmpty();
               goto A;
      case 2 : Display();
               goto A;
      case 3 : printf("\nEnter element to be pushed:\n");
               int x;
               scanf("%d",&x);
               push(x);
               goto A;
      case 4 : pop();
               goto A;
      case 5 : break;
      default: printf("\nwrong input!");
               goto A;
      
   }
  return 0;
}
