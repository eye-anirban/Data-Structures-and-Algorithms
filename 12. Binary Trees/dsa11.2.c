//Binary tree Inorder preorder postorder using recursive
# include <stdio.h>
# include <stdlib.h>

struct BinaryTree{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

struct BinaryTree* create_node(){
    struct BinaryTree* node = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    int data;
    printf("Enter the data for the current node: ");
    scanf("%d", &data);
    printf("\n");

    if(data == -1){
        return NULL;
    }

    node->data = data;

    printf("Left child of %d\n", data);
    node->left = create_node();

    printf("Right child of %d\n", data);
    node->right = create_node();

    return node;
}

void in_order_tree_traversal(struct BinaryTree* root){
    if(root == NULL){
        return;
    }

    in_order_tree_traversal(root->left);
    printf("%d ", root->data);
    in_order_tree_traversal(root->right);
}


void pre_order_tree_traversal(struct BinaryTree* root){
    if(root == NULL){
        return;
    }

    printf("%d ", root->data);
    pre_order_tree_traversal(root->left);
    pre_order_tree_traversal(root->right);
}

void post_order_tree_traversal(struct BinaryTree* root){
    if(root == NULL){
        return;
    }

    post_order_tree_traversal(root->left);
    post_order_tree_traversal(root->right);
    printf("%d ", root->data);
}


int main(){
    struct BinaryTree *root = create_node();
    
    printf("\n ------------------ Traversal of tree ------------------\n");
    printf("Enter any number from 1 2 or 3\n");
    printf("1 : Pre order tree traversal\n");
    printf("2 : In order tree traversal\n");
    printf("3 : Post order tree traversal\n");
    printf("-1: Exit the choices ...\n");

    int choice;
    scanf("%d ", &choice);

    if(choice == 1) {
        printf("Pre order traversal of the tree \n");
        pre_order_tree_traversal(root);
        printf("\n");
    }

    else if(choice == 2) {
        printf("In order traversal of the tree \n");
        in_order_tree_traversal(root);
        printf("\n");
    }

    else if(choice == 3) {
        printf("Post order traversal of the tree \n");
        post_order_tree_traversal(root);
        printf("\n");
    }

    else {
        printf("exiting ....\n");
    }

}
