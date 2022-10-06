/*All of the BST functions included*/
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
int countLeaves(struct node *);
int nonleafnodes(struct node *);
int countnodes(struct node *);
int sumofnodes(struct node *);
int maxDepth(struct node* );
void printlevel(struct node *,int,int);
int isBST(struct node *); 
int main()
{
    int choice, key,i;
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
        printf("8. Count the number of leaf nodes in the tree.\n");
        printf("9. Count the number of non leaf nodes.\n");
        printf("10.Count the number of nodes in tree.\n");
        printf("11.Count the Sum of all nodes of the tree.\n");
        printf("12.Depth of the tree.\n");
        printf("13.Find all the element kth level in single line.\n");
        printf("14.Check whether tree is BST or not.\n");
        printf("15. EXIT\n");
        printf("------------------------------------------------------\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter a value:\n");
            scanf("%d", &key);
            create_tree_ins(key);
            printf("Value inserted!\n");
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
            printf("Total no of the leaf node is : ");
            printf("%d\n",countLeaves(root));
            printf("\n");
            break;
        case 9:
            printf("Total number of non leaf nodes is: %d",nonleafnodes(root));
            printf("\n");
            break;
        case 10:
            printf("Number of nodes in the tree is : %d",countnodes(root));
            printf("\n");
            break;
        case 11:
            printf("Sum of all nodes of the tree is : %d", sumofnodes(root));
            printf("\n");
            break;
        case 12:
            printf("Depth of the tree is : %d", maxDepth(root));
            printf("\n");
            break;
        case 13:
            printf("\nEnter the Level : ");
            scanf("%d",&i);
            printf("All the elements at level %d is : ",i);
            printlevel(root, i, 0);
            printf("\n");
            break;
        case 14:
            printf("If the tree is BST then 1 else 0 : %d",isBST(root));
            printf("\n");
            break;
        case 15:
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
int countLeaves(struct node *node)
{
  if(node == NULL)
  {
    return 0;
  }
  if(node->lptr == NULL && node->rptr == NULL)
  {
    return 1;
  }
  return countLeaves(node->lptr) + countLeaves(node->rptr);
}
int count = 0;
int nonleafnodes(struct node* node)
{
    if(node != NULL)
    {
        nonleafnodes(node->lptr);
        if((node->lptr != NULL) || (node->rptr != NULL))
        {
            count++;
        }
        nonleafnodes(node->rptr);
    }
    return count;
}
static int c = 0;
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->lptr);
        c++;
        countnodes(root->rptr);
    }
    return c;
}
int sumofnodes(struct node *root)
{
    int rightsubtree, leftsubtree, sum = 0;
    if(root != NULL)
    {
        leftsubtree = sumofnodes(root->lptr);
        rightsubtree = sumofnodes(root->rptr);
        sum = (root->data) + leftsubtree + rightsubtree;
        return sum;
    }
}
int maxDepth(struct node* node)
{
    if (node == NULL)
        return -1;
    else
    {
        int lDepth = maxDepth(node->lptr);
        int rDepth = maxDepth(node->rptr);
     
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}
void printlevel(struct node *n, int desired, int current)
{
    if (n)
    {
        if (desired == current)
            printf("%d\t", n->data);
        else
        {
            printlevel(n->lptr, desired, current + 1);
            printlevel(n->rptr, desired, current + 1);
        }
    }
}
int isBST(struct node* node) 
{ 
  if (node == NULL) 
    return 1; 

  if (node->lptr!=NULL && find_maximum(node->lptr) > node->data) 
    return 0;
    
  if (node->rptr!=NULL && find_minimum(node->rptr) < node->data) 
    return 0; 
  
  if (!isBST(node->lptr) || !isBST(node->rptr)) 
    return 0; 

  return 1; 
}
