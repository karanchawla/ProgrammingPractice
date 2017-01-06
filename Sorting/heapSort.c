/*
 Karan Chawla
 Algorithm: Heap Sort
*/
#include <stdio.h> 

//Time Complexity O(n log n)

void swap(int * a, int * b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

//standard function to heapify node at i
void heapify(int *a, int size, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l<size && a[l]>a[largest])
	{
		largest = l;
	}

	if(r<size && a[r]>a[largest])
	{
		largest = r;
	}

	if(largest!=i)
	{
		swap(&a[i], &a[largest]);

		//recursively heapify the modified sub-tree
		heapify(a,size,largest);
	}

}


void heapSort(int *a, int size)
{
	//Build heap
	for(int i=size/2 - 1;i>=0;i--)
	{
		heapify(a,size,i);
	}

	//extract elements one by one
	for(int i=size-1;i>=0;i--)
	{
		swap(&a[0],&a[i]);

		heapify(a,i,0);
	}

}

//utility function to print array
void printArray(int *a, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ", *(a+i));
	}
}

//Driver function
int main(void)
{
	int a[] = {12, 11, 13, 5, 6, 7};
	int size = sizeof(a)/sizeof(*a);
	heapSort(a,size);
	printArray(a,size);
	return 0;
}