// WAP to create a Binary Tree and display all the nodes using Iterative Version of all types of traversals 
// using Stack data structure.
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;

typedef struct stack STACK;
struct stack
{
    NODE *data;
    STACK *next;
};

void push(STACK **st,NODE *t)
{
    STACK *new=(STACK*)malloc(sizeof(STACK));
    new->next=NULL;
    new->data=t;
    if(*st==NULL)
    {
        *st=new;
    }
    else
    {
        new->next=*st;
        *st=new;
    }
}
NODE* pop(STACK **st)
{
    STACK *temp=*st;
    *st=(*st)->next;
    NODE *p=temp->data;
    free(temp);
    return p;
}

void preorder_it(NODE *t)
{
    STACK *s;
    while(s || t)
    {
        if(t!=NULL)
        {
            printf("%d ",t->data);
            push(&s,t);
            t=t->left;
        }
        else
        {
            t=pop(&s);
            t=t->right;
        }
    }
}

void inorder_it(NODE *tr)
{
    STACK *s;
    while(s || tr)
    {
        if(tr!=NULL)
        {
            push(&s,tr);
            tr=tr->left;
        }
        else
        {
            tr=pop(&s);
            printf("%d ",tr->data);
            tr=tr->right;
        }
    }
}

void postorder_it(NODE* root)
{
    // Check for empty tree
    if (root == NULL)
        return;
     
    STACK *stack;
    do
    {
        
        while (root)
        {
          
            if (root->right)
                push(&stack, root->right);
            push(&stack, root);
 
           
            root = root->left;
        }
          root = pop(&stack);
 
        
        if (root->right && stack->data == root->right)
        {
            pop(&stack);
            push(&stack, root); 
            root = root->right; 
        }
        else 
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (stack);
}
NODE* create()
{
    NODE *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
    return NULL;
    p=(NODE*)malloc(sizeof(NODE));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
    
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
void delete_tree(NODE *root)
{
    if (root) 
    {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }

}
int main()
{
    root=create();
    int c;
    do
    {
        printf("0.Exit\n1.Iterative inorder\n2.Iterative preorder\n3.Iterative postorder\nEnter your choice:");
        scanf("%d",&c);
        switch (c)
        {
            case 0:
            break;
        case 1:
            printf("\nInorder:");
            inorder_it(root);
            break;
        case 2:
            printf("\nPreorder:");
            preorder_it(root);
            break;
        case 3:
            printf("\nPostorder:");
            postorder_it(root);
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (c);

    delete_tree(root);
    return 0;
}
