//POLYNOMIAL CREATE ADD MULTIPLY
#include <stdio.h>
#include<stdlib.h>

struct Node {
	int coeff;
	int power;
	struct Node* next;
};

void create_node(int x, int y, struct Node** temp)
{
	struct Node *r, *z;
	z = *temp;
	if (z == NULL) {
		r = (struct Node*)malloc(sizeof(struct Node));
		r->coeff = x;
		r->power = y;
		*temp = r;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
	else {
		r->coeff = x;
		r->power = y;
		r->next = (struct Node*)malloc(sizeof(struct Node));
		r = r->next;
		r->next = NULL;
	}
}

void polyadd(struct Node* poly1, struct Node* poly2,
			struct Node* poly)
{
	while (poly1->next && poly2->next) {
	
		if (poly1->power > poly2->power) {
			poly->power = poly1->power;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}

	
		else if (poly1->power < poly2->power) {
			poly->power = poly2->power;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}

	
		else {
			poly->power = poly1->power;
			poly->coeff = poly1->coeff + poly2->coeff;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}

		
		poly->next
			= (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
	while (poly1->next || poly2->next) {
		if (poly1->next) {
			poly->power = poly1->power;
			poly->coeff = poly1->coeff;
			poly1 = poly1->next;
		}
		if (poly2->next) {
			poly->power = poly2->power;
			poly->coeff = poly2->coeff;
			poly2 = poly2->next;
		}
		poly->next
			= (struct Node*)malloc(sizeof(struct Node));
		poly = poly->next;
		poly->next = NULL;
	}
}

void show(struct Node* node)
{
	while (node->next != NULL) {
		printf("%dx^%d", node->coeff, node->power);
		node = node->next;
		if (node->coeff >= 0) {
			if (node->next != NULL)
				printf("+");
		}
	}
}

struct Node* addnode(struct Node* start,int coeff, int power)
{
	
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->coeff = coeff;
	newnode->power = power;
	newnode->next = NULL;

	
	if (start == NULL)
		return newnode;


	struct Node* ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = newnode;

	return start;
}


void removeDuplicates(struct Node* start)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;
		while (ptr2->next != NULL) {
			if (ptr1->power == ptr2->next->power) {
					ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

struct Node* multiply(struct Node* poly1, struct Node* poly2,struct Node* poly3)
{
	struct Node *ptr1, *ptr2;
	ptr1 = poly1;
	ptr2 = poly2;
	while (ptr1 != NULL) {
		while (ptr2 != NULL) {
			int coeff, power;
			coeff = ptr1->coeff * ptr2->coeff;
			power = ptr1->power + ptr2->power;			
			poly3 = addnode(poly3, coeff, power);
			ptr2 = ptr2->next;
		}
		ptr2 = poly2;
		ptr1 = ptr1->next;
	}

	removeDuplicates(poly3);
	return poly3;
}


int main()
{
	struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL ,*poly4 = NULL;
    int n1,n2,a,b,i;
    printf("\nInsert Number of terms of 1st Polynomial:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Insert coefficient: ");
        scanf("%d",&a);
        printf("Insert exponent: ");
        scanf("%d",&b);
        create_node(a, b, &poly1);
        a=0;b=0;
    }
	
	printf("\nInsert Number of terms of 2nd Polynomial:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Insert coefficient: ");
        scanf("%d",&a);
        printf("Insert exponent: ");
        scanf("%d",&b);
        create_node(a, b, &poly2);
        a=0;b=0;
    }

	printf("1st Number: ");
	show(poly1);

	printf("\n2nd Number: ");
	show(poly2);

	poly3 = (struct Node*)malloc(sizeof(struct Node));
    poly4 = (struct Node*)malloc(sizeof(struct Node));

	polyadd(poly1, poly2, poly3);
	printf("\nAdded polynomial: ");
	show(poly3);
    
    multiply(poly1, poly2, poly4);
    printf("\nMultiplied polynomial: ");
    show(poly4);
	return 0;
}
