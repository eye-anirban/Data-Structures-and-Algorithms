//Circular Queue using Linked List all operations
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int d)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->next = NULL;
    if (rear == NULL && front == NULL)
    {
        front = rear = t;
        rear->next = front;
    }
    else
    {
        rear->next = t;
        rear = t;
        t->next = front;
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;
    t = front;
    if (front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else if (front == rear)
    {
        x = t->data;
        front = rear = NULL;
        free(t);
    }
    else
    {
        x = t->data;
        front = front->next;
        rear->next = front;
        free(t);
    }
    return x;
}
void display()
{
    struct Node *t;
    t = front;
    if (front == NULL && rear == NULL)
        printf("Queue is empty\n");
    else
    {
        do
        {
            printf("%d ", t->data);
            t = t->next;
        } while (t != front);
    }
}
int main()
{
    int ch, data, c;
    printf("Enter Your Choice:-");
    do
    {
        printf("\nMENU\n1. Enqueue\n2. Dequeue \n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter your data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            printf("%d is dequeued", dequeue());
            break;
        case 3:
            display();
            break;
        default:
            printf("\nIncorrect Choice\n");
        }
        printf("\nDo you want to continue? (1/0): ");
        scanf("%d", &c);
    } while (c != 0);
    return 0;
}
