//Double Ended Queue using Linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

int isEmpty()
{
	if(rear==NULL && front ==NULL)
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

void traversal()
{
	struct Node* ptr=front;
	
	if(isEmpty())
	{
		printf("Queue is empty \n");
	}
	
	else
	{
		printf("Elements : \n");
		
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	printf("\n");
	}

}

void enqueueFront()
{
	int num;
	printf("Enter the number : \n");
	scanf("%d",&num);
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	new_node->data=num;
	
	
	if(isEmpty())
	{
		new_node->next=NULL;
		front=rear=new_node;
	}
	
	else
	{
	new_node->next=front;
	front=new_node;
	}

}

void enqueueRear()
{
		int num;
	printf("Enter the number : \n");
	scanf("%d",&num);
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
		new_node->data=num;
		
	if(isEmpty())
	{
		front = rear = new_node;
		new_node->next=NULL;
	}
	
	else
	{
	rear->next=new_node;
	new_node->next=NULL;
	rear=new_node;
	}
	
}

void dequeueRear()
{
	if(isEmpty())
	{
		printf("Queue is empty ... Deleteion not possible \n");
	}
	
	else
	{
		struct Node* ptr=front;
		
		while(ptr->next!=rear)
		{
			ptr=ptr->next;
		}	
		
		struct Node* p=rear;
		
		ptr->next=NULL;
		
		printf("Deleted Element : %d \n",rear->data);
		
		rear=ptr;
		free(p);
		
		
	}
	
		
}

void dequeueFront()
{
	if(isEmpty())
	{
		printf("Queue is empty .... Deletion not possible \n");
	}
	
	else
	{
		struct Node* p=front;
		
		printf("Deleted element : %d \n",front->data);
		
		front=front->next;
		
		free(p);
	}
		
}



int main()
{
	
	int choice,c,a,ch;
	

	
	printf("CHOICE : \n");
	printf("1. Input restricted DEqueue \n");
	printf("2. Output restricted DEqueue \n");
	printf("Enter the choice : (1/2) \n");
	scanf("%d",&choice);
	
	if(choice == 1)
	{
		
		do
		{
			
			printf("CHOICE : \n Input restricted DEqueue \n");
			printf("1. Check Empty \n");
			printf("2. Insert at rear end\n");
			printf("3. Delete at front end \n");
			printf("4. Delete at rear end \n");
			printf("5. Display the elements of the Queue \n");
			printf("Enter the choice(1/2/3/4/5): \n");
			scanf("%d",&c);
			
			switch(c)
			{
				case 1:
					a=isEmpty();
					
					if(a==1)
					printf("Queue is Empty \n");
					
					else
					printf("Queue is not Empty \n");
					
					break;
				
				case 2:
					enqueueRear();
					break;
					
				case 3:
					dequeueFront();
					break;
					
				case 4:
					dequeueRear();
					break;
					
				case 5:
					traversal();
					break;
					
					default:
						printf("Wrong input \n");
									
			}
			
			printf("Want to continue ? \n Enter 1 if Yes , otherwise press any other digit :\n");
			scanf("%d",&ch);
			
		}
		while(ch==1);
				
	}
	
	else if(choice == 2)
	{
		
		do
		{
			
			printf("CHOICE : \n Output restricted DEqueue \n");
			printf("1. Check Empty \n");
			printf("2. Insert at rear end\n");
			printf("3. Insert at front end \n");
			printf("4. Delete at front end \n");
			printf("5. Display the elements of the Queue \n");
			printf("Enter the choice(1/2/3/4/5): \n");
			scanf("%d",&c);
			
			switch(c)
			{
				case 1:
					a=isEmpty();
					
					if(a==1)
					printf("Queue is Empty \n");
					
					else
					printf("Queue is not Empty \n");
					
					break;
				
				case 2:
					enqueueRear();
					break;
					
				case 3:
					enqueueFront();
					break;
					
				case 4:
					dequeueFront();
					break;
					
				case 5:
					traversal();
					break;
					
					default:
						printf("Wrong input \n");
									
			}
			
			printf("Want to continue ? \n Enter 1 if Yes , otherwise press any other digit :\n");
			scanf("%d",&ch);
			
		}
		while(ch==1);
					
	}
	
	else
	{
		printf("Wrong input \n");
	}
	
	return 0;
}
