//Karan Chawla
//In place merge two sorted arrays 
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void merge(int *a, int *b, int m, int n, int* ans)
{
	size_t i, j, k;
	i = 0; j = 0; k = 0;

	//while index less than the size of first array
	while( i < m )
	{	
		//if first element of second array less than first - swap them
		if( b[0] < a[i] )
		{
			swap(&b[0],&a[i]);
			//sort the second array everytime a swap is done
			qsort( b, n, sizeof(*b), comp);	
		}
		i++;
	}

}

int main(void)
{
	int a[] = { 1, 4, 7, 8, 10 };
	int b[] = { 2, 3, 9 };

	size_t m = sizeof(a)/sizeof(*a);
	size_t n = sizeof(b)/sizeof(*b);

	int ans[m+n];

	merge(a, b, m, n, ans);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", *(b+i));
	}

	return 0;
}