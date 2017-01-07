/*
Karan Chawla
Algorithm: Given an array find the largest sum contiguoius subarray
*/

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//function to calculate max subarray
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main(void)
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(a)/sizeof(*a);
	printf("Maximum contiguous sum is %d.\n", maxSubArraySum(a,size));
	return 0;
}