#include <stdio.h>
#include <stdlib.h>

void var_col_643(int col_643)
{
    int *q[4],m,n,row_643=4;
    printf("\nEnter the elements of the 2D array\n");
    for(m=0;m<4;m++)
    {
     q[m]= (int *)malloc(col_643*sizeof(int));
     for(n=0;n<col_643;n++)
      scanf("%d",&q[m][n]);
    }
    printf("The array is as follows\n");
    for(m=0;m<4;m++)
    {
        for(n=0;n<col_643;n++)
            printf("%d\t",q[m][n]);
        printf("\n");
    }
}

void var_row_643(int row_643)
{
    int m,n,col_643=4;
    int (*q)[4];
    q = (int (*)[4])malloc(row_643*4*sizeof(int));
    printf("\nEnter the elements of the 2D array\n");
    for(m=0;m<row_643;m++)
        for(n=0;n<4;n++)
            scanf("%d",&q[m][n]);
    printf("The array is as follows\n");
    for(m=0;m<row_643;m++)
    {
        for(n=0;n<4;n++)
            printf("%d\t",q[m][n]);
        printf("\n");
    }
    
}

void var_both(int row_643,int col_643)
{
    int m,n,**q;
    q= (int **)malloc(row_643*sizeof(int *));
    printf("\nEnter the elements of the 2D array\n");
    for(m=0;m<row_643;m++)
    {
        q[m]=(int *)malloc(col_643*sizeof(int));
        for(n=0;n<col_643;n++)
         scanf("%d",&q[m][n]);
    }
    printf("The array is as follows\n");
    for(m=0;m<row_643;m++)
    {
        for(n=0;n<col_643;n++)
            printf("%d\t",q[m][n]);
        printf("\n");
    }
}

int main()
{
    int ch,row_643,col_643;
    printf("What type of array do you want?\n1) Fixed rows variable columns\n");
    printf("2) Variable rows fixed columns\n3) Both rows and columns variable\n");
    printf("Enter your choice = ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter the number of columns (rows fixed to 4) = ");
               scanf("%d",&col_643);
               var_col_643(col_643);
               break;
        case 2:printf("Enter the number of rows (columns fixed to 4) = ");
               scanf("%d",&row_643);
               var_row_643(row_643);
               break;
        case 3:printf("Enter the number of rows and columns = ");
               scanf("%d%d",&row_643,&col_643);
               var_both(row_643,col_643);
               break;
        default: printf("Wrong Input!");
    }
    return 0;
}
