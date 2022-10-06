/*SCLL insert delete count search*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *first = NULL;
void
create (int A[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *) malloc (sizeof (struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
    {
      t = (struct Node *) malloc (sizeof (struct Node));
      t->data = A[i];
      t->next = NULL;
      last->next = t;
      last = t;
    }
}

void
Traverse (struct Node *p)
{
  int count = 0;
  while (p != NULL)
    {
      printf ("\n%d element is traversed", count);
      p = p->next;
      count++;
    }
}

int
count (struct Node *p)
{
  int l = 0;
  while (p)
    {
      l++;
      p = p->next;
    }
  return l;
}

void
Display (struct Node *p)
{
  while (p != NULL)
    {
      printf ("%d ", p->data);
      p = p->next;
    }
}

void
Insert (struct Node *p, int index, int x)
{
  struct Node *t;
  int i;

  if (index < 0 || index > count (p))
    return;
  t = (struct Node *) malloc (sizeof (struct Node));
  t->data = x;

  if (index == 0)
    {
      t->next = first;
      first = t;
    }
  else
    {
      for (i = 0; i < index - 1; i++)
	p = p->next;
      t->next = p->next;
      p->next = t;

    }
}    

void isEmpty ()
  {
    if (first->next == first && first->data == 0)
      printf ("Linked List is Empty");
    else
      printf ("Not Empty");
  }

int Delete (struct Node *p, int index)
  {
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count (p))
      return -1;
    if (index == 1)
      {
	q = first;
	x = first->data;
	first = first->next;
	free (q);
	return x;
      }
    else
      {
	for (i = 0; i < index - 1; i++)
	  {
	    q = p;
	    p = p->next;
	  }
	q->next = p->next;
	x = p->data;
	free (p);
	return x;

      }
  }

void deleteNode(struct Node* head, int key)
{
	if (head == NULL)
		return;


	struct Node *curr = head, *prev;
	while (curr->data != key)
	{
		if (curr->next == head)
		{
			printf("\nGiven node is not found"
				" in the list!!!");
			break;
		}

		prev = curr;
		curr = curr->next;
	}


	if (curr->next == head)
	{
		head = NULL;
		free(curr);
		return;
	}


	if (curr == head)
	{
		prev = head;
		while (prev->next != head)
			prev = prev->next;
		head = curr->next;
		prev->next = head;
		free(curr);
	}

	else if (curr->next == head && curr == head)
	{
		prev->next = head;
		free(curr);
	}
	else
	{
		prev->next = curr->next;
		free(curr);
	}
}

void search (struct Node *head, int key)
	{
	  int index = 0;
	  struct Node *current = head;

	  do
	    {
	      if (current == NULL)
		return;

	      if (current->data == key)
		printf ("%d is found at %d index ", key, index);

	      current = current->next;
	      index++;
	    }
	  while (current != head);

	  printf ("-1");
	}

int main ()
	{
	  int ch;
	  int A_643[100], n, i;
	  printf ("Enter the size of array:\n");
	  scanf ("%d", &n);

	  printf ("Insert the elements :\n");
	  for (i = 0; i < n; i++)
	    {
	      scanf ("%d", &A_643[i]);
	    }

	  create (A_643, n);
	  printf ("The created linked list is:");
	  Display (first);
	A:
	  printf ("\nwhich operation do you want to perform?\n");
	  printf ("1) Traverse the linked list\n");
	  printf ("2) Insert a node at the certain position\n");
	  printf ("3) Delete a node at the certain position\n");
	  printf ("4) Count the total number of nodes\n");
	  printf ("5) Search for an element in the linked list\n");
	  printf ("6) Check if the linked list is empty?\n");
	  printf ("7) Delete node for a certain key\n");
	  printf ("8) exit!\n");
	  scanf ("%d", &ch);

	  switch (ch)
	    {
	    case 1:
        	      Traverse (first);
        	      goto A;
	    case 2:
        	      printf ("Enter index and element\n");
        	      int index, element;
        	      scanf ("%d %d", &index, &element);
        	      Insert (first, index, element);
	              goto A;
	    case 3:
        	      printf ("Enter index to be deleted\n");
        	      int ind;
        	      scanf ("%d", &ind);
        	      Delete (first, ind);
        	      goto A;
	    case 4:
        	      printf ("The total number of nodes is:%d\n", count (first));
        	      goto A;
	    case 5:
        	      printf ("enter element to be searched:\n");
        	      int key;
        	      scanf ("%d", &key);
        	      search (first, key);
        	      goto A;
	    case 6:
        	      isEmpty ();
        	      goto A;
        case 7:   
                  printf("\nWhich element do you want to delete?");
                  int KEY;
                  scanf("%d",&KEY);
                  deleteNode(first,KEY);
                  goto A;
        case 8:
                  break;
	    default:
        	      printf ("Wrong input\n");
        	      goto A;

	    }
	  printf ("The final linked list is: ");
	  Display (first);
	  return 0;
}
