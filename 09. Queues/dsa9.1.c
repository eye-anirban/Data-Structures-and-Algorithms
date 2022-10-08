/*Queue implementation using array*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear==MAX-1) 
    {
        printf("Overflow because queue is full");
    }
    else if(front==-1 && rear==-1) 
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1) 
    {
        printf("Underflow");
    }
    else if(front==rear) 
    {   
        printf("\n%d ",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n%d ",queue[front]);
        front++;
    }
}

void display()
{   
    int i;
    for(i=front;i<=rear;++i)
    {
        printf("%d -> ",queue[i]);
    }
}

void peek()
{
    printf("\n%d ",queue[front]);
}



int main()
{
    int ch,p;
    A:
    printf("\nWhat operation?\n1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1: 
                printf("\nEnter integer to be inserted:");
                scanf("%d",&p);
                enqueue(p);
                goto A;
        case 2: dequeue();
                goto A;
        case 3: display();
                printf("NULL\n");
                goto A;
        case 4: peek();
                goto A;
        case 5: break;
        default: printf("wrong input!");
                 goto A;
    }
    return 0;
}
