/*
 Karan Chawla
 Algorithm: Quick Select
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE 10000
#endif

// Time Complexity: O(n)
int a[SIZE];

//utility function to swap two numbers
void swap(int *a, int *b)
{
	int * temp = b;
	*b = *a;
	*a = *temp;
}
//utility function to print array
void printArray(int *a, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ", a[i]);
	}
}

int quickSelect(int left, int right, int k)
{
	if(left<right)
	{
		int pivotIndex = left;
		int pivot = a[(left + right)/2];
		swap(&pivot, &a[right]);
		for(int i=left;i<right;i++)
		{
			if(a[i]<pivot)
			{
				swap(&a[pivotIndex],&a[i]);
				pivotIndex++;
			}
		}

		swap(&a[pivotIndex],&a[right]);
		if(pivotIndex==k) return a[pivotIndex];
		else if (k<pivotIndex) return quickSelect(left, pivotIndex-1, k);
		else return quickSelect(pivotIndex+1,right,k);
	}
	else 
		return a[left];
}

int main(void)
{
	int n = 4; int k = 2;
	for(int i=0;i<4;i++) a[i] = i+2;
	printf("%d\n", quickSelect(0,n-1,k)); 
	return 0;
}