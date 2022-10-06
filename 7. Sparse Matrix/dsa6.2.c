//SPARSE MATRIX through Linked List, Transpose and Multiply
#include<stdio.h>
#include<stdlib.h>

struct node* initilise(struct node*, int, int, int);
void insert(struct node *head, int, int, int);
void display(struct node *head);
struct node* transpose(struct node*);
struct node* multiplyMatrix(struct node*, struct node*);

struct node {
    int row_643;
    int col_643;
    int value_643;
    struct node* next_643;
};
int main(){
    int row_643,col_643,val_643,value_643;
    printf("\nSparse matrix #1\n");
    printf("Enter no. of rows : "), scanf("%d",&row_643);
    printf("Enter no. of cols : "), scanf("%d",&col_643);
    printf("Enter no of non-zero entries : "), scanf("%d",&val_643);

    struct node* mat1 = initilise(mat1,row_643,col_643,val_643);
    printf("Enter matrix elements.\n");
    for(int i=0;i<val_643;i++){
        printf("\nElement no. #%d\n",i+1);
        printf("row no : "), scanf("%d",&row_643);
        printf("col no : "), scanf("%d",&col_643);
        printf("value : "), scanf("%d",&value_643);
        insert(mat1,row_643,col_643,value_643);
    }
    printf("\nSparse matrix #2\n");
    printf("Enter no. of rows : "), scanf("%d",&row_643);
    printf("Enter no. of cols : "), scanf("%d",&col_643);
    printf("Enter no of non-zero entries : "), scanf("%d",&val_643);
    struct node* mat2 = initilise(mat2,row_643,col_643,val_643);
    printf("Enter matrix elements.\n");
    for(int i=0;i<val_643;i++){
        printf("\nElement no. #%d\n",i+1);
        printf("row no : "), scanf("%d",&row_643);
        printf("col no : "), scanf("%d",&col_643);
        printf("value : "), scanf("%d",&value_643);
        insert(mat2,row_643,col_643,value_643);
    }
    printf("\nMatrix #1:\n");
    display(mat1);
    printf("\nMatrix #2:\n");
    display(mat2);
    struct node* product = multiplyMatrix(mat1,mat2);
    printf("\nProduct =\n");
    display(product);
    return 0;
}
struct node* transpose(struct node* head_643){
    if(!head_643){
        return NULL;  }
    struct node* ptr_643 = head_643->next_643;
    while(ptr_643){
        int temp_643 = ptr_643->row_643;
        ptr_643->row_643 = ptr_643->col_643;
        ptr_643->col_643 = temp_643;
        ptr_643= ptr_643->next_643;
    }
    return head_643;   }
struct node* multiplyMatrix(struct node* mat1_643, struct node* mat2_643){
    if(mat1_643->col_643 != mat2_643->row_643){
        printf("Invalid dimensions for matrices multiplication.\n");
        return NULL;
    }
    mat2_643 = transpose(mat2_643);
    printf("\ntranspose of matrix #2 :\n");
    display(mat2_643);
    struct node* temp_643 = (struct node*)malloc(sizeof(struct node));
    temp_643->row_643 = mat1_643->row_643;
    temp_643->col_643 = mat2_643->row_643;
    struct node* tempptr_643 = temp_643;
    struct node* ptr1_643 = mat1_643->next_643;   
    while(ptr1_643){
        struct node* ptr2_643 = mat2_643->next_643;
        while(ptr2_643){
            struct node* new_643 = (struct node*)malloc(sizeof(struct node));
            new_643->row_643 = ptr1_643->row_643;
            new_643->col_643 = ptr2_643->row_643;
            new_643->value_643 = ptr1_643->value_643*ptr2_643->value_643;
            new_643->next_643 = NULL;
            tempptr_643 = tempptr_643->next_643 = new_643;
            ptr2_643=ptr2_643->next_643;
        }
        ptr1_643=ptr1_643->next_643;        
    }
    struct node* product_643 = (struct node*)malloc(sizeof(struct node));
    product_643->row_643 = temp_643->row_643;
    product_643->col_643 = temp_643->col_643;
    product_643->value_643 = 0;
    product_643->next_643 = NULL;
    struct node* prodptr_643 = product_643;
    tempptr_643 = temp_643->next_643;
    while(temp_643){
        struct node* temp2_643 = temp_643->next_643;
        int flag_643 = 1;
        while(temp2_643){
    if(temp_643->row_643 == temp2_643->row_643 && temp_643->col_643 == temp_643->col_643){
          struct node* new_643 = (struct node*)malloc(sizeof(struct node));
    new_643->value_643  = temp_643->value_643 + temp2_643->value_643;
                new_643->row_643 = temp_643->row_643;
                new_643->col_643 = temp_643->col_643;
                new_643->next_643 = NULL;
                product_643->value_643++;
                prodptr_643 = prodptr_643->next_643 = new_643;
            }
            temp2_643 = temp2_643->next_643;  }
        if(!flag_643){
            struct node* new_643 = (struct node*)malloc(sizeof(struct node));
   new_643->value_643  = temp_643->value_643 + temp2_643->value_643;
            new_643->row_643 = temp_643->row_643;
            new_643->col_643 = temp_643->col_643;
            new_643->next_643 = NULL;
            product_643->value_643++;
            prodptr_643 = prodptr_643->next_643 = new_643;
        }
        temp_643=temp_643->next_643;
    }
    return product_643;  }
struct node* initilise(struct node* head_643,int r_643,int c_643,int v_643){
    head_643 = (struct node*)malloc(sizeof(struct node));
    if(!head_643){
        printf("Insufficient memory!\n");
        exit(0);
    }
    head_643->row_643 = r_643;
    head_643->col_643 = c_643;
    head_643->value_643 = v_643;
    head_643->next_643 = NULL;
    return head_643;
}

void insert(struct node* head_643,int r_643,int c_643,int v_643){
    struct node* ptr_643 = head_643;
    struct node* new_643 = (struct node*)malloc(sizeof(struct node));
    if(!new_643){
        printf("Insufficient memory!\n");
        exit(0);
    }
    new_643->row_643 = r_643;
    new_643->col_643 = c_643;
    new_643->value_643 = v_643;
    new_643->next_643 = NULL;
    while(ptr_643->next_643){
        ptr_643 = ptr_643->next_643;
    }
    ptr_643->next_643 = new_643;
    return;
}
void display(struct node* head_643){
    struct node* ptr_643 = NULL;
    for(int i = 0;i<head_643->row_643;i++){
        for(int j=0;j<head_643->col_643;j++){
            ptr_643 = head_643->next_643;
            int flag_643 = 0;
            while(ptr_643){
               if(i==ptr_643->row_643 && j ==ptr_643->col_643){
                   printf("%d ",ptr_643->value_643);
                   flag_643 = 1;
                   break;
               }
               ptr_643 = ptr_643->next_643;
            }
            if(!flag_643){
                 printf("0 ");
            }     }
        printf("\n");
    }  }
