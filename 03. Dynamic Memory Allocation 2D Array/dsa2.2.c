
int nz_643 (int **p, int n)
{
  int c = 0, i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (p[i][j] != 0)
	c++;
  return c;
}

int sum_643 (int **p, int n)
{
  int s = 0, i, j;
  for (i = 0; i < n; i++)
    for (j = 1 + i; j < n; j++)
      s = s + p[i][j];
  return s;
}

void swap_643 (int **p, int n)
{
  int i, j, t;
  for (i = 0; i < n; i++)
    if (p[i][0 + i] != p[i][n - 1 - i])
      {
	t = p[i][n - 1 - i];
	p[i][n - 1 - i] = p[i][0 + i];
	p[i][0 + i] = t;
      }
}

int pro_643 (int **p, int n)
{
  int p1 = 1, i, j;
  for (i = 0; i < n; i++)
    p1 = p1 * p[i][0 + i];
  return p1;
}

int main ()
{
  int n, i, j, c, r;
  printf ("Enter the value of n: ");
  scanf ("%d", &n);
  
  int *p[n];
  for (i = 0; i < n; i++)
    p[i] = (int *) malloc (n * sizeof (int));
    
  printf ("Enter the elements of the matrix: \n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf ("%d", *(p + i) + j);
      
  printf ("1) Find the number of nonzero elements in A\n");
  printf ("2) Find the sum of the elements above the leading diagonal.\n");
  printf ("3) Swap the major diagonal element to the minor diagonal element.\n");
  printf ("4) Find the product of the diagonal elements.\n");
  printf ("Enter your choice: ");
  scanf ("%d", &c);
  
  switch (c)
    {
    case 1:
              printf ("\nNumber of nonzero elements in A: %d", nz_643 (p, n));
              break;
    case 2:
              printf ("\nSum of the elements above the leading diagonal: %d",
        	      sum_643 (p, n));
              break;
    case 3:
              swap_643 (p, n);
              printf ("\nSwapped Matrix:\n");
              for (i = 0; i < n; i++)
        	{
        	  for (j = 0; j < n; j++)
        	    printf ("%d ", p[i][j]);
        	  printf ("\n");
        	}
              break;
    case 4:
              printf ("Product of the diagonal elements: %d", pro_643 (p, n));
              break;
    default:
              printf ("Wrong choice");
    }
  return 0;
}
