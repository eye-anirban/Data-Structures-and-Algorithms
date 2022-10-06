// 1.WAP using C
// I.To create a BST 
// II. Display the elements using Level order Traversal 
// III.Delete the leaf node and print it .
// IV.Delete a node which has only one child and readjust the BST
// V.Delete the node whose degree is 2 and display the deleted node,it’s inorder predecessor and inorder
//  successor and display all nodes in Inorder traversal after readjustment of BST 
#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    NODE *left;
    int data;
    NODE *right;
};NODE *root;

void delete_tree(NODE *root)
{
    if (root) 
    {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }

}
void inorderTraversal(struct node* root)
{
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}
void insert(NODE **tree, int value) 
{
    NODE *temp = NULL;
    if(!(*tree))
    {
        temp =(NODE*)malloc(sizeof(NODE));
        temp->left = temp->right = NULL;
        temp->data = value;
        *tree = temp;
        return;
    }
    if(value < (*tree)->data) 
    {
        insert(&(*tree)->left, value);
    } else if(value > (*tree)->data) 
    {
        insert(&(*tree)->right, value);
    }
}
NODE* deleteLeaf(NODE* root, int x)
{
    if (root == NULL)   return NULL;
    root->left = deleteLeaf(root->left, x);
    root->right = deleteLeaf(root->right, x);
    if (root->data == x && root->left == NULL && root->right == NULL) 
    {
        printf("\nDeleted leaf:%d",root->data);
        free(root);
        return NULL;
    }
    return root;
}
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int depth(NODE *root)
{
    if(root==NULL)
    {
        return -1;
    }
    else 
    {
        int leftD=depth(root->left);
        int rightD=depth(root->right);
        return max(leftD,rightD)+1;
    }
}

void print_kth_level(NODE *root , int k)   
{
   if(root == NULL|| k < 0 )  return;
   if( k == 0 )
   {
        printf( "%d ", root->data );
        return ;
   }  
    print_kth_level( root->left, k-1 ) ;
    print_kth_level( root->right, k-1 ) ;
}
void printLevelOrder(NODE *root)
{        
    int d = depth(root);
    int i;
    for(i=0;i<=d;i++) 
    {
        printf("\n");
         print_kth_level(root,i);
    }
   
}
NODE* minValueNode(NODE* node)
{
    struct node* current = node;
      while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
NODE* deleteNode(NODE* root, int key)
{
  
    if (root == NULL)
        return root;
     if (key < root->data)
        root->left = deleteNode(root->left, key);
     else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
         if (root->left == NULL)
        {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            NODE* temp = root->left;
            free(root);
            return temp;
        }
 
        
        NODE* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
	printf("How many nodes do you want to insert?");
	int n,i,a,b;
	scanf("%d",&n);
	printf("Enter those 5 nodes");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(&root,a);
		a=0;
	}

    printf("which Non-leaf node do you want to delete?");
    scanf("%d",&b);
    int c;
    printf("which leaf node do you want to delete?");
    scanf("%d",&c);
    printf("\nBefore deletion");
    printLevelOrder(root);
    printf("\nAfter deletion");
    deleteNode(root, b);
    deleteLeaf(root, c);
    printLevelOrder(root);
    printf("\n");
    inorderTraversal(root);
    delete_tree(root);
    return 0;
}
