#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
int i, j, c=0;
for (i = 0; i < n-1; i++)	

	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
		{
			swap(&arr[j], &arr[j+1]);
			c++;
		}
		printf("No. of swaps: %d\n",c);
}

void insertionSort(int arr[], int n)
{
	int i, key, j, c=0;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
			c++;
		}
		arr[j + 1] = key;
	}
	printf("No. of swaps: %d\n",c);
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx,c;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
		swap(&arr[min_idx], &arr[i]);
		c++;
	}
	printf("No. of swaps: %d\n",c);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
	int arr1[] = { 2, 3, 4, 1, 5 };
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	printf("Bubble sort\nArray inserted:\n");
    printArray(arr1,n1);
    bubbleSort(arr1,n1);
    printArray(arr1,n1);
     printf("\n");
    int arr2[] = { 9, 6 ,3 ,1 ,8 };
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	printf("Insertion sort\nArray inserted:\n");
    printArray(arr2,n2);
    insertionSort(arr2,n2);
    printArray(arr2,n2);
     printf("\n");
    int arr3[] = { 5, 6, 3,2, 9 };
	int n3 = sizeof(arr3)/sizeof(arr2[0]);
	printf("Selection sort\nArray Inserted\n");
	printArray(arr3,n3);
    selectionSort(arr3,n3);
    printArray(arr3,n3);
     printf("\n");
    
    printf("Lets check when sorted arrays with duplicate elements are passed:\n");
    {
    int arr1[] = { 2, 2,3,4,5 };
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	printf("Bubble sort\nArray inserted:\n");
    printArray(arr1,n1);
    bubbleSort(arr1,n1);
    printArray(arr1,n1);
    printf("\n");
    int arr2[] = { 2,2,3,4,5 };
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	printf("Insertion sort\nArray inserted:\n");
    printArray(arr2,n2);
    insertionSort(arr2,n2);
    printArray(arr2,n2);
     printf("\n");
    int arr3[] = { 2,2,3,4,5 };
	int n3 = sizeof(arr3)/sizeof(arr2[0]);
	printf("Selection sort\nArray Inserted\n");
	printArray(arr3,n3);
    selectionSort(arr3,n3);
    printArray(arr3,n3);
     printf("\n");
    }
    
    printf("It can be concluded that bubble sort and insertion sort\n are stable and adaptive\nBut selecion sort is neither stable nor adaptive");
    return 0;
}