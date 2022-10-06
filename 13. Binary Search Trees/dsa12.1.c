//BST in,pre,post traversals find max,min search BST 
#include<stdio.h>
#include<stdlib.h>             

struct node
{
    struct node * lptr;
    int data;
    struct node * rptr;
};

struct node * root;

void create_tree_ins(int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
int find_minimum(struct node *);
int find_maximum(struct node *);
struct node * search(struct node *, int);

int main()
{
    int choice, key;
    struct node * x;
    while(1)
    {
        printf("\n------------------------------------------------------\n");
        printf("1. Insert a node\n");
        printf("2. Traverse the Tree in Inorder\n");
        printf("3. Traverse the tree in Pre-order\n");
        printf("4. Traverse the tree in post-order\n");
        printf("5. smallest Node\n");
        printf("6. largest Node\n");
        printf("7. Search whether a given node is present or not.\n");
        printf("8. EXIT\n");
        printf("------------------------------------------------------\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter a value:\n");
            scanf("%d", &key);
            create_tree_ins(key);
            break;
        case 2:
                printf("In-Order Traversal of BST - \n");
                inorder(root);
                printf("\n");
                break;
        case 3:
                printf("Pre-Order Traversal of BST - \n");
                preorder(root);
                printf("\n");
                break;
        case 4:
                printf("Post-Order Traversal of BST - \n");
                postorder(root);
                printf("\n");
                break;
        case 5:
                printf("Smallest Node in BST : ");
                printf("%d\n",find_minimum(root));
                break;
        case 6:
                printf("Largest Node in BST : ");
                printf("%d\n",find_maximum(root));
                break;
        case 7:
            printf("Enter the key to find:\n");
            scanf("%d", &key);
            x = search(root, key);
            if(x == NULL)   
                printf("Element not found!\n");
            else    
                printf("Element %d found!\n", x -> data);
            break;

        case 8:
            exit(1);
            break;
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}

void create_tree_ins(int key)
{
    struct node * t, * new, * r;
    t = root;

    if(root == NULL)           
    {
        new = (struct node *) malloc(sizeof(struct node));
        new -> data = key;
        new -> lptr = new -> rptr = NULL;
        root = new;
        return;
    }
    
    while(t != NULL)
    {
        r = t;
        if(key < t -> data)
        {
            t = t -> lptr;
        }
        else if(key > t -> data)
        {
            t = t -> rptr;
        }
        else                   
        {
            return;             
        }
    }
    
    new = (struct node *) malloc(sizeof(struct node));
    new -> data = key;
    new -> lptr = new -> rptr = NULL;

    if(new -> data < r -> data)
    {
        r -> lptr = new;
    }
    else
    {
        r -> rptr = new;
    }
}

int find_minimum(struct node *root)
{
    if(root == NULL)
        return -1;
    else if(root->lptr != NULL)
        return find_minimum(root->lptr);
    return root->data;
}

int find_maximum(struct node *root)
{
    if(root == NULL)
        return -1;
    else if(root->rptr != NULL)
        return find_maximum(root->rptr);
    return root->data;
}


void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->lptr);
    printf("%d ", root->data);
    inorder(root->rptr);
}

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lptr);
    preorder(root->rptr);
}

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d ", root->data);
}

struct node * search(struct node * t, int key)
{
    while (t != NULL)
    {
        if(key > t -> data)
            t = t -> rptr;
        else if(key < t -> data)
            t = t -> lptr;
        else              
            return t;
    }
    return NULL;
}
