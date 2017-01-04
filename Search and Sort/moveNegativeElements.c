#include <stdio.h> 

void printArray(int *a, int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ", a[i]);
	}
}

int main(void)
{
	int a[] = {1,-1, 3, 2, -7, -5,11, 6};
	int size = sizeof(a)/sizeof(*a);
	int temp[size];
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(a[i]>0)
		{
			temp[j++]=a[i];
		}
	}

	for(int k=0;k<size;k++)
	{
		if(a[k]<0)
		{
			temp[j++] = a[k];
		}
	}

	printArray(temp,size);

	return 0;
}