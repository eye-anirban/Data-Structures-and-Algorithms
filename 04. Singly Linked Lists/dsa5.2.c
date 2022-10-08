/*DELETE NODE FROM SLL AT DIFFERENT POS*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;
 
 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}

int count(struct Node *p)
{
 int l=0;
 while(p)
 {
 l++;
 p=p->next;
 }
 return l;
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}

int delete_beginning(struct Node *p)
{struct Node *q=NULL;
 int x=-1;
 q=first;
 x=first->data;
 first=first->next;
 free(q);
 return x;
 
}
int Delete_anypos(struct Node *p,int index)
{
 struct Node *q=NULL;
 int x=-1,i;
 
 if(index < 1 || index > count(p))
 return -1;

 for(i=0;i<index-1;i++)
 {
 q=p;
 p=p->next;
 }
 q->next=p->next;
 x=p->data;
 free(p);
 return x;
}

int delete_last(struct Node *p)
{  struct Node *last, *beforelast;
    if(first == NULL)
    {
        printf(" There is no element in the list.");
    }
    else
    {
        last = first;
        beforelast = first;
        
        while(last->next != NULL)
        {
            beforelast = last;
            last = last->next;
        }
        if(last == first)
        {
            first = NULL;
        }
        else
        {
            beforelast->next = NULL;
        }
 
        free(last);
    }
}

int main()
{
 int ch,n,i;
 int A[10];
 printf("Enter length of linked list :");
 scanf("%d",&n);
 printf("Enter Array elements :");
 for(i=0;i<n;i++) scanf("%d",&A[i]);
 create(A,n);
 printf("Created LL is:\n");
  Display(first);
 printf("which node do you want to delete?\n");
 printf("Enter 1: for 1st node\n");
  printf("Enter 2: for last node\n");
   printf("Enter 3: for any pos node\n");
 scanf("%d", &ch);
 
 if(ch == 1) printf("deleted node is: %d\n",delete_beginning(first));
 else if(ch == 2) printf("deleted node is: %d\n",delete_last(first));
 else if(ch == 3) 
 {   int index;
     printf("Enter index to be deleted:\n");
     scanf("%d",&index);
     printf("deleted node is: %d\n", Delete_anypos(first,index));
 }
 return 0;
}
