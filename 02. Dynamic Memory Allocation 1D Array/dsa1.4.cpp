#include<stdlib.h>
#include <math.h>
#include <stdio.h>
float standard(float *p_643) 
{
    float sum = 0.0, avg, std = 0.0;
    int i;
    for (i = 0; i < 20; i++) 
	{
        sum = sum + *(p_643+i);
    }
    avg = sum / 20;
    for (i = 0; i < 20; i++) 
	{
        std = std + pow(*(p+i) - avg, 2);
    }
    return sqrt(std / 20);
}
int main() 
{
    int i;
    float *p_643= (float*)malloc(20*sizeof(int));
    
    printf("Enter 20 elements: ");
    for (i = 0; i < 20; i++)
        scanf("%f", p_643+i);
    printf("\nStandard Deviation = %0.2f", standard(p_643));
    return 0;
}



