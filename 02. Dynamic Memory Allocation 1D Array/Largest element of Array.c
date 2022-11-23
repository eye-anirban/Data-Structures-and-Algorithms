#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i, n,*p_643;
      printf("Enter number of elements: ");
      scanf("%d", &n);
      
      p_643 = (int*)malloc(n* sizeof(int));
      printf("\n");
      
      for(i = 0; i < n; i++)
      {
            printf("Enter element %d: ", i + 1);
            scanf("%d", p_643 + i);
      }
      
      for(i = 1; i < n; i++)
      {
            if(*p_643 < *(p_643 + i))
                  *p_643 = *(p_643 + i);
      }
      printf("\nLargest Element of the elements which have been entered is : %d", *p_643);
      return 0;
}


