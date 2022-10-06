//Selection Sort 

#include <stdio.h>
#include<stdlib.h>

void swap(float *x,float *y)
{
 float temp=*x;
 *x=*y;
 *y=temp;
}

void SelectionSort(float A[],float n)
{
 int i,j,k;
 
 for(i=0;i<n-1;i++)
 {
 for(j=k=i;j<n;j++)
 {
 if(A[j]<A[k])
 k=j;
 }
 swap(&A[i],&A[k]);
 }
}

int main()
{
 float A[20];
 int n,i;
 printf("Enter the no. of elements:");
 scanf("%d",&n);
 printf("Enter those elements:");
 for(i=0;i<n;i++)
 {
    scanf("%f",&A[i]); 
 }
 
 SelectionSort(A,n);
 printf("\nSorted Elements:");
 for(i=0;i<n;i++)
 printf("%.1f ",A[i]);
 printf("\n");
 
 return 0;
}
