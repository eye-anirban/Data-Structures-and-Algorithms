// C++ program for sorting dates using selection sort
#include<stdio.h>

struct date
{
	int day;
	int month;
	int year;
};

int main()
{
	struct date input[5];
	printf("Insert 5 Dates:\n");
	for(int i=0; i<5; i++)
	{
		scanf("%d",&input[i].day);
		scanf("%d",&input[i].month);
		scanf("%d",&input[i].year);

	}
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<5-i-1; j++)
		{
			if (input[j].year > input[j+1].year)
			{
				struct date temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			}
			else if (input[j].year == input[j+1].year && input[j].month > input[j+1].month)
			{
				struct date temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			}
			else if (input[j].year == input[j+1].year && input[j].month == input[j+1].month && input[j].day > input[j+1].day)
			{
				struct date temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			}

		}
	}
    
    printf("Dates after sorting are:\n");
	for(int i=0; i<5; i++)
	{
		printf("%d %d %d\n",input[i].day,input[i].month,input[i].year);
	}
}
