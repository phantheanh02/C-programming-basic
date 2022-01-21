// Phan The Anh 20204941
#include <stdio.h>
#include <stdlib.h>

int n = 0;
void in(int number[])
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", number[i]);
	}	
}

void insertionSort(int arr[], int k)
{
   int i, key, j;
   for (i = 1; i < k; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main()
{
	int a[100];
	fflush(stdin);
	scanf("%d", &n);
	for(int i = 0; i< n; i++)
	{
		a[i] = rand();
	}
	in(a);
	insertionSort(a, n);
	printf("\nSau khi sap xep:\n");
	in(a);
	
}
