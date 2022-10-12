// Double Ended Queue implementation in C using Arrays

#include <stdio.h>
#define MAX 10

int count(int *arr) 
{
  int c = 0, i;

  for (i = 0; i < MAX; i++) 
  {
    if (arr[i] != 0)
      c++;
  }
  return c;
}
void enqueueFront(int *arr, int item, int *pfront, int *prear) 
{
  int i, k, c;

  if (*pfront == 0 && *prear == MAX - 1) 
  {
    printf("\nDeque is full.\n");
    return;
  }

  if (*pfront == -1) 
  {
    *pfront = *prear = 0;
    arr[*pfront] = item;
    return;
  }

  if (*prear != MAX - 1) 
  {
    c = count(arr);
    k = *prear + 1;
    for (i = 1; i <= c; i++) 
    {
      arr[k] = arr[k - 1];
      k--;
    }
    arr[k] = item;
    *pfront = k;
    (*prear)++;
  } 
  else 
  {
    (*pfront)--;
    arr[*pfront] = item;
  }
}

void enqueueRear(int *arr, int item, int *pfront, int *prear) 
{
  int i, k;

  if (*pfront == 0 && *prear == MAX - 1) 
  {
    printf("\nDeque is full.\n");
    return;
  }

  if (*pfront == -1) 
  {
    *prear = *pfront = 0;
    arr[*prear] = item;
    return;
  }

  if (*prear == MAX - 1) 
  {
    k = *pfront - 1;
    for (i = *pfront - 1; i < *prear; i++) 
    {
      k = i;
      if (k == MAX - 1)
        arr[k] = 0;
      else
        arr[k] = arr[i + 1];
    }
    (*prear)--;
    (*pfront)--;
  }
  (*prear)++;
  arr[*prear] = item;
}

int dequeueFront(int *arr, int *pfront, int *prear) 
{
  int item;

  if (*pfront == -1) 
  {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*pfront];
  arr[*pfront] = 0;

  if (*pfront == *prear)
    *pfront = *prear = -1;
  else
    (*pfront)++;

  return item;
}

int dequeueRear(int *arr, int *pfront, int *prear) 
{
  int item;

  if (*pfront == -1) 
  {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*prear];
  arr[*prear] = 0;
  (*prear)--;
  if (*prear == -1)
    *pfront = -1;
  return item;
}

void display(int *arr) 
{
  int i;

  printf("\n front:  ");
  for (i = 0; i < MAX; i++)
    printf("  %d", arr[i]);
  printf("  :rear\n");
}

int main()
{
    int arr[MAX];
    int front, rear, i, n;

    front = rear = -1;
    for (i = 0; i < MAX; i++)
      arr[i] = 0;
    
    int choice,c,a,ch , item=0;

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

					if(count(arr)==0)
					printf("Queue is Empty \n");
					
					else
					printf("Queue is not Empty \n");
					
					break;
				
				case 2:
				    printf("\nEnter element to be added :");
				    scanf("%d",&item);
					enqueueRear(arr, item, &front, &rear);
					break;
					
				case 3:
					dequeueFront(arr, &front, &rear);
					break;
					
				case 4:
					dequeueRear(arr, &front, &rear);
					break;
					
				case 5:
					display(arr);
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

					if(count(arr)==1)
					printf("Queue is Empty \n");
					
					else
					printf("Queue is not Empty \n");
					
					break;
				
				case 2:
				    printf("\nEnter element to be added :");
				    scanf("%d",&item);				
					enqueueRear(arr, item, &front, &rear);
					break;
					
				case 3:
				    printf("\nEnter element to be added :");
				    scanf("%d",&item);
					enqueueFront(arr, item, &front, &rear);
					break;
					
				case 4:
					dequeueFront(arr, &front, &rear);
					break;
					
				case 5:
					display(arr);
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
	
	return 0 ;
}