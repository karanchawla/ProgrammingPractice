/*
Karan Chawla
Source: GFG
Median of two sorted array by divide and conquer 
Approach:
1) Calculate the medians m1 and m2 of the input arrays ar1[] 
and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
return m1 (or m2)
3) If m1 is greater than m2, then median is present in one 
of the below two subarrays.
a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one    
of the below two subarrays.
a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays 
becomes 2.
6) If size of the two arrays is 2 then use below formula to get 
the median.
Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
*/

#include <stdio.h>
#include <stdlib.h> 

int findMedian(int *a, int *b, int size)
{	
	if(size == 0)
		return -1;
	if(size==1)
		return (a[0]+b[1])/2;
	if(size==2)
		return (max(a[0],b[0]) + min(a[1],b[1]))/2;
 
	int median1 = median(a,size);
	int median2 = median(b,size);

	if(median1 = median2)
		return median1;
	else if(median1 > median2)
	{
		if(size % 2 == 0)
		{
			return findMedian(a + size/2 - 1, b, size - size/2 + 1);
		}
		return findMedian(a + size/2, b, size - size/2);
	}
	else 
		if(size % 2 == 0)
		{
			return findMedian(a, b + size/2 - 1, size - size/2 + 1);
		}
		return findMedian(a, b + size/2, size - size/2);
}

int median(int *a, int size)
{
	if(size%2==0)
		median1 = (arr[n/2] + arr[n/2-1])/2;
	else
		median1 = a[(n)/2];

	return median1;
}

//Driver program

int main(void)
{
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if(n1==n2)
	    findMedian(a,b,n1);
	else
		printf("Arrays are of unequal size\n");
	
	return 0;
}
