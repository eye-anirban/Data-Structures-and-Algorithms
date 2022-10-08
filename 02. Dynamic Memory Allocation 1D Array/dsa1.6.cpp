#include<stdio.h>
#include<stdlib.h>
int main()
{
      int *p_643,n,i,temp;
      printf("Enter number of elements: ");
      scanf("%d",&n);
      
      p_643=(int*)malloc(n * sizeof(int));
      
      printf("\nEnter %d Numbers:\n",n);
      for(i=0;i<n;i++)
      {
            scanf("%d",p_643+i);
      }
      
      for(i=0;i<n/2;i++)
      { temp=*(p_643+i);
        *(p_643+i)=*(p_643+(n-i-1));
        *(p_643+(n-i-1))=temp;
	  }
      
      printf("\nArray in Reverse Order: \n\n");
      for(i=0;i<n;i++)
      {
            printf(" %d",*(p_643+i));
      }
      return 0;
}

