//Peek highest, lowest and middle element from stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack
{
    int data;
    struct Stack * next;
};

void push(struct Stack **, int);
int pop(struct Stack **);
int isEmpty(struct Stack *);
void display(struct Stack *);
int peek_lowest(struct Stack *);
int peek_highest(struct Stack *);
int peek_middle(struct Stack *, int *, int);
int main()
{
    struct Stack *stack = NULL;
    int choice,i,n,a;
    printf("How many elements in the stack?");
    scanf("%d",&n);
    printf("Insert those elements");
    for(i=0;i<n;i++)
    { 
    	scanf("%d",&a);
    	push(&stack,a);
    	a=0;
    }
    do
    {
        int val;
        printf("1) Insert in stack\n2) Display\n3) Delete top\n");
        printf("4) Peek lowest\n5) Peek highest\n6) Peek middle\n7) Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value:\n");
            scanf("%d", &val);
            push(&stack, val);
            break;
        case 2:
            printf("\nThe stack is:\n");
            display(stack);
            printf("\n");
            break;
        case 3:
            printf("\nDeleted element:\n%d\n", pop(&stack));
            break;
        case 4:
            printf("\nLowest value:\n%d\n", peek_lowest(stack));
            break;
        case 5:
            printf("\nHighest value:\n%d\n", peek_highest(stack));
            break;
        case 6:
            printf("\nMiddle element:\n%d\n",
                   peek_middle(stack, &val, 0));
            break;
        default:
            printf("\nExiting...\n");
        }
        printf("----------------------------\n");
    } while (choice >= 1 && choice <= 6);
    return 0;
}

void push(struct Stack ** stack, int num)
{
    struct Stack * new = (struct Stack *) malloc(sizeof(struct Stack));
    new -> data = num;
    new -> next = * stack;
    * stack = new;
}

int pop(struct Stack **stack)
{
    if (isEmpty(* stack))
    {
        printf("\nUnderflow!");
        return -9999999;
    }
    struct Stack * temp = (* stack);
    * stack = (* stack) -> next;
    int val = temp -> data;
    free(temp);
    return val;
}

int isEmpty(struct Stack * stack)
{
    if (stack == NULL)
        return 1;
    return 0;
}

void display(struct Stack * stack)
{
    if (isEmpty(stack))
    {
        printf("\n");
        return;
    }
    int temp = pop(&stack);
    printf("%d ", temp);
    display(stack);
    push(&stack, temp);
}

int peek_lowest(struct Stack * stack)
{
    if (stack == NULL)
    {
        return INT_MAX;
    }
    int val = pop(&stack);
    int lowest = peek_lowest(stack);
    push(&stack, val);
    if (lowest > val)
    {
        return val;
    }
    return lowest;
}

int peek_highest(struct Stack * stack)
{
    if (stack == NULL)
    {
        return INT_MIN;
    }
    int val = pop(&stack);
    int highest = peek_highest(stack);
    push(&stack, val);
    if (highest < val)
    {
        return val;
    }
    return highest;
}

int peek_middle(struct Stack *stack, int *length, int position)
{
    if (stack == NULL)
    {
        * length = position;
        return INT_MIN;
    }
    int val = pop(&stack);
    int next = peek_middle(stack, length, position + 1);
    push(&stack, val);
    if (*length / 2 == position)
    {
        return val;
    }
    return next;
}
