//STACK implementation using Array
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
  int size;
  int top;
  int *S;
};
void
create (struct Stack *st)
{
  printf ("Enter Size :");
  scanf ("%d", &st->size);
  st->top = -1;
  st->S = (int *) malloc (st->size * sizeof (int));
}

void
Display (struct Stack st)
{
  int i;
  for (i = st.top; i >= 0; i--)
    printf ("%d ", st.S[i]);
  printf ("\n");

}

void
push (struct Stack *st, int x)
{
  if (st->top == st->size - 1)
    printf ("Stack overflow\n");
  else
    {
      st->top++;
      st->S[st->top] = x;
    }

}

int
pop (struct Stack *st)
{
  int x = -1;

  if (st->top == -1)
    printf ("Stack Underflow\n");
  else
    {
      x = st->S[st->top--];
    }
  return x;
}

void
isEmpty (struct Stack st)
{
  if (st.top == -1)
    printf("Stack is empty ");
  else printf("Stack is not empty");
}

int
main ()
{ 
  int n,A[100],ch,x,i;
  struct Stack st;
  create (&st);
  printf("Enter size of the stack to be created:\n");
  scanf("%d",&n);
  
  for( i=0;i<n;i++)
  { printf("Enter element to be pushed: ");
    scanf("%d", &A[i]);
    push(&st, A[i] );
  }
  A:
  printf("\nWhat do you want to perform?\n");
  printf("1.check if empty\n");
  printf("2.push\n");
  printf("3.pop\n");
  printf("4.display\n");
  printf("5.exit\n");
  scanf("%d", &ch);
  
  switch(ch)
  {
    case 1: isEmpty(st);
            goto A;
    case 2: printf("\nEnter value to be pushed :");
            scanf("%d",&x);
            push(&st,x);
            goto A;
    case 3: pop(&st);
            goto A;
    case 4: Display(st);
            goto A;
    case 5: break;
    default:printf("Wrong Input\n");
            goto A;
  }
  
  return 0;
}
