#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int minDist(int arr_643[], int n, int x, int y)
{
	int minimumDist = INT_MAX;
    	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ( (x == arr_643[i] && y == arr_643[j] ||  y == arr_643[i] && x == arr_643[j]) &&   minimumDist > abs(i - j))
			{
				minimumDist = abs(i - j);
			}
		}
	}
	if (minimumDist == INT_MAX)
	{
		return -1;
	}
	return minimumDist;
}
int main() 
{       
        int n, *p_643 ,i,x,y;
		        printf("Enter the number of elements:\n");
		        scanf("%d",&n);
		        p_643=(int *)malloc(n*sizeof(int));
        for (i = 0; i < n; i++) 
				{ scanf("%d", p_643+i); }
        printf("The numbers between which the distance needs to be calculated are:\n");
        scanf("%d %d", &x,&y);
        printf("The minimum distance between the numbers is: %d",minDist(p_643, n, x, y));
        return 0;
}






