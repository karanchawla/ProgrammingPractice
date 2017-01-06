/*
 Karan Chawla
 Algorithm: Binary Search
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE 10000
#endif
// Time complexity: O(log n) 

int a[SIZE];

int binarySearch(int left, int right, int x)
{
	int i = left;
	int j = right;
	while(i<j)
	{
		int mid = (i+j)/2;
		if(a[mid]==x) return mid;
		if(a[mid]<x) i = mid + 1;
		else j = mid - 1; 
	}
	if(a[i]==x) return i;
	return -1;
}

int main(void)
{
	int x = 4;
	for(int i=0;i<4;i++) a[i] = i+1;
	printf("%d\n",binarySearch(0,3,x));
	return 0;
}