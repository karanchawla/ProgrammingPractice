//Karan Chawla 
//Problem : https://en.wikipedia.org/wiki/Dutch_national_flag_problem

#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int*b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}


void threeWayParition(int *a, size_t size)
{
	int i = 0;
	int j = 0;

	int n = size - 1; 

	while (j <= n)
	{
		if(a[j] < 1)
		{
			swap(&a[i],&a[j]);
			i++;
			j++;
		}
		else if(a[j] > 1)
		{
			swap(&a[j],&a[n]);
			n = n-1;
		}
		else
		{
			j++;
		}
	}
}

void printArray(int *a, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(a+i));
	}
}

int main(void)
{
	int a[] = {0,0,0,1,1,1,0,0,2,1,2,0,1,2,0,1,1,2,2,2,0,0,0,1,0,1,2};

	size_t size = sizeof(a)/sizeof(*a);

	threeWayParition(a,size);

	printArray(a,size);

	return 0;
}