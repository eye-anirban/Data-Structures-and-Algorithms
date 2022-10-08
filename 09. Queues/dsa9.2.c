/*Queue implementation using Linked List*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x)
{
    struct node *temp;
    temp= (struct node *) malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No memory");
    }
    else
    {
        temp->data=x;
        temp->next=NULL;
        if(front==NULL)
        {
            front=rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=temp;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Underflow / Queue is empty");
    }
    else
    {
        temp=front;
        x=front->data;
        front=front->next;
        free(temp);
    }
    return x;
}

void display()
{
    struct node *temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Underflow / Queue is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
    printf("%d\n",front->data);
}

int main()
{
    int ch,p;
    A:
    printf("What operation?\n1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1: 
                printf("\nEnter integer to be inserted:");
                scanf("%d",&p);
                enqueue(p);
                goto A;
        case 2: printf("\n%d\n",dequeue());
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
