//Reverse a Stack using another stack
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int size;
	int top;
	int *s;
};

void create_stack(struct stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc((st->size)*sizeof(int));
}

void push(struct stack *st, int x)
{
    if (st->top==st->size-1)
        printf("\nStack Overflow");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
        printf("\nStack Underflow");
    else
    {
        x=st->s[st->top--];
    }
    return x;
}

void display_stack(struct stack st)
{
    int i;
    if(st.top==-1)
        printf("Stack is empty");
    else
    {
        for(i=st.top;i>=0;--i)
            printf("%d\n",st.s[i]);
    }
}

void reverse_stack(struct stack *st)
{
	int x;
	struct stack temp;
	temp.size=st->size;
	temp.top=-1;	
	temp.s=(int *)malloc((temp.size)*sizeof(int));
	while(st->top!=-1)
	{
		temp.top++;
		temp.s[temp.top]=st->s[st->top];
		st->top--;
	}
	display_stack(temp);
	while(temp.top!=-1)
	{
		st->top++;
		st->s[st->top]=temp.s[temp.top];
		temp.top--;
	}
}

int main()
{
	int ch=1,x;
	struct stack st;
	create_stack(&st);
	while(ch==1)
	{
		printf("Enter element to push in stack = ");
		scanf("%d",&x);
		push(&st,x);
		printf("Do you want to enter another element (1/0) = ");
		scanf("%d",&ch);
	}
	printf("\nThe stack is as follows:\n");
	display_stack(st);
	printf("\nThe stack after reversing:\n");
	reverse_stack(&st);
	return 0;
}
