//Insertion sort descending order
#include <stdio.h>

void print_array (int arr[], int size) 
{
	int i;
  
for ( i = 0; i < size; i++)
    
    {
      
printf ("%d ", arr[i]);
    
} 
printf ("\n");

} 

void insertion_sort (int arr[], int size) 
{
  int i;
for ( i = 1; i < size; i++)
    
    {
      
int key = arr[i];
      
int j = i - 1;
      
while (key > arr[j] && j >= 0)
	
	{
	  
 
        arr[j + 1] = arr[j];
	  
        --j;
	
    }
      
arr[j + 1] = key;
    
}

}


int main () 
{
  
int arr[20];
  
int n , i;

printf("\nEnter the size of array");
 scanf("%d",&n);
 
 printf("Enter the elements of array: \n");
 for(i=0;i<n;i++)
 {
     scanf("%d",&arr[i]);
 }
  
insertion_sort (arr, n);
  
printf ("Sorted array in descending order:\n");
  
print_array (arr, n);

}
