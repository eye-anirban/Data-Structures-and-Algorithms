#include <stdio.h> 
#include <stdlib.h>
int main(void)
{
   int i, *p_643,n,j=-1,m;
   printf("Enter the number of elements:\n");
   scanf("%d",&n);
   p_643=(int *)malloc(n*sizeof(int));
   
   printf("Enter the elements:\n");
   for (i=0;i<n;i++)
  	{ 
   	 scanf("%d", p_643+i);
  	}
   
    for(i=0;i<n;i++)
    {
      if(p_643[i]%2==0)
	   {
		 j++;
		 m=p_643[j];
		 p_643[j]=p_643[i];
		 p_643[i]=m;           
       }
	}
	
	printf("\nArray after separating the 0s to left and 1s to right are:\n");
	for(i=0;i<n;i++)
    printf("%d " , *(p_643+i));
	return 0;
}


