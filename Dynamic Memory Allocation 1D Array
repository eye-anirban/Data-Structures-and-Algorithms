#include<stdio.h>
#include<stdlib.h>
int main()
{   int n,*p_643,i, sum=0;
	
	printf("Enter no. of elements: \n");
	scanf("%d", &n);
	p_643=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{
		 printf("Enter element %d :", i+1);
		 scanf("%d", p_643+i);
	}
    for (i = 0; i <n; i++)
	{
        sum = sum + *(p_643 + i);
    }
    
    printf("\nElemets of the array are:\n");
    for(i=0;i<n;i++)
	{
	 	printf("%d ", *(p_643+i));
	}
    printf("\nAverage of array elements is: %d \n", sum/n);
    free(p_643);
    return 0;
}                                                                                             
