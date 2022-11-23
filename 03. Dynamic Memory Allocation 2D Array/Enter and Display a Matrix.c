#include <stdio.h>
#include <stdlib.h>
int main ()
{
  int n, i, j, temp_643, m;
  printf ("Enter the number of rows and columns: ");
  scanf ("%d %d", &n, &m);
  
  int *p_643[n];
  for (i = 0; i < n; i++)
    p_643[i] = (int *) malloc (n * sizeof (int));
    
  printf ("Enter the elements of the matrix: \n");
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf ("%d", *(p_643 + i) + j);
      
  for (i = 0; i < n; i++)
    {
	 	for (j = 0; j < m/2; j++)  
		  {
		  	temp_643=p_643[i][j];
		  	p_643[i][j]=p_643[i][m-j-1];
		  	p_643[i][m-j-1]=temp_643;
		  }
    }
    printf("The elements are:\n");
    for (i = 0; i < n; i++)
    {   printf("\n");
	 	for (j = 0; j < m; j++)  
		  { 
		      printf("%d ", p_643[i][j]);
	      }
    }
    return 0;
}

		  	  
